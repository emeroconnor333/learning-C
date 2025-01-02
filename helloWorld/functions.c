// Create functions to calculate the sum, average, and maximum of an array of numbers.
#include <stdio.h>

float sum(int size, float nums[]) {
    float result = 0;
    for (int i=0; i<size; i++) {
        result += nums[i];
    }
    return result;
}

float average(int size, float nums[]) {
    return sum(size, nums) / size;
}

float max(int size, float nums[]) {
    float max = nums[0];
    for (int i=0; i<size; i++) {
        if (nums[i]>max) {
            max = nums[i];
        }
    }
    return max;
}

int main() {
    printf("Enter amount of numbers: ");
    int size = 0;
    scanf("%d", &size);

    float nums[size];
    for (int i=0; i<size; i++){
        printf("Enter number %d: ", i+1);
        scanf("%f", &nums[i]);
    }

    printf("%.2f\n", sum(size, nums));
    printf("%.2f\n", average(size, nums));
    printf("%.2f\n", max(size, nums));
}