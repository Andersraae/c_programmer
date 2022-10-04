#include <stdio.h>

int main(void)
{
    double p1x, p1y, p2x, p2y, p3x, p3y; //Punkter
    double dy, dx, len1, len2, len3, lensum; //Længder

    //Scanner dine koordinater
    printf("Indtast koordinater for p1> \n");
    scanf("%lf %lf", &p1x, &p1y);
    printf("Indtast koordinater for p2> \n");
    scanf("%lf %lf", &p2x, &p2y);
    printf("Indtast koordinater for p3> \n");
    scanf("%lf %lf", &p3x, &p3y);

    //Mellem p1 og p2
    dy = p1y - p2y;
    dx = p1x - p2x;
    len1 = sqrt(dy*dy + dx*dx);

    //Mellem p2 og p3
    dy = p2y - p3y;
    dx = p2x - p3x;
    len2 = sqrt(dy*dy + dx*dx);

    //Mellem p3 og p1
    dy = p3y - p1y;
    dx = p3x - p1x;
    len3 = sqrt(dy*dy + dx*dx);

    lensum = len1 + len2 + len3;

    printf("%lf \n", lensum);

    return 0;
}
