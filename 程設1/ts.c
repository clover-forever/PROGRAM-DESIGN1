#include<stdio.h>
#include<stdlib.h>
void Reverse(char t[100])//字串反轉 
{
     int str_length,i,j;
     char temp;
     for(i=0;;i++)   //找尋字串長度
        if (t[i]=='\0') break;
     str_length=i;
     for(i=0;i<str_length/2;i++)  //反轉字串    
     {
         temp=t[i];
         t[i]=t[str_length-i-1];
         t[str_length-i-1]=temp;
     }    
}
void bignum_add(char a[100],char b[100],char c[100])
{
     int i=0;
       //需要做將a,b兩字串相加  
　　　　　　
//需要做進位處理
}
main()
{
    char a[100],b[100],c[100];
    int i;
    for(i=0;i<100;i++) {a[i]=0; b[i]=0; c[i]=0;}
    printf("請輸入超長整數(<100位數)\n被加數=");
    scanf("%s",a);    
    printf("加數=");
    scanf("%s",b);
    Reverse(a); //反轉字串
    printf("a=%s\n",a);
    Reverse(b);
    printf("b=%s\n",b);
    bignum_add(a,b,c);
    Reverse(c);                
    printf("c=%s\n",c);
    system("PAUSE");
}