#include<stdio.h>
#include<math.h>
void remain_copy(int i,int a[][6],int change[][6],int n);
int matrix(int n,int a[][6]);

int main(void)
{
int a[6][6];//記錄行列式的值
int i; //紀錄行列式的階數
int j,k;
int result; //結果

printf("請問要輸入幾階矩陣(至多6階)>");
scanf("%d",&i);

for(j=0;j<i;j++)
for(k=0;k<i;k++)
{ //依序請使用者輸入行列式的每個元素值
//printf("請輸入a[%d][%d]>",j,k);
scanf("%d",&a[j][k]);
}

result=matrix(i,a);//利用外部函數遞迴運算

printf("答案為%d\n",result);//印出答案
return(0);
}

int matrix(int n,int a[][6])
{
int change[6][6];//儲存刪掉i列j行的行列式
int ans=0; //答案
int i;
int pn; //判正負
int n2; //降階後的階數
n2=n-1; //每遞迴一次降一階
if(n==1)
ans=a[0][0]; //階數為一直接取值
if(n>=1)
for(i=0;i<n;i++)
{
remain_copy(i,a,change,n);//計算刪掉i列j行的行列式

if(i%2==0)//判正負
pn=1;
else
pn=-1;

ans=ans+pn*a[i][0]*matrix(n2,change);//遞迴傳回新的行列式和新階數
}

return(ans);

}

void remain_copy(int i,int a[][6],int change[][6],int n)
{
int j;
int k;
int p;
k=0;

for(p=0;p<n;p++)
{
if(p==i)//把原來的行列式第i列略過
continue;

for(j=1;j<n;j++)//跳過第0行,j從1開始(原來的)
change[k][j-1]=a[p][j];
k++;
}


}