#include <stdio.h>

int main(){
    FILE *f = fopen("./entrada.txt", "r"); // opens the file

    char aux[99999]; // auxiliar variable to store each word
    int noWords = 0; // number of words

    // goes through each word and increments the counter
    while(fscanf(f, "%s", aux) > 0){ noWords++; }

    // closes the file
    fclose(f);

    // prints the output
    printf("%d\n", noWords);

    return 0;    
}