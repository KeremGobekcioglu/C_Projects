#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.14
enum shapes{Triangle=1,Quadrilateral,Circle,Pyramid,Cylinder};
enum calculators{Area=1,Perimeter,Volume};

void flush(void)
{/* This function works like fflush , if you enter 1a scanf reads 1 and
    a stays in stdin. This function clears stdin. It takes garbage chars
    which prevent my program */
    int k; 
    do
    {  // Takes chars to an integer , it is like trash bin
        k = getchar();
    }
    while (k != '\n' && k != EOF); // Until the 'enter' (\n) and EOF
}
/* If you want to go to upper menu while you are in 1.Area 2.Perimeter 3.VOlume
0.Exit , enter 7 . */


int select_shape(void)
{
    printf("Welcome to the geometric calculator!\n"
    "Select a shape to calculate:\n---------------\n"
    "1. Triangle\n2. Quadrilateral\n3. Circle\n4. Pyramid\n"
    "5. Cylinder\n0. Exit\n-----------------\n");
    printf("Input :");
    int sel;
    char d;
    if(scanf("%d",&sel) == 1 ) // If it is an integer ...
    {
        d = getchar();
        if ( d == '\n' ||  d == ' ') // If user enters like 1a ,function returns -2.
        {
            if( sel == 0) // If you enter an integer , this parts will work
                return 0; // Exit code
            else if ( sel != Triangle && sel != Quadrilateral && sel != Circle && sel != Pyramid && sel != Cylinder  )    
                return -1; // If user enters an integer another than these enums , i return -1
            return sel;
        }
    }
    else
        flush(); // Clearing the buffer if user enters char
    return -2; // If there is a problem with scanf , if the thing we scanned isn't integer
}

int select_calc(void)
{
    printf("Select calculator:\n-------------\n1. Area\n"
    "2. Perimeter\n3. Volume\n0. Exit\n-----------\n");
    printf("Input: ");
    int sel;
    char d;
    if(scanf("%d",&sel) == 1 )//&& flush() == 1) // If it is an integer ...
    {
    	d = getchar();
        if ( d == '\n' ||  d == ' ') // It is for control the integerchar situations.
        {
            if ( sel == 0 )
                return 0; // Exit code
            else if ( sel == 7) // It is for going upper menu
                return 7;
            else if ( sel != Area && sel != Perimeter && sel != Volume ) 
                return -1;   // If user enters an integer another than these enums , i return -1
            else
                return sel;
        }
    }
    else
        flush(); // Clearing the buffer if user enters char
    return -2; // If there is a problem with scanf , if the thing we scanned isn't an integer or buffer
    // isn't clear
}
/* I have tons of "break"s in my homework, that s because of i couldn't handle some specific char situations so i had
to break the loops and turn the loops again.

 And i need a lot of flush() in my code , that s because of handling the 'a' situations 
which i saw in the pdf. You will enter chars and my program has to work. Flush() clears the buffer , ( i explained it at flush function ) and 
removes the chars. One more thing i have if ( scanf("%f",&a) != 1 ) : it is for you have to enter a float , if you don't program gives error
clears the buffer and breaks the loop and i call this function again.

 Also i have else if( scanf("%f%c",&c,&d) != 2 || d != '\n' )
: it is for : if you enter 1a to third side or radius or the last entry i check this situation and if you enter a char another than enter , i give error , clear the buffer
break the loop and call this function again. ALl of my calc_shape functions works same way so i won't make another comment.
if you enter 1a this scanf("%f%c",&c,&d) will be 2 but d will be a so my prograö will enter this if and make the work i need.

Lastly, i added "1453" situation for going upper menu. If you enter all sides and one of them is 1453 , program will go upper menu.

*/
int calc_triangle(int op)
{
    float a = 1453;
    float b = 1453;
    float c = 1453;
    char d;
    printf("\n\n!!!A little note before you start: If you want to return the upper menu"
    " , enter 1453 for one side!!!\n\n");
    while(1)
    {
        switch(op)
        {
            case Area:
                
                printf("Please enter three sides of Triangle :\n");
                if( scanf("%f",&a) != 1)
                {   
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if( scanf("%f",&b) != 1)
                {    
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if( scanf("%f%c",&c,&d) != 2 || d != '\n' )
                {    
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if(a == (float)1453 || b == (float)1453 || c == (float)1453 ) // 1453 situation
                        return 0;
                else if( a <= 0.0 || b <= 0.0 || c <= 0.0 )
                    printf("ERROR ! Please enter a valid entry.\n");
                else if (  (a+b+c)/2 <= a || (a+b+c)/2 <= b || (a+b+c)/2 <= c)
                    printf("ERROR ! Please enter a valid triangle.\n");
                else if ( a+b <= c || b+c <= a || a+c <= b) 
                    printf("ERROR ! Please enter a valid triangle.\n");
                else
                {
                    double s = (a+b+c)/(double)2;
                    float area= (float)sqrt(s*(s-a)*(s-b)*(s-c));
                    printf("Area of TRIANGLE : %0.2f\n",area);
                }
                break;
            case Perimeter:
            
                printf("Please enter three sides of Triangle :\n");
                if( scanf("%f",&a) != 1)
                {   
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if( scanf("%f",&b) != 1)
                {    
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if( scanf("%f%c",&c,&d) != 2 || d != '\n')
                {    
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if(a == (float)1453 || b == (float)1453 || c == (float)1453) // 1453 situation
                        return 0;
                else if( a <= (float)0 || b <= (float)0 || c <= (float)0 )
                    printf("ERROR ! Please enter a valid entry.\n");
                else if ( (a+b+c)/2 <= a || (a+b+c)/2 <= b || (a+b+c)/2 <= c) // Triangle validation
                    printf("ERROR ! Please enter a valid triangle.\n");
                else if ( a+b <= c || b+c <= a || a+c <= b)
                    printf("ERROR ! Please enter a valid triangle.\n");
                else
                    printf("Perimeter of Triangle : %0.2f\n",(a+b+c));
                break;
            case Volume:
                printf("You can not calculate the volume of Triangle. Please try again.\n");
                return 8; // It is for controlling the volume part in calculate function
        }
    }
    return 1;
}


int calc_quadrilateral(int op)
{
    float a,b,c,d;
    char e;
    printf("\n\n!!!A little note before you start: If you want to return the upper menu"
    " , enter 1453 for one side!!!\n\n");
    while(1)
    {
        switch(op)
        {
            case Area:
                
                printf("Please enter three sides of Quadrilateral :\n");
                if( scanf("%f",&a) != 1)
                {   
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if( scanf("%f",&b) != 1)
                {    
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if( scanf("%f",&c) != 1 )
                {    
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if( scanf("%f%c",&d,&e) != 2 || e != '\n' )
                {    
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if(a == (float)1453 || b == (float)1453 || c == (float)1453 || d ==(float)1453)
                        return 0;
                else if( a <= 0.0 || b <= 0.0 || c <= 0.0 || d <= 0.0 )
                    printf("ERROR ! Please enter a valid entry.\n"); 
                else if (  (a+b+c+d)/2 <= a || (a+b+c+d)/2 <= b || (a+b+c+d)/2 <= c || (a+b+c+d)/2 <= d )
                    printf("ERROR ! Please enter a valid Quadrilateral.\n");
                else
                {
                    double s = (a+b+c+d)/(double)2;
                    float area= (float)sqrt((s-a)*(s-b)*(s-c)*(s-d));
                    printf("Area of QUADRILATERAL : %0.2f\n",area);
                }
                break;
            case Perimeter:
            
                printf("Please enter three sides of Quadrilateral :\n");
                if( scanf("%f",&a) != 1)
                {   
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if( scanf("%f",&b) != 1)
                {    
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if( scanf("%f",&c) != 1 )
                {    
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if( scanf("%f%c",&d,&e) != 2 || e != '\n' )
                {    
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if(a == (float)1453 || b == (float)1453 || c == (float)1453 || d ==(float)1453)
                        return 0;
                else if( a <= 0.0 || b <= 0.0 || c <= 0.0 || d <= 0.0 )
                    printf("ERROR ! Please enter a valid entry.\n"); 
                else if (  (a+b+c+d)/2 <= a || (a+b+c+d)/2 <= b || (a+b+c+d)/2 <= c || (a+b+c+d)/2 <= d )
                    printf("ERROR ! Please enter a valid Quadrilateral.\n"); 
                else
                    printf("Perimeter of QUADRILATERAL : %0.2f\n",(a+b+c+d));
                break;
            case Volume:
                printf("You can not calculate the volume of Quadrilateral. Please try again.\n");
                return 8;  // It is for controlling the volume part in calculate function
        }
    }
    return 1;
}

int calc_circle(int op)
{
    float r;
    char d;
    int a;
    printf("\n\n!!!A little note before you start: If you want to return the upper menu"
    " , enter 1453 for radius!!!\n\n");
    while(1)
    {
        switch(op)
        {
            case Area:
           
                printf("Please enter the radius of circle :\n");
                if( scanf("%f%c",&r,&d) != 2 || d != '\n' )
                {   
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if(r == (float)1453)
                        return 0; 
                else if( r <= 0.0 )
                    printf("ERROR ! Please enter a valid Circle.\n"); 
                else
                {
                    float area= PI*r*r;
                    printf("Area of CIRCLE : %0.2f\n",area);
             	    break;
                }
                break;
            case Perimeter:
            
                printf("Please enter the radius of circle :\n");
                if( scanf("%f%c",&r,&d) != 2 || d != '\n' )
                {   
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if(r == (float)1453)
                        return 0; 
                else if( r <= 0.0 )
                    printf("ERROR ! Please enter a valid Circle.\n"); 
                else
                    printf("Circumference of CIRCLE : %0.2f\n",(float)2*PI*r);
                break;
            case Volume:
                printf("ERROR ! You can not calculate the volume of Circle. Please try again.\n");
                return 8;  // It is for controlling the volume part in calculate function
        }
    } 
    return 1;
}

int calc_pyramid(int op)
{
    float h,l,a;
    float B,L;
    char d;
    printf("\n\n!!!A little note before you start: If you want to return the upper menu"
    " , enter 1453 for slant height or base side!!!\n\n");
    while(1)
    {
        switch(op)
        {
            case Area:
                
                printf("Please enter the base side and slant height of Pyramid :\n");
                if( scanf("%f",&a) != 1)
                {   
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if( scanf("%f%c",&l,&d) != 2 || d != '\n')
                {    
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if(a == (float)1453 || l == (float)1453 )
                        return 0;
                else if( a <= 0.0 || l <= 0.0 )
                    printf("ERROR ! Please enter a valid entry.\n"); 
                else
                {
                    B = a*a;
                    L = (float)2*a*l;
                    printf("Base Surface Area of A PYRAMID : %0.2f\n",B);
                    printf("Lateral Surface Area of A PYRAMID : %0.2f\n",L);
                    printf("Surface Area of A PYRAMID : %0.2f\n",B+L);
                }   
                break;
            case Perimeter:
            
                printf("Please enter the base side of Pyramid :\n");
                if( scanf("%f%c",&a,&d) != 2 || d != '\n')
                {   
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if(a == (float)1453 )
                        return 0;
                else if( a <= 0.0 )
                    printf("ERROR ! Please enter a valid entry.\n"); 
                else
                    printf("Base Perimeter of PYRAMID : %0.2f\n",(float)4*a);
                break;
            case Volume:
                printf("Please enter the base side and height of Pyramid :\n");
                if( scanf("%f",&a) != 1)
                {   
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if( scanf("%f%c",&h,&d) != 2 || d != '\n')
                {    
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if(a == (float)1453 || h == (float)1453 )
                        return 0;
                else if( a <= 0.0 || h <= 0.0 )
                    printf("ERROR ! Please enter a valid entry.\n"); 
                else
                    printf("Volume of a PYRAMID : %0.2f\n",(float)1/(float)3 * (a*a*h));
                break;
        }
    }
    return 1;
}

int calc_cylinder(int op)
{
    float h,r;
    float B,L,S;
    char d;
    
    printf("\n\n!!!A little note before you start: If you want to return the upper menu"
    " , enter 1453 for radius or height!!!\n\n");
    while(1)
    {
        switch(op)
        {
            case Area:
                
                printf("Please enter the radius and height of Cylinder :\n");
                if( scanf("%f",&r) != 1)
                {   
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush(); 
                    break;
                }
                else if( scanf("%f%c",&h,&d) != 2 || d != '\n' )
                {    
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if(r == (float)1453 || h == (float)1453 )
                        return 0;
                else if( r <= 0.0 || h <= 0.0 )
                    printf("ERROR ! Please enter a valid entry.\n"); 
                else
                {
                    B = PI*r*r;
                    L = (float)2*PI*r*h;
                    S = (float)2*B + L;
                    printf("Base Surface Area of A CYLINDER : %0.2f\n",B);
                    printf("Lateral Surface Area of A CYLINDER : %0.2f\n",L);
                    printf("Surface Area of A CYLINDER : %0.2f\n",S);
                }   
                break;
            case Perimeter:
            
                printf("Please enter the radius of Cylinder :\n");
                if( scanf("%f%c",&r,&d) != 2 || d != '\n' )
                {   
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if(r == (float)1453 )
                        return 0;
                else if( r <= 0.0 )
                    printf("ERROR ! Please enter a valid entry.\n"); 
                else
                    printf("Base Surface Perimeter of CYLINDER : %0.2f\n",(float)2*PI*r);
                break;
            case Volume:
                printf("Please enter the radius and height of Cylinder :\n");
                if( scanf("%f",&r) != 1)
                {   
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if( scanf("%f%c",&h,&d) != 2 || d != '\n' )
                {    
                    printf("ERROR ! Please enter a valid entry.\n");
                    flush();
                    break;
                }
                else if( r == (float)1453 || h == (float)1453 )
                        return 0;
                else if( r <= 0.0 || h <= 0.0 )
                    printf("ERROR ! Please enter a valid entry.\n"); 
                else
                    printf("Volume of a CYLINDER : %0.2f\n",PI*r*r*h);
                break;
        }
    }
    return 1;
}
int calculate(int (*shape)(), int(*calc)())
{
    // we have two parameters shape and calc and they have return values
    // ıf they return -2 we have to choose again and also -1 , too
    // If they return -1 it means the user have chosen wrong number
    // else if they return -2 it means the use have written like 1a or a
    // if they return 0 , it means exit
    int s,c,z; // shape,calc and calc_shape control ...
    while(1)
    {
        s = shape(); // We did function pointer , our paramaters is our functions.
        if ( s == 0 ) 
        {
            printf("Exitting...\n");
            return 0;  // Terminating the program
        }
        else if( s == -2 || s == -1 )  // If it isn ' t the right number or if it isn't a number ...
            printf("Try again...\n");
        else if ( s > 0 && s <= 5 ) // If shape is chosen from enum shapes{Triangle=1,Quadrilateral,Circle,Pyramid,Cylinder};
        {
            while(1) // Second loop because i couldnt manage to do it in one loop.
            {
                c = calc();
                if ( c == 0 )
                {
                    printf("Exitting...\n");
                    return 0; // Terminating the program
                }   
                else if ( c == -2 || c == -1) // If it isn ' t the right number or if it isn't a number ...
                    printf("Try again...\n"); 
                else if ( c == 7 ) // It is for going the first menu, i got bored while exitting all the time.
                    break; 
                else if ( c > 0 && c <= 3 ) // If calc is chosen from enum calculators{Area=1,Perimeter,Volume};
                {
                    switch(s) // shape
                    {
// z == 1 situations is the solution of some specific char situation, i think i solved it.
// I break the loops in calc_shape functions and call them again.
                        case Triangle:
                             z = calc_triangle(c);
                            if( z == 0 ) // When it returns 0 , it is going to upper menu
                                break; // So , i break the loop and choose the calculation again.
                            else if ( z == 1 ) // If it breaks the loop in calc_triangle , i call it again. It is a solution to char situations.
                            	calc_triangle(c);
                            break;
                        case Quadrilateral:
                            z = calc_quadrilateral(c);
                            if ( z == 0 ) // When it returns 0 , it is going to upper menu
                                break;
                            else if ( z == 1 )
                            	calc_quadrilateral(c);  // So , i break the loop and choose the calculation again.
                            break;
                        case Circle:
                            z = calc_circle(c);
                            if ( z == 0 ) // When it returns 0 , it is going to upper menu
                                break;
                            else if ( z == 1 )
                            	calc_circle(c);   // So , i break the loop and choose the calculation again.
                            break;
                        case Pyramid:
                            z = calc_pyramid(c);
                            if ( z == 0 )  // When it returns 0 , it is going to upper menu
                                break;
                            else if ( z == 1 )
                            	calc_pyramid(c); // So , i break the loop and choose the calculation again.
                            break;
                        case Cylinder:
                            z = calc_cylinder(c);
                            if ( z == 0 )  // When it returns 0 , it is going to upper menu
                                break;
                            else if ( z == 1 )
                            	calc_cylinder(c);  // So , i break the loop and choose the calculation again.
                            break;
                    }
                }
                if ( z == 8 ) // It is the volume check. Triangle , quadrilateral
                    break; // and circle don't have volume so function returns 8 and program goes back to first menu
            }
        }    
    }
} 

int main()
{
    calculate(select_shape,select_calc);
    return 0;
}

