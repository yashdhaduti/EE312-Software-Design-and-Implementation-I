#include<stdio.h>
#include<stdbool.h>


// CodeCampTester.c -- EE 312 Project 1 -- Tester class

/* Student information for assignment:
 *
 * Name: Yash
 * email address: yashdhaduti@ymail.com
 * UTEID: ysd97
 * Section 5 digit ID: 16040
 *
 */

//function prototypes. These will be completed in CodeCamp.c
int hammingDistance(int aList[], int bList[], int len);
int sum3or5Multiples();
bool lastDigit(int num1, int num2);
int reverseInt(int num);
//****************************

int main() {

    // test 1, hammingDistance
    int h1[] = {-1, 4, 32, 0, 2, 2, 4, 1};
    int h2[] = {1, 44, 1, 0, 3, 2, -1, -4};
    int expected = 6;
    int actual = hammingDistance(h1, h2, 8);
    printf("Test 1 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)
        printf("passed test 1, hamming distance\n\n");
    else
        printf("**** FAILED **** test 1, hamming distance\n\n");

    // test 2, hamming distance
    int h3[] = {-6, 4, -5, 6, -32, 4, 5, 32, 534, 23, 0, -6};
    int h4[] = {-6, -4, 3, 66, 32, -6, 7, 43, 2, 435, 0, 0};
    expected = 10;
    actual = hammingDistance(h3, h4, 12);
    printf("Test 2 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)
        printf("passed test 2, hamming distance\n\n");
    else
        printf("**** FAILED **** test 2, hamming distance\n\n");

    // test 3, last digit
    int n1 = -4;
    int n2 = 204;
    expected = true;
    actual = lastDigit(n1, n2);
    printf("Test 3 last digit: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)
        printf("passed test 3, last digit\n\n");
    else
        printf("**** FAILED **** test 3, last digit\n\n");

    // test 4, last digit
    n1 = -24;
    n2 = 6;
    expected = false;
    actual = lastDigit(n1, n2);
    printf("Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)
        printf("passed test 4, last digit\n\n");
    else
        printf("**** FAILED **** test 4, last digit\n\n");

    // test 5, sum of multiples of 3 or 5
    expected = 233168;
    actual = sum3or5Multiples();
    printf("Test 5 sum of multiples: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)
        printf("passed test 5, sum of multiples of 3 or 5\n\n");
    else
        printf("**** FAILED **** test 5, sum of multiples of 3 or 5\n\n");

    // test 6, reverse int
    n1 = -143;
    expected = -341;
    actual = reverseInt(n1);
    printf("Test 6 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)
        printf("passed test 6, reverse int\n\n");
    else
        printf("**** FAILED **** test 6, reverse int\n\n");

    // test 7, reverse int
    n1 = 2000000512;
    expected = 0;
    actual = reverseInt(n1);
    printf("Test 7 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)
        printf("passed test 7, reverse int\n\n");
    else
        printf("**** FAILED **** test 7, reverse int\n\n");

}

