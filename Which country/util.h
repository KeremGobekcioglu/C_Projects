#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, int s, int w);

char dt1a(float PL, float PW, float SL, float SW);
char dt1b(float PL, float PW, float SL, float SW);

double dt2a(double x1, double x2, double x3, int x4, int x5);
double dt2b(double x1, double x2, double x3, int x4, int x5);

int sort(int array[],int size); // I addded this for sorting.
/* Write the prototype of the functions implementing the decision trees for the third problem */
char dt3a(int time, int continent, int money, int arr[], int si, int barr[], int size);
char dt3b(int time, int continent, int money, int arr[], int si, int barr[], int size);

#endif /* _UTIL_H_ */
