#include <stdio.h>

void convertTime(char *planet, unsigned long long *days, unsigned long long *hours, unsigned long long *mins, unsigned long long *secs){
    unsigned long long div; // total de minutos em um dia no planeta

    // calcula o valor de div
    div = (planet[0] == 'V')
        ? 243 * 24 * 60 // se for Vênus
        : (planet[0] == 'M') 
            ? (58 * 24 + 16) * 60 // se for Mercúrio
            : (planet[0] == 'J')
                ? 9 * 60 + 56 // se for Júpiter
                : 24 * 60; // se for a Terra

    // Calcula a quantidade de dias
    *days = *secs/60/div;
    *secs -= *days * div * 60; // E a quantidade de segundos que sobrou
    
    // Calcula a quantidade de horas
    *hours = *secs/3600;
    *secs -= *hours * 3600; // E a quantidade de dias que sobrou

    // Calcula a quantidade de minutos
    *mins = *secs/60;
    *secs -= *mins * 60; // E a quantidade de segundos que sobrou

    return;
}

int main(){
    unsigned long long days, hours, mins, secs;
    char planet[9];

    // recebe o input
    scanf("%llu", &secs);
    scanf("%s", planet);

    // printa o input
    printf("%llu segundos no planeta %s equivalem a:\n", secs, planet);

    // faz a conversão
    convertTime(planet, &days, &hours, &mins, &secs);

    // printa o resultado
    printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n", days, hours, mins, secs);

    return 0;
}