#include <stdio.h>
#include <string.h>
#define M 100 //定義了數量M是100作為陣列初始化的數量 

int main()
{
	int i, j, len_s1, len_s2;    // len_s1是字元陣列s1的長度， len_s2是字元陣列s2的長度，
	char s1[M], s2[M];
	int num1[M] = {0};           // 數字陣列num1 
	int num2[M] = {0};           // 數字陣列num2 
	scanf("%s %s", s1, s2);    
	
	len_s1 = strlen(s1);         //	求第一個加數的位數 
	len_s2 = strlen(s2);	     // 求第二個加數的位數 
	
	for(i=len_s1-1, j=0; i>=0; i--)   //將字元陣列轉化為數字陣列，並倒數存放，作為第一個加數 
	{
		num1[j] = s1[i] - '0';
		j++;
	}
	for(i=len_s2-1, j=0; i>=0; i--)   //將字元陣列轉化為數字陣列，並倒數存放，作為第二個加數 
	{
		num2[j] = s2[i] - '0';
		j++;
	}
	
	for(i=0; i<=M; i++)               //實現大數的加法 
	{
		num1[i] = num1[i]+num2[i];
		if(num1[i]>9)
		{
			num1[i] = num1[i]-10;
			num1[i+1]++; 	
		}	
	}
	
	for(i=M-1; i>=0&&num1[i]==0; i--);  //求得最終結果的位數 
	
	if(i>0)
	{
		for(; i>=0; i--)                    //最終答案的輸出 
		{
			printf("%d", num1[i]);	
		}
	}
	else 
		printf("0");
	return 0;
}
