/*
* Ibrahim Khan
* CS 2060-002
* Assignment 1 - Celsius to Fahrenheit Pass By Reference
* 02/20/2020
* This program converts Celsius to Fahrenheit through pass by reference.  The program
* takes in user input for lower and upper Celsius values.  Then, the program outputs
* the conversions in a table with values calculated in 10 degree increments.  The
* outputs start from the lower value and end with the upper value or the last value that
* was a 10 degree increment.
*/
 
#include <stdio.h>
 
void degreeConversion(float*, float*);

int main (int argc, char * argv[]) {
	
	//Declaring all variables
	float lowerValue;
	float upperValue;
	float fahrenheitValue;
	
	//Welcome and program description print statements
	printf(" Welcome to Ibrahim\'s Celsius to Fahrenheit Converter!\n\n");
	printf(" This program takes in lower and upper Celsius values from the user.\n");
	printf(" Then, it prints a table of conversions in 10 degree increments\n");
	printf(" The conversions start with the lower Celsius value and continue until\n");
	printf(" the highest value, or the last value that was a 10th degree.\n\n");
	
	//Obtaining lower and upper Celsius values from user
	printf(" Enter lower Celsius value > ");
	scanf("%f", &lowerValue);
	
	printf(" Enter upper Celsius value > ");
	scanf("%f", &upperValue);
	
	//while loop that checks if upperValue is greater than lowerValue
	//Continues to execute until user's upperValue is greater than lowerValue
	while (upperValue <= lowerValue) {
		
		printf(" You have entered an invalid upper Celsius value.\n");
		printf(" Enter upper Celsius value > ");
		scanf("%f", &upperValue);
	}
	
	//Table print statements
	printf("\n Celsius\tFahrenheit\n");
	printf("---------------------------\n");
	
	//for loop that iterates by 10 from lowerValue to upperValue
	//It also invokes the degreeConversion method and prints the conversions
	for (lowerValue; lowerValue <= upperValue; lowerValue += 10) {
		
		degreeConversion(&lowerValue, &fahrenheitValue);
		printf("%6.0f \t\t %6.2f\n", lowerValue, fahrenheitValue);
	}
	
	return 0;
	
} //Main


//Method uses pass by reference to convert from celsius to fahrenheit
void degreeConversion(float *celsiusPtr, float *fahrenheitPtr) {
	
	*fahrenheitPtr = ((*celsiusPtr * 9) / 5) + 32;
	
} //degreeConversion
