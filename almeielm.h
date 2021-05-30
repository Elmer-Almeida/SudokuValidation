/*
* @author Elmer Almeida
* @date May 29 2021
*
* almeielm.h provides all the pre-processor definitions and function prototypes
 * required for main.c to operate.
 *
* The main purpose of this project is to validate a sudoku grid is valid or not.
* In addition, two rows of input will be gathered from the user and
* replaced with the randomly generated sudoku's first two rows in the grid.
*/


#ifndef ELMERALMEIDAASSIGN1_ALMEIELM_H
#define ELMERALMEIDAASSIGN1_ALMEIELM_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define RANGE 9
#define OFFSET 1
#define SUDOKU_ROWS 9
#define SUDOKU_COLUMNS 9

void fillBoard(int board[SUDOKU_ROWS][SUDOKU_COLUMNS], int, int);
void printBoard(int [SUDOKU_ROWS][SUDOKU_COLUMNS], int, int);
void checkBoard(int [SUDOKU_ROWS][SUDOKU_COLUMNS], int, int);
int getInputFromUser(int [SUDOKU_ROWS][SUDOKU_COLUMNS], int);
void displayRowInputPrompt();

#endif //ELMERALMEIDAASSIGN1_ALMEIELM_H
