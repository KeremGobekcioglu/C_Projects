#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STACK_BLOCK_SIZE 10

typedef int data_type;

typedef struct
{
	int *array;
	int currentsize;
	int maxsize;
} stack;

stack *init_return(void)
{
	stack *new;
	new = (stack *)malloc(sizeof(stack));					   // allocation
	new->array = (int *)calloc(STACK_BLOCK_SIZE, sizeof(int)); // allocation space for our array
	new->maxsize = STACK_BLOCK_SIZE; // equaling maxsize to stack block size
	new->currentsize = 0; // currentsize is 0 because it is empty
	return new;
}

void push(stack *s, int d) // why it is int?
{
	if (s->currentsize < s->maxsize) // if size isn't exceeded ...
		s->array[(s->currentsize)++] = d; // arrays start from 0 so if there is one element it is array[0] and currentsize = 1
		//s->currentsize++ will increase the currentsize 1 but first s->array[s->currentsize ] will be equal to d
	else
	{
		s->array = realloc(s->array,(++(s->maxsize))*sizeof(int)); // reallocation memory because size is exceeded , 
		//++s->maxsize will increase the maxsize and realloc will allocate 1 more space
		s->array[(s->currentsize)++] = d; // arrays start from 0 so if there is one element it is array[0] and currentsize = 1	
	}
}

int pop(stack *s)
{
	if (s->currentsize > 0)
		return s->array[--(s->currentsize)]; // --s->currentsize will decrease the size and will return the last element
	return 0; // s->currentsize must decrease because we have to reach the element before the last element we popped
}

int smallestelement(stack *s) // I wrote this function because i didn't want to write right->array[right->currentsize-1] > mid->array[mid->currentsize-1] every time
{
	if (s->currentsize > 0) // if currentsize > 0 it will return the last element, let s  say currentsize is the 4 , last element will be 3
		return s->array[(s->currentsize) - 1]; 
	return 1000; // i return 1000 because i will compare the elements from '1' , '2' and '3' if you enter towersize = 8, biggest element will be
	// 8 , if we compare smallestelement(left) > smallestelement(right) , right( '3' ) will be empty at first and this function
	// so this function will return 1000 to smallestelement(right) , and left will be 8 at most so algorithm wont pop from right ,
	// it will pop from left and push right.
	// if right isn't empty , lets say right has 6 and left has 7  smallestelement(left) > smallestelement(right) will be true 
	// and algorithm wil pop from right and push left.
	// left is '1' , mid is '2' , right is '3'
	// it is the summary of algorithm
}

int init(stack *s)
{
	if(s == NULL) // if allocation couldn't happen it will return 0
		return 0;
	return 1;
}
int main()
{

	stack *right, *left, *mid;
	left = NULL;
	right = NULL;
	mid = NULL;
	right = init_return(); // creating our stacks
	left = init_return();
	mid = init_return();
	int towersize;
	if(!init(left) || !init(right) || !init(mid)) // even one of them is NULL, program will finish
	{
		printf("Allocation isn't successfull.\n");
		return 0;
	}
	printf("Enter the tower size :");
	scanf("%d", &towersize);
	for (int b = towersize; b > 0; b--) // filling our starting stack
		push(left, b);
	for (int a = 0; a < left->currentsize; a++) // our elements
		printf(" left[%d] = %d\n",a,left->array[a]);
	int movecounter = 0; // it will count our moves
	int holder; // it will hold our pop return value
	// algorithm works different on odds and evens
	while (right->currentsize < towersize) // if right->currentsize is equal to towersize,loop will finish
	{
	// left is 1 , mid is 2 , right is 3
		if (towersize % 2 == 1) // odds and evens have different ways to solve
		{
			if (movecounter % 3 == 0) // There is two move , pop from '3' or pop from '1' , push to '1' or push to '3'
			{	// and i control which one is bigger than i make my moves
				if(smallestelement(left) > smallestelement(right)) // I explained the algorithm above
				{
					holder = pop(right); 
					push(left,holder);
					printf("Move the disk %d from '3' to '1'\n",holder);
				}
				else
				{
					holder = pop(left);
					push(right,holder);
					printf("Move the disk %d from '1' to '3'\n",holder);
				}
			}
			else if ((movecounter - 1) % 3 == 0)
			{
				if( smallestelement(left) > smallestelement(mid))
				{
					holder = pop(mid);
					push(left,holder);
					printf("Move the disk %d from '2' to '1'\n",holder);
				}
				else
				{
					holder = pop(left);					
					push(mid,holder);
					printf("Move the disk %d from '1' to '2'\n",holder);
				}
			}
			else if((movecounter - 2) % 3 == 0)
			{
				if ( smallestelement(mid) > smallestelement(right) )
				{
					holder = pop(right);
					push(mid,holder);
					printf("Move the disk %d from '3' to '2'\n",holder);
				}
				else
				{
					holder = pop(mid);
					push(right,holder);
					printf("Move the disk %d from '2' to '3'\n",holder);
				}	
			}
		}

		else // it is for even ones , odd ones start from '1' to '3' ,  even ones start from '1' to '2'
		{
			if (movecounter % 3 == 0)
			{
				if(smallestelement(left) > smallestelement(mid))
				{
					holder = pop(mid);
					push(left,holder);
					printf("Move the disk %d from '2' to '1'\n",holder);
				}
				else
				{
					holder = pop(left);					
					push(mid,holder);
					printf("Move the disk %d from '1' to '2'\n",holder);
				}
			}
			else if ((movecounter - 1) % 3 == 0)
			{
				if( smallestelement(left) > smallestelement(right))
				{
					holder = pop(right);
					push(left,holder);
					printf("Move the disk %d from '3' to '1'\n",holder);
				}
				else
				{
					holder = pop(left);
					push(right,holder);
					printf("Move the disk %d from '1' to '3'\n",holder);
				}
			}
			else if((movecounter - 2) % 3 == 0)
			{
				if ( smallestelement(mid) > smallestelement(right) )
				{
					holder = pop(right);
					push(mid,holder);
					printf("Move the disk %d from '3' to '2'\n",holder);
				}
				else
				{
					holder = pop(mid);
					push(right,holder);
					printf("Move the disk %d from '2' to '3'\n",holder);
				}	
			}
		}
		movecounter++;
	}
	for (int z = 0; z < right->currentsize; z++)
		printf(" right[%d] = %d\n", z, right->array[z]);
	free(left);
	free(right);
	free(mid);
	return 0;
}
