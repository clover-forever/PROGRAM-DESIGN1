#include <stdio.h>
int i;
int line_count = 0;
int A,B,C,D,E,F;
int main()
{
   FILE *fp;
   char str[60];

   /* opening file for reading */
   fp = fopen("input.txt" , "r");
   if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
   for (line_count=0;line_count=1;line_count++){
   
      if( fgets (str, 60, fp)!=NULL ) {
      /* writing content to stdout */
        
		printf(str);
   }}
   fclose(fp);
   
   return(0);
}

