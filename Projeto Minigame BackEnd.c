#include <stdio.h>
#include <stdlib.h>

int main() {
   char *mapa[10][10] = {{NULL}}; // Essencial setar o ponteiro como null antes de utilizar
   int i, j, menu;
   
   
   mapa[0][0] = "👮";
   mapa[1][1] = "█";
   mapa[2][2] = "🏃";
   mapa[3][3] = "💰";

printf("——— Policia e Ladrão ———\nDigite 1 para jogar ou 0 para sair\n");
scanf("%d", &menu);

switch(menu){
    
    case 0:
        printf("Saindo...\n");
        break;
    
    case 1:
    printf("\n");
   for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if (mapa[i][j] != NULL){ // Se o conteúdo da matriz não estiver vazio, printe o conteúdo dela 
            printf("%s\t", mapa[i][j]);
            }
            else{ // Caso esteja vazio, printe "."
                printf(".\t");
            }
        }
    printf("\n");
    }
    break;
}// Fim do case aqui
    return 0;
}
