#include <stdio.h>  

int main(void)
{
    double r, x, y;
    double afstand;

    printf("Indtast r, x og y vaerdier> ");
    scanf("%lf %lf %lf", &r, &x, &y);

    afstand = sqrt(x*x + y*y);

    printf("%s", (afstand > r) ? "Punktet er udenfor cirklen" : (afstand == r) ? "Punktetner paa cirkelperiferien" : "Punktet er indenfor");    
    
    return 0;
}
