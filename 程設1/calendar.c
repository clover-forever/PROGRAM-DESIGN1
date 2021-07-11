#include <stdio.h>
int month;
int main(void)
{
    scanf("%d",&month);
    int days, start_day, i, j;
printf("Sun Mon Tue Wed Thu Fri Sat \n");
switch(month){
case(1):{
    /* prints the blank days of the first week */
    for (i = 1; i < 4; i++) {
        printf("    ");
    }
 
    /* prints the calendar numbers */
    for (j = 1; j <= 31; i++, j++) {
        printf("%3d ", j);
        if (i % 7 == 0)
            printf("\n");
    }break;
}
case(2):{
    for (i = 1; i < 7; i++) {
        printf("    ");
    }
 
    /* prints the calendar numbers */
    for (j = 1; j <= 29; i++, j++) {
        printf("%3d ", j);
        if (i % 7 == 0 && j != 29)
            printf("\n");
    }break;
}
case(3):{
    for (i = 1; i < 1; i++) {
        printf("    ");
    }
 
    /* prints the calendar numbers */
    for (j = 1; j <= 31; i++, j++) {
        printf("%3d ", j);
        if (i % 7 == 0)
            printf("\n");
    }break;
}
case(4):{
    for (i = 1; i < 4; i++) {
        printf("    ");
    }
 
    /* prints the calendar numbers */
    for (j = 1; j <= 30; i++, j++) {
        printf("%3d ", j);
        if (i % 7 == 0)
            printf("\n");
    }break;
}
case(5):{
    for (i = 1; i < 6; i++) {
        printf("    ");
    }
 
    /* prints the calendar numbers */
    for (j = 1; j <= 31; i++, j++) {
        printf("%3d ", j);
        if (i % 7 == 0)
            printf("\n");
    }break;
}
case(6):{
    for (i = 1; i < 2; i++) {
        printf("    ");
    }
 
    /* prints the calendar numbers */
    for (j = 1; j <= 30; i++, j++) {
        printf("%3d ", j);
        if (i % 7 == 0)
            printf("\n");
    }break;
}
case(7):{
    for (i = 1; i < 4; i++) {
        printf("    ");
    }
 
    /* prints the calendar numbers */
    for (j = 1; j <= 31; i++, j++) {
        printf("%3d ", j);
        if (i % 7 == 0)
            printf("\n");
    }break;
}
case(8):{
    for (i = 1; i < 7; i++) {
        printf("    ");
    }
 
    /* prints the calendar numbers */
    for (j = 1; j <= 31; i++, j++) {
        printf("%3d ", j);
        if (i % 7 == 0)
            printf("\n");
    }break;
}
case(9):{
    for (i = 1; i < 3; i++) {
        printf("    ");
    }
 
    /* prints the calendar numbers */
    for (j = 1; j <= 30; i++, j++) {
        printf("%3d ", j);
        if (i % 7 == 0)
            printf("\n");
    }break;
}
case(10):{
    for (i = 1; i < 5; i++) {
        printf("    ");
    }
 
    /* prints the calendar numbers */
    for (j = 1; j <= 31; i++, j++) {
        printf("%3d ", j);
        if (i % 7 == 0 && j!=31)
            printf("\n");
    }break;
}
case(11):{
    for (i = 1; i < 1; i++) {
        printf("    ");
    }
 
    /* prints the calendar numbers */
    for (j = 1; j <= 30; i++, j++) {
        printf("%3d ", j);
        if (i % 7 == 0)
            printf("\n");
    }break;
}
case(12):{
    for (i = 1; i < 3; i++) {
        printf("    ");
    }
 
    /* prints the calendar numbers */
    for (j = 1; j <= 31; i++, j++) {
        printf("%3d ", j);
        if (i % 7 == 0)
            printf("\n");
    }break;
}
}
    return 0;
}