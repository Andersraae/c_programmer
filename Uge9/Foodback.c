#include <stdio.h> 

void udskift(char str[], char bog1, char bog2);

int main(int argc, char const *argv[])
{
    char streng[] = "Foodback";

    printf("Streng %s \n", streng);
    printf("Vi udskifter \n");

    udskift(streng, 'o', 'e');

    printf("Streng: %s \n", streng);
    return 0;
}

void udskift(char str[], char c1, char c2){
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] == c1){
            str[i] = c2;
        }
        i++;
    }
}

