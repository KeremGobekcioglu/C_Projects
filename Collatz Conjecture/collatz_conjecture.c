#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
int main()
{
    int xs, currentlen, seqlen;
    currentlen = 1;
    int c = 0;
    int *loop; 
    int h[9];
    int ls = 0;
    int le = 0;
    printf("Please enter the sequence lenght: ");
    scanf("%d", &seqlen);
    printf("Please enter the first element: ");
    scanf("%d", &xs);
    int looplen = seqlen / 2; // looplen max = n/2 n = seqlen
    loop = (int *)malloc(sizeof(int) * (looplen)); // allocating space for loop
    int digit = 1;
    check_loop_iterative(generate_sequence, xs, seqlen, loop, &looplen);
    printf("Looplen = %d\n",looplen);
    hist_of_firstdigits(generate_sequence, xs, seqlen, h, digit);
    for (c = 0; c < looplen; c++) // printing the loop
    {
        if (c == 0)
            printf("Loop: {");
        if (c < looplen - 1)
            printf("%d, ", loop[c]);
        else
            printf("%d", loop[c]);
        if (c == looplen - 1)
            printf("}\n");
    }
    for(c = 0; c<9; c++) // printing the histogram
    {
        if(c == 0)
            printf("Histogram of sequence: {");
        if(c < 8)
            printf("%d, ",h[c]);
        else
        	printf("%d",h[c]);
        if( c == 8)
        	printf("}\n");
    }
    free(loop); // freeing the space which i allocated for the loop
    while(1)
        getchar(); // to prevent the program from terminating
    return 0;
}





