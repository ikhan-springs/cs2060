/*
* Ibrahim Khan
* CS 2060-002
* Ordered Linked List
* 04/16/2020
* This program creates an ordered linked list and accepts only positive integers.  There
* is a struct that provides the framework for creating nodes to be placed into the 
* linked list.  The program contains four functions: one that creates a new node, one that
* inserts the node into its proper place in the list, one that prints the entire list, 
* one that frees all nodes.  All functions use node pointers to carry out their intended
* purposes.  There is a global header so that it does not have to be passed into each 
* function.  The program continues to accept user inputted values, which are placed into 
* the linked list, until the user enters 0 or a negative number.  Lastly, the list is 
* printed out and all nodes are freed before the program exits.
*/

#include <stdio.h>
#include <stdlib.h>

//Creating struct for node
struct listNode {
	int data;
	struct listNode * next;
};

//Function prototypes
void createNewNode(double);
void insertNode(struct listNode*);
void printList(void);
void freeList(void);

//Global header node
struct listNode header = {0, NULL};

int main(int argc, char * argv[]) {
	
	//Variable that stores user input
	int userInput = 0;
	
	//Welcome print statements
	printf(" Welcome to Ibrahim\'s Ordered Linked List!\n\n");
	printf(" This program uses structs to create nodes to place values in the linked list.\n");
	printf(" You will be asked to enter values, which will be placed into nodes.\n");
	printf(" These nodes will then be placed into the correct position in the list.\n");
	printf(" The program will continue to run until you input 0 or a negative number.\n");
	printf(" Afterwards, the entire list will be printed and all nodes will be freed.\n\n");
	printf(" NOTE: This linked list is designed to only take in positive integers.\n");
	
	//Loop that runs until user inputs 0 or a negative number
	do {
		
		//Obtaining user input
		printf("\n\n Enter value to place into Linked List > ");
		scanf("%d", &userInput);
		
		//Check if user input is positive
		if (userInput > 0) {
			createNewNode(userInput);
			printf(" The value %d was placed into the Linked List.", userInput);
		}
		
	} while (userInput > 0);
	
	//Print list
	printf("\n Printing list: \n");
	printList();
	
	//Free list
	freeList();
	
	//End program statement
	printf("\n\n All nodes have been freed.  This is the end of the program.");
	
	return 0;
	
} //Main


//Function that creates a new node
void createNewNode(double nodeData) {
	
	//Creating new node and deallocating memory
	struct listNode * newNode = NULL;
	newNode = (struct listNode*) malloc (sizeof(struct listNode));
	
	//User input placed into node
	newNode->data = nodeData;
	newNode->next = NULL;
	
	//Calling function to insert node into linked list
	insertNode(newNode);
	
} //createNewNode

//Function that inserts a node into its proper location in the list
void insertNode(struct listNode * newNode) {
	
	//Creating two node pointers to search correct position in list
	struct listNode * previous = NULL;
	struct listNode * current = NULL;
	
	//previous pointer starts at header
	previous = &header;
	//current pointer starts at node after header
	current = header.next;
	
	//Loop that runs until correct position is found
	while (current != NULL && newNode->data > current->data) {
		//Pointers point at next node
		previous = current;
		current = previous->next;
	}
	
	//Node inserted into list
	previous->next = newNode;
	newNode->next = current;
	
} //insertNode

//Function that prints the list
void printList() {
	
	//Pointer that will go through list
	struct listNode * current = NULL;
	current = header.next;
	
	//Loop that runs until all nodes have been printed
	while (current != NULL) {
		printf(" %d -->", current->data);
		current = current->next;
	}
	
	printf(" NULL");
	
} //printList

//Function that frees all nodes in list
void freeList() {
	
	//current pointer that is used to check if list is empty
	struct listNode * current = NULL;
	//temp pointer that is used to free nodes
	struct listNode * temp = NULL;
	
	current = header.next;
	temp = current->next;
	
	//Loop that runs until all nodes are freed
	while (current != NULL) {
		
		//Freeing node
		free(temp);
		current = temp;
		
		//Checks if both current and temp point to NULL
		//If true, temp will not move to next element
		if (temp != NULL) {
			temp = temp->next;
		}
	}
	
} //freeList
