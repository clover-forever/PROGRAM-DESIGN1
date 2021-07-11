#include<stdio.h>
int y,Height,Weight,Age;
float BMI;
int main(){
  scanf("%d %d %d",&y,&Height,&Weight);
  Age=2020-y+1;
  printf("Age = %d\n",Age);
  printf("Height = %dcm\n",Height);
  printf("Weight = %dkg\n",Weight);
  BMI=Weight/((Height*0.01)*(Height*0.01));
  printf("BMI = %.1f\n",BMI);
  if (Age<19||Age>36){
    printf("Not a Draftee (age < 19 or age > 36 years old)\n");
    printf("No need to perform Military Service");
  }
  else if (BMI<16.5||31.5<BMI){
    printf("Physical Status of Military Service Exemption\n");
    printf("Exemption from Military Service");}
  else if (16.5 <= BMI&&BMI< 17 || 31 < BMI&&BMI<= 31.5){
    printf("Physical Status of Substitute Service Draftees\n");
    if (y>=1994)
      printf("Replacement Service");
    else
      printf("Substitute Services");}
  else if (17<=BMI&&BMI<=31){
    printf("Physical Status of Regular Service Draftees\n");
    if (y>=1994)
      printf("4 months of Regular Service");
    else
      printf("1 year of Regular Service");}
    return 0;
}