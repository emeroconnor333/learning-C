#include <stdio.h>
#include <windows.h>  // For Sleep()
#include <conio.h>  // For kbhit()
#include <stdlib.h>
#include <string.h>

#define ROWS 20
#define COLUMNS 40

// Function to clear the screen
void clearScreen() {
    #ifdef _WIN32
        // For Windows
        system("cls");
    #else
        // For Linux/Mac
        printf("\033[H\033[2J");
        fflush(stdout);
    #endif
}

int main() {
    // initial grid
    int grid[ROWS][COLUMNS];
    for (int j=0; j<ROWS; j++) {
        for (int i=0; i<COLUMNS; i++) {
            grid[j][i] = 0;
        }
    }

    printf("   ______                               _          ______                              ____   __    _ ____   \n");
    printf("  / ____/___  ____ _      ______ ___  _( )_____   / ____/___ _____ ___  ___     ____  / __/  / /   (_) __/__ \n");
    printf(" / /   / __ \\/ __ \\ | /| / / __ `/ / / /// ___/  / / __/ __ `/ __ `__ \\/ _ \\   / __ \\/ /_   / /   / / /_/ _ \\\n");
    printf("/ /___/ /_/ / / / / |/ |/ / /_/ / /_/ / (__  )  / /_/ / /_/ / / / / / /  __/  / /_/ / __/  / /___/ / __/  __/\n");
    printf("\\____/\\____/_/ /_/|__/|__/\\__,_/\\__, / /____/   \\____/\\__,_/_/ /_/ /_/\\___/   \\____/_/    /_____/_/_/  \\___/ \n");
    printf("                               /____/                                                                         \n");

    printf("Choose a pattern to start with:\n");
    printf("1) R-Pentomino\n");
    printf("2) Glider\n");
    printf("3) Gosper Glider Gun\n");
    printf("4) Pulsar\n");
    printf("5) 5x5\n");
    printf("6) Methuselah\n");

    int pattern = 0;
    scanf("%d", &pattern);

    switch(pattern) {
        case 1: // R-Pentomino
            grid[10][20] = 1;
            grid[10][21] = 1;
            grid[11][19] = 1;
            grid[11][20] = 1;
            grid[12][20] = 1;
            break;

        case 2: // Glider
            grid[0][1] = 1;
            grid[1][2] = 1;
            grid[2][0] = 1;
            grid[2][1] = 1;
            grid[2][2] = 1;
            break;

        case 3: // Gosper Glider Gun
            grid[0][24] = 1;
            grid[1][22] = 1; grid[1][24] = 1;
            grid[2][12] = 1; grid[2][13] = 1; grid[2][20] = 1; grid[2][21] = 1; grid[2][34] = 1; grid[2][35] = 1;
            grid[3][11] = 1; grid[3][15] = 1; grid[3][20] = 1; grid[3][21] = 1; grid[3][34] = 1; grid[3][35] = 1;
            grid[4][0] = 1; grid[4][1] = 1; grid[4][10] = 1; grid[4][16] = 1; grid[4][20] = 1; grid[4][21] = 1;
            grid[5][0] = 1; grid[5][1] = 1; grid[5][10] = 1; grid[5][14] = 1; grid[5][16] = 1; grid[5][17] = 1; grid[5][22] = 1; grid[5][24] = 1;
            grid[6][10] = 1; grid[6][16] = 1; grid[6][24] = 1; grid[7][11] = 1; grid[7][15] = 1;
            grid[8][12] = 1; grid[8][13] = 1;
            break;

        case 4: // Pulsar
            // Rows with consecutive cells
            int consecutiveRows[] = {4, 9, 11, 16};
            int consecutiveColumns1[] = {16, 17, 18};
            int consecutiveColumns2[] = {22, 23, 24};

            for (int i = 0; i < 4; i++) {  // Loop through consecutive rows
                int row = consecutiveRows[i];
                for (int j = 0; j < 3; j++) {
                    grid[row][consecutiveColumns1[j]] = 1;  // First set of consecutive columns
                    grid[row][consecutiveColumns2[j]] = 1;  // Second set of consecutive columns
                }
            }

            // Rows with specific single cells
            int specificRows[] = {6, 7, 8, 12, 13, 14};
            int specificColumns[] = {14, 19, 21, 26};

            for (int i = 0; i < 6; i++) {  // Loop through specific rows
                int row = specificRows[i];
                for (int j = 0; j < 4; j++) {
                    grid[row][specificColumns[j]] = 1;  // Set specific cells
                }
            }
            break;

        case 5: //5x5
            for (int i=17; i<22; i++){
                for (int j=7; j<12; j++){
                    grid[j][i]= 1;
                }
            }
            break;
        
        case 6: // Methuselah
            grid[7][15] = 1; grid[7][16] = 1; grid[7][20] = 1; grid[7][22] = 1;
            grid[8][15] = 1; grid[8][16] = 1; grid[8][21] = 1;
            grid[9][21] = 1;
            break;

        default:
            printf("Not a valid choice.");
            break;
    }

    int iteration = 1;
    while (1) {
        if (_kbhit()) {
            break;
        };

        // print grid
        clearScreen();
        printf("\nIteration %d:     ", iteration);
        printf("(Press any key to exit.)\n");
        for (int j=0; j<ROWS; j++) {
            for (int i=0; i<COLUMNS; i++) {
                if (grid[j][i]==1) {
                    printf(" O ");
                }
                else {
                    printf(" . ");
                }
            }
            printf("\n");
        }
        Sleep(200); // wait

        int count[ROWS][COLUMNS];
        for (int j=0; j<ROWS; j++) {
        for (int i=0; i<COLUMNS; i++) {
            count[j][i] = 0;
        }
    }

        // check how many surrounding cells are alive
        for (int i=0; i<COLUMNS; i++) {
            for (int j=0; j<ROWS; j++) {
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
                else if (i==COLUMNS-1 && j==0) { // top right corner (0, 8), (1, 8), (1, 9)
                    if (grid[0][COLUMNS-2] == 1) {
                        count[0][COLUMNS-1]++;
                    }
                    if (grid[1][COLUMNS-2] == 1) {
                        count[0][COLUMNS-1]++;
                    }
                    if (grid[1][COLUMNS-1] == 1) {
                        count[0][COLUMNS-1]++;
                    }
                    // printf("Cells alive around top right corner: %d\n", count[0][9]);
                }
                else if (i==0 && j==ROWS-1){ // bottom left corner (8, 0), (8, 1), (9, 1)
                    if (grid[ROWS-2][0] == 1) {
                        count[ROWS-1][0]++;
                    }
                    if (grid[ROWS-2][1] == 1) {
                        count[ROWS-1][0]++;
                    }
                    if (grid[ROWS-1][1] == 1) {
                        count[ROWS-1][0]++;
                    }
                    // printf("Cells alive around bottom left corner: %d\n", count[9][0]);
                }
                else if (i==COLUMNS-1 && j==ROWS-1){ // bottom right corner (8, 8), (8, 9), (9, 8)
                    if (grid[ROWS-2][COLUMNS-2] == 1) {
                        count[ROWS-1][COLUMNS-1]++;
                    }
                    if (grid[ROWS-2][COLUMNS-1] == 1) {
                        count[ROWS-1][COLUMNS-1]++;
                    }
                    if (grid[ROWS-1][COLUMNS-2] == 1) {
                        count[ROWS-1][COLUMNS-1]++;
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
                else if (j==ROWS) {
                    for (int k=ROWS-2; k <= ROWS-1; k++) {
                        for (int l = i-1; l <= i+1; l++){
                            if (!(k==ROWS-1 && l==i)){
                                if (grid[k][l] == 1) {
                                    count[ROWS-1][i]++;
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
                else if (i==COLUMNS-1) {
                    for (int k=j-1; k <= j+1; k++) {
                        for (int l = COLUMNS-2; l <= COLUMNS-1; l++){
                            if (!(k==j && l==COLUMNS-1)){
                                if (grid[k][l] == 1) {
                                    count[j][COLUMNS-1]++;
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
        for (int i=0; i<COLUMNS; i++) {
            for (int j=0; j<ROWS; j++) {
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

        iteration++;
    }

    
    return 0;
}

