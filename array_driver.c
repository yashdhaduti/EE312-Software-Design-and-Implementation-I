//
// Created by yashd on 10/2/2019.
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
#include "stack312_arr.h"
#include <string.h>
#define MAX_CHARS 80
void readFile(char fName[]);
void checkEquation(char *grid);

int main(int argc, char *argv[]){
    readFile(argv[1]);//arg[1] is user inputted file
    return 0;
}
//reads a .dat file given and receives the equations in it and calls checkequations to check if they are valid
//pre:given file name to get equations from, calls checkequations to see if valid
//post: gives string to checkEquations to check if it is valid for all rows in the given file 
void readFile(char fName[]) {
    FILE *fptr;
    fptr = fopen(fName, "r");
    if(fptr == NULL) {//checks for no file given
        printf("No file found");
        exit(-42);
    }
    char buf[MAX_CHARS];//has max given elements for an equation
    while(fgets(buf, sizeof(buf), fptr)) {
        char check[MAX_CHARS];
        if (strlen(buf) > 0 && buf[strlen(buf)-1] == '\n') {//has -1 for \n character
            strncpy(check, buf, strlen(buf)-1);//-1 for newline character
            check[strlen(buf)-1]=0;
        }
        else {
            strncpy(check, buf, strlen(buf));
            check[strlen(buf)]=0;
        }
        checkEquation(check);   
    }
    fclose(fptr); //closes file pointer
}
//checks the equation to see if it is valid or not, and tells the user of the missing brace if it is not valid
//pre: given string of an equation
//post: prints equation saying what they are missing or saying valid expression
void checkEquation(char *grid){
        Stack312 stack;
        makeStack(&stack);
        bool errorFlag = false;
	printf("%s",grid);	 
        for(int i=0;i<strlen(grid);i++) {
            if(grid[i]=='(' && !errorFlag){
                StackEntry open = '(';
                push(open, &stack);
            }
            else if(grid[i]=='<' && !errorFlag){
                StackEntry open = '<';
                push(open, &stack);
            }
            else if(grid[i]=='[' && !errorFlag){
                StackEntry open = '[';
                push(open, &stack);
            }
            else if(grid[i]==')' && !errorFlag) {
                if(isEmpty(stack)) {
                    printf(" === missing (\n");
                    errorFlag = true;
                }
                else {
                    StackEntry open = pop(&stack);
                    if (open == '<') {
                        printf(" === missing >\n");
                        errorFlag = true;
                    } else if (open == '[') {
                        printf(" === missing ]\n");
                        errorFlag = true;
                    }
                }
            }
            else if(grid[i]=='>' && !errorFlag) {
                if(isEmpty(stack)) {
                    printf("  === missing <\n");
                    errorFlag = true;
                }
                else {
                    StackEntry open = pop(&stack);
                    if (open == '(') {
                        printf(" === missing )\n");
                        errorFlag = true;
                    } else if (open == '[') {
                        printf(" === missing ]\n");
                        errorFlag = true;
                    }
                }
            }
            else if(grid[i]==']' && !errorFlag) {
                if(isEmpty(stack)) {
                    printf(" === missing [\n");
                    errorFlag = true;
                }
                else {
                    StackEntry open = pop(&stack);
                    if (open == '<') {
                        printf(" === missing >\n");
                        errorFlag = true;
                    } else if (open == '(') {
                        printf(" === missing )\n");
                        errorFlag = true;
                    }
                }
            }
        }
        if(!(isEmpty(stack)) && !errorFlag) {
            StackEntry missing = pop(&stack);
            if(missing=='(')
                printf(" === missing )\n");
            if(missing=='<')
                printf(" === missing >\n");
            if(missing=='[')
                printf(" === missing ]\n");
        }
        else if(!errorFlag)
            printf(" === valid expression\n");
}

