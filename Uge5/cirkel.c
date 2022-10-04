#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

double RegnOmkreds(double r);
void PrintOmkreds(double r);
void OmkredsAlt(double r);
void Areal(double r);

int main(void)
{
    double r;
    char valg;

    printf("Vil du udregne omkreds(o) eller areal(a) af cirklen? \n");
    scanf("%c", &valg);

    if (valg == 'o'){
        printf("Skriv radius af cirklen: \n");
        scanf("%lf", &r);
        //PrintOmkreds(r);
        OmkredsAlt(r);

    } else if (valg == 'a'){
        printf("Skriv radius af cirklen: \n");
        scanf("%lf", &r);
        Areal(r);
    }

    return 0;
}

double RegnOmkreds(double r){
    double omkreds = 2 * M_PI * r;
    return omkreds;
}

void PrintOmkreds(double r){
    double omkreds = RegnOmkreds(r);
    printf("Omkreds: %lf \n", omkreds);
}

void OmkredsAlt(double r){
    double omkreds = 2 * M_PI * r;
    printf("Omkreds: %lf \n", omkreds);
}

void Areal(double r){
    double areal = M_PI * pow(r, 2);
    printf("Areal: %lf \n", areal);
}

