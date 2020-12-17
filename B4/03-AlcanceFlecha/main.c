#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// gravity
#define g 9.81 // (m/s^2)

// arrow
typedef struct arrow_ {
    int speed; // initial speed
    float angle; // relative to the ground
} arrow;

int main(){
    // number of archers
    int noArchers;
    scanf("%d", &noArchers);

    // array of arrows
    arrow *arrows = (arrow *)malloc(noArchers * sizeof(arrow));

    // reads the input
    for(int i = 0; i < noArchers; i++){ scanf("%d %f", &arrows[i].speed, &arrows[i].angle); }

    // calculates the distance
    // and prints the output
    for(int i = 0; i < noArchers; i++){
        float distance = (pow(arrows[i].speed, 2)*sin(2*arrows[i].angle))/g;
        printf("%.2f\n", distance);
    }

    // frees the array
    free(arrows);

    return 0;
}