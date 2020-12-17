#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 3

// Reads a ROWS x COLS matrix of integers and returns it
int **readMatrix(){
    int **matrix = (int **)malloc(ROWS * sizeof(int *)); // allocates the matrix

    // goes through each row
    for(int i = 0; i < ROWS; i++){
        matrix[i] = (int *)malloc(COLS * sizeof(int)); // allocates that row's columns

        // goes through each column reading the input
        for(int j = 0; j < COLS; j++){ scanf("%d", &matrix[i][j]); }
    }

    // return the matrix
    return matrix;
}

// mixes the colors
void mixColor(int **matrix, int firstIndex, int secondIndex, int targetIndex){
    int tmp; // auxiliar variable

    // goes through each columns in the target row
    for(int j = 0; j < COLS; j++){ 
        // stores the new value in the auxiliar variable
        tmp = matrix[targetIndex][j] + matrix[firstIndex][j]/2 + matrix[secondIndex][j]/2;
        matrix[targetIndex][j] = tmp > 255 ? 255 : tmp; // and sets it to max(255, tmp)
    }

    return;
}

// prints the matrix in the specified format "Color(%d): [\t%d\t%d\t%d\t]\n"
void printMatrix(int **matrix){
    // goes through each row
    for(int i = 0; i < ROWS; i++){
        printf("Color(%d): [\t", i); // prints row number and opening bracket
        for(int j = 0; j < COLS; j++){ printf("%d\t", matrix[i][j]); } // goes through each column printing it's value
        printf("]\n"); // prints closing bracket and linebreak
    }
}

int main(){
    int firstIndex, secondIndex, targetIndex;
    scanf("%d %d %d", &firstIndex, &secondIndex, &targetIndex);

    int **matrix = readMatrix();
    printf("Start:\n");
    printMatrix(matrix);

    mixColor(matrix, firstIndex, secondIndex, targetIndex);
    printf("\nResult:\n");
    printMatrix(matrix);

    for(int i = 0; i < ROWS; i++){ free(matrix[i]); }
    free(matrix);

    return 0;
}