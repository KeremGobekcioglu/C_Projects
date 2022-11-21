#include <stdio.h>
#include<math.h>
#include "util.h"

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, int s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return r;
}

char dt1a(float PL, float PW, float SL, float SW)
{
    char s = 's'; //  Setosa = s
    char vi = 'i'; // Virginica = i
    char ve = 'e'; // Versicolor = e

    if( PL < 2.45)
        return s;
    else
    {
        if( PW < 1.75)
        {
            if( PL < 4.95)
            {
                if( PW < 1.65)
                    return ve;
                else
                    return vi;
            }
            else
                return vi;
        }
        else
            return vi;
    }
}
char dt1b(float PL, float PW, float SL, float SW)
{
    char s = 's'; // Setosa = s
    char vi = 'i'; // Virginica = i
    char ve = 'e'; // Versicolor = e
    
    if( PL < 2.55)
        return s;
    else
    {
        if( PW < 1.69)
        {
            if( PL < 4.85)
                return ve;
            else
                return vi;
        }
        else
            return vi;
    }
}

double dt2a(double x1, double x2, double x3, int x4, int x5)
{
	if ( x1 < 31.5 )
	{
		if ( x2 > -2.5 )
			return 5.0;
		else if ( x2 - 0.1 <= x1 && x1 <= x2 + 0.1 )
			return 2.1;
		else
			return -1.1;
	}
	else 
	{
		if ( -1 <= x3 && x3 <= 2 )
			return 1.4;
		else if ( x4 && x1 )
			return -2.23;
		else
			return 11.0; 
	}
}	
			
double dt2b(double x1, double x2, double x3, int x4, int x5)
{
	if ( 12 < x1 && x1 < 22 )
	{
		if ( x3 > 5/3 )
			return -2.0;
		else if ( x1 - 0.1 <= x3 && x3 <= x1 + 0.1 )
			return 1.01;
		else 
			return -8;
	}
	else
	{
		if ( x4 && x5 )
			return -1;
		else if ( -1 <= x2 && x2 <= 2 )
			return -1/7;
		else
			return sqrt(2)/3;
	}
}
int sort(int array[],int size) // Bubble Sort algorithm for my trees in dt3a,dt3b
{
	int i = 0;
	int j = 0;
	for(i = 0; i<size; i++)
	{
		for(j = 0; j<size -1 -i; j++)
		{	
			if ( array[j+1] < array[j] )
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	return 0;
}
 
/* Write the prototype of the functions implementing the decision trees for the third problem */
char dt3a(int time, int continent, int money, int arr[], int si, int barr[], int size)
{
	if ( continent )
	{ 	
		if ( time <= arr[0] )
			return 'p'; // Philippines
		else
		{
			if ( money >= barr[1] )
				return 'k'; // Korea
			else
				return 'v'; // Vietnam 
		}
	}
	else
	{
		if ( money < barr[2] )
			return 'b'; // Bulgaria
		else
		{
			if ( time > arr[4] )
				return 'c'; // Crotia
			else if ( arr[2] < time && time <= arr[3] )
			{
				if ( barr[3] <= money && money <= barr[4] )
					return 'g'; // Germany
				else
					return 'n'; // Norway
			}
			else
			{
				if ( time <= arr[1] /*time <= arr[2] */ )
					return 'i'; // Italy
				else
					return 's'; // Spain
			}
		}	 
	}
	return 'e'; // Error
}
	
char dt3b(int time, int continent, int money, int arr[], int si, int barr[], int size)
{
	if ( money >= barr[2] )
	{
		if ( continent )
		{
			if ( time >= arr[0] )
				return 'p'; // Philippines
			else if ( barr[1] <= money )
				return 'k'; // Korea
			else 
				return 'v'; // Vietnam
		}
		else
		{
			if ( time <= arr[4] )
			{
				if ( barr[4] >= money )
				{
					if ( time >= arr[1] )
					{
						if ( barr[3] >= money )
						{
							if ( arr[1] <= time )
								return 'i'; // Italy
							else
								return 's'; // Spain	
						}
						else
							return 'g'; // Germany		
					}
					else
						return 's'; // Spain
					
				}
				else
					return 'n'; // Norway
			}
			else
				return 'c'; // Crotia
		}
	}
	else if ( continent == 0 )
		return 'b'; // Bulgaria
	else if ( time > arr[0] )
	{
		if ( money < barr[1] )
			return 'v'; // Vietnam
		else 
			return 'k'; // Korea
	}
	else
		return 'p'; // Philippines
	return 'e'; // Error 
}

/* Provide your implementations for all the requested functions here */
