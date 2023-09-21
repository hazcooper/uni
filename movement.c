#include <stdio.h>
#include <stdlib.h>
#include "movement.h"
#include "macros.h"
#include "array.h"
#include "terminal.h"

/* 
* Function: testMovement
* Import: char ** arr, int, int
* Export: none
* Assertion: moves the player around the 2d array
 */
void testMovement(char ** arr, int * row, int * col, int * mainrow, int * maincol, int* isSuccess)
{
    char input;
    moveCars(arr, *row, *col);

    disableBuffer();
    scanf("%c", &input);
    enableBuffer();

    


    if(input == KEY_UP)
    {
        /* what do we wanna do 
        check the boundary to make sure there are no asteriks*/
        /* if i moved up, thats row minus 1. i would check row - 1 of the char array, is equal to '*' */
        /* fill the map with new player location
        redraw the map with updated locations */

        /* checks for asterik in next row, does not allow movement if filled with asterik */
        if(arr[*row - 1][*col] == BORDER)
        {
            fillPlayer(arr, *row, *col); /* fills currents location with P */
        }
        /* checks for goal, then fill with P and prints you win */
        else if(arr[*row - 1][*col] == GOAL)
        {
            
            fillPlayer(arr, *row - 1, *col);
            fillEmpty(arr, *row, *col);
            *row = *row - 1;
            printf("You win");
            *isSuccess = TRUE;
            
            /* updates goal row and goal column set by initial values with 'P' then makes the condition for do while loop TRUE */
            /**mainrow = PLAYER;
            *maincol = PLAYER;*/
            /*printf("You win");*/

            
        }
        
        else if (arr[*row - 1][*col] == ROAD)
        {
            fillPlayer(arr, *row - 1, *col);
            fillEmpty(arr, *row, *col);
            *row = *row - 1;

        }
        /* moves the location of P one row up, then fills the previous square with empty and updates row with new P */
        else 
        {
            fillPlayer(arr, *row - 1, *col);
            fillRoad(arr, *row, *col);
            
            *row = *row - 1;
        }
    }
    else if(input == KEY_DOWN)
    {
        /* checks for asterik in next row, does not allow movement if filled with asterik */
        if(arr[*row + 1][*col] == BORDER)
        {
            fillPlayer(arr, *row, *col); /* fills current location with P */
        }
        /* checks for goal, then fills with P and prints you win */
        else if(arr[*row + 1][*col] == CAR_LEFT || CAR_RIGHT)
        {
           fillEmpty(arr, *row, *col); 
           fillPlayer(arr, *row + 2, *col);
            *row = *row + 2;
        }
        else if(arr[*row + 1][*col] == GOAL)
        {
            fillPlayer(arr, *row + 1, *col);
            fillEmpty(arr, *row, *col);
            *row = *row + 1;
            
            /* updates goal row and goal column set by initial values with 'P' then makes the condition for do while loop TRUE */
            /**mainrow = PLAYER;
            *maincol = PLAYER;*/
            printf("You win");
            *isSuccess = TRUE;
            

        }
        /* moves the location of P one row down, then fills with the previous square with empty and updates row with new P location */
        else if (arr[*row + 1][*col] == ROAD)
        {
            fillPlayer(arr, *row + 1, *col);
            fillEmpty(arr, *row, *col);
            *row = *row + 1;

        }
        /* moves the location of P one row up, then fills the previous square with empty and updates row with new P */
        else 
        {
            fillPlayer(arr, *row + 1, *col);
            fillRoad(arr, *row, *col);
            
            *row = *row + 1;
        }

    }
    else if(input == KEY_RIGHT)
    {
        /* checks for asterik in next col, does not allow movement if filled with asterik */
        if(arr[*row][*col + 1] == BORDER)
        {
            fillPlayer(arr, *row, *col);
        }
        /* checks for goal, then fills with p and prints you win */
        else if(arr[*row][*col + 1] == GOAL)
        {
            fillPlayer(arr, *row, *col+1);
            fillEmpty(arr, *row, *col);
            *col = *col + 1;
            printf("You win");
        }
        /* moves the location of P one row down, then fills with the previous square with empty and updates row with new P location */
        else if (arr[*row][*col+1] == ROAD)
        {
            fillPlayer(arr, *row, *col+1);
            fillRoad(arr, *row, *col);
            *col = *col + 1;

        }
        /* moves the location of P one row up, then fills the previous square with empty and updates row with new P */
        else 
        {
            fillPlayer(arr, *row, *col+1);
            fillEmpty(arr, *row, *col);
            
            *col = *col + 1;
        }
        
    }
    else if(input == KEY_LEFT)
    {
        /* checks for asterik in next col, does not allow movement if filled with asterik */
        if(arr[*row][*col - 1] == BORDER)
        {
            fillPlayer(arr, *row, *col);
        }
        /* checks for goal, then fills with p and prints you win */
        else if(arr[*row][*col - 1] == GOAL)
        {
            fillPlayer(arr, *row, *col - 1);
            fillEmpty(arr, *row, *col);
            *col = *col - 1;
            printf("You win");
        }
        else if (arr[*row][*col-1] == ROAD)
        {
            fillPlayer(arr, *row, *col-1);
            fillRoad(arr, *row, *col);
            *col = *col - 1;

        }
        /* moves the location of P one row up, then fills the previous square with empty and updates row with new P */
        else 
        {
            fillPlayer(arr, *row, *col-1);
            fillEmpty(arr, *row, *col);
            
            *col = *col - 1;
        }
        
    }  

    else if (arr[*row - 1][*col] == GOAL)
    {
        // ...
        printf("You win");
        *isSuccess = TRUE;
    }
    
    else if(input != KEY_UP && input != KEY_DOWN && input != KEY_RIGHT && input != KEY_LEFT)
    {
        printf("Invalid input");
    }

    moveCars(arr, *row, *col);
}

/* 
* Function: checkPlayerGoal
* Import: char ** arr, int *, int *
* Export: int
* Assertion: checks to see if player and goal are on the same square then returns TRUE
 */
int checkPlayerGoal(char ** arr, int * row, int * col)
{
    int isSuccess;
    isSuccess = FALSE;

     if(arr[*row][*col] == PLAYER && arr[*row][*col] == GOAL)
        {
            printf("You win\n");
            isSuccess = TRUE;
        }
        return isSuccess;
}

