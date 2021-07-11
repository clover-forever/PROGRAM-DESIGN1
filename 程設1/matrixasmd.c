#include<stdio.h>
#include<string.h>
#define MAX 1000    // 大數的最大位數 
/*
大數加法 
引數： 
num1為第一個大數，用字元陣列儲存
num2為第二個大數
sum陣列儲存相加的結果  即：num1 num2=sum
返回值：返回陣列sum的有效長度，即計算結果的位數 
*/
int Addition(char num1[], char num2[], int sum[])
{
int i, j, len;
int n2[MAX] = {0};
int len1 = strlen (num1); // 計算陣列num1的長度，即大數的位數 
int len2 = strlen (num2); // 計算陣列num2的長度，即大數的位數 
len = len1>len2 ? len1 : len2; // 獲取較大的位數
//將num1字元陣列的數字字元轉換為整型數字，且逆向儲存在整型陣列sum中，即低位在前，高位在後
for (i = len1-1, j = 0; i >= 0; i--, j  ) 
sum[j] = num1[i] - '0';
// 轉換第二個數 
for (i = len2-1, j = 0; i >= 0; i--, j  )
n2[j] = num2[i] - '0';
// 將兩個大數相加 
for (i = 0; i <= len; i  )
{
sum[i]  = n2[i];  // 兩個數從低位開始相加 
if (sum[i] > 9)   // 判斷是否有進位 
{   // 進位 
sum[i] -= 10;
sum[i + 1];
}
}
if(sum[len] != 0)  // 判斷最高位是否有進位 
len  ;
return len;   // 返回和的位數 
}
int main()
{
int i, len;
int sum[MAX] = {0}; // 存放計算的結果，低位在前，高位在後，即sum[0]是低位 
char num1[] = "1234567891234567891234"; // 第一個大數 
char num2[] = "2345678912345678913345"; // 第二個大數 
len = Addition(num1, num2, sum);    // 兩數相加 
printf("%s\n   \n%s\n  =\n", num1, num2);
// 反向輸出求和結果
for (i = len-1; i >= 0; i--)
printf("%d", sum[i]);
printf("\n"); 
return 0;
}