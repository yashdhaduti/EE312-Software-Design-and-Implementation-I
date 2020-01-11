/* mathStuff_ysd97.c

Roger Priebe and (you)
cs1428 10/15/2007 (updated 3/24/09)
EE312  10/3/2018

Finish comments here
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//**********  Function Prototypes  ******************

//function primeChecker
//input parameter - positive integer, and divisor starting at 2
//returns true if the number is prime, otherwise false by recursively checking divisibility with every number until the given number
//
bool primeChecker(int number, int divisor);

//function factors
//input parameter - positive integer, and divisor starting at 2
//prints the prime factors of the given number to standard output by recursively checking for divisibility of given number,
//and if divisible by a prime number, uses that new number as a number to check divisibility until the input number is prime
void factors(int number, int divisor);

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number);

//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.

void printPrimes (int n);


//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n);


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number);


//******************  MAIN  *****************************

int main () {


    int testNum;

    //test for the isPrime function
    printf("Enter a test number - ");
    scanf("%d",&testNum);

    if (isPrime(testNum))
        printf("%d is prime\n",testNum);
    else
        printf("%d is not prime.\n", testNum);

    //test for printing primes
    printf("Enter n to print the prime numbers between 1 and n: ");
    scanf("%d",&testNum);

    printPrimes(testNum);

    printf("\n");

    //test for Fibonacci number finder
    do {

        printf("Which Fibonacci number? ");
        scanf("%d", &testNum);
    }while(testNum<0);
    printf("\nThe %d Fibonacci number is : %d \n", testNum, findFibo(testNum));

    printf("\n");

    //test for prime factors
    printf("Factor what number? ");
    scanf("%d",&testNum);

    findFactors(testNum);

    return 0;
}




//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number) {
    const int START_DIVISOR = 2; //HINT: You may want a helper function
    if(number == 1)
        return false;
    if(primeChecker(number, START_DIVISOR))
        return true;
    return false;

}
//function primeChecker
//input parameter - positive integer, and divisor starting at 2
//returns true if the number is prime, otherwise false by recursively checking divisibility with every number until the given number
//
bool primeChecker(int number, int divisor){
    if(divisor == number)   //to see if only number that is divisible is itself
        return true;
    else{
        if((number % divisor) == 0) //to see if number is not prime
            return false;
        return primeChecker(number, divisor+1);
    }
}


//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.

void printPrimes (int n) {
    if(n==1) {
	printf("");
	return;
}
    if(n!=2)
        printPrimes(n-1);
    if(isPrime(n))
        printf("%d ", n);
}




//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n) {

    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else{
        return findFibo(n-2) + findFibo(n-1);   //given formula to find fibonacci number
    }
    //YOUR CODE GOES HERE

}


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number) {
    const int START_DIVISOR = 2; //HINT: You may want a helper function
    printf("%d=",number);
    if(number == 0) {
	printf("0\n");
	return;
    }
    if(number == 1) {
	printf("1\n");
	return;
    }
    if(isPrime(number))
        printf("prime", number);
    else{
        factors(number, START_DIVISOR);
    }
    printf("\n");
}

//function factors
//input parameter - positive integer, and divisor starting at 2
//prints the prime factors of the given number to standard output by recursively checking for divisibility of given number,
//and if divisible by a prime number, uses that new number as a number to check divisibility until the input number is prime
void factors(int number, int divisor) {
    if(isPrime(number)){
        printf("%d",number);
        return;
    }
    if(isPrime(divisor) && number%divisor==0){
        int newNumber = number/divisor;     //calculates new number to find prime factor of
        printf("%d*",divisor);
        factors(newNumber, divisor);
    }
    else
        factors(number, divisor+1);
}

