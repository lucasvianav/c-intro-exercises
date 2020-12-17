#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define str char*
#define WORD_SIZE 20

// returns the char's integer value (non case-sensitive alphabetical order)
int val(char c){
    // will compare input ASCII value with every letter's
    for(int i = 0; i < 26; i++){
        // 65 is ASCII for a and 97 is ASCII for A
        if((int) c == i + 65 || (int) c == i + 97){ // non case-sensitive
            return i;
        }
    }

    return -1;
}

// compares how many letters each word has
// returns the one that has the more
int cmpSize(str firstWord, str scndWord){
    int size_1 = strlen(firstWord);
    int size_2 = strlen(scndWord);

    if(size_1 > size_2){
        return 1;
    }

    else if(size_1 < size_2){
        return 2;
    }

    else{
        return 0;
    }
}

// compares the word's order alphabetically
// returns the one that comes first
int cmpAlphaOrder(str firstWord, str scndWord){
    int i = 0;

    // goes through the words until one of then ends
    while(firstWord[i] != '\0' && scndWord[i] != '\0'){
        // comparing each corresponding letter
        // if there's already one that comes before the order
        //return that word

        // letter in first word comes before letter in second word
        if(tolower(firstWord[i]) < tolower(scndWord[i])){
            return 1;
        }

        // the opposite
        else if(tolower(firstWord[i]) > tolower(scndWord[i])){
            return 2;
        }

        // if the letters are the same, goes to the next
        i++;
    }

    // if gets out of the loop, means that at least one word has ended
    // and all of it's letters are the same as the first i letters
    // of the other word. in this case, the smaller word comes first

    // if both words are the same it's a tie
    if(firstWord[i] == '\0' && scndWord[i] == '\0'){
        return 0;
    }

    // if the smaller word is the first
    else if(firstWord[i] == '\0'){
        return 1;
    }

    // if the smaller word was the second
    else{
        return 2;
    }
}

// compares the sum of the word's letters' int values
int cmpSum(str firstWord, str scndWord){
    int sum_1 = 0, sum_2 = 0;

    // sums all the first word's letters
    for(int i = 0; firstWord[i] != '\0'; i++){
        sum_1 += val(firstWord[i]);
    }

    // sums all the second word's letters
    for(int i = 0; scndWord[i] != '\0'; i++){
        sum_2 += val(scndWord[i]);
    }

    if(sum_1 == sum_2){
        return 0;
    }

    else if(sum_1 < sum_2){
        return 2;
    }

    else{
        return 1;
    }

}

// compares how many ocurrences of a given the words contain
int cmpLetterRep(str firstWord, str scndWord, char c){
    int count_1 = 0, count_2 = 0; // starts at 0 ocurrences

    // count's how many occurrences in the first word
    for(int i = 0; firstWord[i] != '\0'; i++){
        if(tolower(firstWord[i]) == tolower(c)){
            count_1++;
        }
    }

    // count's how many occurrences in the second word
    for(int i = 0; scndWord[i] != '\0'; i++){
        if(tolower(scndWord[i]) == tolower(c)){
            count_2++;
        }
    }
    
    // compares them
    if(count_1 > count_2){
        return 1;
    }
    
    else if(count_1 < count_2){
        return 2;
    }

    else{
        return 0;
    }

}

// compares in which word a given letter comes first
int cmpLetterFirst(str firstWord, str scndWord, char c){
    int pos_1 = 0, pos_2 = 0; // position of the first ocurrence of that letter in the word

    // goes through the first word until the first
    // occurence of that letter or until the word ends
    for(int i = 0; firstWord[i] != '\0'; i++){
        if(tolower(firstWord[i]) == tolower(c)){
            pos_1 = i;
            break;
        }
    }

    // goes through the second word until the first
    // occurence of that letter or until the word ends
    for(int i = 0; scndWord[i] != '\0'; i++){
        if(tolower(scndWord[i]) == tolower(c)){
            pos_2 = i;
            break;
        }
    }
    
    if(pos_1 < pos_2){
        return 1;
    }
    
    else if(pos_1 > pos_2){
        return 2;
    }

    else{
        return 0;
    }
}

int main(){
    int command;
    char c; // for commands 4 and 5
    str first = (str)malloc(WORD_SIZE * sizeof(char)); // first word
    str second = (str)malloc(WORD_SIZE * sizeof(char)); // second word

    // receives input
    scanf("%d", &command);
    scanf("%s", first);
    scanf("%s", second);

    // calls the correct function according to the command
    switch (command){
    case 1:
        printf("%d\n", cmpSize(first, second));
        break;
    
    case 2:
        printf("%d\n", cmpAlphaOrder(first, second));
        break;
    
    case 3:
        printf("%d\n", cmpSum(first, second));
        break;
    
    case 4:
        scanf(" %c", &c);
        printf("%d\n", cmpLetterRep(first, second, c));
        break;
    
    case 5:
        scanf(" %c", &c);
        printf("%d\n", cmpLetterFirst(first, second, c));
        break;
    
    default:
        break;
    }

    // deallocates memory
    free(first);
    free(second);

    return 0;
}