/* The player selects rock, paper, or scissors.
The computer randomly selects an option.
Compares choices to determine the winner. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to Rock, Paper, Scissors!\n");
    printf("Enter a choice:\n");
    printf("1) Rock\n");
    printf("2) Paper\n");
    printf("3) Scissors\n");
    int user;
    scanf("%d", &user);

    switch (user) {
        case 1:
            printf("You chose rock.\n");
            break;
        case 2:
            printf("You chose paper.\n");
            break;
        case 3:
            printf("You chose scissors.\n");
            break;
        default:
            printf("Not a valid choice.\n");
    }

    srand(time(NULL));
    int computer = (rand() % 3) + 1;
    switch (computer) {
        case 1:
            printf("Computer chose rock.\n");
            break;
        case 2:
            printf("Computer chose paper.\n");
            break;
        case 3:
            printf("Computer chose scissors.\n");
            break;
        default:
            printf("Not a valid choice.\n");
    }

    // user wins
    if (user==1 & computer==3 || user==2 & computer==1 || user==3 & computer==2) {
        printf("You win!");
    }
    // computer wins
    else if (user==1 & computer==2 || user==2 & computer==3 || user==3 & computer==1) {
        printf("You lose!");
    }
    // draw
    else {
        printf("It's a draw!");
    }

    return 0;
}