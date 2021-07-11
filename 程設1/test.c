#include<stdio.h>
#include<math.h>
int a;
int main(){
    scanf("%d",&a);
    switch(a){
        case(1):{
            double v;
            double b;
            
            scanf("%lf",&b);
            v=b*b*b;
            printf("%.2f",v);
            break;
        }
        case(2):{
            double c,d,e;
            double v2;
            scanf("%lf%lf%lf",&c,&d,&e);
            v2=c*d*e;
            printf("%.2f",v2);
            break;
        }
        case(3):{
            double f,g;
            double v3;
            scanf("%lf%lf",&f,&g);
            v3=3.14*f*f*g;
            printf("%.2f",v3);
            break;
        }
        case(4):{
            double h;
            double v4;
            scanf("%lf",&h);
            v4=sqrt(2/(12*h*h*h));
            printf("%.2f",v4);
            break;
        }
    }
    return 0;
}