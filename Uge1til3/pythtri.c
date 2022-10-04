#include <stdio.h> //Inkluder scan og print

int main(void)
{
    int m, n; //Definer input variable
    int side1, side2, hypo;

    printf("Indsaet heltal m og n, hvor m > n \n");
    scanf("%d %d", &m, &n); //Modtag input fra bruger

    printf("m er %d, n er %d \n", m, n);

    //Udregn sider og hyp
    side1 = m*m - n*n;
    side2 = 2*m*n;
    hypo = m*m + n*n;

    printf("Side 1 = %d, Side 2 = %d, Hypotenusen = %d \n", side1, side2, hypo);


    return 0;
}
