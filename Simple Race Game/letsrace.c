#include <stdio.h>
#include <time.h>
#include <stdlib.h>
char array[15][30];// My array is here, then i fill this array.

void red()
{
	printf("\033[1;31m");
}
void yellow()
{
	printf("\033[1;33m");
}
void reset()
{
	printf("\033[0m");
}
void green() 
{
	printf("\033[0;32m");
}
void blue()
{
	printf("\033[0;34m");
}
void purple()
{
	printf("\033[0;35m");
}
void cyan()
{
	printf("\033[0;36m");
}
void white()
{
	printf("\033[0;37m");
}

void flush(void)
{ /* This function works like fflush , if you enter 1a scanf reads 1 and
	 a stays in stdin. This function clears stdin. It takes garbage chars
	 which prevents my program */
	int k;
	do
	{ // Takes chars to an integer , it is like trash bin
		k = getchar();
	} while (k != '\n' && k != EOF); // Until the 'enter' (\n) and EOF
}

int dice()
{
	return rand() % 6 + 1; // [1,6]; rand()%6 means random numbers from 0-6, when we add one it becomes 1-6
}

void printMap(char array[][30])
{
	// It is a simple print fucntion for our array, i just add colors. Nothing much to tell.
	int i = 0, j = 0;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 30; j++)
		{
			if(array[i][j] == 'X')  
			{
				yellow();
				printf("%c", array[i][j]);
				reset();
			}
			else if(array[i][j] == '1')  
			{
				purple();
				printf("%c", array[i][j]);
				reset();
			}
			else if(array[i][j] == '2')  
			{
				green();
				printf("%c", array[i][j]);
				reset();
			}
			else if(array[i][j] == '_')  
			{
				yellow();
				printf("%c", array[i][j]);
				reset();
			}
			else if(array[i][j] == ':')  
			{
				blue();
				printf("%c", array[i][j]);
				reset();
			}
			else if(array[i][j] == '.')  
			{
				red();
				printf("%c", array[i][j]);
				reset();
			}
			else
			{
				blue();
				printf("%c", array[i][j]);
				reset();
			}
		}
		printf("\n");
	}
}

void makearray()
{
	// If I had created the array manually , I would have spent less time.
	// When i tried this function for the first time, i hadn't use else if and i saw that my array was wrong.
	// I thought why ? then i realised some if s were terminating each other and i put else if 's.
	// I have a nested loop looking rows then columns and i create the array.
	// The rest is if s and else if s and else s , i put our characters in our array. Nothing much to tell.
	int y = 0;
	int x = 0;
	for (y = 0; y < 15; y++)
	{
		for (x = 0; x < 30; x++)
		{
			if ((y == 1 || y == 13) && (x != 0 && x != 29))
			{
				if (y == 1 && x == 1)
					array[y][x] = '1';
				else if (x == 14)
					array[y][x] = 'X';
				else
					array[y][x] = ' ';
			}
			if ((x == 0 || x == 29) && (y != 0 && y != 14))
				array[y][x] = ':';
			if (y == 0 || y == 14)
				array[y][x] = '.';
			if ((y == 2 && (x != 0 && x != 29)) || (y == 12 && (x != 0 && x != 29)))
			{
				if (y == 2 && x == 1)
					array[y][x] = '_';
				else if (y == 2 && x == 28)
					array[y][x] = ' ';
				else if (y == 12 && (x == 1 || x == 28))
					array[y][x] = ' ';
				else
					array[y][x] = '.';
			}
			if ((y == 4 && (x != 0 && x != 29)) || (y == 10 && (x != 0 && x != 29)))
			{
				if (y == 4 && x == 3)
					array[y][x] = '_';
				else if (x == 2 || x == 27)
					array[y][x] = ':';
				else if (y == 10 && x == 26)
					array[y][x] = 'X';
				else if (y == 4 && (x == 1 || x == 26 || x == 28))
					array[y][x] = ' ';
				else if (y == 10 && (x == 1 || x == 3 || x == 28))
					array[y][x] = ' ';
				else
					array[y][x] = '.';
			}
			if ((y == 3 || y == 11) && (x != 0 && x != 29))
			{
				if (x == 2 || x == 27)
					array[y][x] = ':';
				else if (y == 3 && x == 3)
					array[y][x] = '2';
				else if (x == 10 || x == 18)
					array[y][x] = 'X';
				else
					array[y][x] = ' ';
			}
			if ((y >= 5 && y <= 9) && (x != 0 && x != 29))
			{
				if (y == 5 && x == 26)
					array[y][x] = 'X';
				else if (y == 7 && x == 28)
					array[y][x] = 'X';
				else if (x == 2 || x == 4 || x == 25 || x == 27)
					array[y][x] = ':';
				else
					array[y][x] = ' ';
			}
		}
	}
}

int enter(int l) // returns dice
{
	int hold = 0;
	char ent;
	while (1)
	{
		printf("PLAYER %d... press ENTER to dice", l);
		ent = getchar();
		if (ent == '\n')
		{
			hold = dice(); // Takes a dice.
			printf("DICE: %d\n", hold);
			break; // breaks if you entered 'enter' after taking a dice.
		}
		else
			printf("ENTER !!!\n");
		flush(); // You cant type anything other than enter. 
	}
	return hold;
}

int startGame() // Decides which player will start the game
{
	int p1 = 0, p2 = 0;
	printf("To start to game, players should dice and"
		   "decide who is going to start first according to it...\n");
	do
	{
		p1 = enter(1); // For player 1
		p2 = enter(2); // For player 2
		if (p1 > p2)
		{
			printf(" *** PLAYER 1 will start the game... ***\n");
			return 1; // 1;
		}
		else if (p2 > p1)
		{
			printf(" *** PLAYER 2 will start the game... ***\n");
			return 2; // 2;
		}
		printf("Same dice value... Please try again.\n"); // If they are equal , this will be printMaped.
	} 
	while (p1 == p2);
}

void letsplay(int who)
{
	int i = 1, j = 1;    // We assume player 1 is first
	int whichplayer = 1; // Same.
	int finishcheck = 0; // A flag for ending part, it is because when you pass the '_' , sometimes you have to move a bit. And my first movement part takes the last movement part but i already arranged it in last movement part,so that i put a flag.
	if (who == 1)		// line, player 1 s movement goes the first movement part so i neded to check this.
		whichplayer += 1; // If it is whichplayer becomes player 2.
	// If player 2 is first whichone stays 1 so everything is fine.
	int dice1 = 0;  // Dices for players.
	int dice2 = 0;
	int back = 0;
	int i2 = 3,j2 = 3;  // Position for player 2
	int player2check = 0; // Check for player 2
	int flag = 0; // Flag to control finishing.
	while (flag == 0)
	{
		if (who == 1)// who starts?
		{
			dice1 = enter(who); // returns dice
			if (j + dice1 < 29 && j != 28 && i == 1 && finishcheck == 0)
			{
				if (array[i][j + dice1] != 'X') // If it isn t a penalty , move on.
				{
					array[i][j + dice1] = array[i][j]; // New position becomes the old which is '1'.
					array[i][j] = ' '; // And the old position becomes ' '
					j += dice1; // Updating the j 
				}
				else
				{
					// If it is a penalty ...
					array[i][j + dice1 - 2] = array[i][j];  // Coming back .
					if ( j + dice1 - 2 != j ) // If dice is 2 , dont make the old position ' ', because we will go back there due to penalty.
						array[i][j] = ' ';
					j += dice1 - 2; // Updating.
					printf("Penalty for Player %d\n",who); // Penalty error for players.
				}
			}
			else if(j+dice1 >= 29 && j != 28 && i == 1)
			{
			/* This part is for when our players exceed the borders. When they exceed the borders, i rearranged their dice and positions.
			We have [15][30] array our border is 29 , player 1 has to stop at array[i][j]>= j = 28
			so if player is at array[][25] and dice is 6, player has to move 3 right and 3 down so our new dice must be 3. So that,
			If we add dice with our position (array[][j] here j ) j - 28(we have to stop here) >= dice + (j -28) 
			It will be our new dice then I assume we came to j = 28 and our i increases and we don't exceed the borders and 
			move on properly. Then I make equal our j = 28 so that program understand where my player at and can contunie on. (array[][j] here j )
			And also i == 1 and j!= 28 because only we exceed borders in i = 1 and j != 28 because if j = 28 everything is okay.
			*/
				dice1 = j + dice1 - 28; // We have [15][30] array our border is 29 , player 1 has to stop at array[i][j]>= j = 28
				array[i+dice1][28] = array[i][j];
				array[i][j] = ' ';
				j = 28; // Our j became 28.
				i+=dice1;
			}
			else if (j == 28 && i + dice1 < 14 && i != 13) // i + dice1 < 14 because of borders. And i!= 13 because because when i becomes 13 , it will be a new move.
			{
				if (array[i + dice1][j] != 'X')  // If it isn t a penalty , move on.
				{
					array[i + dice1][j] = array[i][j]; // New position becomes the old which is '1'.
					array[i][j] = ' ';  // And the old position becomes ' '
					i += dice1;   // Updating.
				}
				else
				{
					array[i + dice1 - 2][j] = array[i][j]; // Coming back .
					if (i + dice1 - 2 != i) // If dice is 2 , dont make the old position ' ', because we will go back there due to penalty.
						array[i][j] = ' '; 
					i += dice1 - 2; // Updating.
					printf("Penalty for Player %d\n",who); // Penalty error for players.
				}

			}
			else if(i+dice1 >= 14 && i != 13 && j == 28)
			{
				/* Borders again. (array[i][j]) Let's say our i is 10 and our dice is 6. Player 1 has to move i = 13 then dice must be decreased
				13 - i. So , new dice is dice = dice + (i - 13). First, we come to edge and didnt exceed the border , after that we normally move on. */
				dice1 = i + dice1 - 13;
				array[13][j-dice1] = array[i][j]; // But we went to left so our j must be decreased. (array[][j])
				array[i][j] = ' ';
				i = 13; // I'm doing this so that my program understands where is my player at , which row our player at.
				j -= dice1; // Updating...
				
			}
			else if (i == 13 && j - dice1 > 0 && j != 1)
			{
				if (array[i][j - dice1] != 'X')  // If it isn t a penalty , move on.
				{
					array[i][j - dice1] = array[i][j];   // New position becomes the old which is '1'.
					array[i][j] = ' ';   // And the old position becomes ' '
					j -= dice1;  // Updating.
				}
				else
				{
					array[i][j - dice1 + 2] = array[i][j];  // Coming back .
					if (j - dice1 + 2 != j)  // If dice is 2 , dont make the old position ' ', because we will go back there due to penalty.
						array[i][j] = ' ';
					j += 2 - dice1;  // Updating.
					printf("Penalty for Player %d\n",who);  // Penalty error for players.
				}
				finishcheck++; // I have to increment this flag somewhere and i choose this part.
			}
			else if ( j - dice1 <= 0 && j != 1 && i == 13)
			{
				/* Borders again. (array[i][j]) Let's say our j is 4 and our dice is 6. Player 1 has to move j = 1 then dice must be decreased
				(j-1). So , new dice is dice = dice + (j - 1). First, we come to edge and didnt exceed the border , after that we normally move on. */
				dice1 = dice1 -j + 1; // dice-= (j-1); I didn't have enough time to rearrange this to normal and good way like dice -= (j-1).
				array[i-dice1][1] = array[i][j]; // We went up so that our i must be decreased , we are j == 1 and i == 13 then it will be i = i - dice1.
				array[i][j] = ' ';
				j = 1;  // I'm doing this so that my program understands where is my player at , which column our player at.
				i -= dice1; // Updating
			}
			else if (i - dice1 == 2 && j == 1) // When we come to finish line...
			{
				array[i - dice1][j] = '1'; // Our new position must be '1' .
				array[i][j] = ' '; // And the old position becomes ' '
				printf(" *** PLAYER 1 WON THE GAME ***\n\n");
				printMap(array); // I need this because if player 1 wins , i dont need a dice for player 2.
				break; // I added this break and flag means nothing now but i dont have enough time to remove all flags.
				// Some flags are useless.
				flag++; // flag++ so that I broke the while(flag==0) and program finishes.
				// Parts before this one , i made i or j = something to program understand where player at but now , i dont need that because game finished.
			}
			else if (i - dice1 == 1 && j == 1) // If '1' player 1 comes to first position(it means he won.)
			{
				array[i - dice1][1] = '1'; // Our new position must be '1' .
				array[i][j] = ' '; // And the old position becomes ' '
				printf(" *** PLAYER 1 WON THE GAME ***\n\n");
				printMap(array); // I need this because if player 1 wins , i dont need a dice for player 2.
				break; // I added this break and flag means nothing now but i dont have enough time to remove all flags.
				// Some flags are useless.
				flag++;  // flag++ so that I broke the while(flag==0) and program finishes.
				// Parts before this one , i made i or j = something to program understand where player at but now , i dont need that because game finished.
			} 
			else if (i - dice1 > 2 && j == 1) // i - dice 1 > 2 means player didn't pass the finish line and moves on the last part.
			{
				array[i - dice1][j] = array[i][j];  // New position becomes the old which is '1'. i - dice1 because we are going up and i decreases.
				array[i][j] = ' '; // Old position becomes ' '.
				i -= dice1; // Updating.
			}
			else if (i - dice1 <= 0 && j == 1 && i != 1) // ıt is for going out from array in last part.
			{
				/* Borders again. (array[i][j]) Let's say our i is 3 and our dice is 6. Player 1 has to move i = 1 then dice must be decreased
				(i-j). So , new dice is dice = dice + (j-i). First, we come to edge and didnt exceed the border , after that we normally move on. */
				dice1 = dice1 + j - i; // dice1 = dice 1 -(i-j) // in if there is a j == 1 so j = 1 in every stiuatin if we want to get in this if .
				array[1][j+dice1] = array[i][j]; // Our new position must be '1' .
				array[i][j] = ' '; // Old position becomes ' ';
				printf(" *** PLAYER 1 WON THE GAME ***\n\n");
				printMap(array); // I need this because if player 1 wins , i dont need a dice for player 2.
				break; // I added this break and flag means nothing now but i dont have enough time to remove all flags.
				// Some flags are useless.
				flag++;  // flag++ so that I broke the while(flag==0) and program finishes.
				// Parts before this one , i made i or j = something to program understand where player at but now , i dont need that because game finished.
			} 
			dice2 = enter(whichplayer); // Player 1 starts then player 2 takes a dice.	 // returns dice
			if (j2 + dice2 < 27 && j2 != 26 && i2 == 3 && player2check == 0) // You have to move in borders , it is the first part of Player 2.
			{
				if (array[i2][j2 + dice2] != 'X') // If it isn t a penalty , move on.
				{
					array[i2][j2 + dice2] = array[i2][j2];  // New position becomes the old which is '1'.
					array[i2][j2] = ' ';  // And the old position becomes ' '
					j2 += dice2; // Updating.
				}
				else
				{
					array[i2][j2 + dice2 - 2] = array[i2][j2];   // Coming back .
					if ( j2 + dice2 - 2 != j2 )  // If dice is 2 , dont make the old position ' ', because we will go back there due to penalty.
						array[i2][j2] = ' ';
					j2 += dice2 - 2; // Updating. 
					printf("Penalty for Player %d\n",whichplayer); // Penalty error for players.
				}
			}
			else if(j2+dice2 >= 27 && j2 != 26 && i2 == 3)
			{
			/* This part is for when our players exceed the borders. When they exceed the borders, I rearranged their dice and positions.
			We have [15][30] array our border is 27 for player 2. , player 2 has to stop at array[i2][j2]>= j2 = 26.
			so if player is at array[][25] and dice is 6, player has to move 1 right and 5 down so our new dice must be 5. So that,
			If we add dice with our position (array[][j2] here j2 ) j2 - 26(we have to stop here) >= dice + (j -26) 
			It will be our new dice then I assume we came to j = 26 and our i increases and we don't exceed the borders and 
			move on properly. Then I make equal our j = 26 so that program understand where my player at and can contunie on. (array[][j2] here j2 )
			And also i2 == 3 and j!= 26 because only we exceed borders in i = 3 and j != 26 because if j = 26 everything is okay.
			*/
				dice2 = j2 + dice2 - 26; // Updating my dice.
				if(array[i2+dice2][26] != 'X') // If it isn t a penalty , move on.
				{	
					array[i2+dice2][26] = array[i2][j2];  // My new position becomes '2'
					array[i2][j2] = ' '; // and my last becomes ' '
					j2 = 26; // I'm doing this so that my program understands where is my player at , which column our player at.
					i2+=dice2; // Updating ..
				}
				else
				{  // There is a X close to border , sometimes my player 2 takes a penalty in second part. But this X s location is 5 26 when player comes back 2
					// players new location becomes 3 26.
					array[3][26] = '2'; // 3 26 becomes '2'
					array[i2][j2] = ' '; // old position becomes ' '
					j2=26; // I'm doing this so that my program understands where is my player at , which column our player at.
				}
			}
			else if (j2 == 26 && i2 + dice2 < 12 && i2 != 11)
			{
				if (array[i2 + dice2][j2] != 'X') // If it isn t a penalty , move on.
				{
					array[i2 + dice2][j2] = array[i2][j2];  // New position becomes the old which is '2'.
					array[i2][j2] = ' '; // old position becomes ' '
					i2 += dice2; // Updating
				}
				else
				{
					array[i2 + dice2 - 2][j2] = array[i2][j2];  // Coming back .
					if (i2 + dice2 - 2 != i2)   // If dice is 2 , dont make the old position ' ', because we will go back there due to penalty.
						array[i2][j2] = ' ';
					i2 += dice2 - 2;  // Updating.
					printf("Penalty for Player %d\n",whichplayer);  // Penalty error for players.
				} 
				player2check++; // I have to increment this flag somewhere so i chose this part.
			}
			else if(i2+dice2 >= 12 && i2 != 11 && j2 == 26)
			{
			/* Borders again. (array[i2][j2]) Let's say our i2 is 10 and our dice is 6. Player 1 has to move i2 = 11 then dice must be decreased
				11 - i2. So , new dice is dice2 = dice2 + (i2 - 11). First, we come to edge and didnt exceed the border , after that we normally move on. */
				dice2 = i2 + dice2 - 11;
				array[11][j2-dice2] = array[i2][j2];  // But we went to left so our j2 must be decreased. (array[][j])
				array[i2][j2] = ' '; // old position becomes ' '
				i2 = 11;  // I'm doing this so that my program understands where is my player at , which row our player at.
				j2 -= dice2;  // Updating
			}
			else if (i2 == 11 && j2 - dice2 > 2 && j2 != 3)
			{
				if (array[i2][j2 - dice2] != 'X')    // If it isn t a penalty , move on.
				{
					array[i2][j2 - dice2] = array[i2][j2]; // new position becomes '2'
					array[i2][j2] = ' '; // old position becomes ' '
					j2 -= dice2; // updating
				}
				else
				{
					array[i2][j2 - dice2 + 2] = array[i2][j2];  // Coming back .
					if (j2 - dice2 + 2 != j2)  // If dice is 2 , dont make the old position ' ', because we will go back there due to penalty.
						array[i2][j2] = ' ';
					j2 += 2 - dice2; // Updating
					printf("Penalty for Player %d\n",whichplayer); // penalty errors
				}
			}
			else if ( j2 - dice2 <= 2 && j2 != 3 && i2 == 11)
			{
				/* Borders again. (array[i2][j2]) Let's say our j2 is 5 and our dice is 6. Player 1 has to move j2 = 3 then dice must be decreased
				j2 - 3. So , new dice is dice2 = dice2 - (j2 - 3). First, we come to edge and didnt exceed the border , after that we normally move on. */
				dice2 = dice2 -(j2-3); // updating the dice
				array[i2-dice2][3] = array[i2][j2]; // i - dice 2 becauese we are going up and i decreases.
				array[i2][j2] = ' '; // old position becomes ' '
				j2 = 3; // it is for our program, our program understands which column our player at with this.
				i2 -= dice2; // updating the dice.
			}
			else if (i2 - dice2 == 4 && j2 == 3)
			{
				array[i2 - dice2][j2] = array[i2][j2]; // Our new position must be '2' which is our last.
				array[i2][j2] = ' '; // And the old position becomes ' '
				printf(" *** PLAYER 2 WON THE GAME ***\n\n");
				flag++;  // flag++ so that I broke the while(flag==0) and program finishes.
			}
			else if (i2 - dice2 == 3 && j2 == 3)
			{
				array[i2 - dice2][j2] = array[i2][j2]; // Our new position must be '2' which is our last.
				array[i2][j2] = ' '; // And the old position becomes ' '
				printf(" *** PLAYER 2 WON THE GAME ***\n\n");
				flag++;  // flag++ so that I broke the while(flag==0) and program finishes.				
			} 
			else if (i2 - dice2 > 4 && j2 == 3)
			{
				array[i2 - dice2][j2] = array[i2][j2];  // New position becomes the old which is '1'. i2 - dice2 because we are going up and i2 decreases.
				array[i2][j2] = ' '; // old position ecomes ' '
				i2 -= dice2; // updating .
			}
			else if (i2 - dice2 <= 2 && j2 == 3 && i2 != 3)
			{
				/* Borders again. (array[i][j]) Let's say our i2 is 5 and our dice is 5. Player 1 has to move i2 = 3 then dice must be decreased
				(i2-j2). So , new dice is dice = dice + (j2-i2). First, we come to edge and didnt exceed the border , after that we normally move on. */
				dice2 = dice2 + j2 - i2; // updating the dice
				array[3][j2+dice2] = array[i2][j2]; // new position becomes '2' which is our last.
				array[i2][j2] = ' '; // old position becomes ' '
				printf(" *** PLAYER 2 WON THE GAME ***\n\n");
				flag++;  // flag++ so that I broke the while(flag==0) and program finishes.
				// Parts before this one , i made i or j = something to program understand where player at but now , i dont need that because game finished.
			}
			printMap(array);
			/* Player 1 started so i dont have breaks in player2 because if player 2 wins when player 1 
			started, flag++ will happen and in the end map will be printed then while stops. */
		}
		else // I dont have so many comments here because everything is same with above , just player 2 starts. I added necessary ones.
		{
			dice2 = enter(who); // returns dice
			if (j2 + dice2 < 27 && j2 != 26 && i2 == 3 && player2check == 0) // You have to move in borders , it is the first part of Player 2.
			{
				if (array[i2][j2 + dice2] != 'X') // If it isn t a penalty , move on.
				{
					array[i2][j2 + dice2] = array[i2][j2];  // New position becomes the old which is '1'.
					array[i2][j2] = ' ';  // And the old position becomes ' '
					j2 += dice2; // Updating.
				}
				else
				{
					array[i2][j2 + dice2 - 2] = array[i2][j2];   // Coming back .
					if ( j2 + dice2 - 2 != j2 )  // If dice is 2 , dont make the old position ' ', because we will go back there due to penalty.
						array[i2][j2] = ' ';
					j2 += dice2 - 2; // Updating. 
					printf("Penalty for Player %d\n",whichplayer); // Penalty error for players.
				}
			}
			else if(j2+dice2 >= 27 && j2 != 26 && i2 == 3)
			{
			/* This part is for when our players exceed the borders. When they exceed the borders, I rearranged their dice and positions.
			We have [15][30] array our border is 27 for player 2. , player 2 has to stop at array[i2][j2]>= j2 = 26.
			so if player is at array[][25] and dice is 6, player has to move 1 right and 5 down so our new dice must be 5. So that,
			If we add dice with our position (array[][j2] here j2 ) j2 - 26(we have to stop here) >= dice + (j -26) 
			It will be our new dice then I assume we came to j = 26 and our i increases and we don't exceed the borders and 
			move on properly. Then I make equal our j = 26 so that program understand where my player at and can contunie on. (array[][j2] here j2 )
			And also i2 == 3 and j!= 26 because only we exceed borders in i = 3 and j != 26 because if j = 26 everything is okay.
			*/
				dice2 = j2 + dice2 - 26; // Updating my dice.
				if(array[i2+dice2][26] != 'X') // If it isn t a penalty , move on.
				{	
					array[i2+dice2][26] = array[i2][j2];  // My new position becomes '2'
					array[i2][j2] = ' '; // and my last becomes ' '
					j2 = 26; // I'm doing this so that my program understands where is my player at , which column our player at.
					i2+=dice2; // Updating ..
				}
				else
				{  // There is a X close to border , sometimes my player 2 takes a penalty in second part. But this X s location is 5 26 when player comes back 2
					// players new location becomes 3 26.
					array[3][26] = '2'; // 3 26 becomes '2'
					array[i2][j2] = ' '; // old position becomes ' '
					j2=26; // I'm doing this so that my program understands where is my player at , which column our player at.
				}
			}
			else if (j2 == 26 && i2 + dice2 < 12 && i2 != 11)
			{
				if (array[i2 + dice2][j2] != 'X') // If it isn t a penalty , move on.
				{
					array[i2 + dice2][j2] = array[i2][j2];  // New position becomes the old which is '2'.
					array[i2][j2] = ' '; // old position becomes ' '
					i2 += dice2; // Updating
				}
				else
				{
					array[i2 + dice2 - 2][j2] = array[i2][j2];  // Coming back .
					if (i2 + dice2 - 2 != i2)   // If dice is 2 , dont make the old position ' ', because we will go back there due to penalty.
						array[i2][j2] = ' ';
					i2 += dice2 - 2;  // Updating.
					printf("Penalty for Player %d\n",whichplayer);  // Penalty error for players.
				} 
				player2check++; // I have to increment this flag somewhere so i chose this part.
			}
			else if(i2+dice2 >= 12 && i2 != 11 && j2 == 26)
			{
			/* Borders again. (array[i2][j2]) Let's say our i2 is 10 and our dice is 6. Player 1 has to move i2 = 11 then dice must be decreased
				11 - i2. So , new dice is dice2 = dice2 + (i2 - 11). First, we come to edge and didnt exceed the border , after that we normally move on. */
				dice2 = i2 + dice2 - 11;
				array[11][j2-dice2] = array[i2][j2];  // But we went to left so our j2 must be decreased. (array[][j])
				array[i2][j2] = ' '; // old position becomes ' '
				i2 = 11;  // I'm doing this so that my program understands where is my player at , which row our player at.
				j2 -= dice2;  // Updating
			}
			else if (i2 == 11 && j2 - dice2 > 2 && j2 != 3)
			{
				if (array[i2][j2 - dice2] != 'X')    // If it isn t a penalty , move on.
				{
					array[i2][j2 - dice2] = array[i2][j2]; // new position becomes '2'
					array[i2][j2] = ' '; // old position becomes ' '
					j2 -= dice2; // updating
				}
				else
				{
					array[i2][j2 - dice2 + 2] = array[i2][j2];  // Coming back .
					if (j2 - dice2 + 2 != j2)  // If dice is 2 , dont make the old position ' ', because we will go back there due to penalty.
						array[i2][j2] = ' ';
					j2 += 2 - dice2; // Updating
					printf("Penalty for Player %d\n",whichplayer); // penalty errors
				}
			}
			else if ( j2 - dice2 <= 2 && j2 != 3 && i2 == 11)
			{
				/* Borders again. (array[i2][j2]) Let's say our j2 is 5 and our dice is 6. Player 1 has to move j2 = 3 then dice must be decreased
				j2 - 3. So , new dice is dice2 = dice2 - (j2 - 3). First, we come to edge and didnt exceed the border , after that we normally move on. */
				dice2 = dice2 -(j2-3); // updating the dice
				array[i2-dice2][3] = array[i2][j2]; // i - dice 2 becauese we are going up and i decreases.
				array[i2][j2] = ' '; // old position becomes ' '
				j2 = 3; // it is for our program, our program understands which column our player at with this.
				i2 -= dice2; // updating the dice.
			}
			else if (i2 - dice2 == 4 && j2 == 3)
			{
				array[i2 - dice2][j2] = array[i2][j2]; // Our new position must be '2' which is our last.
				array[i2][j2] = ' '; // And the old position becomes ' '
				printf(" *** PLAYER 2 WON THE GAME ***\n\n");
				printMap(array); // I need this because if player 1 wins , i dont need a dice for player 2.
				break; // I added this break and flag means nothing now but i dont have enough time to remove all flags.
				// Some flags are useless.
				flag++;  // flag++ so that I broke the while(flag==0) and program finishes.
			}
			else if (i2 - dice2 == 3 && j2 == 3)
			{
				array[i2 - dice2][j2] = array[i2][j2]; // Our new position must be '2' which is our last.
				array[i2][j2] = ' '; // And the old position becomes ' '
				printf(" *** PLAYER 2 WON THE GAME ***\n\n");
				printMap(array); // I need this because if player 1 wins , i dont need a dice for player 2.
				break; // I added this break and flag means nothing now but i dont have enough time to remove all flags.
				// Some flags are useless.
				flag++;  // flag++ so that I broke the while(flag==0) and program finishes.				
			} 
			else if (i2 - dice2 > 4 && j2 == 3)
			{
				array[i2 - dice2][j2] = array[i2][j2];  // New position becomes the old which is '1'. i2 - dice2 because we are going up and i2 decreases.
				array[i2][j2] = ' '; // old position ecomes ' '
				i2 -= dice2; // updating .
			}
			else if (i2 - dice2 <= 2 && j2 == 3 && i2 != 3)
			{
				/* Borders again. (array[i][j]) Let's say our i2 is 5 and our dice is 5. Player 1 has to move i2 = 3 then dice must be decreased
				(i2-j2). So , new dice is dice = dice + (j2-i2). First, we come to edge and didnt exceed the border , after that we normally move on. */
				dice2 = dice2 + j2 - i2; // updating the dice
				array[3][j2+dice2] = array[i2][j2]; // new position becomes '2' which is our last.
				array[i2][j2] = ' '; // old position becomes ' '
				printf(" *** PLAYER 2 WON THE GAME ***\n\n");
				printMap(array); // I need this because if player 1 wins , i dont need a dice for player 2.
				break; // I added this break and flag means nothing now but i dont have enough time to remove all flags.
				// Some flags are useless.
				flag++;  // flag++ so that I broke the while(flag==0) and program finishes.
				// Parts before this one , i made i or j = something to program understand where player at but now , i dont need that because game finished.
			}
			
			dice1 = enter(whichplayer);
			if (j + dice1 < 29 && j != 28 && i == 1 && finishcheck == 0)
			{
				if (array[i][j + dice1] != 'X')  // If it isn t a penalty , move on.
				{
					array[i][j + dice1] = array[i][j];
					array[i][j] = ' ';
					j += dice1;
				}
				else
				{
					array[i][j + dice1 - 2] = array[i][j];
					if ( j + dice1 - 2 != j )
						array[i][j] = ' ';
					j += dice1 - 2;
					printf("Penalty for Player %d\n",whichplayer);
				}
			}
			else if(j+dice1 >= 29 && j != 28 && i == 1)
			{
				/* This part is for when our players exceed the borders. When they exceed the borders, i rearranged their dice and positions.
			We have [15][30] array our border is 29 , player 1 has to stop at array[i][j]>= j = 28
			so if player is at array[][25] and dice is 6, player has to move 3 right and 3 down so our new dice must be 3. So that,
			If we add dice with our position (array[][j] here j ) j - 28(we have to stop here) >= dice + (j -28) 
			It will be our new dice then I assume we came to j = 28 and our i increases and we don't exceed the borders and 
			move on properly. Then I make equal our j = 28 so that program understand where my player at and can contunie on. (array[][j] here j )
			*/
				dice1 = j + dice1 - 28;
				array[i+dice1][28] = array[i][j];
				array[i][j] = ' ';
				j = 28;
				i+=dice1;
				finishcheck++;
			}
			else if (j == 28 && i + dice1 < 14 && i != 13)
			{
				if (array[i + dice1][j] != 'X')  // If it isn t a penalty , move on.
				{
					array[i + dice1][j] = array[i][j];
					array[i][j] = ' ';
					i += dice1;
				}
				else
				{
					array[i + dice1 - 2][j] = array[i][j];
					if (i + dice1 - 2 != i)
						array[i][j] = ' ';
					i += dice1 - 2;
					printf("Penalty for Player %d\n",whichplayer);
				} 
			}
			else if(i+dice1 >= 14 && i != 13 && j == 28)
			{
				dice1 = i + dice1 - 13;
				array[13][j-dice1] = array[i][j];
				array[i][j] = ' ';
				i = 13;
				j -= dice1;
				
			}
			else if (i == 13 && j - dice1 > 0 && j != 1)
			{
				if (array[i][j - dice1] != 'X')  // If it isn t a penalty , move on.
				{
					array[i][j - dice1] = array[i][j];
					array[i][j] = ' ';
					j -= dice1;
				}
				else
				{
					array[i][j - dice1 + 2] = array[i][j];
					if (j - dice1 + 2 != j)
						array[i][j] = ' ';
					j += 2 - dice1;
					printf("Penalty for Player %d\n",whichplayer);
				}
			}
			else if ( j - dice1 <= 0 && j != 1 && i == 13)
			{
				dice1 = dice1 -j + 1;
				array[i-dice1][1] = array[i][j];
				array[i][j] = ' ';
				j = 1;
				i -= dice1;
			}
			else if (i - dice1 == 2 && j == 1)
			{
				array[i - dice1][j] = '1';
				array[i][j] = ' ';
				printf(" *** PLAYER 1 WON THE GAME ***\n\n");
				flag++;
			}
			else if (i - dice1 == 1 && j == 1)
			{
				array[i - dice1][1] = '1';
				array[i][j] = ' ';
				printf(" *** PLAYER 1 WON THE GAME ***\n\n");
				flag++;
			} 
			else if (i - dice1 > 2 && j == 1)
			{
				array[i - dice1][j] = array[i][j];
				array[i][j] = ' ';
				i -= dice1;
			}
			else if (i - dice1 <= 0 && j == 1 && i != 1)
			{
				dice1 = dice1 + j - i;
				array[1][j+dice1] = array[i][j];
				array[i][j] = ' ';
				printf(" *** PLAYER 1 WON THE GAME ***\n\n");
				flag++;
			} 
			printMap(array);
		}
	}
}

int main()
{
	srand(time(NULL));
	makearray();
	printMap(array);
	letsplay(startGame()); // sending start games result to this function as a parameter
	return 0;
}