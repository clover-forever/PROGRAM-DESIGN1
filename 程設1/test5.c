#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char s[5000];
int words = 0;

int main(void) {
	//readin
	while(gets(s) != NULL) {
		for(int i = 0; i < strlen(s); i++) {
			if(isalpha(s[i])) {
				while(isalpha(s[i])) {
					i++;
				}
				words++;
			}
		}
		printf("%d\n", words);
		words = 0;
	}
	
	return 0;
}