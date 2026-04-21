#include <stdio.h>
#include <stdlib.h>
#include "sparse_utils.h"

typedef struct Element
{
    int row;
    int col;
    int value;
} Element;

Element *arr;
int size = 0;


void initSparse(int nonZero)
{
    arr = (Element*) malloc(nonZero * sizeof(Element));
}

void convert()
{
size=0;
    for(int i = 0; i < lineCount; i++) 
    {
        for(int j = 0; j < wordCount; j++) 
        {
            if(matrix[i][j] != 0) 
            {
                arr[size].row = i;
                arr[size].col = j;
                arr[size].value = matrix[i][j];
                size++;
            }
        }
    }
}

// Print sparse matrix
void printSparse() 
{

    for(int i = 0; i < size; i++) 
    {
        printf("(%d, %d, %d)\n",arr[i].row,arr[i].col,arr[i].value);
    }
}