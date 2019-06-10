#ifndef BATTLE_H_INCLUDED
#define BATTLE_H_INCLUDED
//Pokemon
typedef struct
{
    char name[30];
    int life;
} monster;

//Ataques
typedef struct
{
    char name[30];
    int damage;
    char type[30];
    int usages;
    int extraTurns;
    int voidTurn;
    char efect[30];
} atacks;

typedef struct
{
    char name[30];
    int perCatch;
    int quant;
    int master;
} balls;

typedef struct
{
    char name[30];
    int healEffect;
    int statusHeal;

} iten;

#endif // BATTLE_H_INCLUDED
