#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *alvor(char *str);

int main(int argc, char const *argv[])
{
    char *str;

    scanf("%s", &*str);

    str = alvor(str);

    printf("%s", str);

    free(str);
    return 0;
}

char *alvor(char *str){
    char *str2 = (char *) malloc((strlen(str) + 2) * sizeof(char));
    printf("Størrelse %d og %d \n", strlen(str), strlen(str2));
    int i = 0;

    if (*str2 == NULL){
        exit(EXIT_FAILURE);
    }
    

    while (str[i] != '\0')
    {
        str2[i] = str[i];
        i++;
        printf("%s", str2[i]);
    }

    str2[i] = '!';
    str2[i+1] = '\0';
    
    return str2;
}
