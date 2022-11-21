#include<stdio.h>
#include "utils.h.h"

int	find_divisible(int x, int y, int z)
{
	//we are going to find first divisible so i need an loop
	int	holder; // will hold the first value
	if( y>=x ) // Numbers may be equal
	{
		for(x; x<=y; x++) // x<= y because borders can be divided by z , too. We have to look.
		{
			if(x % z == 0)
			{
				holder=x;
				return (holder); // I returned the first integer
			}
		}
	}
	return -1;
}

int find_nth_divisible(int n, int f_l, int z)
{
	// Assume that you have a and need 3a , you can find it with 3a = a + 2a;
	// of course you can find it with a*3 ( in our case (n+1)*f_i) but we have to use z
	int next;
	if (z < 0) // It wasn't working at negatives , now with this, I hope it will work.
		z *= -1;
	next = f_l + n*z;
	return next;
}

int validate_identity_number(char identity_number [])
{
	int a = 0;
	int sum_even = 0;
	int sum_odd = 0;
	int b = 0;
	int array[11];
	int control10 = 0;
	int control11 = 0;
	while (identity_number[a] != '\0')
	{
		array[a] = identity_number[a] - 48;  // turning to integer array for addition
		a++; 
	}
	if ( a == 11)
	{
		if ( identity_number[0] != '0') // first character shouldn't be zero
		{
			while ( identity_number[b] != '\0' && ( 48 <= identity_number[b]) && (identity_number[b] <= 57))
			{
	// b % 2 == 1 but why sum_even ? Because if you want to look at the first character , you should look array[0]
	// if b is even , we add the number to sum_odd. 
				if ( b % 2 == 1 && b != 9 && b != 10 )   
					sum_even += array[b];  
				else if (b % 2 == 0  && b != 9 && b != 10) // we musn't look 10th and 11th characters because they have conditions for existence
					sum_odd += array[b];
				b++; // I have to increase b because loop has to continue
			}
			// I added this control10 and control 11 because if condition would be too long without them
			control10 = ((7*sum_odd) - sum_even) % 10;  // I learnt it from the document
			if ( control10 != array[9] ) // control 10 must be equal to array[9] because array[9] is the 10th digit in our identity_number
				return 0;
			control11 = (sum_even + sum_odd + array[9]) % 10;
			if ( control11 != array[10] ) //control 11 must be equal to array[10] because array[10] is the 11th digit in our identity_number
				return 0;
			return 1; // If everything is okay , return 1.
		}
	}
	return 0;
}

int	create_customer(char identity_number[], int password)
{
	int digit = 0;
	int hold = password; // hold will be 0 after the loop because of hold/=10;	
		while (hold != 0)  
			{
				hold /= 10;
				digit++; // I find how many digit of the password
			}
	
		if ( digit == 4 &&  validate_identity_number(identity_number) == 1) // If everything is okay , open the file and write the parameters
		{
			FILE *customeraccount = fopen("customeraccount.txt", "w"); // I opened the file in write mode
			fprintf(customeraccount, "%s,%d",identity_number,password); // I wrote identity_number in a string(char array) mode and password as an integer
	  		fclose(customeraccount);
	  		return 1;
	  	} 
	  
	return 0;
}


int	check_login(char identity_number[], int password)
{
	char tc[12];
	int pass;
	int i=0;
	
	FILE *customeraccount = fopen("customeraccount.txt", "r"); // I opened the file at read mode
	fscanf(customeraccount, "%11s,%d",tc,&pass);  // Write the first 11 character to string , after that take the value as a integer
    fclose(customeraccount);  
    // Actually in this section , tc[i] will be always true , because I read it from the txt and txt is always correct
    // but I can't know if the identity_number is correct so i have to read all of it so i m going to go to end of it
	while(identity_number[i] != '\0')
	{
	// If they are not equal , return 0;
		if ( tc[i] != identity_number[i])
			return 0;
		i++;
	}
	// if they are equal and their length are 11 , also if the password is true, it means everything is okay
	if(i==11 && pass == password)
		return 1;
	else
		return 0;
}

int	withdrawable_amount(float cash_amount)
{
	// we can only use mod with integers so i turned the cash_amount to integer , type casting
	int	a=0;
	if((int)cash_amount % 10 == 0)
		return	(int)cash_amount; // If the cash_amount can be divide to 10 , i return it because it is okay.
	// If not ...	
	else if((int)cash_amount % 10 != 0)
	{
	// Let's assume that you want to withdraw 21.75 , if I do while ( a < cash_amount ) a will be 30
	// Because when a is 20 , it is still less than 21.75 so i did cash_amount - 10 , when a become 10 it still
	// will be less than 11.75 ( cash_amount - 10 ) but it will increase 10 one last time and will be 20 
	// Loop has to be turn cash_amount / 10 times . 
		while( a < cash_amount - 10)  
			a += 10;
		return a;
	}
	// You can't withdraw negative numbers. 
	return 0;
}
