#include <stdio.h>

void scale(int faktor, int gammelpl, int gammelpb, int *nyplp, int *nypbp);

int main(int argc, char const *argv[])
{
    int gammelpl = 5, gammelpb = 3;
    int nypl, nypb;
    int faktor = 2;

    scale(faktor, gammelpl, gammelpb, &nypl, &nypb);

    printf("Ny laengde: %d \n", nypl);
    printf("Ny bredde: %d \n", nypb);

    return 0;
}

void scale(int faktor, int gammelpl, int gammelpb, int *nyplp, int *nypbp){
    *nyplp = gammelpl * faktor;
    *nypbp = gammelpb * faktor;
}