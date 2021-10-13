#include <stdio.h>
//#include <stdlib.h>

int main(int argc, char* argv[])
{
   short i;
   FILE *fh;

   i = 1234;
   fh = fopen("data.bin", "wb" );
   fwrite( &i, sizeof( i ), 1, fh );
   fclose(fh);
}