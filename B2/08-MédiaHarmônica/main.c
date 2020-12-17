#include <stdio.h>

// funções são como descritas no enunciado da questão

int readInt(){
    int e;

    scanf("%d", &e);

    return e;
}

double readDouble(){
    double e;

    scanf("%lf", &e);

    return e;
}

double printDouble(double val){
    printf("%.2lf\n", val);

    return val;
}



int main(){
    int N = readInt();
    double grade[N]; // notas
    double mean = 0; // média

    // recebe o input das notas e já vai calculando a média simultaneamente
    for(int i = 0; i < N; i++){
        grade[i] = readDouble();
        mean += 1.0/(grade[i] + 1.0);
    }

    // finaliza o cálculo da média
    mean = N/mean - 1;

    printDouble(mean);

    return 0;

}
