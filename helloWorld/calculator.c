# include <stdio.h>

int main() {
    float num1;
    printf("Enter first number: ");
    scanf("%f", &num1);

    float num2;
    printf("Enter second number: ");
    scanf("%f", &num2);

    int operator;
    printf("Choose an operation:\n");
    printf("1) add\n");
    printf("2) subtract\n");
    printf("3) multiply\n");
    printf("4) divide\n");
    scanf("%d", &operator);

    if (operator == 1){
        printf("%.2f + %.2f = %.2f", num1, num2, num1+num2);
    }
    else if (operator == 2){
        printf("%.2f - %.2f = %.2f", num1, num2, num1-num2);
    } 
    else if (operator == 3){
        printf("%.2f x %.2f = %.2f", num1, num2, num1*num2);
    }   
    else if (operator == 4){
        printf("%.2f / %.2f = %.2f", num1, num2, num1/num2);
    }          
    else {
        printf("Unknown operator.");
    }    

    return 0;
}