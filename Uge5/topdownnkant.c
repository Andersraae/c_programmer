#include <stdio.h>
#include <math.h>

double regn_side(double pA_x, double pA_y, double pB_x, double pB_y);

int main(void){
    double last_x, last_y, temp_x, temp_y, samlet;
    int n;
    samlet = 0;
    
    printf("Hvor mange punkter har din form:\n");
    scanf("%d", &n);

    printf("Hvad er det foerste punkt? \n");
    scanf("%lf %lf", &last_x, &last_y);

    for (int i = 0; i < n-1; i++)
    {
        printf("Hvad er det naeste punkt? \n");
        scanf("%lf %lf", &temp_x, &temp_x);

        samlet += regn_side(last_x, last_y, temp_x, temp_y);
        temp_x = last_x;
        temp_y = last_y;
    }

    printf("Hvad var det foerste punkt? \n");
    scanf("%lf %lf", &temp_x, &temp_x);
    samlet += regn_side(last_x, last_y, temp_x, temp_y);

    printf("Den samlede laengde er %lf", samlet);

    return 0;
}

double regn_side(double pA_x, double pA_y, double pB_x, double pB_y){
  double delta_x = pA_x - pB_x;
  double delta_y = pA_y - pB_y;
  return sqrt(delta_x*delta_x + delta_y*delta_y);
}



