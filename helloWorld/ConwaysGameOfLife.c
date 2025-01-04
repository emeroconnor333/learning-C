#include <stdio.h>

int main() {
    // initial grid
    int grid[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    int day = 1;
    while (day < 23) {
        printf("\nDay %d:\n", day);
        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                if (grid[i][j]==1) {
                    printf(" O ");
                }
                else {
                    printf(" . ");
                }
            }
            printf("\n");
        }

        int count[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        };

        // check how many surrounding cells are alive
        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                // check if is corner cell
                if (i==0 && j==0) { // top left corner (1,0), (0,1), (1,1)
                    if (grid[1][0] == 1) {
                        count[0][0]++;
                    }
                    if (grid[0][1] == 1) {
                        count[0][0]++;
                    }
                    if (grid[1][1] == 1) {
                        count[0][0]++;
                    }
                    // printf("Cells alive around top left corner: %d\n", count[0][0]);
                }
                else if (i==9 && j==0) { // top right corner (0, 8), (1, 8), (1, 9)
                    if (grid[0][8] == 1) {
                        count[0][9]++;
                    }
                    if (grid[1][8] == 1) {
                        count[0][9]++;
                    }
                    if (grid[1][9] == 1) {
                        count[0][9]++;
                    }
                    // printf("Cells alive around top right corner: %d\n", count[0][9]);
                }
                else if (i==0 && j==9){ // bottom left corner (8, 0), (8, 1), (9, 1)
                    if (grid[8][0] == 1) {
                        count[9][0]++;
                    }
                    if (grid[8][1] == 1) {
                        count[9][0]++;
                    }
                    if (grid[9][1] == 1) {
                        count[9][0]++;
                    }
                    // printf("Cells alive around bottom left corner: %d\n", count[9][0]);
                }
                else if (i==9 && j==9){ // bottom right corner (8, 8), (8, 9), (9, 8)
                    if (grid[8][8] == 1) {
                        count[9][9]++;
                    }
                    if (grid[8][9] == 1) {
                        count[9][9]++;
                    }
                    if (grid[9][8] == 1) {
                        count[9][9]++;
                    }
                    // printf("Cells alive around bottom right corner: %d\n", count[9][9]);
                }
                // top edge cells (0, i-1), (0, i+1), (1, i-1), (1, i), (1, i+1)
                else if (j==0) {
                    for (int k=0; k <= 1; k++) {
                        for (int l = i-1; l <= i+1; l++){
                            if (!(k==0 && l==i)){
                                if (grid[k][l] == 1) {
                                    count[0][i]++;
                                }
                            }
                        }
                    }
                    // printf("\nCells alive around i=%d, j=%d: %d\n", i, j, count[0][i]);
                }
                // bottom edge cells (8, i-1), (8, i+1), (9, i-1), (9, i), (9, i+1)
                else if (j==9) {
                    for (int k=8; k <= 9; k++) {
                        for (int l = i-1; l <= i+1; l++){
                            if (!(k==9 && l==i)){
                                if (grid[k][l] == 1) {
                                    count[9][i]++;
                                }
                            }
                        }
                    }
                    // printf("\nCells alive around i=%d, j=%d: %d\n", i, j, count[j][i]);
                }
                // left edge cells (j-1, 0), (j-1, 1), (j, 1), (j+1, 0), (j+1, 1)
                else if (i==0) {
                    for (int k=j-1; k <= j+1; k++) {
                        for (int l = 0; l <= 1; l++){
                            if (!(k==j && l==0)){
                                if (grid[k][l] == 1) {
                                    count[j][0]++;
                                }
                            }
                        }
                    }
                    //printf("\nCells alive around i=%d, j=%d: %d\n", i, j, count[j][i]);
                }
                // right edge cells (j-1, 8), (j-1, 9), (j, 8), (j+1, 8), (j+1, 9)
                else if (i==9) {
                    for (int k=j-1; k <= j+1; k++) {
                        for (int l = 8; l <= 9; l++){
                            if (!(k==j && l==9)){
                                if (grid[k][l] == 1) {
                                    count[j][9]++;
                                }
                            }
                        }
                    }
                    // printf("\nCells alive around i=%d, j=%d: %d\n", i, j, count[j][i]);
                }
                else { // inner cells j-1 -> j+1, i-1 -> i+1
                    for (int k=j-1; k <= j+1; k++) {
                        for (int l = i-1; l <= i+1; l++){
                            if (!(k==j && l==i)){
                                if (grid[k][l] == 1) {
                                    count[j][i]++;
                                }
                            }
                        }
                    }
                    // printf("\nCells alive around i=%d, j=%d: %d\n", i, j, count[j][i]);
                }
            }
        }
        // update grid
        // if cell alive: dies if neighbours is not 2 or 3
        // if cell dead: is born if neighbours = 3
        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                if (grid[j][i]==1) { // if cell is alive
                    if (count[j][i] !=2 && count[j][i] !=3) { // if under or overpopulated
                        grid[j][i] = 0; // dies 
                    }
                }
                else {
                    if (count[j][i] == 3) { //reproduction
                        grid[j][i] = 1; // is born
                    }
                }
            }
        }

        day++;
    }

    
    return 0;
}

