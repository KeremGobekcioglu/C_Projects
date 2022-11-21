#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include "util.h"


int main() {

    /* Ask for the problem selection (1,2,3) .....  */

    /* Get the input from the user for the first problem, i.e., to test dt1a and dt1b */
    /* Compare performances and print results */

    /* Get the input from the user for the second problem, i.e., to test dt2a and dt2b */
    /* Compare performances and print results */

    /* Get the input from the user for the third problem, i.e., to test dt3a and dt3b */
    /* Compare performances and print results */
    int a;
    printf("Which problem do you want to solve ? Enter the number ( 1 , 2 , 3) ( 3 is the best !) :");
    scanf("%d",&a);
    if ( a == 0 )
    {
    	int t,s,w;
    	double p,h;
    	printf("Please enter values of t,s and w. Enter : ");
    	scanf("%d%d%d",&t,&s,&w);
    	printf("Please enter values of p and h. Enter : ");
    	scanf("%lf%lf",&p,&h);
    	if ( dt0(t,p,h,s,w) == 1 )
    		printf("%d\n",dt0(t,p,h,s,w));
    	else
    		printf("%d\n",dt0(t,p,h,s,w));
    }
    else if ( a == 1 )
    {
    	char vi[]="Virginica";
    	char ve[]="Versicolor";
    	char s[]="Setosa";
        float PL,PW,SL,SW;
        printf("Please enter PL : ");
        scanf("%f",&PL);
        printf("Please enter PW : ");
        scanf("%f",&PW);
        printf("Please enter SL : ");
        scanf("%f",&SL);
        printf("Please enter SW : ");
        scanf("%f",&SW);
        
        if( dt1a(PL,PW,SL,SW) == dt1b(PL,PW,SL,SW) && dt1a(PL,PW,SL,SW) == 'i')
        	printf("%s\n",vi);
        else if( dt1a(PL,PW,SL,SW) == dt1b(PL,PW,SL,SW) && dt1a(PL,PW,SL,SW) == 's')
        	printf("%s\n",s);
        else if( dt1a(PL,PW,SL,SW) == dt1b(PL,PW,SL,SW) && dt1a(PL,PW,SL,SW) == 'e')
        	printf("%s\n",ve);
        else if( dt1a(PL,PW,SL,SW) != dt1b(PL,PW,SL,SW) ) 
	{	
		if ( dt1a(PL,PW,SL,SW) == 'i')
			printf("%s\n",vi);
		else if ( dt1a(PL,PW,SL,SW) == 's')
			printf("%s\n",s);
		else if ( dt1a(PL,PW,SL,SW) == 'e')
			printf("%s\n",ve);
		if ( dt1b(PL,PW,SL,SW) == 's' )
			printf("%s\n",s);
		else if ( dt1b(PL,PW,SL,SW) == 'e' )
			printf("%s\n",ve);
		else if ( dt1b(PL,PW,SL,SW) == 'i' )
			printf("%s\n",vi);
        }
    }
    else if ( a == 2 )
    {
    	double x1,x2,x3;
    	int x4,x5;
    	printf("Please enter x1 , x2 and x3 : ");
    	scanf("%lf%lf%lf",&x1,&x2,&x3);
    	printf("Please enter x4 and x5 : ");
    	scanf("%d%d",&x4,&x5);
    	
    	if ( dt2a(x1,x2,x3,x4,x5) == dt2b(x1,x2,x3,x4,x5) )
    		printf("%0.2lf\n",dt2b(x1,x2,x3,x4,x5));
    	else if ( dt2a(x1,x2,x3,x4,x5) != dt2b(x1,x2,x3,x4,x5) && ( dt2a(x1,x2,x3,x4,x5) - dt2b(x1,x2,x3,x4,x5) == CLOSE_ENOUGH || dt2b(x1,x2,x3,x4,x5) - dt2a(x1,x2,x3,x4,x5) == CLOSE_ENOUGH))
    		printf("%0.2lf\n",(dt2a(x1,x2,x3,x4,x5) + dt2b(x1,x2,x3,x4,x5)) / 2.0 );

    	else 
    	{
    		printf("%0.2lf\n",dt2a(x1,x2,x3,x4,x5));
    		printf("%0.2lf\n",dt2b(x1,x2,x3,x4,x5));
	}
     } 
     else if ( a == 3 )
     {
     	printf("\n");
     	int arr[5]; // months
     	int barr[5]; // budget
     	int co; // binary decision
     	int mo; // final decision of budget
     	int time; // final decision of months
     	char b[]="Congratulations ! You have won 50.000 USD from The Jackpot. What are you going to do with this money ? ";
     	char c[]="I can't describe in words how happy I am. I have a dream, I want to travel to Asia and Europe, but at the same time, i can spend some of this money on my education. I'm sure I'm going to travel but I don't know where to start. ";
     	char d[]="No problem , sir. We have algorithms to solve this. Which countries do you want to travel , how long will you travel and how much money will you spend? If you give answers of these questions to our algorithm, it is going to show where you should begin with. You can choose your path from two different choice or maybe your path will be chosen.";
     	char e[]="This is perfect. Let's find out.";
     	printf("%s\n\n%s\n\n%s\n\n%s\n\n",b,c,d,e);
     	printf("A short brief before our algorithms. Our algorithms work like this , you need to enter five different times like 2 months , 3 months and you are going to set your final decision at last. Also, you need to enter five different amount of money like 10000 USD, 25000 USD and again, you are going to set your final decision at last. And you should decide which continent dou you want to travel, Asia or Europe ? When you have entered all the things we wanted, our algorithms will show you the paths you can go on. The rest will be up to you.\n\n");
     	printf(" Please enter the estimated number of months you can travel : Remember , it is going to be like , I will travel at least one month, and 12 months top.\n Enter :");
     	for(int k = 0; k<5; k++) // We have to use loops for filling up the arrays
 		scanf("%d",&arr[k]);
 	int z = sort(arr,5);
 	printf(" Now, you need to enter how much money you can spend while travelling. It is exactly the same like months, I will spend minimum 10000 USD and maximum 100.000 USD, you need to enter five different amount of money\n. A little remainder, travelling fees are a little bit high in this times, we suggest you to enter minimum 10.000 USD  , but it is up to you.\n Enter :");
 	for(int j = 0; j<5; j++) 
 		scanf("%d",&barr[j]);
 	int ze = sort(barr,5); // I sorted this arrays, because my trees work with in an order.
 	printf("I guess , everything is going fine. Now please enter how long will you travel. Remember, it is your final decision.\n Enter : ");
 	scanf("%d",&time);
 	printf("You are so close to an adventure. Now , please enter how much money you are going to spend. Remember, it is your final decision.\n Enter : ");
 	scanf("%d",&mo);
 	printf(" One last step. You are going to decide which continent you are going to fly. 1 for Asia , 0 for Europe.\n Enter : ");
 	scanf("%d",&co);

 	if ( dt3a(time, co, mo, arr, 5, barr, 5) == dt3b(time, co, mo, arr, 5, barr, 5) &&
 		dt3a(time, co, mo, arr, 5, barr, 5) == 'p')
 		printf("\n Philippines \n");
 	else if ( dt3a(time, co, mo, arr, 5, barr, 5) == dt3b(time, co, mo, arr, 5, barr, 5) &&
 		dt3a(time, co, mo, arr, 5, barr, 5) == 'k' )
 		printf("\n Korea \n");
 	else if ( dt3a(time, co, mo, arr, 5, barr, 5) == dt3b(time, co, mo, arr, 5, barr, 5) &&
 		dt3a(time, co, mo, arr, 5, barr, 5) == 'v')
 		printf("\n Vietnam \n");
 	else if ( dt3a(time, co, mo, arr, 5, barr, 5) == dt3b(time, co, mo, arr, 5, barr, 5) &&
 		dt3a(time, co, mo, arr, 5, barr, 5) == 'b')
		printf("\n Bulgaria \n");
	else if ( dt3a(time, co, mo, arr, 5, barr, 5) == dt3b(time, co, mo, arr, 5, barr, 5) &&
 		dt3a(time, co, mo, arr, 5, barr, 5) == 'c')
		printf("\n Crotia \n");
	else if ( dt3a(time, co, mo, arr, 5, barr, 5) == dt3b(time, co, mo, arr, 5, barr, 5) &&
 		dt3a(time, co, mo, arr, 5, barr, 5) == 'n')
		printf("\n Norway \n");
	else if ( dt3a(time, co, mo, arr, 5, barr, 5)== dt3b(time, co, mo, arr, 5, barr, 5) &&
 		dt3a(time, co, mo, arr, 5, barr, 5) == 'g')
		printf("\n Germany \n");
	else if ( dt3a(time, co, mo, arr, 5, barr, 5) == dt3b(time, co, mo, arr, 5, barr, 5) &&
 		dt3a(time, co, mo, arr, 5, barr, 5) == 'i')
		printf("\n Italy \n");
	else if ( dt3a(time, co, mo, arr, 5, barr, 5) == dt3b(time, co, mo, arr, 5, barr, 5) &&
 		dt3a(time, co, mo, arr, 5, barr, 5) == 's')
		printf("\n Spain \n");
	else if ( dt3a(time, co, mo, arr, 5, barr, 5) == dt3b(time, co, mo, arr, 5, barr, 5) &&
 		dt3a(time, co, mo, arr, 5, barr, 5)== 'e')
		printf("\n Error ! Our algorithms says that , you have to use this money on your education \n");
 	else
 	{
 		if ( dt3a(time, co, mo, arr, 5, barr, 5) == 'p' )
 			printf("\n Philippines \n");
 		else if ( dt3a(time, co, mo, arr, 5, barr, 5)== 'k' )
 			printf("\n Korea \n");
 		else if ( dt3a(time, co, mo, arr, 5, barr, 5) == 'v' )
 			printf("\n Vietnam \n");
 		else if ( dt3a(time, co, mo, arr, 5, barr, 5) == 'b' )
 			printf("\n Bulgaria \n");
 		else if ( dt3a(time, co, mo, arr, 5, barr, 5)== 'c' )
 			printf("\n Crotia \n");
 		else if ( dt3a(time, co, mo, arr, 5, barr, 5) == 'n' )
 			printf("\n Norway \n");
 		else if ( dt3a(time, co, mo, arr, 5, barr, 5) == 'g' )
 			printf("\n Germany \n");
 		else if ( dt3a(time, co, mo, arr, 5, barr, 5) == 'i' )
 			printf("\n Italy \n");
 		else if ( dt3a(time, co, mo, arr, 5, barr, 5) == 's' )
 			printf("\n Spain \n");
 		else if ( dt3a(time, co, mo, arr, 5, barr, 5) == 'e' )
 			printf ("\n Error \n");
 		if ( dt3b(time, co ,mo, arr, 5, barr, 5) == 'p' )
 			printf("\n Philippines \n");
 		else if ( dt3b(time, co, mo, arr, 5, barr, 5) == 'k' )
 			printf("\n Korea \n");
 		else if ( dt3b(time, co, mo, arr, 5, barr, 5) == 'v' )
 			printf("\n Vietnam \n");
 		else if ( dt3b(time, co, mo, arr, 5, barr, 5) == 'b' )
 			printf("\n Bulgaria \n");
 		else if ( dt3b(time, co, mo, arr, 5, barr, 5) == 'c' )
 			printf("\n Crotia \n");
 		else if ( dt3b(time, co, mo, arr, 5, barr, 5) == 'n' )
 			printf("\n Norway \n");
 		else if ( dt3b(time, co, mo, arr, 5, barr, 5) == 'g' )
 			printf("\n Germany \n");
 		else if ( dt3b(time, co, mo, arr, 5, barr, 5) == 'i' )
 			printf("\n Italy \n");
 		else if ( dt3b(time, co, mo, arr, 5, barr, 5) == 's' )
 			printf("\n Spain \n");
 		else if ( dt3b(time, co, mo, arr, 5, barr, 5) == 'e' )
 			printf ("\n Error \n");
 	}
 }  
    	
     return 0;
}
