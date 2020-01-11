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
//creates the stack
void makeStack(Stack312 *s){
    s->top=-1;
}
//checks if stack array is full
bool isFull(Stack312 s){
    if(s.top==MAX_ELEMENTS - 1)
        return true;
    return false;
}
//checks if stack is empty
bool isEmpty(Stack312 s){
    if(s.top==-1)
        return true;
    return false;
}
//pushes a stackEntry to the stack
void push(StackEntry e,Stack312 *s){
    s->top=s->top+1;
    s->elements[s->top]=e;
}
//pops a stackEntry from the stack
StackEntry pop(Stack312 *s){
    StackEntry popped = s->elements[s->top];
    s->top=s->top-1;
    return popped;
}