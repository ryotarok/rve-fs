SECTIONS
{
   . = 0x0000000000000000;
   .text :  {
         start.o (.text);
         main.o (.text);
   }
}