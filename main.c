#include <stdio.h>
#include <stdlib.h>
#define ASCII_ESC 27
#include "infos.h"
#include "battle.c"
#include "menu.c"

int main()
{
    printf("\n\n");
    int battle=1;
    int *ptr_battle=&battle;

    //Pokemon 1
    monster one;
    char one_name[]="Charmander";
    strcpy(one.name,one_name);
    one.life=200;
    monster *ptr1=&one;

    atacks one_atk1;
    atacks one_atk2;
    atacks one_atk3;
    atacks one_atk4;

    char at1[]="Scrach";
    strcpy(one_atk1.name,at1);
    one_atk1.damage=10;
    one_atk1.usages=10;

    char at2[]="Growl";
    strcpy(one_atk2.name,at2);
    one_atk2.damage=20;
    one_atk1.usages=5;

    char at3[]="Ember";
    strcpy(one_atk3.name,at3);
    one_atk3.damage=30;
    one_atk1.usages=3;

    char at4[]="Tail Whip";
    strcpy(one_atk4.name,at4);
    one_atk4.damage=40;
    one_atk1.usages=2;

    //Pokemon 2
    monster two;
    char two_name[]="Bulbassaur";
    strcpy(two.name,two_name);
    two.life=200;
    monster *ptr2=&two;

    atacks two_atk1;
    atacks two_atk2;
    atacks two_atk3;
    atacks two_atk4;

    char at12[]="Scrach";
    strcpy(two_atk1.name,at12);
    two_atk1.damage=10;
    two_atk1.usages=10;

    char at22[]="Growl";
    strcpy(two_atk2.name,at22);
    two_atk2.damage=20;
    two_atk2.usages=5;

    char at32[]="Vine Whipe";
    strcpy(two_atk3.name,at32);
    two_atk3.damage=30;
    two_atk3.usages=3;

    char at42[]="Solarbean";
    strcpy(two_atk4.name,at42);
    two_atk4.damage=40;
    two_atk4.usages=2;

    //Variaveis de Decisão
    int dec,dec2;


    //Menu de Batalha
    while(battle==1)
    {
        menu(one,two,ptr_battle);
        scanf("%d",&dec);
        puts( "\033[2J" );
        switch(dec)
        {
        case 1:
            menuBattle(one,two,one_atk1,one_atk2,one_atk3,one_atk4);
            scanf("%d",&dec2);
            nameATK(one,one_atk1,one_atk2,one_atk3,one_atk4,dec2);
            atack(ptr1,ptr2,chooseATK(one_atk1,one_atk2,one_atk3,one_atk4,dec2));
            break;
        case 4:
            return 0;
            break;
        default:
            printf("You did nothing\n");
            break;
        }
        dec2=rand() % 5;
        nameATK(two,two_atk1,two_atk2,two_atk3,two_atk4,dec2);
        atack(ptr2,ptr1,chooseATK(two_atk1,two_atk2,two_atk3,two_atk4,dec2));
    }
    puts( "\033[2J" );
    printf("####END GAME####");
    return 0;
}
