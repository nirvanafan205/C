#include <stdio.h>
#include <stdlib.h>

/*
	Advantages of Linked Lists over arrays

		Dynamic Array
		Ease of Insertion/Deletion

	Disadvantages
	
		Random access not allowed
		Extra memory space for pointer with each element in list
		not cache friendly

	Types of Linked List

		Simple Linked List
			traverse the linked list in only one direction

		Doubly Linked List
			can traverse linked list forward or backwards

		Circular Linked List
			last node links to first/head node of the linked list
			first/head node is linked to the last node for its prev pointer			
*/

struct Node
{
	int data;
	struct Node* next;
};

//prints data of linked list from given node
void printList(struct Node* n)
{
	while(n != NULL)
	{
		printf(" %d ", n->data);
		n = n->next;
	}
}

int main()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	struct Node* fourth = NULL;
	struct Node* fifth = NULL;

	//allocate 5 nodes in the heap
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	fourth = (struct Node*)malloc(sizeof(struct Node));
	fifth = (struct Node*)malloc(sizeof(struct Node));

	head->data = 3; //asign data to nodes
	head->next = second; //link node to next node

	second->data = 8;
	second->next = third;

	third->data = 4;
	third->next = fourth;

	fourth->data = 10;
	fourth->next = fifth;

	fifth->data = 32;
	fifth->next = NULL;

	//function call starting from head of list
	printList(head);

	/*
		time complexity for 

		Search
			O(n) : worst/average case

		insert
			O(1) : worst/average case

		delete
			O(1) : worst/average case
	*/
}
