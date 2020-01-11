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
#include <string.h>
#include "stack312_ll.h"

//creates the stack
void makeStack(Stack312 *s) {
    s->top=NULL;
}
//checks if stack is full
bool isFull(Stack312 s) {
    return false;
}
//checks if stack is empty
bool isEmpty(Stack312 s) {
    if(s.top == NULL)
        return true;
    return false;
}
//pushes a stackentry to the stack
void push(StackEntry e, Stack312 *s) {
    StackNode *new = (StackNode *) malloc(sizeof(StackNode));
    new -> pixel = e;
    new -> next = s->top;
    s->top = new;
}
//pops a stackEntry from the stack
StackEntry pop(Stack312 *s) {
    StackNode *old = s->top;
    s->top = old->next;
    StackEntry info = old->pixel;
    free(old);
    return info;

}

