#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum forret {guacamole, tarteletter, lakserulle, graeskarsuppe} forret;
typedef enum hovedret {gyldenkaal, hakkeboef, gullash, forloren_hare} hovedret;
typedef enum dessert {pandekagermedis, gulerodskage, chokolademousse, citronfromage} dessert;

int getRandNum(int *forret, int *hovedret, int *dessert);
void maaltid(forret f, hovedret h, dessert d);

int main(void) {

    srand(time(NULL));

    int maaltid_f, maaltid_h, maaltid_d;

    for (int i = 1; i <= 25; i++) {
        printf("\nMaaltid nr. %d: ", i);
        getRandNum(&maaltid_f, &maaltid_h, &maaltid_d);
    
        enum forret f = maaltid_f;
        enum hovedret h = maaltid_h;
        enum dessert d = maaltid_d;
        
        maaltid(f, h, d);
    }
    
    return 0;
}

void maaltid(forret f, hovedret h, dessert d) {
    //Forret
    switch (f){
    case guacamole:
        printf("Guacamole");
        break;
    case tarteletter:
        printf("Tarteletter");
        break;
    case lakserulle:
        printf("Lakserulle");
        break;
    case graeskarsuppe:
        printf("Graeskarsuppe");
        break;
    }
    printf(", ");
    
    //Hovedret
    switch (h){
    case gyldenkaal:
        printf("gyldenkaal");
        break;
    case hakkeboef:
        printf("hakkeboef");
        break;
    case gullash:
        printf("gullash");
        break;
    case forloren_hare:
        printf("forloren_hare");
        break;
    }
    printf(", ");

    //Dessert
    switch (d){
    case pandekagermedis:
        printf("pandekagermedis");
        break;
    case gulerodskage:
        printf("gulerodskage");
        break;
    case chokolademousse:
        printf("chokolademousse");
        break;
    case citronfromage:
        printf("citronfromage");
        break;
    }
}

int getRandNum(int *forret, int *hovedret, int *dessert){
    *forret = (rand() % 4);
    *hovedret = (rand() % 4);
    *dessert = (rand() % 4);
}