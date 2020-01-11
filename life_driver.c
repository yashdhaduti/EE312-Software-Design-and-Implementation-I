//life_driver.c
//
//Life Driver program
//Roger Priebe 9/5/2018
//EE 312


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

//This file is a driver program for the life.c module.
//This program must work with your implementations life.h and life.c
//Do not change the function definitions for populateWorld, showWorld or
//iterateGeneration.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "life.h"
#include <string.h>

int main(int argc, char *argv[]) {

    //edit these two lines and use the command line arguments
    ///char fName[] = "world.txt";
    //const int numGenerations  = 20; //set to a smaller number for debugging

    char fName[] = "s";
    strcpy(fName, argv[1]); // putting input for text file into fName
    const int numGenerations = atoi(argv[2]); //getting input for # of generations

    const int MAX_ROWS = 80; //we want the world to fit on one screen

    //array of strings that will hold the grid
    char *world[MAX_ROWS];
    int numRows;
    int numCols;


    populateWorld(fName, world, &numRows, &numCols);

    showWorld(world, numRows, numCols);

    for (int iteration = 0; iteration < numGenerations; iteration++) {

        //system("cls"); //Windows only

        system("clear"); //Linux only

        iterateGeneration(world, numRows, numCols);

        showWorld(world, numRows, numCols);
    }
    for(int i=0;i<numRows;i++)
	free(world[i]);		// frees allocated memory to prevent memory leak
    return 0;
}



