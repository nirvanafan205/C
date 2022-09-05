#include <stdio.h>
#include <stdlib.h>

int main()
{
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //regular array

	for(int i = 0; i < 10; i++)
	{
		printf("%d\n", array[i]);
	}

	printf("\n");

	int *nums = new int[10]; //dynamically allocates array of pointers

	for(int i = 11, b = 0; i < 21; i++, b++)
	{
		nums[b] = i; //inputting numbers
		*(nums + b) = i;
	}

	for(int i = 0; i < 10; i++)
	{
		printf("%d\n", nums[i]);
	}

	free(nums); //frees memory
}
