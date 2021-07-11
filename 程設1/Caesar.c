#include<stdio.h>
int j, key;
int main()
{
 unsigned char ch;
  scanf("%d\n", &key);
  key=key%26;
  while((ch = getchar())!= '\n'){
    if(ch >= 'a' && ch <= 'z'){
      ch = ch + key;
      if(ch > 'z'){
        ch = ch - 'z' + 'a'-1;}
      if(ch<'a')
        ch='z'+ch-'a'+1;
      
    }
    else if(ch >= 'A' && ch <= 'Z'){
      ch = ch + key;
      if(ch > 'Z'){
        ch = ch - 'Z' + 'A' - 1;}
      if(ch<'A')
        ch='Z'-'A'+ch+1;
      
  }
  printf("%c",ch);
  }
  return 0;
}