#include <stdio.h>
#include <stdlib.h>
#define ASCII_ESC 27

typedef struct{
char name[30];
int life;
}monster;

typedef struct{
char name[30];
int damage;
char type[30];
int usages;
int extraTurns;
int voidTurn;
char efect[30];
}atacks;

void atack(monster *one,monster *two,int atak){
(*two).life =(*two).life - atak;
printf("%s deals %d damage in %s.\n",(*one).name,atak,(*two).name);
}
void status(monster two){
    if(two.life<=0){
    printf("#%s        DEAD\n",two.name);
    printf("HP:DEAD   ");}else{
    printf("#%s        normal\n",two.name);
    printf("HP:%d   ",two.life);}
    printf("\n");
    }
void menu(monster one,monster two,int *battle){
    if(two.life<=0||one.life<=0){
    *battle=0;
    status(two);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    status(one);
    if(one.life<=0&&two.life<=0){
    printf("Battle End, DRAW.\n");}
    else if(one.life<=0){
    printf("Battle End,%s Winner.\n",two.name);}
    else if(two.life<=0){
    printf("Battle End,%s Winner.\n",one.name);}

    printf("1-END//Click 5");
    printf("\t2-END//Click 5\n");
    printf("3-END//Click 5");
    printf("\t4-END//Click 5\n:");
    }else{
    status(two);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    status(one);
    printf("What you gonna do?\n");
    printf("1-Atack");
    printf("\t2-Capture\n");
    printf("3-Bag");
    printf("\t4-Run\n:");
    }
}
void menuBattle(monster one,monster two,atacks atk1,atacks atk2,atacks atk3,atacks atk4){
    status(two);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    status(one);
    printf("What you gonna do?\n");
    printf("1-%s",atk1.name);
    printf("\t 2-%s\n",atk2.name);
    printf("3-%s",atk3.name);
    printf("\t 4-%s\n:",atk4.name);
    }
int chooseATK(atacks atk1,atacks atk2,atacks atk3,atacks atk4,int choose){
    switch(choose){
    case 1:
    return atk1.damage;
    break;
    case 2:
    return atk2.damage;
    break;
    case 3:
    return atk3.damage;
    break;
    case 4:
    return atk4.damage;
    break;
    default:
    return 10;
    break;
    }
    }
void nameATK(monster one,atacks atk1,atacks atk2,atacks atk3,atacks atk4,int choose){
    switch(choose){
    case 1:
    printf("%s used %s,  ",one.name,atk1.name);
    break;
    case 2:
    printf("%s used %s,  ",one.name,atk2.name);
    break;
    case 3:
    printf("%s used %s,  ",one.name,atk3.name);
    break;
    case 4:
    printf("%s used %s,  ",one.name,atk4.name);
    break;
    default:
    printf("%s used body,  ",one.name);
    break;
    }
    }
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
    char at12[]="Scrach";
    char at22[]="Growl";
    char at32[]="Vine Whipe";
    char at42[]="Solarbean";
    //strcpy(two.Natack1,at12);
    //strcpy(two.Natack2,at22);
    //strcpy(two.Natack3,at32);
    //strcpy(two.Natack4,at42);
    //two.atack1=20;
    //two.atack2=30;
    //two.atack3=40;
    //two.atack4=50;

    //Variaveis de Decisão
    int dec,dec2;


    //Menu de Batalha
    while(battle==1){
    menu(one,two,ptr_battle);
    scanf("%d",&dec);
    puts( "\033[2J" );
    switch(dec){
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
    dec2=rand() % 6;
    //nameATK(two,dec2);
    //atack(ptr2,ptr1,chooseATK(two,dec2));
    }
    puts( "\033[2J" );
    printf("####END GAME####");
    return 0;
}
