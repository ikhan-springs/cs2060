/*
* Ibrahim Khan
* CS 2060-002
* File IO
* 05/07/2020
* This program deals with File IO, specifically reading and appending to a file.  First, 
* the program asks the user for a file name to read from.  If the user inputs a file name
* that does not exist, a new file will be created.  Then, the program asks the user for
* three strings that will be appended to the end of the file.  Lastly, the program prints
* the file contents again along with the three appended strings.
* ---------------------------------------------------------------------------------------
*/

#include <stdio.h>

#define MAX 1024 //max line length in file

int main (int argc, char * argv[]) {
	
	//Declaring and initializing variables
	char fileName[MAX] = "File name"; //Char array to store file name
	FILE * filePtr = NULL; //File pointer used to open file
	char * endOfFile = NULL; //Char pointer used to track when end of file is reached
	char data[MAX] = "Data"; //Char array used to store file strings
	
	//Welcome print statements
	printf(" Welcome to Ibrahim\'s File IO Program!\n\n");
	printf(" This program deals with File IO.  First, the program will ask the\n");
	printf(" user for a file name.  The program will read the contents of the\n");
	printf(" file.  Afterwards, the user will be able to append thrice to that\n");
	printf(" same file.  Lastly, the program prints the changed file\'s contents.\n\n");
	
	//Obtain user input for file name
	printf("\n Enter the name of the file you would like to read > ");
	scanf("%s", fileName);
	
	//Open file for reading
	filePtr = fopen(fileName, "r");
	
	//If file does not exist
	if (filePtr == NULL) {
		//Notify user that a new file is created
		printf(" %s does not exist.  Creating new file %s", fileName, fileName);
	}
	
	//If file does exist
	else {
		
		//endOfFile iterates through the file contents
		endOfFile = fgets(data, MAX, filePtr);
		
		printf("\n Printing file contents:\n");
		
		//Loop prints file contents until end of file is reached
		while (endOfFile != NULL) {
			printf(" %s", data);
			endOfFile = fgets(data, MAX, filePtr);
		}
		
		//Close file
		fclose(filePtr);
		printf("\n\n Done reading file!");
	}
	
	//Open file for appending
	filePtr = fopen(fileName, "a");
	
	//If file could not be opened
	if (filePtr == NULL) {
		printf(" Error opening the %s file", fileName);
	}
	else {
		
		//Loop obtains three strings from user
		for (int i = 0; i <= 3; i++) {
			
			//Error - print statement prints twice first time loop runs
			//If statement removes unnecessary statement
			if (i != 0) {
				printf("\n Enter string to append to file > ");
			}
			
			//Obtain user input
			fgets(data, MAX, stdin);
			//Place user input into file
			fputs(data, filePtr);
		}
		
		//Close file
		fclose(filePtr);
		printf("\n Done appending to file!\n");
	}
	
	//Open file for reading
	filePtr = fopen(fileName, "r");
	
	//If file does not exist
	if (filePtr == NULL) {
		printf(" %s does not exist.", fileName);
	}
	
	//If file does exist
	else {
		
		//endOfFile iterates through the file contents
		endOfFile = fgets(data, MAX, filePtr);
		
		printf("\n Printing file contents:\n");
		
		//Loop prints file contents until end of file is reached
		while (endOfFile != NULL) {
			printf(" %s", data);
			endOfFile = fgets(data, MAX, filePtr);
		}
		
		//Close file
		fclose(filePtr);
		printf("\n Done reading file!");
	}
	
	return 0;
	
} //Main
