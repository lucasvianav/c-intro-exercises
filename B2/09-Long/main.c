#include <stdio.h>

int main(){
    long e;

    // receives input
    scanf("%ld", &e);

    // gets list of bytes
    unsigned char *p = (unsigned char *)&e;

    // prints the output
    for(int i = 0; i < 8; i++){
        printf("%x\n", p[i]);
    }

    return 0;
}