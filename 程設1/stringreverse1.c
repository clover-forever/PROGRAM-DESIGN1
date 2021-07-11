#include "stdio.h"
void fun(char *x)
{
	if(*x){                    //若該字元型變數為0（ascii碼值為0，不是數字'0'）的字元則不進入
		fun(x+1);          //遞迴呼叫
		printf("%c",*x);   //輸出單個字元
	}
}
int main()
{
	char str[100];
	gets(str);
	fun(str);
	return 0;
}