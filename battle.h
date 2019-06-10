#ifndef BATTLE_H_INCLUDED
#define BATTLE_H_INCLUDED
typedef struct
{
    char name[30];
    int life;
} monster;

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

#endif // BATTLE_H_INCLUDED
