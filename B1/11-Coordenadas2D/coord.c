#include <stdio.h>
#include <stdlib.h>

#define NUMBER_INPUTS 6

int main(){
    char *input = (char*)malloc(6 * sizeof(char));
    int x = 0, y = 0;

    // scanf("%c%c%c%c%c%c", &input[0], &input[1], &input[2], &input[3], &input[4], &input[5]);

    for(int i = 0; i < NUMBER_INPUTS; i++){
        scanf("%c", &input[i]);

        switch(input[i]){
            case 'W': 
                y+=1;
                break;
            case 'A': 
                x-=1;
                break;
            case 'S': 
                y-=1;
                break;
            case 'D': 
                x+=1;
                break;
        }

    }

    printf("%d %d\n", x, y);

    return 0;

}