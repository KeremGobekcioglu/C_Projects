#include<stdio.h>
#include "utils.h.h"

int main()
{
	int first_integer, second_integer, divisor, next;
	int control;
	int next_integer = 0;
	
	printf("Enter the first integer: ");
	scanf("%d",&first_integer);
	
	printf("Enter the second integer: ");
	scanf("%d",&second_integer);
	
	printf("Enter the divisor: ");
	scanf("%d",&divisor);
	control = find_divisible(first_integer, second_integer, divisor);
	
	if ( control != -1) // If find_divisible is true , nth_divisible part will work but if it's not , it won't.
	{
		printf("The first integer between %d and %d divided by %d is %d\n",first_integer,second_integer,divisor,control);	
		printf("Enter the number how many next: ");	
		scanf("%d",&next);
		
		next_integer = find_nth_divisible(next,control,divisor); 
		
		if (second_integer >= next_integer) // nth divisible musn't be bigger than second integer
			printf("The %dth integer between %d and %d divided by %d is %d\n",(next+1),first_integer,second_integer,divisor,next_integer);
		else
			printf("No possible to find %dth divisible between %d and %d divided by %d\n",next,first_integer,second_integer,divisor);
	}
	else
		printf("There is not any integer between %d and %d can be divided by %d\n",first_integer,second_integer,divisor); 
	
	char identity[12];
	int	password;
	printf("Please enter your identity number: ");
	scanf("%s",identity);
	
	printf("Please enter your password: ");
	scanf("%d",&password);
	if (create_customer(identity,password) == 1 && validate_identity_number(identity) == 1) // If both of them is true, the rest will work
	{
		printf("Welcome.\n");
		char i[12]; 
		int p;
		  printf("Please enter your identity number: ");
		scanf("%s",i);
		printf("Please enter your password: ");
		scanf("%d",&p);
		if ( check_login(i,p) == 1) // If you can login, you can withdraw
		{
			printf("Login Successful\n");
			float a;
			printf("Enter your withdraw amount: ");
			scanf("%f",&a);
			if (withdrawable_amount(a) != 0)
				printf("Withdrawable amount is %d\n",withdrawable_amount(a));
			else
				printf("You can't withdraw negative numbers!\n");
		}
		else
		{
			printf("Invalid identity number or password\n");	
		}
	}
		else // If you can't manage the pass the create_customer and validate identity_number , this will come up.
			printf("Invalid identity number or password\n");   
		
	return (0);
}
