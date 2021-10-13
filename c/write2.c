#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num,i=1;
   
   FILE *fptr;
   fptr = fopen("C:\\cygwin64\\home\\eduardo.cruces\\c\\write2.txt","w");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

   printf("Enter num: ");
   scanf("%d",&num);

   for (i=1; i<=num; ++i) {
       fprintf(fptr,"%d\n",i);
       printf("%d\n", i);
   }
   
   fclose(fptr);
   return 0;
}