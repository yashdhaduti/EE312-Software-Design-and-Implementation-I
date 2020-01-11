
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
#include <string.h>

void userInput(int *row, int *column, char *color, int numRows, int numCols);
void readWorld(char fName[], char *grid[], int *numRows, int *numCols);
void showWorld(char *grid[], int numRows, int numCols);
void ffill(char *grid[], int numRows, int numCols, int row, int col, char color);
void checkNeighbors(int row, int col, char color, char *grid[], char prevColor, int numRows, int numCols);

int main(int argc, char *argv[]) {

    const int MAX_ROWS = 25;//max rows for a world
    char *world[MAX_ROWS];
    int numRows;
    int numCols;
    char *fName = argv[1];
    readWorld(fName, world, &numRows, &numCols);
    showWorld(world, numRows, numCols);
    int row,col;
    char color;
    while(true)
    {
        userInput(&row, &col, &color, numRows, numCols);
        if((row==-1)||(col==-1)) { //ways to exit program by inputing -1 for row or column
            for (int i = 0; i < numRows; i++)
                free(world[i]);        // frees allocated memory to prevent memory leak
            return 0;
        }
	if(!((row<-1) || (col<-1) || (row>=numRows) || (col>=numCols)))
       	    ffill(world, numRows, numCols, row, col, color);
	showWorld(world, numRows, numCols);
    }
}

//Reads the user input for the row, column to floodfill with the given color
//pre:address of row and column for the input as well as color, and given numRows and numCols range
//post: puts entered row, column, and color into the address of the row, column, and color variables
void userInput(int *row, int *column, char *color, int numRows, int numCols){
        printf("\nEnter a row:");
        scanf("%d", row);
        printf("Enter a column:");
        scanf("%d", column);
        printf("Enter a color:");
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
    else {
        char buf[BUFSIZ];
        int row = 0;
        while(fgets(buf, sizeof(buf), fptr)) {
            grid[row]  = (char *) malloc(strlen(buf)+1);
            if(row==0)
                *numCols = strlen(buf) - 1;  // the -1 is to account for the extra /n character at the end of each row
            strncpy(grid[row], buf, *numCols);
            row++;
    }
    *numRows=row;
    fclose(fptr); //closes file pointer
    }
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

//does the act of floodfilling the picture
//pre: given grid of world, as well as inputed row, col, and color to flood fill, along with range of rows and columns
//post: does the floodfill act and changes grid
void ffill(char *grid[], int numRows, int numCols, int row, int col, char color) {
    if(grid[row][col]!=color) {
        char prevColor = grid[row][col];
        grid[row][col] = color;
        checkNeighbors(row, col, color, grid, prevColor, numRows, numCols);
    }
}

//checks what neighbors around for every neighbor with same color using recursion
//given row, column in the grid to flood fill that space along with all neighbors of a given color
//pre: given row, column to check neighbors are equal to the previous color in the grid
//post: changes the neighbors to the new color
void checkNeighbors(int row, int col, char color, char *grid[], char prevColor, int numRows, int numCols)
{
    if((row-1>=0) && (col-1>=0) && (grid[row-1][col-1]==prevColor)) {
        grid[row-1][col-1] = color;
        checkNeighbors(row-1, col-1, color, grid, prevColor, numRows, numCols);
    }
    if((row-1>=0) && (grid[row-1][col]==prevColor)){
        grid[row-1][col] = color;
        checkNeighbors(row-1, col, color, grid, prevColor, numRows, numCols);
    }
    if((col-1>=0) && (grid[row][col-1]==prevColor)){
        grid[row][col-1] = color;
        checkNeighbors(row, col-1, color, grid, prevColor, numRows, numCols);
    }
    if((row+1<numRows) && (col+1<numCols) && (grid[row+1][col+1]==prevColor)){
        grid[row+1][col+1] = color;
        checkNeighbors(row+1, col+1, color, grid, prevColor, numRows, numCols);
    }
    if((row+1<numRows) && (grid[row+1][col]==prevColor)){
        grid[row+1][col] = color;
        checkNeighbors(row+1, col, color, grid, prevColor, numRows, numCols);
    }
    if((col+1<numCols) && (grid[row][col+1]==prevColor)){
        grid[row][col+1] = color;
        checkNeighbors(row, col+1, color, grid, prevColor, numRows, numCols);
    }
    if((row+1<numRows) && (col-1>=0) && (grid[row+1][col-1]==prevColor)){
        grid[row+1][col-1] = color;
        checkNeighbors(row+1, col-1, color, grid, prevColor, numRows, numCols);
    }
    if((row-1>=0) && (col+1<numCols) && (grid[row-1][col+1]==prevColor)){
        grid[row-1][col+1] = color;
        checkNeighbors(row-1, col+1, color, grid, prevColor, numRows, numCols);
    }
    return;
}
