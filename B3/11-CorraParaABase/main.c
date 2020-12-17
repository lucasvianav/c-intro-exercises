#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int rows, cols; // map's size
    int posX, posY; // characters position
    int baseX, baseY; // base's position
    double speed, distance;

    scanf("%d %d", &rows, &cols);
    scanf("%d %d %lf", &posX, &posY, &speed);

    // allocates the map and receives it
    int **map = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++){
        map[i] = (int *)malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++){
            scanf("%d", &map[i][j]); 

            // simultaneously search for the base's position
            if(map[i][j] == 1){
                baseX = i;
                baseY = j;
            }
        }
    }

    // calculates the euclidian distance
    distance = sqrt(pow((baseX - posX), 2) + pow((baseY - posY), 2));

    // prints the result
    printf("%s\n", (distance <= speed) ? "Voce escapou!" : "Game Over!");

    // frees the map
    for(int i = 0; i < rows; i++){ free(map[i]); }
    free(map);

    return 0;
}