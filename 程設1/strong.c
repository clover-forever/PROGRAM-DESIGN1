#include <stdio.h>
int main(){ 
    int i, originalNum, num, lastDigit, sum;
    long fact;
    scanf("%d", &num); 
    originalNum = num; /* Copy the value of num to a temporary variable */
    sum = 0;
    while(num > 0) /* Find sum of factorial of digits */ { 
        lastDigit = num % 10; /* Get last digit of num */ 
        fact = 1;  /* Find factorial of last digit */ 
        for(i=1; i<=lastDigit; i++){ 
            fact = fact * i;
        }
        sum = sum + fact; /* Add factorial to sum */ 
        num = num / 10;
    }
    if(sum == originalNum){ /* Check Strong number condition */ 
        printf("%d is a strong number.", originalNum);
    }
    else{ 
        printf("%d is not a strong number.", originalNum);
    }
    return 0;
}
