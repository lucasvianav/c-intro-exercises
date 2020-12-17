#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int boolean;
#define True 1
#define False 0

int main(){
    // Matrix
    char **names = (char **)malloc(sizeof(char *));

    // Auxiliar variable in order to perform the swap
    char tmp; 

    // Indexes
    int i = 0, j, k, w; 

    // Number of names entered
    int noNames;

    // Has the char '$' been read?
    boolean hasFinished = False; 

    // Gets all the names
    while(True){
        names = (char **)realloc(names, (i+1) * sizeof(char *)); // Adds a row to the matrix
        names[i] = (char *)malloc(sizeof(char)); // Makes that row have one column
        j = 0; // Sets the secondary index to 0

        while(True){
            names[i] = (char *)realloc(names[i], (j+1) * sizeof(char)); // Adds a column to the current row
            scanf("%c", &names[i][j]); // Gets a char from the current name (or '\n' if the current name is finished)

            // If the current name is finished
            if(names[i][j] == '\n' || (j > 0 && names[i][j-1] == '$')){ 
                // If gets '$', it means no more names will be read
                if(names[i][j] == '$'){
                    hasFinished = True; 
                }

                else if(j > 0 && names[i][j-1] == '$'){ 
                    hasFinished = True; 
                    names[i][j-1] = '\0'; // Deletes the '$' from the string
                }

                names[i][j] = '\0'; // Adds the string terminator to it
                
                break; // And breaks (so the next name will be read)
            }

            j++; // Increments the current column (letter)
        }

        i++; // Increments the current row

        if(hasFinished){ break; }
    }

    noNames = i;

    // Goes through each row
    for(j = 0, i = noNames - 1; j < i; j++, i--){
        k = strlen(names[j]); // Last char ('\0') from the current row
        w = strlen(names[i]); // Last char ('\0') from the corresponding row (in the other extreme)

        // Gets k to the last name's first letter's index
        while(names[j][k-1] != ' '){ k--; }

        // The same for w
        while(names[i][w-1] != ' '){ w--; }

        // Checks which last is shorter and reallocates memory to the row that contains it
        // (the reallocated memory is equal to the previous size + the difference between the 
        // last names' sizes)
        if(strlen(names[j]) - k > strlen(names[i]) - w){
            names[i] = (char *)realloc(names[i], ((int)strlen(names[j]) - k + w + 1) * sizeof(char));
        }

        else if(strlen(names[j]) - k < strlen(names[i]) - w){
            names[j] = (char *)realloc(names[j], ((int)strlen(names[i]) + k - w + 1) * sizeof(char));
        }

        // Swaps the last names' letters until one of them is finished
        while(names[j][k-1] != '\0' && names[i][w-1] != '\0'){ 
            tmp = names[j][k];
            names[j][k++] = names[i][w];
            names[i][w++] = tmp;
        }

        // Finish swapping the remaining chars
        while(names[j][k-1] != '\0'){
            names[j][k++] = names[i][w++];
        }

        while(names[i][w-1] != '\0'){
            names[i][w++] = names[j][k++];
        }

    }

    for(i = 0; i < noNames; i++){
        // Prints the current row
        printf("%s\n", names[i]);

        // Frees the current row
        free(names[i]);
    }

    // Frees the matrix
    free(names);

    return 0;
}