#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

int main() {
   char *mapa[5][5] = {{NULL}}; // Essencial setar o ponteiro como null antes de utilizar
   int i, j;
   
/* F = Caçador
   L = Lobo
   O = Ovelha */
   
   mapa[0][0] = "F";
   mapa[1][1] = "L";
   mapa[2][2] = "O";

   for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if (mapa[i][j] != NULL){ // Se o conteúdo da matriz não estiver vazio, printe o conteúdo dela 
            printf("%s\t", mapa[i][j]);
            }
            else{ // Caso esteja vazio, printe "."
                printf(".");
                printf("\t");
            }
        }
    printf("\n");
    }

   
    return 0;
}