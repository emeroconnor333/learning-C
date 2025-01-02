#include <stdio.h>

int main() {
    // enter number of students
    printf("Number of students: ");
    int numStudents;
    scanf("%d", &numStudents);

    // enter grades
    float grades[numStudents];
    for (int i=0; i<numStudents; i++) {
        printf("Enter grade of student %d: ", i+1);
        scanf("%f", &grades[i]);
        while (grades[i] < 0 || grades[i] > 100) {
            printf("Grade must be between 0 and 100.\nRe-enter grade: ");
            scanf("%f", &grades[i]);
        }
    }
    // print grades
    for (int i=0; i<numStudents; i++) {
        printf("Student %d: %.2f\n", i+1, grades[i]);
    }

    // average grade
    float sum=0;
    for (int i=0; i<numStudents; i++) {
        sum+= grades[i];
    }
    float average = sum / numStudents;
    printf("The average grade is %.2f\n", average);

    // max grade
    float max = 0;
    for (int i=0; i<numStudents; i++) {
        if (grades[i]> max) {
            max = grades[i];
        }
    }
    printf("The highest grade is %.2f\n", max);

    // min grade
    float min = 100;
    for (int i=0; i<numStudents; i++) {
        if (grades[i]< min) {
            min = grades[i];
        }
    }
    printf("The lowest grade is %.2f\n", min);

    return 0;
}