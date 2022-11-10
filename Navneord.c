#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkWord(char s[]);

int main(void)
{
    char *words[] = {"chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish"};

    for (int i = 0; i < sizeof(words); i++)
    {
        checkWord(words[i]);
    }

    return 0;
}

void checkWord(char s[])
{
    // char es[] = "es";
    int size = strlen(s) - 1;
    // char *newword = (char *) malloc((strlen(s) + 4) * sizeof(char));

    char *word = (char *)malloc((strlen(s) + 4) * sizeof(char));
    strcpy(word, s);

    switch (word[size]) {
        case 'y':
            // strncat(word, "ies", size);
            word[size] = 'i';
            strcat(word, "es\0");
            printf("%s\n", word);
            break;

        case 's':
            strcat(word, "es\0");
            printf("%s \n", word);
            break;

        case 'h':
            if (word[size - 1] == 'c' || word[size - 1] == 's')
            {
                strcat(word, "es\0");
                printf("%s \n", word);
            }

            break;
        default:
            strcat(word, "s\0");
            printf("%s\n", word);
            break;
    }
}
