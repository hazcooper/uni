#ifndef ARRAY_H
#define ARRAY_H

void malloc2dArray(int a, int b);
char ** malloc2dArrayReturn(int a, int b);
void printBoundary(char ** arr, int row, int col);
void fillCharArray(char ** arr, int row, int col);
void fillPlayer(char ** arr, int row, int col);
void printGameGrid(char ** arr, int row, int col);
void fillGoal(char ** arr, int row, int col);
void printMovement();
void fillEmpty(char ** arr, int row, int col);
void collapsingFloor(char ** arr, int row, int col);
void fillRoad(char ** arr, int row, int col);
void initializeCars(char ** arr, int row, int col);
#endif
