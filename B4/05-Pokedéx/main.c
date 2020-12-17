#include <stdio.h>
#include <stdlib.h>

// string and array sizes
#define ATTACK_NAME_MAX_LENGTH 20
#define NAME_MAX_LENGTH 50
#define TYPE_MAX_LENGTH 20
#define NUMBER_OF_ATTACKS 4

// commands
#define REGISTER_POKEMON 1
#define REGISTER_ATTACK 2
#define PRINT_POKEMON 3
#define PRINT_ATTACK 4
#define EXIT 0

// status/attribute struct
typedef struct status_ {
    int hp;
    int attack;
    int defense;
    int specialAttack;
    int specialDefense;
    int speed;
} status;

// attack struct
typedef struct attack_ {
    char name[ATTACK_NAME_MAX_LENGTH];
    int power;
    float accuracy;
    char class; // 'p'hysical x 's'pecial
} attack;

// pokémon struct
typedef struct pokemon_ {
    char name[NAME_MAX_LENGTH];
    char primType[TYPE_MAX_LENGTH]; // primary type
    char scndType[TYPE_MAX_LENGTH]; // secondary type
    status attributes;
    attack attacks[NUMBER_OF_ATTACKS];
} pokemon;

int main(){
    int command;

    // pokedéx
    pokemon *pokedex = (pokemon *)malloc(sizeof(pokemon));
    int noPokemon = 0; // number of pokemons in the pokedex

    // indexes that'll be used in the operations
    int pokeIndex; // pokemon's index
    int atkIndex; // attack's index

    // loop that'll be broken only by the EXIT command
    do{
        scanf("%d", &command);

        switch(command){
            case REGISTER_POKEMON:
                // allocates memory for a new pokemon in the pokedex
                pokedex = (pokemon *)realloc(pokedex, ++noPokemon * sizeof(pokemon));

                // reads the new pokemon's info
                scanf(
                    "%s %s %s %d %d %d %d %d %d",
                    pokedex[noPokemon-1].name, pokedex[noPokemon-1].primType, 
                    pokedex[noPokemon-1].scndType, &pokedex[noPokemon-1].attributes.hp,
                    &pokedex[noPokemon-1].attributes.attack, &pokedex[noPokemon-1].attributes.defense,
                    &pokedex[noPokemon-1].attributes.specialAttack, &pokedex[noPokemon-1].attributes.specialDefense,
                    &pokedex[noPokemon-1].attributes.speed
                );

                break;
            
            case REGISTER_ATTACK:
                // reads the indexes
                scanf("%d %d", &pokeIndex, &atkIndex);

                // reads that attack's info
                scanf(
                    "%s %d %f %c",
                    pokedex[pokeIndex].attacks[atkIndex].name, &pokedex[pokeIndex].attacks[atkIndex].power,
                    &pokedex[pokeIndex].attacks[atkIndex].accuracy, &pokedex[pokeIndex].attacks[atkIndex].class
                );

                break;

            case PRINT_POKEMON:
                // reads the pokemon's index
                scanf("%d", &pokeIndex);

                // prints that pokemon's info
                printf("Nome do Pokemon: %s\n", pokedex[pokeIndex].name);
                printf("Tipo primario: %s\n", pokedex[pokeIndex].primType);
                printf("Tipo secundario: %s\n", pokedex[pokeIndex].scndType);

                // prints that pokemon's attributes
                printf("Status:\n");
                printf("\tHP: %d\n", pokedex[pokeIndex].attributes.hp);
                printf("\tAtaque: %d\n", pokedex[pokeIndex].attributes.attack);
                printf("\tDefesa: %d\n", pokedex[pokeIndex].attributes.defense);
                printf("\tAtaque Especial: %d\n", pokedex[pokeIndex].attributes.specialAttack);
                printf("\tDefesa Especial: %d\n", pokedex[pokeIndex].attributes.specialDefense);
                printf("\tVelocidade: %d\n\n", pokedex[pokeIndex].attributes.speed);

                break;

            case PRINT_ATTACK:
                // reads the indexes
                scanf("%d %d", &pokeIndex, &atkIndex);

                // print that attack's info
                printf("Nome do Ataque: %s\n", pokedex[pokeIndex].attacks[atkIndex].name);
                printf("Poder base: %d\n", pokedex[pokeIndex].attacks[atkIndex].power);
                printf("Acuracia: %f\n", pokedex[pokeIndex].attacks[atkIndex].accuracy);
                printf("Classe: %c\n\n", pokedex[pokeIndex].attacks[atkIndex].class);

                break;

            case EXIT:
                free(pokedex);
                break;

            default:
                break;
        }
    } while(command != EXIT);

    return 0;
}