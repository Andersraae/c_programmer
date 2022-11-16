#include <stdio.h>

typedef struct bilkort{
    char navn[20];
    int kmt;
    int hk;
    int acc;
    int ccm;
} bilkort;

void printBilkort(bilkort kort);
bilkort hurtigst(bilkort bil1, bilkort bil2);

int main(int argc, char const *argv[]){
    bilkort lotus = {"Lotus", 200, 110, 8, 1973};
    bilkort mercedes = {"Mercedes", 215, 116, 9, 4520};

    printBilkort(lotus);
    printf("\n");
    printBilkort(mercedes);
    printf("\n");
    
    bilkort hurtigste = hurtigst(lotus, mercedes);
    printf("Den hurtigste bil er %s \n", hurtigste.navn);
    return 0;
}

void printBilkort(bilkort kort){
    printf("Navn: %s \n", kort.navn);
    printf("Kmt: %d \n", kort.kmt);
    printf("Hk: %d \n", kort.hk);
    printf("Acc: %d \n", kort.acc);
    printf("Ccm: %d \n", kort.ccm);
};


bilkort hurtigst(bilkort bil1, bilkort bil2){
    if (bil1.kmt > bil2.kmt)
    {
        // printf("Den hurtigste bil er %s", bil1.navn);
        return bil1;
    } else {
        // printf("Den hurtigste bil er %s", bil2.navn);
        return bil2;
    }
    
}

