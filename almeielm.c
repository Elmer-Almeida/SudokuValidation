/*
 * @author Elmer Almeida
 * @date May 29 2021
 * @revision 1
 *
 * almeielm.c provides all the functions required for main.c to operate.
 * The main purpose of this project is to validate a sudoku grid is valid or not.
 * In addition, two rows of input will be gathered from the user and
 * replaced with the randomly generated sudoku grid.
 */

#include "almeielm.h"

/*
 * This function prompts the user and displays the input requirements.
 */
void displayRowInputPrompt() {
    puts("Use Space/Tab/Return key to enter the next values");
    puts("and press 'RETURN' after entering 9 integers.");
    puts("Remember, to make a valid row of the Sudoku Grid,");
    puts("all integers should be distinct and range from 1-9.\n");
    printf("Input:");
}

/*
 * @param board[9][9] this is the board passed by reference
 * @param rows - Specifies the sudoku board row quantity
 * @param columns - Specifies the sudoku board columns quantity
 *
 * This function takes a sudoku board and populates its cells with random numbers
 */
void fillBoard(int board[SUDOKU_ROWS][SUDOKU_COLUMNS], int rows, int columns) {
    int i, j;
    srand(time(NULL)); // Seed random number generator to force new random numbers
    // loop through 2d array board[rows][columns]
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            board[i][j] = rand() % RANGE + OFFSET; // rand() % n + m | where n is range, m is offset
        }
    }
}

/*
 * @param board[9][9] this is the board passed by reference
 * @param rows - Specifies the sudoku board row quantity
 * @param columns - Specifies the sudoku board columns quantity
 *
 * This function takes the sudoku board, breaks it up into a small grid.
 * This grid will be used to verify that each grid has a sum of 45 and
 * is unique between the specified number of rows and columns.
 */
void checkBoard(int board[SUDOKU_ROWS][SUDOKU_COLUMNS], int rows, int columns) {
    int i, j;
    int rowColumnSum = 0, correctGrids = 0, correctItem = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            // Divide sudoku grid into 3x3's
            if (i % 3 == 0 && j % 3 == 0) {
                int x, y;
                // check each grid for sum and duplicate values
                for (x = 0; x < 3; x++) {
                    for (y = 0; y < 3; y++) {
                        for (int z = 1; z < 10; z++) {
                            if (board[i + x][j + y] == z) {
                                rowColumnSum += board[i + x][j + y]; // 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45
                                correctItem++;
                            }
                        }
                        // count the number of grids valid in the entire sudoku grid
                        if (correctItem == 9 && rowColumnSum == 45) correctGrids++;
                    }
                }
                // reset the 3x3 grid value counter and 3x3 grid sum
                correctItem = 0;
                rowColumnSum = 0;
            }
        }
    }
    printf("Solution: %s\n\n", (correctGrids == 9) ? "Given Sudoku grid is VALID." : "Given Sudoku grid is NOT valid.");
}

/*
 * @param board[9][9] this is the board passed by reference
 * @param rows - Specifies the sudoku board row quantity
 * @param columns - Specifies the sudoku board columns quantity
 *
 * Given a sudoku board, and its rows, and columns, print the board
 * and its contents to the screen.
 *
 * This method also calls checkBoard(board[][], int, int) to validate if the board is valid.
 * The checkBoard(int [][], int, int) is called after printing out the sudoku grid to the screen.
 */
void printBoard(int board[SUDOKU_ROWS][SUDOKU_COLUMNS], int rows, int columns) {
    int i, j;
    printf("Sudoku Grid\n");
    puts("---");
    // loop through entire board board[rows][columns]
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d  ", board[i][j]);
        }
        puts("");
    }
    puts("---");

    // Important: check if the board is valid
    checkBoard(board, rows, columns);
}

/*
 * @param board[9][9] - a sudoku board with a specified row and columns referenced
 * @param row - This is the row the user is currently providing input to
 *              edit the randomly generated sudoku grid.
 *
 * This function will prompt the user for input and validate the input based on
 * stakeholder requirements.
 *
 * @return This function will return either a exit_failure (1) or exit_success(0)
 */
int getInputFromUser(int board[SUDOKU_ROWS][SUDOKU_COLUMNS], int row) {
    int inputs, outsideRange = 0;
    int userInput[9];
    char buffer[100];

    // Display prompt message to user
    displayRowInputPrompt();

    fgets(buffer, sizeof(buffer), stdin);
    inputs = sscanf(buffer, "%d %d %d %d %d %d %d %d %d", &userInput[0], &userInput[1], &userInput[2], &userInput[3], &userInput[4], &userInput[5], &userInput[6], &userInput[7], &userInput[8]);

    if (inputs != 9) {
        printf("Error! Enter exactly 9 INTEGERS separated by Space/Tab followed by the Enter key to end.\n");
        puts("");
        return EXIT_FAILURE;
    } else {
        int i, j, counter = 0;
        for (i = 0; i < 9; i++) {
            // check if values provided are < 1 or > 9
            if (userInput[i] < 1 || userInput[i] > 9) {
                outsideRange = 1; // set flag of outsideRange to 1
            }
            // Loop through 9 elements and check for duplicates
            for (j = 0; j < 9; j++) {
                if (i != j && userInput[i] == userInput[j]) {
                    counter++; // count the number of hits that are duplicate
                }
            }
        }

        // userInput[i] < 1 OR userInput[i] > 9
        if (outsideRange) {
            printf("Error! One or more entries are outside the range 1 to 9.\n");
            puts("");
            return EXIT_FAILURE;
        // There exists a duplicate entry entered by the user
        } else if (counter > 0) {
            printf("Error! There is a duplicate entry.\n");
            puts("");
            return EXIT_FAILURE;
        // The input provided is valid - add the input to the grid
        } else if (outsideRange < 1 && counter < 1) {
            for (int x = 0; x < 9; x++)
                board[row - 1][x] = userInput[x]; // add the row to the randomly generated grid
            printBoard(board, SUDOKU_ROWS, SUDOKU_COLUMNS);
            return EXIT_SUCCESS;
        // an unexpected error
        } else {
            printf("Error! Something went wrong. Please try again later.\n");
            puts("");
            return EXIT_FAILURE;
        }
    }
}