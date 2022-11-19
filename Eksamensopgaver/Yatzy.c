#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROUNDS 15
int *results;
int resultindex;

void throwDice(int dice[], int n);
void oneToSix(int dice[], int n);
void pairs(int dice[], int n);
void alike(int dice[], int n);
void smallBig(int dice[], int n);
void fullHouse(int dice[], int n);
void chance(int dice[], int n);
void yatzy(int dice[], int n);
int compareInt(const void *pa, const void *pb);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    results = (int *) malloc(ROUNDS * sizeof(int));
    resultindex = 0;
    int total = 0;
    int n = 0;
    for (int i = 0; i < ROUNDS; i++)
    {
        results[i] = 0;
    }
    
    printf("Hvor mange terninger vil du kaste? (Alt under 5 terninger programmet) ");
    scanf("%d", &n);
    if (n < 5){
        return 0;
    }
    
    printf("\n");
    int *dice = (int *) malloc(n * sizeof(int));

    printf("printer terninger: \n");
    oneToSix(dice, n);
    pairs(dice, n);
    alike(dice, n);
    smallBig(dice, n); 
    fullHouse(dice, n);
    chance(dice, n);
    yatzy(dice, n);

    int bonus = 1;
    for (int i = 0; i < 6; i++)
    {
        if (results[i] == 0){
            bonus = 0;
            break;
        }
        
    }
    
    bonus = bonus ? 50 : 0;
    total += bonus; // Tilføj bonus

    results[0] = results[0] > 5 ? 5 : results[0];
    results[1] = results[1] > 10 ? 10 : results[1];
    results[2] = results[2] > 15 ? 15 : results[2];
    results[3] = results[3] > 20 ? 20 : results[3];
    results[4] = results[4] > 25 ? 25 : results[4];
    results[5] = results[5] > 30 ? 30 : results[5];

    printf("\nScore board: \n");
    for (int i = 1; i <= 6; i++){
        printf("%d-ere: %d \n", i, results[i - 1]);
    }
    printf("Bonus: %d \n", bonus);
    printf("1 par: %d \n", results[6]);
    printf("2 par: %d \n", results[7]);
    printf("3 ens: %d \n", results[8]);
    printf("4 ens: %d \n", results[9]);
    printf("Lille: %d \n", results[10]);
    printf("Stor: %d \n", results[11]);
    printf("Fuldt hus: %d \n", results[12]);
    printf("Chance: %d \n", results[13]);
    printf("Yatzy: %d \n", results[14]);
    for (int i = 0; i < ROUNDS; i++){
        total += results[i];
    }
    printf("TOTAL: %d", total);
    
    return 0;
}

void throwDice(int dice[], int n){
    for (int i = 0; i < n; i++){ // Kast n antal terninger
        dice[i] = rand() % 6 + 1;
    }
}

void oneToSix(int dice[], int n){
    for (int i = 1; i <= 6; i++){ // Tjek for i øjne
        throwDice(dice, n);
        printf("%d-ere: ", i);
        for (int k = 0; k < n; k++){
            printf("%d ", dice[k]);
        }
        for (int j = 0; j < n; j++){
            if (dice[j] == i){
                results[resultindex] += i;
            }
        }
        printf("-- %d \n", results[resultindex]);
        resultindex++;
    }
}

void pairs(int dice[], int n){
    int bestpair = 0;
    for (int h = 1; h <= 2; h++){ // 1 par og 2 par
        throwDice(dice, n);
        qsort(dice, n, sizeof(int), compareInt);
        for (int i = 6; i > 0 ; i--){ //Start med at søge efter 6-ere
            for (int j = 1; j < n; j++){
                if (dice[j] == dice[j - 1]){
                    results[resultindex] = dice[j] + dice[j - 1];  
                    bestpair = dice[j];
                    break;
                }                
            }                
        }
        if (h == 2){ // Hvis der ledes efter 2 par
            for (int j = 1; j < n; j++){
                if (dice[j] == dice[j - 1] && dice[j] != bestpair){
                    results[resultindex] += dice[j] + dice[j - 1];
                    printf("2 par: ");
                    for (int k = 0; k < n; k++){
                        printf("%d ", dice[k]);
                    }
                    printf("-- %d \n", results[resultindex]);
                    break;
                }
            }
        } else if (h == 1){
            printf("1 par: ");
            for (int k = 0; k < n; k++){
                printf("%d ", dice[k]);
            }
            printf("-- %d \n", results[resultindex]);
        }
        resultindex++;
    }
}

void alike(int dice[], int n){
    for (int h = 3; h <= 4; h++){    
        int current = 0;
        throwDice(dice, n);
        qsort(dice, n, sizeof(int), compareInt);
        for (int i = 6; i > 0 ; i--){ //Start med at søge efter 6-ere
            for (int j = 1; j < n; j++){ // Gå gennem alle slag
                if (dice[j] == dice[j - 1]){ // Hvis dette slag er magen til sidste
                    current++;
                    if (current == h){
                        results[resultindex] = h * dice[j];
                        printf("%d ens: ", h);
                        for (int k = 0; k < n; k++){
                            printf("%d ", dice[k]);
                        }
                        printf("-- %d \n", results[resultindex]);
                        break;
                    } 
                }                
            }    
            current = 0;
            if (results[resultindex] != 0){
                break;
            }
            
        }
        resultindex++;
    }
}
    
void smallBig(int dice[], int n){
    for (int h = 0; h <= 1; h++){
        throwDice(dice, n);
        qsort(dice, n, sizeof(int), compareInt);
        int exists;
        for (int i = 5 + h; i >= 1 + h; i--){ // Søger efter small først, så big
            exists = 0;
            for (int j = 0; j < n; j++){
                if (dice[j] == i){
                    exists = 1;
                }
            }
            if (!exists){
                break;
            }
        }
        if (exists){
            if (resultindex == 10){
                results[resultindex] = 15;
                printf("Lille: ");
            } else if (resultindex == 11) {
                results[resultindex] = 20;
                printf("Stor: ");
            }
            for (int k = 0; k < n; k++){
                printf("%d ", dice[k]);
            }
            printf("-- %d \n", results[resultindex]);
        }
        resultindex++;
    }
    
}

void fullHouse(int dice[], int n){
    throwDice(dice, n);
    qsort(dice, n, sizeof(int), compareInt);
    int first = 0;
    int last = 0;
    for (int i = 1; i >= 0; i--){
        if (i){
            for (int j = 2; j < n; j++){
                if (dice[j] == dice[j - 1] && dice[j] == dice[j - 2]){
                    first = dice[j];
                    break;
                }
            }
            if (!first){
                break;
            }
        } else {
            for (int j = 1; j < n; j++){
                if (dice[j] == dice[j - 1] && dice[j] != first){
                    last = dice[j];
                    break;
                }
            }
        }
    }
    if (first && last){
        results[resultindex] = first * 3 + last * 2;

        printf("Fuldt hus: ");
        for (int k = 0; k < n; k++){
            printf("%d ", dice[k]);
        }
        printf("-- %d \n", results[resultindex]);
    }
    resultindex++;
}

void chance(int dice[], int n){
    throwDice(dice, n);
    qsort(dice, n, sizeof(int), compareInt);

    int counter = 0;
    for (int i = 0; i < 5; i++){
        results[resultindex] += dice[i];
    }
    
    printf("Chance: ");
    for (int k = 0; k < n; k++){
        printf("%d ", dice[k]);
    }
    printf("-- %d \n", results[resultindex]);
    resultindex++;
}

void yatzy(int dice[], int n){
    throwDice(dice, n);
    qsort(dice, n, sizeof(int), compareInt);

    int counter = 1;
    for (int i = 6; i >= 1; i--){
        for (int j = 1; j < n; j++){
            if (dice[j] == dice[j - 1]){
                counter++;
                if (counter == 5){
                    results[resultindex] = 5 * dice[j];
                    break;
                }
            }
            if (counter == 5){
                break;
            }
        }
        counter = 1;
    }
    printf("Yatzy: ");
    for (int k = 0; k < n; k++)
    {
        printf("%d ", dice[k]);
    }
    printf("-- %d", results[resultindex]);
}

int compareInt(const void *pa, const void *pb){ // Sorter tal fra høj til lav
    const int *p1 = pa;
    const int *p2 = pb;
    return *p2 - *p1;
}
