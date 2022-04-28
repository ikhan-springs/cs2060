/*
* Ibrahim Khan
* CS 2060-002
* Stack using Pointers
* 03/20/2020
* This assignment creates a stack of floats, which are filled with user inputs.  The 
* staclk uses three functions: push to add values, pop to remove values, and an exit
* funtion that unwinds the stack and pops out all values.  There are if statements within
* the push and pop functions to ensure the stack is not empty when popping and not full 
* when pushing.  The three functions are invoked by the user in a menu and the exit
* option unwinds the entire stack.  A pointer is necessary to mark the address of the
* last pushed/popped value.  Lastly, the stack size is defined with a preprocessor so 
* that the size can be easily changed and the rest of the program can remain intact.
*/

#include <stdio.h>
#define SIZE 5 //stack size defined here

//Function prototypes
float* push(float*);
float* pop(float*);
float* unwind(float*);

//Declaring and initializing global stack
float stack[SIZE] = {0};

int main(int argc, char *  argv[]) {
	
	//Declaring and initializing variables
	float* top = NULL;
	float* (*stackFunctions[])(float*) = {unwind, push, pop};
	int menuChoice = 0;
	
	//Setting top pointer equal to stack to keep track of the next empty address
	top = stack;
	
	//Welcome and program description
	printf(" Welcome to Ibrahim\'s Stack\n\n");
	printf(" This program has three functions that can manipulate stack values.\n");
	printf(" First, the push function allows you to place a value at the top of \n");
	printf(" the stack.  The pop function removes the top value from the stack. \n");
	printf(" Lastly, the unwind function pops all values out of the stack.  This\n");
	printf(" method will be invoked when you decide to exit.\n");
	
	//do while loop that runs until user decides to exit
	do {
		
		//Menu
		printf("\n Stack Functions Menu\n");
		printf(" 0\tExit (unwind stack)\n");
		printf(" 1\tPush value onto stack\n");
		printf(" 2\tPop value off stack\n");
		
		//Obtaining user input for menu option
		printf("\n Select option > ");
		scanf("%d", &menuChoice);
		
		//while loop if user inputs invalid menu option
		while (menuChoice < 0 || menuChoice > 2) {
			
			printf("\n You have selected an invalid option.");
			printf(" Select option > ");
			scanf("%d", &menuChoice);
		}
		
		//Calling function based on user choice
		top = stackFunctions[menuChoice](top);
		
	} while (menuChoice != 0);
	
	return 0;
	
} //main


//Function that pushes a user input to top of the stack
float* push(float* top) {
	
	//New variable for user input
	float pushValue = 0;
	
	//If stack is not full
	if (top <= stack + (SIZE - 1)) {
		
		//Gather user input and set to pushValue
		printf("\n Enter value to be pushed onto stack > ");
		scanf("%f", &pushValue);
		printf("\n Pushing: %.2f\n", pushValue);
		
		//Dereference pointer and place value into stack
		*top = pushValue;
		
		//Pointer incremented to next available address
		top++;
	}
	
	//If stack is full
	else {
		printf("\n The stack is full. No values can be pushed.\n");
	}
	
	return top;

} //push

//Function that pops the top value of the stack
float* pop(float* top) {
	
	//If stack is not empty
	if (top > stack) {
		
		//Pointer decremented because it currently points to an empty address
		top--;
		
		//Display which value is being removed
		printf("\n Popping: %.2f\n", *top);
		
		//Remove value and replace with 0
		*top = 0;
	}
	
	//If stack is empty
	else {
		printf("\n The stack is empty. There are no values to pop.\n");
	}
	
	return top;

} //pop

//Function that pops all values in the stack
float* unwind(float* top) {
	
	//Loop runs until stack is empty
	while(top != stack) {
		
		//Calls pop function to pop values
		top = pop(top);
	}
	
	return top;
	
} //unwind
