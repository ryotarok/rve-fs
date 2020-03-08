#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <sys/mman.h>

#define NUMBEROF(array) \
    (size_t)(sizeof(array)/sizeof(array[0]))

#define VMEM_SIZE (0x1000)

static void* alloc_writable_memory(size_t size);
static int make_memory_executable(void* m, size_t size);
static size_t build_code(uint8_t* vmem, size_t bytes);
static size_t write_prologue(uint8_t* vmem, size_t current_bytes);
static size_t write_function_body(uint8_t* vmem, size_t current_bytes);
static size_t write_epilogue(uint8_t* vmem, size_t current_bytes);
static void callee(uint64_t first, uint64_t second);
static void dump(uint8_t* vmem, size_t count);

typedef void (*exe_func_t)(void);

static void test() {
    uint8_t *vmem = alloc_writable_memory(VMEM_SIZE);
    size_t bytes = build_code(vmem, VMEM_SIZE);
    make_memory_executable(vmem, VMEM_SIZE);
    dump(vmem, bytes);

    printf("enter generated func\n");
    fflush(stdout);

    exe_func_t f = (exe_func_t)vmem;
    f();

    printf("leaved generated func\n");
    fflush(stdout);

    // printf("f() = %s\n", b?"true":"false");
}

static void test3(uint64_t a, uint64_t b) {
    printf("hello\n");
}

static void test2() {
    test3(0x1234, 0x5678);
}

int main() {
    test2();
    test();
    return 0;
}

// private
// Allocates RW memory of given size and returns a pointer to it. On failure,
// prints out the error and returns NULL. Unlike malloc, the memory is allocated
// on a page boundary so it's suitable for calling mprotect.
static void* alloc_writable_memory(size_t size) {
  void* ptr = mmap(0, size,
                   PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (ptr == (void*)-1) {
    perror("mmap");
    return NULL;
  }
  return ptr;
}

// Sets a RX permission on the given memory, which must be page-aligned. Returns
// 0 on success. On failure, prints out the error and returns -1.
static int make_memory_executable(void* m, size_t size) {
  if (mprotect(m, size, PROT_READ | PROT_EXEC) == -1) {
    perror("mprotect");
    return -1;
  }
  return 0;
}

static size_t build_code(uint8_t* vmem, size_t bytes) {
    size_t current_bytes = 0;
    current_bytes += write_prologue(&vmem[current_bytes], current_bytes);
    current_bytes += write_function_body(&vmem[current_bytes], current_bytes);
    current_bytes += write_epilogue(&vmem[current_bytes], current_bytes);
    return current_bytes;
}

static size_t write_prologue(uint8_t* vmem, size_t current_bytes) {
    static uint8_t code[] = {
        0x55,               // pushq %rbp
        0x48, 0x89, 0xe5,   // movq %rsp, %rbp
    };
    memcpy(vmem, code, NUMBEROF(code));
    return NUMBEROF(code);
}

static size_t write_epilogue(uint8_t* vmem, size_t current_bytes) {
    static uint8_t code[] = {
        0x5d,                   // popq %rbp
        0xc3,                   // retq
        0x90,                   // nop
    };
    memcpy(vmem, code, NUMBEROF(code));
    return NUMBEROF(code);
}

static size_t write_function_body(uint8_t* vmem, size_t current_bytes) {
    static uint8_t code[] = {
        0x48, 0xbf, 0x34, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x12, // movabsq $1369094286720630580, %rdi
        0x48, 0xbe, 0x78, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x56, // movabsq $6269010681299730296, %rsi
        0xe8, 0x00, 0x00, 0x00, 0x00,                               // callq <callee>
    };
    memcpy(vmem, code, NUMBEROF(code));

    uint64_t callee_addr = (uint64_t)callee;
    uint64_t c = (uint64_t)&vmem[25];
    uint64_t diff = (uint64_t)(callee_addr - c);
    printf("callee   : 0x%016llx\n", (uint64_t)callee);
    printf("vmem[25] : 0x%016llx\n", (uint64_t)&vmem[25]);
    printf("diff     : 0x%016llx\n", (uint64_t)diff);

    int32_t jump_addr_base_pos = 21;
    vmem[jump_addr_base_pos + 0] = ((diff >>  0) & 0xff);
    vmem[jump_addr_base_pos + 1] = ((diff >>  8) & 0xff);
    vmem[jump_addr_base_pos + 2] = ((diff >> 16) & 0xff);
    vmem[jump_addr_base_pos + 3] = ((diff >> 24) & 0xff);
    return NUMBEROF(code);
}

static void callee(uint64_t first, uint64_t second) {
    printf("first = %llx\n", first);
    printf("second = %llx\n", second);
}

static void dump(uint8_t* vmem, size_t count) {
    printf("dump callee address : 0x%016llx\n", (uint64_t)callee);
    printf("vmem address        : 0x%016llx\n", (uint64_t)vmem);
    printf("vmem count          : %zu\n", count);
    printf("dump generated code :\n");
    for (size_t i = 0; i < count; ++i) {
        if ((i != 0) && (i % 16 == 0)) {
            printf("\n");
        }
        printf("  %02x", vmem[i]);
    }
    printf("\nend\n");
}
