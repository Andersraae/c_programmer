#include <stdlib.h>

typedef struct planet
{
    char navn[20];
    double volumen;
    double masse;
} planet;

double massefylde(planet jens);

int main(int argc, char const *argv[])
{
    planet planet1 = {"planeten", 200, 500};
    planet planet2 = {"Anden planet", 200000, 4040940};

    double massefylden = massefylde(planet1);
    printf("Massefylden er %lf km^3/kg \n", massefylden);
    double massefylden2 = massefylde(planet2);
    printf("Den anden massefylde er %lf km^3/kg \n", massefylden2);

    return 0;
}

double massefylde(planet jens){
    return jens.volumen/jens.masse;
}
