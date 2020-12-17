#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int boolean;
#define True 1
#define False 0

int main(){
    // Matrix
    char **names = (char **)malloc(sizeof(char *));

    // Indexes
    int i = 0, j, k, w; 

    // Has the char '$' been read?
    boolean hasFinished = False; 

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

    // Goes through each row
    for(j = 0; j < i; j++){
        // If it's index is even and it has a next row
        if(j % 2 == 0 && j+1 < i){
            k = strlen(names[j]) - 1; // Last char ('\0') from the current row
            w = strlen(names[j+1]) - 1; // Last chat ('\0') from teh next row

            // Gets k to the index immediately before the current row's last name's
            while(names[j][k] != ' '){ k--; }

            // Copies the current row's last name to the end of next row
            while(names[j][k-1] != '\0'){ 
                names[j+1] = (char *)realloc(names[j+1], (++w + 1) * sizeof(char));
                names[j+1][w] = names[j][k++];
            }
        }

        // Prints the current row
        printf("%s\n", names[j]);

        // Frees the current row
        free(names[j]);
    }

    // Frees the matrix
    free(names);

    return 0;
}