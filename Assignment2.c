/*
* Ibrahim Khan
* CS 2060-002
* Simple Calculator (Function Pointers)
* 03/12/2020
* This program uses an array of function pointers to perform basic calculator functions
* of addition, subtraction, multiplication, and division.  By using function pointers, 
* the code is more concise, with no need of a switch statement or multiple if statements.
* Each function prints the equation to be solved, but does not print the answer.  The
* answer is printed in main, after obtaining the answer from the function.  The program
* also includes while loops to prevent user from selecting an unavailable menu option as
* well as avoiding the math error of dividing by 0.
*/
 
#include <stdio.h>

//Function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);

int main (int argc, char * argv[]) {
	
	//Declaring and initializing all variables
	int menuChoice = 0;
	double operand1 = 0;
	double operand2 = 0;
	double answer = 0;
	
	//Declaring and initializing array of function pointers
	double (*calculatorArray[])(double, double) = {add, subtract, multiply, divide};
	
	//Welcome and program description
	printf(" Welcome to Ibrahim\'s Simple Calculator!\n\n");
	printf(" This program uses function pointers to perform calculator functions.\n");
	printf(" There are four functions: addition, subtraction, multiplication, and \n");
	printf(" division.  You will be shown a menu with these options.  Once an option\n");
	printf(" is selected, you will input two operands so that the calculator can\n");
	printf(" perform the function called.  The program runs until exit is selected.");
	
	//while loop that runs until user decides to exit
	//do while loop created instead of while since menuOption is 0 at beginning
	do {
		
		//Menu
		printf("\n\n Calculator Menu\n");
		printf(" 0\tExit\n");
		printf(" 1\tAdd\t (operand 1) + (operand 2)\n");
		printf(" 2\tSubtract (operand 1) - (operand 2)\n");
		printf(" 3\tMultiply (operand 1) * (operand 2)\n");
		printf(" 4\tDivide\t (operand 1) / (operand 2)\n");
		
		//Obtaining user input for menu option
		printf("\n Select option: ");
		scanf("%d", &menuChoice);
		
		//while loop if user inputs option not on menu
		//Loop runs until input is a valid option
		while (menuChoice < 0 || menuChoice > 4) {
			
			printf("\n You have selected an invalid option.");
			printf(" Select option: ");
			scanf("%d", &menuChoice);
			
		}
		
		//if statement that runs only if user wants to use calculator (i.e not exit)
		if (menuChoice != 0) {
			
			//Obtaining user input for the two operands
			printf("\n Enter first operand > ");
			scanf("%lf", &operand1);
			printf(" Enter second operand > ");
			scanf("%lf", &operand2);
			
			//while loop to prevent the math error of dividing by 0
			//Loop obtains new value for second operand
			while (menuChoice == 4 && operand2 == 0) {
				
				printf("\n Math Error - cannot divide by 0");
				printf("\n Re-enter second operand: ");
				scanf("%lf", &operand2);
			}
			
			//Run calculator and obtain answer
			answer = (calculatorArray[menuChoice - 1])(operand1, operand2);
			
			//Print answer
			printf("\n Answer: %.2f", answer);
		}
		
	} while (menuChoice != 0);
	
	return 0;
	
} //main


//Method adds two operands and prints equation
double add(double operand1, double operand2) {
	
	double sum;
	sum = operand1 + operand2;
	
	printf("\n Equation: %.2f + %.2f", operand1, operand2);
	
	return sum;
		
} //add

//Method subtracts two operands and prints equation
double subtract(double operand1, double operand2) {
	
	double difference;
	difference = operand1 - operand2;
	
	printf("\n Equation: %.2f - %.2f", operand1, operand2);
	
	return difference;
	
} //subtract

//Method multiplies two operands and prints equation
double multiply(double operand1, double operand2) {
	
	double product;
	product = operand1 * operand2;
	
	printf("\n Equation: %.2f * %.2f", operand1, operand2);
	
	return product;
	
} //multiply

//Method divides two operands and prints equation
double divide(double operand1, double operand2) {
	
	double quotient;
	quotient = operand1 / operand2;
	
	printf("\n Equation: %.2f / %.2f", operand1, operand2);
	
	return quotient;
	
} //divide
