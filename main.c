/*
* @author Elmer Almeida
* @date May 29 2021
*
* almeielm.c provides all the functions required for main.c to operate.
* The main purpose of this project is to validate a sudoku grid is valid or not.
* In addition, two rows of input will be gathered from the user and
* replaced with the randomly generated sudoku grid.
*/

#include "almeielm.h"

int main() {
    int board[SUDOKU_ROWS][SUDOKU_COLUMNS];
    int testBoard[SUDOKU_ROWS][SUDOKU_COLUMNS] = {
            {5,3,4,6,7,8,9,1,2}, {6,7,2,1,9,5,3,4,8}, {1,9,8,3,4,2,5,6,7},
            {8,5,9,7,6,1,4,2,3}, {4,2,6,8,5,3,7,9,1}, {7,1,3,9,2,4,8,5,6},
            {9,6,1,5,3,7,2,8,4}, {2,8,7,4,1,9,6,3,5}, {3,4,5,2,8,6,1,7,9}
    };

    /* Testing Sudoku Grid */
    puts("Testing Sudoku Board\n");
    printBoard(testBoard, SUDOKU_ROWS, SUDOKU_COLUMNS);
    puts("");
    puts("==========================");
    puts("");

    /* User interactive sudoku grid */
    puts("Randomly generated");
    fillBoard(board, SUDOKU_ROWS, SUDOKU_COLUMNS);
    printBoard(board, SUDOKU_ROWS, SUDOKU_COLUMNS);
    puts("");

    /* Get row1 from user for the sudoku grid */
    int row, row1FromUser = 1, row2FromUser;

    do {
        if (row1FromUser) {
            row = 1;
            printf("Enter row %d of your Sudoku grid.\n", row);
            row1FromUser = getInputFromUser(board, row);
        }
        if (row1FromUser == 0) {
            row = 2;
            printf("Enter row %d of your Sudoku grid.\n", row);
            row2FromUser = getInputFromUser(board, row);
            if (row2FromUser == 0) {
                printf("\nThank you for playing. Goodbye!");
            }
        }
    } while (row1FromUser == 1 || row2FromUser == 1);

    return 0;
}
