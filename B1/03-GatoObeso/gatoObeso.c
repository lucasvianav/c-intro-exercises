#include <stdio.h>

void weightBalance(int played, int ate){
    int lost = 5*played;
    int gained = 3*ate;

    if (lost - gained >= 30){
        printf("P\n");
    }

    else if(lost - gained >= 0){
        printf("B\n");
    }

    else{
        printf("R\n");
    }

    return;
}

int main(){
    int hasPlayed, hasEaten;

    scanf("%d %d", &hasPlayed, &hasEaten);

    weightBalance(hasPlayed,hasEaten);

    return 0;

}