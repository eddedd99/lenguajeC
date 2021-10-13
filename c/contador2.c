#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int num;
   FILE *fptr;

   
   fptr = fopen("contador.txt","w+");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   
   int i = 1;
   int veces = 0;
   
   // to store execution time of code
   double time_spent = 0.0;
 
   clock_t begin = clock();
 
   printf("Num veces: ");
   scanf("%d",&veces);
   
   while (i <= veces)
   {
        printf("%d\n", i);
        fprintf(fptr,"%d\n",i);
        ++i;
   }
   
   fclose(fptr);

   clock_t end = clock();
 
   // calculate elapsed time by finding difference (end - begin) and
   // dividing the difference by CLOCKS_PER_SEC to convert to seconds
   time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
   
   printf("Time elpased is %f seconds", time_spent);
   
   return 0;
}
