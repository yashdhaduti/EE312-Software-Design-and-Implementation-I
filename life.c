//
// Created by yashd on 9/15/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/* reads text file and determines number of rows and columns and transfers data from / text file into a grid */
void populateWorld(char fname[], char *grid[], int *numRows, int *numCols) {

    FILE *fptr;
    fptr = fopen(fname, "r");
    int row = 0;
    char buf[BUFSIZ];
    while(fgets(buf, sizeof(buf), fptr)) {
        char *string = (char *) malloc(strlen(buf));
        if(row==0)
	    *numCols = strlen(buf) - 1;// the -1 is to account for the extra /n character at the end of each row
        strncpy(string, buf, *numCols);
        grid[row] = string;
        row++;
    }
    *numRows=row;
    fclose(fptr);//closes file pointer
}
// prints the world with appropriate '*' and'.'s
void showWorld(char *grid[], int numRows, int numCols){
     printf("\n");
     for(int i=0; i<numRows;i++){
        for(int j=0; j<numCols;j++){
            if(grid[i][j]=='1')
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
}
// Follows the rules of the game of lif eto create new cells and has cells die depending on various conditions such as loneliness or overcrowding, or different amount of neighboring cells
void iterateGeneration(char *grid[], int numRows, int numCols){
    char tempGrid[numRows][numCols];
    for(int r=0;r<numRows;r++){
        for(int c=0;c<numCols;c++){
            tempGrid[r][c]=grid[r][c]; //creates tempGrid to store all changes of the grid
        }
    }
    int neighbors = 0;
    for(int r=0;r<numRows;r++){		//checking number of neighboring cells
        for(int c=0;c<numCols;c++){
            if((r-1>=0) && (c-1>=0) && (grid[r-1][c-1]=='1'))
                neighbors++;
            if((r-1>=0) && (grid[r-1][c]=='1'))
                neighbors++;
            if((c-1>=0) && (grid[r][c-1]=='1'))
                neighbors++;
            if((r+1<numRows) && (c+1<numCols) && (grid[r+1][c+1]=='1'))
                neighbors++;
            if((r+1<numRows) && (grid[r+1][c]=='1'))
                neighbors++;
            if((c+1<numCols) && (grid[r][c+1]=='1'))
                neighbors++;
            if((r+1<numRows) && (c-1>=0) && (grid[r+1][c-1]=='1'))
                neighbors++;
            if((r-1>=0) && (c+1<numCols) && (grid[r-1][c+1]=='1'))
                neighbors++;
            if(grid[r][c]=='1')
            {
                if(neighbors>=4)
                    tempGrid[r][c]='0';
                else if(neighbors<2)
                    tempGrid[r][c]='0';
            }
            else if(grid[r][c]=='0')
            {
                if(neighbors==3)
                    tempGrid[r][c]='1';
            }
            neighbors=0;
        }
    }
    for(int r=0;r<numRows;r++){
        for(int c=0;c<numCols;c++){
            grid[r][c]=tempGrid[r][c];//stores changed grid back into original grid
        }
    }

}


