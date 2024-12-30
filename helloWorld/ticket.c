# include <stdio.h>

int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    double price;

    if (age <= 18) {
        printf("Kid's ticket.\n");
        price = 5;
    }
    else if (age >= 18 && age < 60) {
        printf("Adult's ticket.\n");
        price = 10;
    }
    else {
        printf("Senior's ticket.\n");
        price = 7.5;
    }

    printf("Price: €%.2f", price);
    return 0;
}