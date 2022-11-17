#include <stdio.h>
#include <stdlib.h>

int* throwDice(int n);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int total = 0;
    int n = 0;
    printf("Hvor mange terninger vil du kaste? ");
    scanf("%d", &n);
    printf("\n");

    int dice[n];
    dice[n] = throwDice(n);


    for (int i = 0; i < sizeof(dice) / sizeof(dice[0]); i++)
    {
        printf("%d ", dice[i]);
    }
    

    return 0;
}

int* throwDice(int n){
    int dice[n]; //Fix lige det her
    for (int i = 0; i < n; i++)
    {
        dice[i] = rand() % 6;
        printf("Dice[i] er %d", dice[i]);
    }
    
    return dice;
}
