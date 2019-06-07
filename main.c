#include <stdio.h>
#include <stdlib.h>
#define ASCII_ESC 27

typedef struct{
char name[30];
int life;
int atack;
int sp;
int atack1;
char Natack1[30];
int atack2;
char Natack2[30];
int atack3;
char Natack3[30];
int atack4;
char Natack4[30];
}monster;

void atack(monster *one,monster *two,int atak){
(*one).atack=atak;
if((*one).sp>0){
(*one).sp=(*one).sp-5;
(*two).life =(*two).life - (*one).atack;
printf("%s deals %d damage in %s.\n",(*one).name,(*one).atack,(*two).name);
}
}
void status(monster two){

    if(two.life<=0){
    printf("#%s        DEAD\n",two.name);
    printf("HP:DEAD   ");}else{
    printf("#%s        normal\n",two.name);
    printf("HP:%d   ",two.life);}
    if(two.sp<=0){
    printf("SP:No more SP   ");}else{
    printf("SP:%d   ",two.sp);}
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
void menuBattle(monster one,monster two){
    status(two);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    status(one);
    printf("What you gonna do?\n");
    printf("1-%s",one.Natack1);
    printf("\t 2-%s\n",one.Natack2);
    printf("3-%s",one.Natack3);
    printf("\t 4-%s\n:",one.Natack4);
    }
int main()
{
    int battle=1;
    int *ptr_battle=&battle;

    monster one;
    char one_name[]="Charmander";
    strcpy(one.name,one_name);
    one.life=100;
    one.atack=10;
    one.sp=50;
    monster *ptr1=&one;
    char at1[]="Scrach";
    char at2[]="Growl";
    char at3[]="Ember";
    char at4[]="Tail Whip";
    strcpy(one.Natack1,at1);
    strcpy(one.Natack2,at2);
    strcpy(one.Natack3,at3);
    strcpy(one.Natack4,at4);
    one.atack1=20;
    one.atack2=30;
    one.atack3=40;
    one.atack4=50;
    monster two;
    char two_name[]="Bulbassaur";
    strcpy(two.name,two_name);
    two.life=100;
    two.atack=10;
    two.sp=50;
    monster *ptr2=&two;

    int dec,atac;

    while(battle==1){
    menu(one,two,ptr_battle);
    scanf("%d",&dec);
    puts( "\033[2J" );
    switch(dec){
    case 1:
    menuBattle(one,two);
    scanf("%d",&atac);
    switch(atac){
    case 1:
    atac=one.atack1;
    printf("%s used %s,\t",one.name,one.Natack1);
    atack(ptr1,ptr2,atac);
    break;
    case 2:
    atac=one.atack2;
    printf("%s used %s,\t",one.name,one.Natack2);
    atack(ptr1,ptr2,atac);
    break;
    case 3:
    atac=one.atack3;
    printf("%s used %s,\t",one.name,one.Natack3);
    atack(ptr1,ptr2,atac);
    break;
    case 4:
    atac=one.atack4;
    printf("%s used %s,\t",one.name,one.Natack4);
    atack(ptr1,ptr2,atac);
    break;
    default:
    atac=one.atack;
    atack(ptr1,ptr2,atac);
    break;
    }
    break;
    case 4:
    return 0;
    break;
    default:
    printf("You did nothing\n");
    break;
    }
    atack(ptr2,ptr1,two.atack);
    }
    puts( "\033[2J" );
    printf("####END GAME####");
    return 0;
}
