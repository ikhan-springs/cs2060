/*
* Ibrahim Khan
* CS 2060-002
* Array of String Pointers
* 04/30/2020
* This program creates an array of string pointers and contains a method to print the 
* strings in the array and another method to sort the array alphabetically.  The array is
* passed to both methods.  First, the array is printed in its original state.  Then, the 
* array is sorted using a bubble sort, where the first index is sorted, then the next
* index, and so on until the last index is sorted.  Lastly, the sorted array is printed.
* ---------------------------------------------------------------------------------------
*/

#include<stdio.h>
#define SIZE 4 //array size defined here

//Function prototypes
void printList(char**);
void sortList(char**);

int main (int argc, char * argv[]) {
	
	//Creating and initializing array of string pointers
	char * wordPtr[SIZE] = {"Eric","Andrew","Sean","Daniel"};
	
	//Welcome print statements
	printf(" Welcome to Ibrahim\'s Array of String Pointers!\n\n");
	printf(" This program creates and initializes an array of string pointers.\n");
	printf(" Then, a function is invoked that prints each string in that array.\n");
	printf(" Afterwards, the array is passed to a sort function to sort the strings alphabetically.\n");
	printf(" Lastly, the strings are printed again in sorted order.\n");
	
	//Printing original array
	printf("\n\n Printing original array:");
	printList(wordPtr);
	
	//Sorting array
	sortList(wordPtr);
	
	//Printing sorted array
	printf("\n\n Printing sorted array:");
	printList(wordPtr);
	
	//End print statement
	printf("\n\n Program has ended!");
	
	return 0;
	
} //main


//Method iterates through an array of string pointers and prints each string
void printList(char * wordPtr[]) {
	
	//Loop runs until entire array has been iterated through
	for (int i = 0; i < SIZE; i++) {
		//Printing string
		printf("\n %s", wordPtr[i]);
	}
	
} //printList

//Method sorts an array of string pointers via a bubble sort
void sortList(char * wordPtr[]) {
	
	//tempString used when swapping two strings
	char * tempString[1];
	
	//Outer for loop obtains first string to be compared
	for (int i = 0; i < (SIZE - 1); i++) {
		
		//Inner for loop obtains second string to be compared
		for (int j = i; j < SIZE; j++) {
			
			//If a swap needs to occur
			if (wordPtr[i][0] > wordPtr[j][0]) {
				tempString[0] = wordPtr[i];
				wordPtr[i] = wordPtr[j];
				wordPtr[j] = tempString[0];
			}
			
			//If both strings start with the same letter
			else if (wordPtr[i][0] == wordPtr[j][0]) {
				//Compare second letter of each string and swap if necessary
				if (wordPtr[i][1] > wordPtr[j][1]) {
					tempString[0] = wordPtr[i];
					wordPtr[i] = wordPtr[j];
					wordPtr[j] = tempString[0];
				}
			}
		} //Inner for
	} //Outer for
	
} //sortList
