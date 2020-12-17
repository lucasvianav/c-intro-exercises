#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// student struct
typedef struct student_ {
    int _id; // identifier
    char *name;
    char *course;
    int age;
} student;

// prints s's info in the correct format
void printStudent(student s){
    printf("Nome: %s\n", s.name);
    printf("Curso: %s\n", s.course);
    printf("N USP: %d\n", s._id);
    printf("IDADE: %d\n\n", s.age);

    return;
}

// dynamically reads a phrase from the stdin
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
    int aux; // auxiliar variable
    int noStudents = 0; // number of students

    student *students = (student *)malloc(sizeof(student));

    while(1){
        scanf("%d ", &aux);
        if(aux == -1){ break; }

        // allocates one more student to the array
        students = (student *)realloc(students, ++noStudents * sizeof(student));

        // saves the student's info
        students[noStudents-1]._id = aux;
        students[noStudents-1].name = readPhrase();
        students[noStudents-1].course = readPhrase();
        scanf("%d ", &students[noStudents-1].age);
    }

    while(1){
        scanf("%d", &aux);
        if(aux == -1){ break; }

        // operation 1: search by id
        else if(aux == 1){
            scanf("%d", &aux);

            for(int i = 0; i < noStudents; i++){
                if(students[i]._id == aux){
                    printStudent(students[i]);
                    break;
                }
            }
        }

        // operatio 2: search by course
        else if(aux == 2){
            char *course = readPhrase();

            for(int i = 0; i < noStudents; i++){
                if(!strcmp(students[i].course, course)){ printStudent(students[i]); }
            }

            free(course);
        }

        // operation 3: prints all students
        else if(aux == 3){ for(int i = 0; i < noStudents; i++){ printStudent(students[i]); } }
    }

    // frees every string
    for(int i = 0; i < noStudents; i++){
        free(students[i].name);
        free(students[i].course);
    }

    // frees the array
    free(students);

    return 0;
}