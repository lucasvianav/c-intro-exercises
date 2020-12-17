/* Author: Lucas Viana Vilela */
/* noUSP: 10748409 */

#include <stdio.h>
#include <math.h>

/** Return 1 if it's a leap year and 0 if it's not. */
int isLeapYear(int year){
    if(year % 4 != 0) {
        return 0; 
    }
    else if(year % 100 != 0) {
        return 1;
    }
    else if(year % 400 != 0) {
        return 0;
    }
    else {
        return 1; 
    }
}

int main() {
    int year;

    scanf("%d", &year);

    if(isLeapYear(year)) {
        printf("SIM\n");
    }
    else{
        printf("NAO\n");
    }

    return 0;
}