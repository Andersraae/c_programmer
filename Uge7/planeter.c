#include <stdio.h>

typedef enum planet {Merkur, Venus, Jorden, Jupiter, Saturn, Uranus, Neptun} planet;

void circumference(planet p);
void next(planet p);

int main(void)
{
    planet p;
    p = Neptun;

    next(p);
    circumference(p);
    return 0;
}

void circumference(planet p){
    switch (p){
    case Merkur:
        printf("Mere end 2");
        break;
    case Venus:
        printf("Også mere end 2");
        break;
    case Jorden:
        printf("Noget med 41");
        break;
    case Jupiter:
        printf("Ret meget mere end 2");
        break;
    case Saturn:
        printf("Fucking meget mere end 2");
        break;
    case Uranus:
        printf("Jeg ved det ikke");
        break;
    case Neptun:
        printf("Det er Neptun");
        break;
    }
    printf("\n");
}

void next(planet p){
    int num = p;
    num++;
    planet pl = num;
    switch (pl){
    case Merkur:
        printf("Merkur");
        break;
    case Venus:
        printf("Venus");
        break;
    case Jorden:
        printf("Jorden");
        break;
    case Jupiter:
        printf("Jupiter");
        break;
    case Saturn:
        printf("Saturn");
        break;
    case Uranus:
        printf("Uranus");
        break;
    case Neptun:
        printf("Neptun");
        break;
    default:
        printf("Der er ikke flere planeter");
        break;
    }
    printf("\n");
}