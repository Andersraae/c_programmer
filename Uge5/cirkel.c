#include <stdio.h>
#include <math.h>

#define PI 3.14159

double RegnOmkreds(double r);
void PrintOmkreds(double r);

int main(void)
{
    double r;

    printf("Skriv radius af cirklen: \n");
    scanf("%lf", &r);

    PrintOmkreds(r);

    return 0;
}

double RegnOmkreds(double r){
    double omkreds = 2 * PI * r;
    return omkreds;
}

void PrintOmkreds(double r){
    double omkreds = RegnOmkreds(r);
    printf("%lf", omkreds);
}