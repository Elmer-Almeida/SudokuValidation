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

int main() {
    // Sudoku grid to interact with user
    int board[SUDOKU_ROWS][SUDOKU_COLUMNS] = {0};

    // Valid sudoku grid for testing purposes
    int testBoard[SUDOKU_ROWS][SUDOKU_COLUMNS] = {
            {5,3,4,6,7,8,9,1,2}, {6,7,2,1,9,5,3,4,8}, {1,9,8,3,4,2,5,6,7},
            {8,5,9,7,6,1,4,2,3}, {4,2,6,8,5,3,7,9,1}, {7,1,3,9,2,4,8,5,6},
            {9,6,1,5,3,7,2,8,4}, {2,8,7,4,1,9,6,3,5}, {3,4,5,2,8,6,1,7,9}
    };

    /* Testing Sudoku Grid */
    puts("Testing the following Sudoku Board\n");
    printAndCheckBoard(testBoard, SUDOKU_ROWS, SUDOKU_COLUMNS);
    puts("==========================");
    puts("");

    /* User interactive sudoku grid */
    puts("Randomly generated");
    fillBoard(board, SUDOKU_ROWS, SUDOKU_COLUMNS); // fill board provided with random values between 1-9
    printAndCheckBoard(board, SUDOKU_ROWS, SUDOKU_COLUMNS);
    puts("");

    /* Get row1 from user for the sudoku grid */
    int row, row1FromUser = 1, row2FromUser;

    do {
        if (row1FromUser == EXIT_FAILURE) {
            row = 1;
            printf("Enter row %d of your Sudoku grid.\n", row);
            row1FromUser = getInputFromUser(board, row);
        }
        // check if the first input row into the user's sudoku grid is valid
        if (row1FromUser == EXIT_SUCCESS) {
            row = 2; // change the target row
            printf("Enter row %d of your Sudoku grid.\n", row);
            row2FromUser = getInputFromUser(board, row);
            if (row2FromUser == EXIT_SUCCESS) {
                printf("\nThank you for playing. Goodbye!");
            }
        }
    // make sure function to get input from user for row1 and row2 returns exit_success
    } while (row1FromUser == 1 || row2FromUser == 1); // loop if either row's function call return exit_failure

    return 0;
}