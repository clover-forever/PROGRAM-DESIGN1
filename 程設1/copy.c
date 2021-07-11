#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <ctype.h>
int i;
int line_count = 0;
int main(int argc,char *argv[]){
	int c;
	char *string = "i:o:";
	FILE *fInput,*fOutput;
	while((c=getopt(argc,argv,string)) !=-1)
	{
		switch(c){
			case 'i':
				fInput=fopen("input.txt","r");
				{
		
					}
				break;
			case 'o':
				fOutput=fopen("output.txt","w+");
				
				break;
				
		}
		fclose(fInput);
		fclose(fOutput);
}
}
