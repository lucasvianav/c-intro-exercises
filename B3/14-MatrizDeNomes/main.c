#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_OF_NAMES 5
#define MAX_LENGTH 50

void swapElements(char **vector, int i, int j){
    if(i != j){
        char *tmp = (char *)malloc(MAX_LENGTH * sizeof(char)); // Auxiliar variable

        strcpy(tmp, vector[i]);
        strcpy(vector[i], vector[j]);
        strcpy(vector[j], tmp);

        free(tmp);
    }
    
    return;
}

// QUICK SORT
void quickSort(char **vector, int leftIndex, int rightIndex){
    if(leftIndex < rightIndex){
        char *pivot = (char *)malloc(MAX_LENGTH * sizeof(char));
        int left = leftIndex, right = rightIndex;

        strcpy(pivot, vector[(int)((right+left)/2)]);

        while(1){
            // Selects elements from the left that are >= to the pivot
            while(strcmp(vector[left], pivot) < 0){ left++; }

            // Selects elements from the right that are <= to the pivot
            while(strcmp(vector[right], pivot) > 0){ right--; }

            // If the swapping the above selected elements is worth it, do it
            if(left < right){ swapElements(vector, left++, right--); } // And pass to the next element

            // If the swap is not worth it, the vector was successfully partitionted
            else{ break; }
        }

        // Sorts the partitions
        quickSort(vector, leftIndex, right);
        quickSort(vector, right+1, rightIndex);

        free(pivot);
    }

    return;
}

int main(){
    char **matrix = (char **)malloc(NO_OF_NAMES * sizeof(char *)); // vector of strings

    // goes through each row
    for(int i = 0; i < NO_OF_NAMES; i++){
        matrix[i] = (char *)malloc(MAX_LENGTH * sizeof(char)); // allocates the current string
        scanf(" %[^\n]s", matrix[i]); // receives the input
    }

    // sorts the names
    quickSort(matrix, 0, NO_OF_NAMES - 1);

    // prints the output
    for(int i = 0; i < NO_OF_NAMES; i++){ 
        printf("%s\n", matrix[i]); 
        free(matrix[i]); // and frees each string
    }

    // frees the matrix
    free(matrix);

    return 0;
}