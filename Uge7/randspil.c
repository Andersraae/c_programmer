#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getRandNum(int *num1, int *num2, int *num3);

int main(int argc, char const *argv[])
{
    int input, n1, n2, n3;

    printf("Indtast et tal mellem 1 og 10 \n");
    scanf("%d", &input);

    getRandNum(&n1, &n2, &n3);

    if ((input == n1) || (input == n2) || (input == n3)){
        printf("Spiller vandt");
    } else {
        printf("Spiller taber");
    }
    
    return 0;
}

void getRandNum(int *num1, int *num2, int *num3){
    srand(time(NULL));
    printf("%d", rand());
    *num1 = (rand() % 10) + 1;
    *num2 = (rand() % 10) + 1;
    *num3 = (rand() % 10) + 1;
}
