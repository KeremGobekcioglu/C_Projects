#include<stdio.h>

int digitcounter(int a) // I needed this function to print numbers correctly. 
{ // I used \b so i needed their digits , and negative ones have one more due to '-' sign.
	int count = 0;
	if ( 0 > a )
	{	a*=-1;
		count++; // '-' sign is an digit for my code i have one more \b for it.
		// So that , count becomes one for negatives.
	}
	while( a > 0 )
	{	
		a/=10; // I divide the number by 10 until the number becomes 0 and increment a count. So , i find the digit.
		count++;
	}
	return count;
}

int main()
{   
    int select = 0; // It is for our operations.
    int a,b,c; // Our coefficients
    int x,y; // x and y 
    int controlpositive; // These are my flags to prevent overwriting
    int controlnegative;
    while ( select != 4) // If you don't select 4 , loop will turn forever.
    {    
        printf("\nSelect an operation...\n1 -> Enter the " 
                    "coefficients.\n2 -> Draw the graph.\n3 -> Print the" 
                    " graph into a.txt file.\n4 -> Exit.\n\nChoice: "); 
        scanf("%d",&select); // User select the operation from the menu.
   
        if(select == 1) //These are my selections from the menu.
        {
            FILE *fp;
            fp = fopen("coefficients.txt","w"); // I opened at w mode for deleting the previous data and write new ones.
            if ( fp == NULL) // If file pointer is null, i warn the user.
                printf(" There is an error, file could not be created\n");
            else
            {
		    printf("Please enter the coefficient for the "
		            "following equation: x=a*(y*y) + b*y + c\n");
		    printf("\n"); // I took my coefficients from the user and printed them into coefficients.txt file 
		    printf("a: ");
		    scanf("%d",&a);
		    printf("b: ");
		    scanf("%d",&b);
		    printf("c: ");
		    scanf("%d",&c);
		    fprintf(fp,"%d\n%d\n%d",a,b,c); // Printing to the file.
		    fclose(fp); // Closing the file.
	    }
        }
        else if ( select == 2) // These are my selections from the menu.
        {
            FILE *fp;
            fp = fopen("coefficients.txt","r");
            if ( fp == NULL)  // If file pointer is null, i warn the user.
                printf("There is no coefficients.txt file"); 
            else
            {
                fscanf(fp,"%d\n%d\n%d",&a,&b,&c); // I scanned my coefficients from the coefficients.txt file.
               	fclose(fp); // When my job with file ends, i close the file.
                for(y=16; y>=-16; y--) /* We begin to create our graphics from -56,16 , then -55,16 , -54,16 ...  56,16 after we reach to 56 , we go belove to -56,15.
       		Its happening until the 56,-16. Thats why y-- and x++ i used. x is our normal x and y is our normal y, it is more understandable than i and j.
                { And i begin from -56 and 16 and end it 56 and -16 because of > , < , v , ^ signs. I had to add them correctly. */
                {
                    controlpositive = 0; // These are my flags to prevent overwriting
    		    controlnegative = 0; // Flags must be 0 when the inner loop ends.
                    for(x=-56; x<=56; x++)
                    { // This loops creates whole x from -56 to 56.
                        if (x == a*(y*y) + b*y + c)
                        { // If my values match with coefficients, i write a #. And it is the first thing we have to look. Rest is else if.
                        	printf("\033[1;35m"); // Color codes.
                        	printf("#");
                        	printf("\033[0m");
                        	if ( x < 0 ) // If you enter a = 0, b = 0, c = -11 or -12 , the program couldn't draw the graph properly. Overwriting was happening.
                        		controlnegative+=2; // So , i add flags, if you have 3 digit number like negatives(ofc not all of them), flag will be incremented 2 because of overwriting.
                        	if ( x >= 0 )
                        		controlpositive+=1; // Positives have max 2 digits so , i increment the flag just one. 
                        }
                        else if ( x == -1 && y % 5 == 0 && y != 0 && (controlpositive == 0 && controlnegative == 0)) // IF flags aren't zero, if # is written , you can't write a number. 
                        {
	                    	printf("\033[1;32m"); // Color codes.
                        	int k = digitcounter(y); // I find how many digit the number has.
                        	for ( ; k > 1 ; k-- ) /* I delete (how many digit - 1) character. I found this after I tried a few thing. I had known i need to delete some characters
                        	but i didn't know how many characters i should delete, so i tried and found it. It wasn't hard.*/    		
	                        {	printf("\b"); }
                        	printf("%d",y); // After backspaces, i write the number. Before using backspaces, graph was going right for y values.
                        	printf("\033[0m"); // With this , color goes back to normal.
                        }
                        else if ( y == -1 && x % 10 == 0 && x != 0 && (controlpositive == 0 && controlnegative == 0)) // IF flags aren't zero, if # is written , you can't write a number.
                        {	
                        	printf("\033[1;32m"); // Color codes
                        	int f = digitcounter(x);
                        	for ( ; f>1; f-- ) // Same happens here.
                        		printf("\b");
                        	printf("%d",x); // Before backspaces, the x values were exceeding the edges of graph.
                        	printf("\033[0m"); // With this , color goes back to normal.
                        }
                        else if ( x == -56 && y == 0 )
                        {
				printf("\033[1;31m"); // Color codes.
				printf("<"); // At the edges, i print the signs you wanted.
				printf("\033[0m"); // With this , color goes back to normal.
			}
			else if ( x == 56 && y == 0 )
			{
				printf("\033[1;31m");// Color codes.
				printf(">"); // At the edges, i print the signs you wanted.
				printf("\033[0m"); // With this , color goes back to normal.
			}
			else if ( x == 0 && y == 16 )
			{
				printf("\033[1;36m");// Color codes.
				printf("^"); // At the edges, i print the signs you wanted.
				printf("\033[0m"); // With this , color goes back to normal.
			}
			else if ( x == 0 && y == -16 )
			{
				printf("\033[1;36m");// Color codes.
				printf("v"); // At the edges, i print the signs you wanted.
				printf("\033[0m"); // With this , color goes back to normal.
			}
                        else if ( x == 0 )
                        {
                        	printf("\033[1;36m");// Color codes.
                        	printf("|"); //When x becomes 0 , i print | and create the y axis.
                        	printf("\033[0m"); // With this , color goes back to normal.
                        }
                        	
                        else if ( y == 0 )
			{	
				printf("\033[1;31m");// Color codes.
				printf("-"); //When y becomes 0 , i print - and create the x axis.
				printf("\033[0m"); // With this , color goes back to normal.
			}
			else if ( x==-1 && y == -1 )
			{
				printf("\033[1;32m");// Color codes.
				printf("0"); // I print 0 in x axis -1, y axis -1.
				printf("\033[0m"); // With this , color goes back to normal.
			}
			else
			{	printf(" "); // If none of the ifs or else ifs happens, i have to print space
			/* This part is important , both of my flags is decreased 1. But my controlnegative is increased 2. The reason for this, '-' is a digit and '-' is being overwrited in x= -12 , x = -22 etc. If you want to draw x = -10 , you can draw it without flags. But you can't draw x = -12, x = -11 or x = 9 or a equation which overwrites the number on #. We have to check this situation. Firstly, i used only one flag for all of the values but then i realised my graph was overwriting and seperated my flags and controlled negatives and positives seperately. Now , it works
good. */ 	
				if ( controlnegative != 0 )
					controlnegative--; 
				if ( controlpositive != 0 )
					controlpositive--;
			}	
                        
                    }
                    printf("\n"); // When my x axis ends , i have to go the belove y axis like -56,16 - 56,16 ended , i have to go -56,15 - 56, 15. With \n, i do it.
                }
            }
        }
        else if ( select == 3 )
        {
        	FILE *fp2,*fp;
        	fp2 = fopen("graph.txt","w"); // I opened my file and i am going to draw my graph.
        	fp = fopen("coefficients.txt","r");
        	if ( fp == NULL || fp2 == NULL) // If file pointer is null, i warn the user.
                	printf("There is no coefficients.txt file or graph.txt file\n");
                else
                {
			fscanf(fp,"%d",&a); /* I scanned the coefficients from the coefficients.txt file. */
			fscanf(fp,"%d",&b);
			fscanf(fp,"%d",&c);
			printf("Coefficients has been read from the coefficents file\nThe graph of x=%d(y*y) + %d*y + %d has been written to the graph.txt file\n",a,b,c);
			if ( fp == NULL || fp2 == NULL)
		        	printf("There is no coefficients.txt file or graph.txt file\n");
			for(y=16; y>=-16; y--)
		        {
		            for(x=-56; x<=56; x++)
		            { /* Same loops without colors and numbers , i just print in file instead of terminal. I used the fprintf */
		                if (x == a*(y*y) + b*y + c )
		                    	fprintf(fp2,"#"); 
		                else if ( x == -56 && y == 0 )
					fprintf(fp2,"<");
				else if ( x == 56 && y == 0 )
					fprintf(fp2,">");
				else if ( x == 0 && y == 16 )
					fprintf(fp2,"^");
				else if ( x == 0 && y == -16 )
					fprintf(fp2,"v");
		                else if ( x == 0 )
		                	fprintf(fp2,"|");
		                else if ( y == 0 )
					fprintf(fp2,"-");
				else
					fprintf(fp2," ");
		                
		            }
		            fprintf(fp2,"\n");
		        }
		    	fclose(fp2);
		 }
	 }
         else if ( select != 4 )
         	printf("Improper input!\n");
    }
    return 0;
}
