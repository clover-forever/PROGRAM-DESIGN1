#include<stdio.h>
#include<stdlib.h>
int Max(int x, int y)   
{
    if(x>y)    return x;
    else return y;
}   
int Min(int x, int y)   
{
    if(x<y)return x;
    else return y;
}  
main()
{
    char S[1001], t=0;
    while(scanf("%s",&S)==1)
        {
            printf("AB Circle #%d:\n",++t);
            int CA=0, CB=0, a, L;
            for(a=0;S[a];a++)
                if(S[a]=='a')    CA++;
                else    CB++;
            for(L=a, a=0;a+Min(CA,CB)<L;a++)
                {
                    if(CA!=CB)
                        {
                            printf("%d,%d\n",a,a+Min(CA,CB));
                            if(a+Max(CA,CB)<L)
                                printf("%d,%d\n",a,a+Max(CA,CB));
                        }
                    else printf("%d,%d\n",a,a+CA);
                }
        }
    return 0;
}
