#include <stdio.h> 

#define ROCK 'r'
#define SCISSOR 's'
#define PAPER 'p' 

int main(void){ 
    char spiller1, spiller2;
    int spiller1V, spiller2V;
    int tjek;

    printf("Spiller 1 -- tast valg> ");
    scanf("%c", &spiller1);

    while (1)
    {
        if(!(spiller1 == ROCK || spiller1 == PAPER || spiller1 == SCISSOR)){
        printf("Du skal indtaste enten r, p eller s> ");
        scanf("%c", &spiller1);
        } else {
            break;
        }
    }

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("Spiller 2 -- tast valg> ");
    scanf(" %c", &spiller2);

    while (1)
    {
        if(!(spiller2 == ROCK || spiller2 == PAPER || spiller2 == SCISSOR)){
        printf("Du skal indtaste enten r, p eller s> ");
        scanf("%c", &spiller1);
        } else {
            break;
        }
    }

    spiller1V = (spiller1 == ROCK && spiller2 == SCISSOR) 
    || (spiller1 == PAPER && spiller2 == ROCK)
    || (spiller1 == SCISSOR && spiller2 == PAPER);

    spiller2V = (spiller2 == ROCK && spiller1 == SCISSOR) 
    || (spiller2 == PAPER && spiller1 == ROCK)
    || (spiller2 == SCISSOR && spiller1 == PAPER);

    if (spiller1V){
        printf("Spiller 1 vandt");
    } else if (spiller2V){
        printf("Spiller 2 vandt");
    } else if (!spiller1V && !spiller2V){
        printf("Uafgjort");
    }


    return 0;
}
