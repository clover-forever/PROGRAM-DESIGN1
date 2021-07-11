#include <stdio.h>

void p(char *str, int n) {
char ch ;
int i ;
if(n==1) {
  printf("%s", str) ;
}
else {
  for(i=n-1 ; i>=0 ; i--) {
      ch = *(str+i) ;
      *(str+i) = *(str+n-1) ;
      *(str+n-1) = ch ;
      p(str, n-1) ;
      ch = *(str+i) ;
      *(str+i) = *(str+n-1) ;
      *(str+n-1) = ch ;
  }
}
}

int main() {
    int n;
    scanf("%d",&n);
char ch[n];
getchar();
for(int i=0;i<=n;i++){
    scanf("%c",&ch[i]);
}

p(ch, n) ;

return 0 ;
}
