//
// Created by yashd on 9/30/2019.
//

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Yash Dhaduti, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Yash Dhaduti
 * email address: yashdhaduti@utexas.edu
 * UTEID: ysd97
 * Section 5 digit ID: 16040
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack312_ll.h"
#include <string.h>

void userInput(int *row, int *column, char *color, int numRows, int numCols);
void readWorld(char fName[], char *grid[], int *numRows, int *numCols);
void showWorld(char *grid[], int numRows, int numCols);
void ffill(char *grid[], int numRows, int numCols, int row, int col, char color);
void checkNeighbors(Stack312 *stack, StackEntry current, char *grid[], char prevColor, int numRows, int numCols);

int main(int argc, char *argv[]) {

    char *fName = argv[1];//gets user input
    const int MAX_ROWS = 25;//max rows for a world
    char *world[MAX_ROWS];
    int numRows;
    int numCols;

    readWorld(fName, world, &numRows, &numCols);
    showWorld(world, numRows, numCols);
    while(true)
    {
        Pixel input;
        userInput(&(input.row), &(input.col), &(input.color), numRows, numCols);
        if((input.row==-1)||(input.col==-1)) { //ways to exit program by inputing -1 for row or column
            for (int i = 0; i < numRows; i++)
                free(world[i]);        // frees allocated memory to prevent memory leak
            return 0;
        }
        ffill(world, numRows, numCols, input.row, input.col, input.color);
        showWorld(world, numRows, numCols);
    }
}

//Reads the user input for the row, column to floodfill with the given color
//pre:address of row and column for the input as well as color, and given numRows and numCols range
//post: puts entered row, column, and color into the address of the row, column, and color variables
void userInput(int *row, int *column, char *color, int numRows, int numCols){
    do {
        printf("\nEnter a row:");
        scanf("%d", row);
    }while(*row>=numRows || *row<-1);

    do {
        printf("\nEnter a column:");
        scanf("%d", column);
    }while(*column>=numCols || *column<-1);
        printf("\nEnter a color:");
        scanf(" %c", color);
}

//reads the input of the world and puts it into a 2d array
//pre: file name given, as well as grid[] to enter world into, and address of numRows and numCols to be calculated
//post: creates world into grid and calculates numRows and numCols
void readWorld(char fName[], char *grid[], int *numRows, int *numCols) {
    FILE *fptr;
    fptr = fopen(fName, "r");
    if(fptr == NULL){//checks for empty file
	printf("No file found");
	exit(-42);
    }
    char buf[25];
    int row = 0;
    while(fgets(buf, sizeof(buf), fptr)) {
        char *string = (char *) malloc(strlen(buf));
        if(row==0)
            *numCols = strlen(buf) - 1;  // the -1 is to account for the extra /n character at the end of each row
        strncpy(string, buf, *numCols);
        grid[row] = string;
        row++;
    }
    *numRows=row;

    fclose(fptr); //closes file pointer
}

//prints the flood filled world
//pre: given grid and numRows and numCols to print
void showWorld(char *grid[], int numRows, int numCols) {
    printf("\n");
    for(int i=0; i<numRows;i++){
        for(int j=0; j<numCols;j++){
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

//does the act of floodfilling the picture, with the linked list stacks
//pre: given grid of world, as well as inputed row, col, and color to flood fill, along with range of rows and columns
//post: does the floodfill act and changes grid
void ffill(char *grid[], int numRows, int numCols, int row, int col, char color) {
    Stack312 stack;
    makeStack(&stack);
    StackEntry current;
    current.row=row;
    current.col=col;
    if(grid[current.row][current.col]!=color) {
        char prevColor = grid[row][col];
        current.color = color;
        grid[current.row][current.col] = current.color;
        push(current, &stack);
        while (isEmpty(stack) == false) {
            checkNeighbors(&stack, current, grid, prevColor, numRows, numCols);
            StackEntry changing = pop(&stack);
            grid[changing.row][changing.col] = current.color;
            current.row = changing.row;
            current.col = changing.col;
        }
    }
}
//checks what neighbors around 
//a given row,column are of the same color to push to the stack for flood fill
//pre: given stackentry to check neighbors are equal to the previous color in the grid
//post: pushes all neighbors of same color to the stack
void checkNeighbors(Stack312 *stack, StackEntry current, char *grid[], char prevColor, int numRows, int numCols)
{
    if((current.row-1>=0) && (current.col-1>=0) && (grid[current.row-1][current.col-1]==prevColor)) {
        StackEntry neighbor;
        neighbor.row=current.row-1;
        neighbor.col=current.col-1;
        neighbor.color=current.color;
        push(neighbor, stack);
    }
    if((current.row-1>=0) && (grid[current.row-1][current.col]==prevColor)){
        StackEntry neighbor;
        neighbor.row=current.row-1;
        neighbor.col=current.col;
        neighbor.color=current.color;
        push(neighbor, stack);
    }
    if((current.col-1>=0) && (grid[current.row][current.col-1]==prevColor)){
        StackEntry neighbor;
        neighbor.row=current.row;
        neighbor.col=current.col-1;
        neighbor.color=current.color;
        push(neighbor, stack);
    }
    if((current.row+1<numRows) && (current.col+1<numCols) && (grid[current.row+1][current.col+1]==prevColor)){
        StackEntry neighbor;
        neighbor.row=current.row+1;
        neighbor.col=current.col+1;
        neighbor.color=current.color;
        push(neighbor, stack);
    }
    if((current.row+1<numRows) && (grid[current.row+1][current.col]==prevColor)){
        StackEntry neighbor;
        neighbor.row=current.row+1;
        neighbor.col=current.col;
        neighbor.color=current.color;
        push(neighbor, stack);
    }
    if((current.col+1<numCols) && (grid[current.row][current.col+1]==prevColor)){
        StackEntry neighbor;
        neighbor.row=current.row;
        neighbor.col=current.col+1;
        neighbor.color=current.color;
        push(neighbor, stack);
    }
    if((current.row+1<numRows) && (current.col-1>=0) && (grid[current.row+1][current.col-1]==prevColor)){
        StackEntry neighbor;
        neighbor.row=current.row+1;
        neighbor.col=current.col-1;
        neighbor.color=current.color;
        push(neighbor, stack);
    }
    if((current.row-1>=0) && (current.col+1<numCols) && (grid[current.row-1][current.col+1]==prevColor)){
        StackEntry neighbor;
        neighbor.row=current.row-1;
        neighbor.col=current.col+1;
        neighbor.color=current.color;
        push(neighbor, stack);
    }
}
