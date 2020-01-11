// life.h
// -- EE 312 Project 2

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
 *///
// Created by priebe on 9/5/2018.
//

#ifndef UNTITLED1_LIFE_H
#define UNTITLED1_LIFE_H

#endif //UNTITLED1_LIFE_H
// reads from text file, determines number of rows and columns and puts text file into a grid
void populateWorld(char fname[], char *grid[], int *numRows, int *numCols);
// prints the current grid, with appropriate '*' and '.'s for 1s and 0s respectively
void showWorld(char *grid[], int numRows, int numCols);
// follows rules of determines new ells/dead cells after each generation due to overcrowding, loneliness etc depending on the amount of neighboring cell
void iterateGeneration(char *grid[], int numRows, int numCols);
