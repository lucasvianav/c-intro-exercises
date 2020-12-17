#include <stdio.h>

int main(){
    int n, i, j;

    // recebe o input
    scanf("%d %d %d", &n, &i, &j);

    // printa n múltiplos
    // o valor de multiplo começa em -1 porque ele vai ser
    // incrementado antes de ser usado
    for(int k = 0, multiplo = -1; k < n; k++){
        // loop que vai rolar até um mútliplo ser printado para aquele k
        while(1){
            // checa se multiplo é múltiplo de i ou j (ou ambos)
            // sempre incrementa o valor de multiplo antes de checar
            if(++multiplo % i == 0 || multiplo % j == 0){
                printf("%d\n", multiplo); // se for, printa
                break; // e sai do loop
            }
        }
    }

    return 0;
}