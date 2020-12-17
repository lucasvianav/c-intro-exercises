#include <stdio.h>
#include <stdlib.h>

// Receives the original image and
// returns the image with the padding applied
int **applyPadding(int **img, int width, int height, int padding){
    // The padded image has an increse of 2*padding in each dimension
    int **padded = (int **)malloc((height + padding * 2) * sizeof(int *)); // Allocates rows

    // Goes through the matrix
    for(int i = 0; i < height + padding * 2; i++){
        padded[i] = (int *)malloc((width + padding * 2) * sizeof(int)); // Allocates columns for each row

        for(int j = 0; j < width + padding * 2; j++){
            // Applies the padding
            padded[i][j] = (i < padding || i > height + padding - 1 || j < padding || j > width + padding - 1) 
                ? 0 
                : img[i-padding][j-padding];
        }
    }

    return padded;
}

// Prints the matrix
void printMatrix(int **matrix, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return;
}

// Frees each row
void freeMatrix(int **matrix, int rows){
    for(int i = 0; i < rows; i++){ free(matrix[i]); }
    return;
}

int main(){
    int width, height, paddingSize;

    // Gets image's height and width
    scanf("%d", &width);
    scanf("%d", &height);

    int **img = (int **)malloc(height * sizeof(int *)); // Matrix with 'height' rows

    // Gets the image's matrix
    for(int i = 0; i < height; i++){
        img[i] = (int *)malloc(width * sizeof(int)); // Each row has 'width' columns

        for(int j = 0; j < width; j++){
            scanf("%d", &img[i][j]);
        }
    }

    scanf("%d", &paddingSize);

    // Gets the padded image
    int **padded = applyPadding(img, width, height, paddingSize);

    // Prints the result
    printMatrix(padded, height + 2*paddingSize, width + 2*paddingSize);
    printf("\n");
    printMatrix(img, height, width);

    // And frees the matrices
    freeMatrix(img, height); free(img);
    freeMatrix(padded, height + paddingSize * 2); free(padded);

    return 0;
}