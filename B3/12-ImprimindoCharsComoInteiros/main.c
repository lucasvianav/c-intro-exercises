#include <stdio.h>
#include <stdlib.h>

// Swaps vector[i] and vector[j]
void swapElements(char *vector, int i, int j){
   if(i != j){
        char tmp; // Auxiliar variable

        tmp = vector[i];
        vector[i] = vector[j];
        vector[j] = tmp;
   }
    
    return;
}

// QUICK SORT
void quickSort(char *vector, int leftIndex, int rightIndex){
    if(leftIndex < rightIndex){
        int pivot = vector[(int)((rightIndex+leftIndex)/2)];
        int left = leftIndex, right = rightIndex;

        while(1){
            // Selects elements from the left that are >= to the pivot
            while(vector[left] < pivot){ left++; }

            // Selects elements from the right that are <= to the pivot
            while(vector[right] > pivot){ right--; }

            // If the swapping the above selected elements is worth it, do it
            if(left < right){ swapElements(vector, left++, right--); } // And pass to the next element

            // If the swap is not worth it, the vector was successfully partitionted
            else{ break; }

        }

        // Sorts the partitions
        quickSort(vector, leftIndex, right);
        quickSort(vector, right+1, rightIndex);
    }

    return;
}

int main(){
    int inputSize = 0; // input vector's length
    char *input = (char *)malloc(sizeof(char)); // input vector
    char aux; // auxiliar variable in order to receive each input char

    // infinite loop
    while(1){
        scanf("%c", &aux); // receives a char
        if(aux == '\n' || aux == '\r'){ continue; } // ignores linebreaks

        input = (char *)realloc(input, ++inputSize * sizeof(char)); // reallocates memory to accommodate the new char
        input[inputSize - 1] = aux; // adds the new char to the input vector

        if(aux == 'x'){ break; } // if the new char is an 'x', the input has finished
    }

    quickSort(input, 0, inputSize-1); // sorts the input

    int *integers = (int *) input; // integer pointer to the chars

    // print the chars as if it were integers
    // (inputSize/4 because 4 chars are equivalent to 1 integer)
    for(int i = 0; i < inputSize/4; i++){ printf("%d\n", integers[i]); }

    free(input);

    return 0;
}