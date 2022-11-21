#include<stdio.h>
#include <stdlib.h>
#include "utils.h"


void generate_sequence(int xs, int currentlen, int seqlen, int *seq)
{
    /*xs is the first element of sequence, seqlen is the length of sequence,
    currentlen is the length of the sequence in the time of the function called
    *seq is the array of the sequence, f(x)={3x+1 if x is odd,x/2 if x is even}
    x0 is the start, f(x0) = x1, f(x1) = x2 tends up with a loop 4,2,1,4,2,1*/
    seq[0] = xs;
    if (seqlen == currentlen) // if currentlen reaches seqlen, sequence is created
        return;
    else if (seq[currentlen - 1] % 2 == 1)
    {
        seq[currentlen] = seq[currentlen - 1] * 3 + 1;
        generate_sequence(xs, ++currentlen, seqlen, seq); /* ++currentlen we will reach the next element and when we reached currentlen will increase */
    }
    else if (seq[currentlen - 1] % 2 == 0)
    {
        seq[currentlen] = seq[currentlen - 1] / 2;
        generate_sequence(xs, ++currentlen, seqlen, seq);
    }
}

int has_loop(int *arr, int n, int looplen, int *ls, int *le)
{
    /* n is number of elements, looplen >- max = n / 2 , min 2 , *ls is the first occurence like 4,2,1 >- 4 is first ,
     *le is last element of loop like 4,2,1 >- 1.. */
    int k = 0;
    int counter = 0;
    if (looplen < 2)
        return 0;
    for (k = 0; k + looplen <= n; k++)
    {
        if (arr[k] == arr[k + looplen])
        {
            counter++; // increasing the counter, if it becomes equal to looplen , we found a loop
            if (counter == looplen) 
            {
                *le = n - counter - 1; /*counter = looplen , *le is the last element of my loop so
                last looplen(it is a number) elements of my array is the loop, so i substract counter from n. And i substract 1 because n - counter is the loop's second seen's start. */
                *ls = n - 2 * counter; /* ls is the start so i substract 2*counter from because loop will be seen two times then it will end, n-counter is the second loop's start */
// 4,2,1,4,2,1 n = 6 , counter will be 3, you can understand it from here 
                return 1;
            }
        }
        else
            counter = 0; // if it didn't return , counter has to be 0 because it increased.
    	}
    return 0;
}

/* if no loop is found , looplen will be zero instead of seqlen/2 , and the loop array
won't be updated. */
/*looplen max seqlen/2 , min 2 ,, just find one loop if exist,, descending order */
void check_loop_iterative(void (*f)(int xs, int currentlen, int seqlen, int *seq), int xs, int seqlen, int *loop, int *looplen) // seqlen = n, looplen n / 2 den başlıcak
{
    int *seq = (int *)malloc(sizeof(int) * seqlen); // allocating space for sequence array
    int ls, le;
    le = 0, ls = 0;
    int currentlen = 1;
    f(xs, currentlen, seqlen, seq); // creating the sequence array
    if (*looplen == seqlen / 2) // It will only print the sequence one because looplen will decrease
    {

        for (int a = 0; a < seqlen; a++) // printing the sequence
        {
            if (a == 0)
                printf("Sequence: {");
            if (a < seqlen - 1)
                printf("%d, ", seq[a]);
            else
                printf("%d}\n",seq[a]);
        }
    }
    if (*looplen < 2)
    {
        *looplen = 0;
        printf("No loop found.\n");
        return;
    }
    if (has_loop(seq, seqlen, *looplen, &ls, &le) == 1)
    {
        printf("Loop detected with a length of %d\nThe indexes of the loops"
               " first occurance: %d (first digit), %d (last digit)\n",
               *looplen, ls, le);
        for (int b = 0; ls < le+1; b++, ls++)
            loop[b] = seq[ls]; // filling my loop array with the loop in sequence 
        free(seq); // freeing the space which i allocated for seq array
        return;
    }
    printf("Checking if there is a loop of length %d...\n", *looplen);
    --*looplen; // decreasing the looplen for looking another lengths
    free(seq);  // freeing the space which i allocated for seq array
    check_loop_iterative(f, xs, seqlen, loop, looplen); // calling again
}

int findhowmanydigit(int number) // it is for finding the digit count in number
{
    int counter = 0;
    while (number != 0) // when number becomes 0 , i return the counter
    {
        number /= 10; // 145 , 145/10 = 14 counter = 1 , 14 / 10 = 1 counter = 2 , 1 / 10 = 0 counter = 3
        counter++; 
    }
    return counter;
}

int poww(int number, int us) // it is for taking 10^number
{
    if (us == 0) 
        return 1;
    int temp = number; // creating a temp for multiplication, number will change but temp will be same
    while (us > 1) // if us == 1 , we will return same number
    {
        number *= temp; // 4^3 , 4*4 , 16*4 , 64*4 , temp is same but number has changed
        us--; // when i multiplied the number , i decrease the us
    }
    return number;
}

void hist_of_firstdigits(void (*f)(int xs, int currentlen, int seqlen, int *seq),
                        int xs, int seqlen, int *h, int digit)
{
    int *seq = (int *)malloc(sizeof(int) * seqlen); // allocating space
    int currentlen = 1;
    f(xs, currentlen, seqlen, seq); // creating the sequence again.
    if(digit <= 9 )
    {
    	h[digit-1] = 0; // making the current element is zero so i can avoid from garbage values
    	/*To find the first digit of a number we have to divide it by the number of digits. if the number is 456, we have to divide it to 100, 100 is 10^2 */
    	for (int a = 0; a < seqlen; a++)
    	{
    	/* howmanydigit-1 because if the number is 456 >- it has 3 digits, we have to divide it to 100, 100 is 10^(3-1) */
        	int howmanydigit = findhowmanydigit(seq[a]); 
        	if (seq[a] / poww(10, howmanydigit - 1) == digit)
                     	h[digit - 1]++; /* when we find a number's first digit and it is equal to digit currently sent to this function , i increase the h[digit-1] */
    	}
    	free(seq);
    	/* I sent 1 to this function in main because h[0] has to be how many first digit is equal to 1*/
        hist_of_firstdigits(f, xs, seqlen, h, ++digit); // increasing the digit and calling again
    }
    else
    {

	free(seq);
    	return ;
    }
}

