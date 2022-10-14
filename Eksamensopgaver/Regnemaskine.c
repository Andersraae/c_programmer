#include <stdio.h> 
#include <math.h>

void run_calculator(void);
void scan_data(char *opperator, double *opperand);
void do_next_up(char opperator, double opperand, double num, double *number);
int is_binary(char opperator);

int main(int argc, char const *argv[])
{
    run_calculator();
    return 0;
}

void run_calculator(){
    double number = 0.0;
    char opperator;
    double opperand = 0.0;

    while (1){
        scan_data(&opperator, &opperand);
        do_next_up(opperator, opperand, number,  &number);

        if (opperator == 'q'){
            printf("Your final result is %lf \n", number);
            break;
        } else {
            printf("Result so far is %lf \n", number);  
        }
    }

}

void scan_data(char *opperator, double* opperand){
    //Temporary variables for overwriting opperator and opperand
    printf("Enter operator: \n");
    scanf(" %c", &*opperator);
    if (is_binary(*opperator)){
        printf("Enter optional operand: \n");
        scanf("%lf", &*opperand);
    }
}

void do_next_up(char opperator, double opperand, double num, double *number){
    switch (opperator)
    {
    case '+':
        printf("+ \n");
        *number = num + opperand;
        break;
    case '-':
        *number = num - opperand;
        break;
    case '*':
        *number = num * opperand;
        break;
    case '/':
        if (num != 0)
        {
            *number = num / opperand;
        }
        break;
    case '^':
        *number = pow(num, opperand);
        break;
    case '#':
        if (num >= 0)    
        {
            *number = sqrt(num);
        }
        break;
    case '%':
        *number = -num;
        break;
    case '!':
        *number = 1 / num;
        break;
    default:
        break;
    }
}

int is_binary(char opperator){
    switch (opperator){
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 1;
    case '/':
        return 1;
    case '^':
        return 1;
    default:
        return 0;
    }
    return 0;
}
