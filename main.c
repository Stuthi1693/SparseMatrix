#include <stdio.h>
#include "sparse_utils.h"

void printAll() {
    printf("--- Original Text ---\n");
    for(int i = 0; i < lineCount; i++)
        printf("[%d] %s\n", i, lines[i]);

    printf("\n--- Vocabulary Index ---\n");
    for(int i = 0; i < wordCount; i++)
        printf("%d: %s\t", i, words[i]);

    printf("\n\n--- Sparse Matrix (Frequencies) ---\n");
    for(int i = 0; i < lineCount; i++) {
        for(int j = 0; j < wordCount; j++) {
            // Using a dot for zeros makes sparsity visually obvious
            if (matrix[i][j] == 0) printf(". ");
            else printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    // Logic is hidden away in sparse_utils
    buildMatrix();
    
int nonZero = 0;

for(int i = 0; i < lineCount; i++) 
{
    for(int j = 0; j < wordCount; j++) 
    {
        if(matrix[i][j] != 0)
            nonZero++;
    }
}

initSparse(nonZero);
convert();
printSparse();


    // Display results
    printAll();

    return 0;
}