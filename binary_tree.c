#include <stdio.h>
#include <stdlib.h>

/*
	binary tree traversals:

		PreOrder: root-left child - right child
				root node is traversed first then left and finally right child

		InOrder: left child - root - right child
				left child is traversed first then its root node and finally right child

		PostOrder: left child - right child - root
				left child is traversed first, then right and finally root node

	think of binary tree as file system

	user = root
	then it goes to home directory
	it has two other directorys, courses and grades (left child = courses right child = grades)
	courses has all of classes one's taken and grades has letter grades 
*/

struct node
{
	int data; 
	struct node* left;
	struct node* right;
};

//newNode() allocates new node
struct node* newNode(int data)
{
	struct node* node = (struct node*) malloc(sizeof(struct node));

	node->data = data;

	node->left = NULL; //left and right pointers are null
	node->right = NULL; //they are initialized

	return (node);
}

//preorder traversal
void printPreOrder(struct node* node)
{
	if(node == NULL)
	{
		return;
	}

	//prints first data
	printf("%d ", node->data);

	//left subtree recursion
	printPreOrder(node->left);

	//right sub tree recursion
	printPreOrder(node->right);
}

//inOrder traversal
void printInorder(struct node* node)
{
	if(node == NULL)
	{
		return;
	}

	//recursion on left child first
	printInorder(node->left);

	//prints data of node
	printf("%d ", node->data);

	//recursion on right child
	printInorder(node->right);
}

//postOrder traversal
void printPostorder(struct node* node)
{
	if(node == NULL)
	{
		return;
	}

	//recursion on the left
	printPostorder(node->left);

	//recursion on the right
	printPostorder(node->right);
	
	//prints node data
	printf("%d ", node->data);
}

//deleting tree
void deleteTree(struct node* node)
{
	if(node == NULL)
	{
		return;
	}

	//delete both subtrees
	deleteTree(node->left);
	deleteTree(node->right);

	free(node);
}

int main()
{
	struct node* root = newNode(9);
	root->left = newNode(1);
	root->right = newNode(82);
	root->left->right = newNode(199);
	root->left->left = newNode(22);
	root->right->right = newNode(495);
	root->right->left = newNode(43);

	printf("PreOrder traversal\n");
	printPreOrder(root);
	printf("\n");

	printf("InOrder traversal\n");
	printInorder(root);
	printf("\n");

	printf("Postorder traversal\n");
	printPostorder(root);

	printf("\ntree is deleted");
	deleteTree(root);
	root = NULL;
}
