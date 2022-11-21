#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define WORDCOUNT 50 // we have 50 words
#define WORDSIZE 6   // max 5 letteR
#define RANDCOUNT 7  // we need 7 words for board
#define AREA 15      // board is 15*15 2d array

// This function fill a string array with words from the list
void takingwordlisttoarray(char array[WORDCOUNT][WORDSIZE])
{
    FILE *fp;
    fp = fopen("wordlist.txt", "r"); // Openning
    int i;
    for (i = 0; i < 50, !(feof(fp)); i++) // read until the end of file
        fscanf(fp, "%s", array[i]);       // fill the string array
    fclose(fp);
}
/*This function is for controlling the same words. */
int forrandomwords(int array[RANDCOUNT])
{
    int random = 0;
    while (1)
    {
        random = rand() % 50;
        if (array[random] != -1) // My array is filled with numbers 0-49 , both is included, there is no -1
        {
            array[random] = -1; // When you found a random number , i make array[random] = -1 , it is for checking.
            return random;      // Returning the random number which i found
        }
        else                      // If array[random] == -1 it means you found a random number which is found previously
            random = rand() % 50; // That s why you take a new random number
    }
    return 0;
}

// This function fills a string array with random words
void randomwords(char arr[WORDCOUNT][WORDSIZE], char barr[RANDCOUNT][WORDSIZE])
{
    int try[WORDCOUNT]; // It is going to be used for controlling the same words
    int a = 0;
    for (a = 0; a < WORDCOUNT; a++)
        try[a] = a; // Filling the array with 0-49, both included.
    int random = 0;
    int i = 0;
    for (i = 0; i < RANDCOUNT; i++) // we need 7 random words
    {
        random = forrandomwords(try); // random numbers
        strcpy(barr[i], arr[random]); // copying .
    }
}
void printarray(char array[][WORDSIZE], int howmany) // it is for seeing my words, it was a checking for earlier stage of code
{
    for (int i = 0; i < howmany; i++)
        printf("%s\n", array[i]);
}

void printboard(char array[AREA][AREA]) // printing the board...
{
    for (int i = 0; i < AREA; i++)
    {
        for (int j = 0; j < AREA; j++)
            printf("%c ", array[i][j]);
        printf("\n");
    }
}

int choosingtheword(int array[RANDCOUNT]) // ıt is for random words which will be put in board
{
    int random = 0;
    while (1)
    {
        random = rand() % 7;
        if (array[random] != -1) // My array is filled with numbers 0-7 , both is included, there is no -1
        {
            array[random] = -1; // When you found a random number , i make array[random] = -1 , it is for checking.
            return random;      // Returning the random number which i found
        }
        else                     // If array[random] == -1 it means you found a random number which is found previously
            random = rand() % 7; // That s why you take a new random number
    }
    return 0;
}

void buildingtheboard(char randwords[RANDCOUNT][WORDSIZE], char board[AREA][AREA])
{
    int array[RANDCOUNT] = {0, 1, 2, 3, 4, 5, 6}; // it is for choosing the random words and checking if they are equal
    int i = 0, j = 0;
    for (i = 0; i < AREA; i++)
    {
        for (j = 0; j < AREA; j++)
            board[i][j] = '+';
        // filling wih + because im going to check them after some operations
    }
    int random = 0;
    int whichrow = 0; // starting position of my word
    int whichcolumn = 0;  // starting position of my word
    int temprow = 0; // It will be equal to whichrow at the first , for writting the word, i will increase this
    int tempcolumn = 0; //  It will be equal to whichcolumn at the first , for writting the word, i will increase this
    int validlength = 0; // for checking the lenght of word
    int whichword = 0; // it will became the word i chose
    int lengthofword = 0; // you can see
    int allareset = 0; // if it becomes 7 it is okay
    while (1)
    {
        random = rand() % 8; // random writing situation, normal or backward etc
        switch (random)
        {
        case 0:                                 // like this : normal
            whichword = choosingtheword(array); // choosing the word.
            printf("word is = %s\n",randwords[whichword]); // it is for seeing the word
            lengthofword = strlen(randwords[whichword]); // taking the length of word
            while (1)
            {
                whichcolumn = rand() % 15; // taking random column and row
                whichrow = rand() % 15;
                if (whichcolumn <= 15 - lengthofword) // If i want to fit the word into board, i have to check boundaries
                {
                    temprow = whichrow;
                    tempcolumn = whichcolumn;
                    validlength = 0; // if it can't fit the word , it must be 0 again because if i don't do this , writes on another words

                    /* The word is meal, 4 letters, length of it is 4. We found a place which is row is 0 column is 13. we have two space our validlength became 2
                    but we cant put our word here because we passed the boundaries. Our validlength is still 2 . If we don't make it 0 , it will find a new place
                    which has for example row 5 , column 3. It will count 2 space , validlength will be 4. And program will say it is okay, i can put the word
                    but if you have another word there let's say food, our word(meal) will be overwritten on that word(food). 
                    food is row 5, column 5 let's assume. +++mealod it will be like this. Because I only looked '+' characters , i solved it with making validlength 0.
                    If it can't put the word, validlength will be 0 and program will look another place which has 4 space for meal. I hope i could explain how it works. */

                    while (board[temprow][tempcolumn] == '+' && validlength < lengthofword) // If validlenght is equal to length of the word, it will say, okay we can put it here
                    {
                        validlength++; // If it increases, tempcolumn must increase too because i'm looking a space(actually '+') for my word.
                        tempcolumn += 1;
                    }

                    if (validlength == lengthofword) // If they are same ...
                    {
                        printf("ROW : %d    COLUMN : %d\n", whichrow, whichcolumn); //starting positions of the word, it is for finding easily 
                        for (int a = 0; a < lengthofword; a++, whichcolumn++) // we are writing from left to right so column has to increase.
                            board[whichrow][whichcolumn] = randwords[whichword][a]; // Putting the letters.
                        allareset++; // if it is put correctly into board, it is incrased for checking the count of words
                        break;
                    }
                }
            }
            break;
        case 1:                                 // like this : lamron , it s back
            whichword = choosingtheword(array); 
            printf("word is = %s\n",randwords[whichword]);
            lengthofword = strlen(randwords[whichword]);
            while (1)
            {
                whichcolumn = rand() % 15;
                whichrow = rand() % 15;
                if (0 <= whichcolumn - lengthofword) // If i want to fit the word into board, i have to check boundaries
                {
                    temprow = whichrow;
                    tempcolumn = whichcolumn;
                    validlength = 0;
                    while (board[temprow][tempcolumn] == '+' && validlength < lengthofword)
                    {
                        validlength++;
                        tempcolumn -= 1;
                    }
                    if (validlength == lengthofword)
                    {
                        printf("ROW : %d    COLUMN : %d\n", whichrow, whichcolumn); //starting positions of the word, it is for finding easily
                        for (int a = 0; a < lengthofword; a++, whichcolumn--)
                            board[whichrow][whichcolumn] = randwords[whichword][a]; // Putting the letters.
                        allareset++; // if it is put correctly into board, it is incrased for checking the count of words
                        break; 
                    }
                }
            }
            break;
        case 2:                                 // top to bottom normally
            whichword = choosingtheword(array);
            printf("word is = %s\n",randwords[whichword]);
            lengthofword = strlen(randwords[whichword]);
            while (1)
            {
                whichcolumn = rand() % 15;
                whichrow = rand() % 15;
                validlength = 0;
                if (whichrow <= 15 - lengthofword) // If i want to fit the word into board, i have to check boundaries
                {
                    temprow = whichrow;
                    tempcolumn = whichcolumn;
                    validlength = 0;
                    while (board[temprow][tempcolumn] == '+' && validlength < lengthofword)
                    {
                        validlength++;
                        temprow += 1; // now , column is same but row will change because top to bottom
                    }
                    if (validlength == lengthofword)
                    {
                        printf("ROW : %d    COLUMN : %d\n", whichrow, whichcolumn); //starting positions of the word, it is for finding easily
                        for (int a = 0; a < lengthofword; a++, whichrow++) // row is increasing because top to bottom
                            board[whichrow][whichcolumn] = randwords[whichword][a]; // Putting the letters.
                        allareset++; // if it is put correctly into board, it is incrased for checking the count of words
                        break;
                    }
                }
            }
            break;
        case 3:                                 // bottom to top ,  backwards
            whichword = choosingtheword(array); 
            printf("word is = %s\n",randwords[whichword]);
            lengthofword = strlen(randwords[whichword]);
            while (1)
            {
                whichcolumn = rand() % 15;
                whichrow = rand() % 15;
                validlength = 0;
                if (0 <= whichrow - lengthofword) // If i want to fit the word into board, i have to check boundaries
                {
                    temprow = whichrow;
                    tempcolumn = whichcolumn;
                    validlength = 0;
                    while (board[temprow][tempcolumn] == '+' && validlength < lengthofword)
                    {
                        validlength++;
                        temprow -= 1;  // now , column is same but row will change because bottom to top
                    }
                    if (validlength == lengthofword)
                    {
                        printf("ROW : %d    COLUMN : %d\n", whichrow, whichcolumn); //starting positions of the word, it is for finding easily
                        for (int a = 0; a < lengthofword; a++, whichrow--) // row is decreasing because bottom to top
                            board[whichrow][whichcolumn] = randwords[whichword][a]; // Putting the letters.
                        allareset++; // if it is put correctly into board, it is incrased for checking the count of words
                        break;
                    }
                }
            }
            break;
        case 4:                                // right diagonal top to bottom
            whichword = choosingtheword(array); 
            printf("word is = %s\n",randwords[whichword]);
            lengthofword = strlen(randwords[whichword]);
            while (1)
            {
                whichcolumn = rand() % 15;
                whichrow = rand() % 15;
                validlength = 0;
                if (whichcolumn <= 15 - lengthofword && whichrow <= 15 - lengthofword) // If i want to fit the word into board, i have to check boundaries
                {
                    temprow = whichrow;
                    tempcolumn = whichcolumn;
                    validlength = 0;
                    while (board[temprow][tempcolumn] == '+' && validlength < lengthofword)
                    {
                        validlength++;
                        temprow += 1;  // both are increases because we go right and down
                        tempcolumn += 1;
                    }
                    if (validlength == lengthofword)
                    {
                        printf("ROW : %d    COLUMN : %d\n", whichrow, whichcolumn); //starting positions of the word, it is for finding easily
                        for (int a = 0; a < lengthofword; a++, whichrow++, whichcolumn++)
                            board[whichrow][whichcolumn] = randwords[whichword][a]; // Putting the letters.
                        allareset++; // if it is put correctly into board, it is incrased for checking the count of words
                        break;
                    }
                }
            }
            break;
        case 5:                             // right diagonal bottom to up                         
            whichword = choosingtheword(array); 
            printf("word is = %s\n",randwords[whichword]);
            lengthofword = strlen(randwords[whichword]);
            while (1)
            {
                whichcolumn = rand() % 15;
                whichrow = rand() % 15;
                validlength = 0;
                if (0 <= whichcolumn - lengthofword && 0 <= whichrow - lengthofword) // If i want to fit the word into board, i have to check boundaries
                {
                    temprow = whichrow;
                    tempcolumn = whichcolumn;
                    validlength = 0;
                    while (board[temprow][tempcolumn] == '+' && validlength < lengthofword)
                    {
                        validlength++;
                        temprow -= 1;  // both are decreases because we go right and up
                        tempcolumn -= 1;
                    }
                    if (validlength == lengthofword)
                    {
                        printf("ROW : %d    COLUMN : %d\n", whichrow, whichcolumn); //starting positions of the word, it is for finding easily
                        for (int a = 0; a < lengthofword; a++, whichrow--, whichcolumn--)
                            board[whichrow][whichcolumn] = randwords[whichword][a]; // Putting the letters.
                        allareset++; // if it is put correctly into board, it is incrased for checking the count of words
                        break;
                    }
                }
            }
            break;
        case 6:                                //left diagonal top to bottom   
            whichword = choosingtheword(array); 
            printf("word is = %s\n",randwords[whichword]);
            lengthofword = strlen(randwords[whichword]);
            while (1)
            {
                whichcolumn = rand() % 15;
                whichrow = rand() % 15;
                validlength = 0;
                if (0 <= whichcolumn - lengthofword && whichrow <= 15 - lengthofword) // If i want to fit the word into board, i have to check boundaries
                {
                    temprow = whichrow;
                    tempcolumn = whichcolumn;
                    validlength = 0;
                    while (board[temprow][tempcolumn] == '+' && validlength < lengthofword)
                    {
                        validlength++;
                        temprow += 1;  // row increases and column decreases because we go left and down
                        tempcolumn -= 1;
                    }
                    {
                        printf("ROW : %d    COLUMN : %d\n", whichrow, whichcolumn); //starting positions of the word, it is for finding easily
                        for (int a = 0; a < lengthofword; a++, whichrow++, whichcolumn--)
                            board[whichrow][whichcolumn] = randwords[whichword][a]; // Putting the letters.
                        allareset++; // if it is put correctly into board, it is incrased for checking the count of words
                        break;
                    }
                }
            }
            break;
        case 7:                                 // left diagonal bottom to top
            whichword = choosingtheword(array); 
            printf("word is = %s\n",randwords[whichword]);
            lengthofword = strlen(randwords[whichword]);
            while (1)
            {
                whichcolumn = rand() % 15;
                whichrow = rand() % 15;
                validlength = 0;
                if (whichcolumn <= 15 - lengthofword && 0 <= whichrow - lengthofword)  // If i want to fit the word into board, i have to check boundaries
                {
                    temprow = whichrow;
                    tempcolumn = whichcolumn;
                    validlength = 0;
                    while (board[temprow][tempcolumn] == '+' && validlength < lengthofword)
                    {
                        validlength++;
                        temprow -= 1;  // row decreases and column increases because we go left and up 
                        tempcolumn += 1;
                    }
                    if (validlength == lengthofword)
                    {
                        printf("ROW : %d    COLUMN : %d\n", whichrow, whichcolumn); //starting positions of the word, it is for finding easily
                        for (int a = 0; a < lengthofword; a++, whichrow--, whichcolumn++)
                            board[whichrow][whichcolumn] = randwords[whichword][a]; // Putting the letters.
                        allareset++; // if it is put correctly into board, it is incrased for checking the count of words
                        break;
                    }
                }
            }
            break;
        }
        if (allareset == 7) // If all 7 words is put, break the loop
            break;
    }
    for (i = 0; i < AREA; i++)
    {
        for (j = 0; j < AREA; j++)
        {
            if (board[i][j] == '+')             // I put my words on board, now i m making '+' s a random letter
                board[i][j] = 97 + rand() % 26; // 97 + [0-25] (both included) ascii of lowercase letters
        }
    }
}
/* */
int searchnormal(char board[AREA][AREA], int row, int column, char word[20])
{
    // if this function coulndt find the word it will return 0 , if it finds , it will return 1
    /*This function will search the area which has lenght of words lenght */
    int temprow = row, tempcolumn = column, i = 0; // I need temprow and column because row and column will change
    int start;
    int length = strlen(word);
    for (start = 0; column <= 14, word[start] != '\0'; column++, start++) // column increases because we go left to right
    {
        if (board[row][column] != word[start])
            return 0; // If there is a different letter from our word, return 0
    }
    while (i < length) // until i becomes length , replace the lettters with a 'x'
    {
        board[temprow][tempcolumn] = 'x';
        tempcolumn++;
        i++;
    }
    return 1; // If the word is found and replaced all of it s letters with x's , return 1
}

int searchbackwardnormal(char board[AREA][AREA], int row, int column, char word[20])
{
    // if this function coulndt find the word it will return 0 , if it finds , it will return 1
    int temprow = row, tempcolumn = column, i = 0;  // I need temprow and column because row and column will change
    int start;
    int length = strlen(word);
    for (start = 0; column >= 0, word[start] != '\0'; column--, start++) // column decreases because we go right to left
    {
        if (board[row][column] != word[start])
            return 0;  // If there is a different letter from our word, return 0
    }
    while (i < length)  // until i becomes length , replace the lettters with a 'x'
    {
        board[temprow][tempcolumn] = 'x';
        tempcolumn--;
        i++;
    }
    return 1; // If the word is found and replaced all of it s letters with x's , return 1
}

int searchtoptobottom(char board[AREA][AREA], int row, int column, char word[20])
{
    // if this function coulndt find the word it will return 0 , if it finds , it will return 1
    int temprow = row, tempcolumn = column, i = 0;  // I need temprow and column because row and column will change
    int start;
    int length = strlen(word);
    for (start = 0; row <= 14, word[start] != '\0'; row++, start++) // row increases because we go down
    {
        if (board[row][column] != word[start])
            return 0;  // If there is a different letter from our word, return 0
    }
    while (i < length)  // until i becomes length , replace the lettters with a 'x'
    {
        board[temprow][tempcolumn] = 'x';
        temprow++;
        i++;
    }
    return 1; // If the word is found and replaced all of it s letters with x's , return 1
}

int searchbottomtotop(char board[AREA][AREA], int row, int column, char word[20])
{
    // if this function coulndt find the word it will return 0 , if it finds , it will return 1
    int temprow = row, tempcolumn = column, i = 0;  // I need temprow and column because row and column will change
    int start;
    int length = strlen(word);
    for (start = 0; row >= 0, word[start] != '\0'; row--, start++)  // row decreases because we go up
    {
        if (board[row][column] != word[start])
            return 0;  // If there is a different letter from our word, return 0
    }
    while (i < length)  // until i becomes length , replace the lettters with a 'x'
    {
        board[temprow][tempcolumn] = 'x';
        temprow--;
        i++;
    }
    return 1;  // If the word is found and replaced all of it s letters with x's , return 1
}

int searchrightdiagonaltoptobottom(char board[AREA][AREA], int row, int column, char word[20])
{
    // if this function coulndt find the word it will return 0 , if it finds , it will return 1
    int temprow = row, tempcolumn = column, i = 0;  // I need temprow and column because row and column will change
    int start;
    int length = strlen(word);
    for (start = 0; column <= 14, row <= 14, word[start] != '\0'; row++, column++, start++)  // both are increases because we go right and down
    {
        if (board[row][column] != word[start])
            return 0;  // If there is a different letter from our word, return 0
    }
    while (i < length)   // until i becomes length , replace the lettters with a 'x'
    {
        board[temprow][tempcolumn] = 'x';
        temprow++;
        tempcolumn++;
        i++;
    }
    return 1; // If the word is found and replaced all of it s letters with x's , return 1
}

int searchrightdiagonalbottomtotop(char board[AREA][AREA], int row, int column, char word[20])
{
    // if this function coulndt find the word it will return 0 , if it finds , it will return 1
    int temprow = row, tempcolumn = column, i = 0;  // I need temprow and column because row and column will change
    int start;
    int length = strlen(word);
    for (start = 0; column >= 0, row >= 0, word[start] != '\0'; row--, column--, start++)  // both are decreases because we go right and up
    {
        if (board[row][column] != word[start])
            return 0;  // If there is a different letter from our word, return 0
    }
    while (i < length)   // until i becomes length , replace the lettters with a 'x'
    {
        board[temprow][tempcolumn] = 'x';
        temprow--;
        tempcolumn--;
        i++;
    }
    return 1;   // If the word is found and replaced all of it s letters with x's , return 1
}

int searchleftdiagonaltoptobottom(char board[AREA][AREA], int row, int column, char word[20])
{
    // if this function coulndt find the word it will return 0 , if it finds , it will return 1
    int temprow = row, tempcolumn = column, i = 0;  // I need temprow and column because row and column will change
    int start;
    int length = strlen(word);
    for (start = 0; column >= 0, row <= 14, word[start] != '\0'; row++, column--, start++)  // row increases and column decreases because we go left and down
    {
        if (board[row][column] != word[start])
            return 0; // If there is a different letter from our word, return 0
    }
    while (i < length)   // until i becomes length , replace the lettters with a 'x'
    {
        board[temprow][tempcolumn] = 'x';
        temprow++;
        tempcolumn--;
        i++;
    }
    return 1;   // If the word is found and replaced all of it s letters with x's , return 1
}

int searchleftdiagonalbottomtotop(char board[AREA][AREA], int row, int column, char word[20])
{
    // if this function coulndt find the word it will return 0 , if it finds , it will return 1
    int temprow = row, tempcolumn = column, i = 0;  // I need temprow and column because row and column will change
    int start;  
    int length = strlen(word);
    for (start = 0; column <= 14, row >= 0, word[start] != '\0'; row--, column++, start++)  // row decreases and column increases because we go left and up 
    {
        if (board[row][column] != word[start])
            return 0;  // If there is a different letter from our word, return 0
    }
    while (i < length)   // until i becomes length , replace the lettters with a 'x'
    {
        board[temprow][tempcolumn] = 'x';
        temprow--;  
        tempcolumn++;
        i++;
    }
    return 1;   // If the word is found and replaced all of it s letters with x's , return 1
}
/*I took strings for row,column and word. This function turns row and column string to integer.
It is a very simple atoi but of course it  has a lot of differences */
int turningstringtointeger(char array[20])
{
    int i = 0;
    int number = 0;
    // array[i] - '0' means if you have a char which is a number like '2' , when you substract '0' , that char will be integer. '2' - '0' = 2 >- int
    /* Assume that we have "12" string, first element is 1. While we are in in the loop, number = 0(number)*10 + array[0]('1') - '0' , number will be 1.
    now number is 1 and we still have one more char in our string '2' >- number = 1(new number)*10 + array[1] - '0' >- number will be 12 and i will be 2
    array[2] is '\0' so while loop will end and function will return 12(number) */
    while (array[i] != '\0')
    {
        number = number * 10 + array[i] - '0'; 
        i++;
    }
    return number;
}

void letsPlay(char board[AREA][AREA], /*char randwords[RANDCOUNT][WORDSIZE] ,*/ char words[WORDCOUNT][WORDSIZE])
{
    printf("How to play:\n"
           "You have to enter the row,column of the word and the word you found\n"
           "Row and column which you entered of the word must be the starting positions of the word\n"
           "For every word you have found, you will earn 2 points\n"
           "If you make 3 mistakes, the game will be finished and you will lose\n"
           "If you want to quit , you have to write ':q'\n"
           "Good luck!\n");
    char row[20], column[20]; // taking row and column as strings
    int count = 3; // if you give 3 wrong answer game will finish
    int point = 0;  // point of user
    int realrow, realcolumn; // using turningstringtointeger function , my strings (row,column) will be integers and i will attend them to this variables
    int check = 0; // word check
    char word[20]; // our words
    while (count > 0) // IF count is 0 , while loop will end
    {
        if (point != 14) // If you didn't collect all points
        {
            printf("Enter coordinates and word:");
            scanf("%s", row); // it is for checking the exit situation which is ":q"
            if (row[0] != ':' || row[1] != 'q') // If you didn't want to exit...
            {
                scanf("%s %s", column, word); 
                check = 0;
                for (int ke = 0; ke < 50; ke++) // this loop checks if your word is in our wordlist 
                {
                    if (strcmp(word, words[ke]) == 0 && check != 1) // If word is found , we won't enter this if and check will be 1 
                        check++;
                }
                if (check == 1) // If word is found
                {
                    realrow = turningstringtointeger(row); // turning strings to integer
                    realcolumn = turningstringtointeger(column);
                    if (searchnormal(board, realrow, realcolumn, word) == 1) // checking the return of search functions
                    {
                        printf("Founded! You got 2 points. Your total point is: %d\n", point + 2);
                        point += 2;
                        printboard(board);
                    }
                    else if (searchbackwardnormal(board, realrow, realcolumn, word) == 1)  // checking the return of search functions
                    {
                        printf("Founded! You got 2 points. Your total point is: %d\n", point + 2);
                        point += 2;
                        printboard(board);
                    }
                    else if (searchtoptobottom(board, realrow, realcolumn, word) == 1)  // checking the return of search functions
                    {
                        printf("Founded! You got 2 points. Your total point is: %d\n", point + 2);
                        point += 2;
                        printboard(board);
                    }
                    else if (searchbottomtotop(board, realrow, realcolumn, word) == 1)   // checking the return of search functions
                    {
                        printf("Founded! You got 2 points. Your total point is: %d\n", point + 2);
                        point += 2;
                        printboard(board);
                    }
                    else if (searchrightdiagonaltoptobottom(board, realrow, realcolumn, word) == 1)  // checking the return of search functions
                    {
                        printf("Founded! You got 2 points. Your total point is: %d\n", point + 2);
                        point += 2;
                        printboard(board);
                    }
                    else if (searchrightdiagonalbottomtotop(board, realrow, realcolumn, word) == 1)   // checking the return of search functions
                    {
                        printf("Founded! You got 2 points. Your total point is: %d\n", point + 2);
                        point += 2;
                        printboard(board);
                    }
                    else if (searchleftdiagonaltoptobottom(board, realrow, realcolumn, word) == 1)  // checking the return of search functions
                    {
                        printf("Founded! You got 2 points. Your total point is: %d\n", point + 2);
                        point += 2;
                        printboard(board);
                    }
                    else if (searchleftdiagonalbottomtotop(board, realrow, realcolumn, word) == 1)  // checking the return of search functions
                    {
                        printf("Founded! You got 2 points. Your total point is: %d\n", point + 2);
                        point += 2;
                        printboard(board);
                    }
                    else // If none of my search functions return 1 , you will lose count
                    {
                        count--;
                        if (count != 0) 
                        {
                            printf("Wrong choice! You have only %d lefts.\n", count);
                            printboard(board);
                        }
                        else 
                        {
                            printf("Game finished. You have %d points.\n", point);
                            printboard(board);
                        }
                    }
                }

                else // If you enter a word which isn't in our wordlist , if you enter 3 wrong words , game will be finished
                {
                    count--;
                    if (count != 0)
                    {
                        printf("This word is not in our repertoire. You have only %d lefts.\n", count);
                        printboard(board);
                    }
                    else
                    {
                        printf("Game finished. You have %d points.\n", point);
                        printboard(board);
                    }
                }
            }

            else // If you enter ":q" ...
            {
                printf("Game finished. You have %d points.\n", point);
                printboard(board);
                break;
            }
        }

        else // If you found all the words , you will win
        {
            printf("You have won the game. Your point is %d\n", point);
            printboard(board);
            break;
        }
    }
}

int main()
{
    srand(time(NULL));
    char words[WORDCOUNT][WORDSIZE];
    char randwords[RANDCOUNT][WORDSIZE];
    char board[AREA][AREA];
    takingwordlisttoarray(words);
    //printf("Words in randomwords array : \n");
    randomwords(words, randwords);
    printarray(randwords, RANDCOUNT);    // if you want to test are the words put randomly...
    buildingtheboard(randwords, board);
    printboard(board);
    letsPlay(board,words);

    return 0;
}
