#include<stdio.h>


void atack(monster *one,monster *two,int atak)
{
    (*two).life =(*two).life - atak;
    printf("%s deals %d damage in %s.\n",(*one).name,atak,(*two).name);
}
int chooseATK(atacks atk1,atacks atk2,atacks atk3,atacks atk4,int choose)
{
    switch(choose)
    {
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
void nameATK(monster one,atacks atk1,atacks atk2,atacks atk3,atacks atk4,int choose)
{
    switch(choose)
    {
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
