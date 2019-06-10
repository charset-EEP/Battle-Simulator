#include <stdio.h>
#include <stdlib.h>

void status(monster two)
{
    if(two.life<=0)
    {
        printf("#%s        DEAD\n",two.name);
        printf("HP:DEAD   ");
    }
    else
    {
        printf("#%s        normal\n",two.name);
        printf("HP:%d   ",two.life);
    }
    printf("\n");
}
void menu(monster one,monster two,int *battle)
{
    if(two.life<=0||one.life<=0)
    {
        *battle=0;
        status(two);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        status(one);
        if(one.life<=0&&two.life<=0)
        {
            printf("Battle End, DRAW.\n");
        }
        else if(one.life<=0)
        {
            printf("Battle End,%s Winner.\n",two.name);
        }
        else if(two.life<=0)
        {
            printf("Battle End,%s Winner.\n",one.name);
        }

        printf("1-END//Click 5");
        printf("\t2-END//Click 5\n");
        printf("3-END//Click 5");
        printf("\t4-END//Click 5\n:");
    }
    else
    {
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
void menuBattle(monster one,monster two,atacks atk1,atacks atk2,atacks atk3,atacks atk4)
{
    status(two);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    status(one);
    printf("What you gonna do?\n");
    printf("1-%s",atk1.name);
    printf("\t 2-%s\n",atk2.name);
    printf("3-%s",atk3.name);
    printf("\t 4-%s\n:",atk4.name);
}
