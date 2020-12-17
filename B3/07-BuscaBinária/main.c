#include <stdio.h>
#include <stdlib.h>

void radixSort(int *vector, int vectorSize, int maxValue, int base){
    int *counters = (int *)malloc((base+1) * sizeof(int));
    int *aux = (int *)malloc(vectorSize * sizeof(int));

    // Counting sorts each digit d (starting by the unit, d = 1)
    for(unsigned long d = 1; maxValue/d > 0; d *= base){
        // Sets all counters to 0
        // Digit range is 0-base --> digitMaxValue = base
        for(int i = 0; i <= base; i++){ counters[i] = 0; }

        // Counts how many of each digit in the d position the vector contains
        // (vector[i]/d) % base = value of the digit in the position d of the number vector[i]
        for(int i = 0; i < vectorSize; i++){ counters[(vector[i]/d) % base]++; }

        // counters[i]: quantity of i in the vector ---> last position + 1 of an i in the vector
        for(int i = 1; i <= base; i++){ counters[i] += counters[i-1]; }

        // Sorts (stable)
        for(int i = vectorSize - 1; i >= 0; i--){
            aux[counters[(vector[i]/d) % base]-- - 1] = vector[i];
        }

        for(int i = 0; i < vectorSize; i++){ vector[i] = aux[i]; }
    }

    // Deallocates memory
    free(counters);
    free(aux);

    return;
}

void readVector(int *vector, int vectorSize, int *maxValue){
    // Receives the whole vector
    for(int i = 0; i < vectorSize; i++){
        scanf("%d", &vector[i]);

        // Simultaneously selects the highest value in the vector
        // (variable passed by reference) in order to use the radix
        // sort later
        *maxValue = (*maxValue < vector[i]) ? vector[i] : *maxValue;
    }

    return;
}

int binarySearch(int *vector, int size, int target){
    int middle; // Vector's middlepoint
    int start = 0; // Vector's beginning
    int end = size - 1; // Vector's ending

    // Searchs through the whole vector
    while(start <= end){
        middle = (start + end)/2; // Sets the middlepoint
    
        // Checks if the searched number (target) is in the middle
        // If it is, then the search if finished
        if(vector[middle] == target) { return middle; }

        // Checks if the searched number is in the vector's
        // first or second half and sets a new start or end

        // First half 
        else if(target < vector[middle]) { end = middle - 1; }

        // Second half
        else { start = middle + 1; }
    }

    // If it gets out of the loop it means that the
    // vector does not contain the searched number
    return -1;
}

int main(){
    int vectorSize, target, maxValue, *vector;

    // Reads the vector size and searched number
    scanf("%d %d", &vectorSize, &target);

    // Allocates the vector
    vector = (int *)malloc(vectorSize * sizeof(int));

    // Reads the vector
    readVector(vector, vectorSize, &maxValue);

    // Sorts the vector (using hexadecimal base)
    radixSort(vector, vectorSize, maxValue, 16);

    // Searches for the target
    int result = binarySearch(vector, vectorSize, target);

    // Prints the results
    result != -1 ? printf("%d\n", result) : printf("Chave inexistente\n");

    // Deallocates memory
    free(vector);
}