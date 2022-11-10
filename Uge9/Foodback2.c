#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

char *udskift2(char str[], char bog1, char bog2);

int main(int argc, char const *argv[])
{
    char streng[] = "Foodback";
    char *streng2;

    printf("Streng %s \n", streng);
    printf("Vi udskifter \n");

    streng2 = udskift2(streng, 'o', 'e');

    printf("Streng: %s \n", streng);
    printf("Streng 2: %s \n", streng2);

    free(streng2);

    return 0;
}

char *udskift2(char str[], char c1, char c2){
    char *str2 = (char *) malloc((strlen(str) + 1) * sizeof(char));
    int i = 0;

    if (str2 == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while (str[i] != '\0')
    {
        if (str[i] == c1){
            str2[i] = c2;
        } else {
            str2[i] = str[i];
        }
        i++;
    }

    str2[i] = '\0';
    
    return str2;
}

