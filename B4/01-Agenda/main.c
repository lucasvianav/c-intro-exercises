#include <stdio.h>
#include <stdlib.h>

typedef struct date_ {
    int day;
    int month;
    int year;
} date;

typedef struct timestamp_ {
    int hour;
    int minute;
    int second;
} timestamp;

typedef struct appointment_ {
    date day;
    timestamp time;
    char *name;
} appointment;

char *readPhrase(){
    char aux;
    int phraseLength = 0; // number of chars in the phrase ('\0' included)
    char *phrase = (char *)malloc(sizeof(char)); // phrase

    // reads each of the phrase's letters
    do{
        // reads a cahr
        scanf("%c", &aux);

        // reallocates the phrase so it'll fit the new char
        phrase = (char *)realloc(phrase, ++(phraseLength) * sizeof(char));

        // adds either the new char or '\0' (if it's a newline) to the phrase
        phrase[phraseLength-1] = (aux != '\n' && aux != '\r') ? aux : '\0';

    } while(phrase[phraseLength-1] != '\0'); // if '\0' was added to the phrase, then it's finished

    return phrase;
}

int main(){
    int scheduleSize;
    scanf("%d", &scheduleSize);

    appointment *schedule = malloc(scheduleSize * sizeof(appointment));

    for(int i = 0; i < scheduleSize; i++){
        scanf("%d %d %d ", &schedule[i].day.day, &schedule[i].day.month, &schedule[i].day.year);
        scanf("%d %d %d ", &schedule[i].time.hour, &schedule[i].time.minute, &schedule[i].time.second);
        schedule[i].name = readPhrase();
    }

    for(int i = 0; i < scheduleSize; i++){
        printf(
            "%02d/%02d/%02d - %02d:%02d:%02d\n", 
            schedule[i].day.day, schedule[i].day.month, schedule[i].day.year, 
            schedule[i].time.hour, schedule[i].time.minute, schedule[i].time.second
        );

        printf("%s\n", schedule[i].name);

        free(schedule[i].name);
    }

    free(schedule);

    return 0;
}