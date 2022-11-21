#ifndef _UTILS_H_
#define _UTILS_H_

void generate_sequence(int xs, int currentlen, int seqlen, int *seq);


int has_loop(int *arr, int n, int looplen, int *ls, int *le);


void check_loop_iterative(void (*f)(int xs, int currentlen, int seqlen, int *seq), int xs, int seqlen, int *loop, int *looplen);


int findhowmanydigit(int number);


int poww(int number, int us);


void hist_of_firstdigits(void (*f)(int xs, int currentlen, int seqlen, int *seq),
                        int xs, int seqlen, int *h, int digit);

#endif
