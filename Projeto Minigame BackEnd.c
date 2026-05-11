#include <stdio.h>
#include <stdlib.h>

void renderizarMapa(char *m[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if (m[i][j] != NULL){ // Se o conteúdo da matriz não estiver vazio, printe o conteúdo dela 
            printf("%s\t", m[i][j]);
            }
            else{ // Caso esteja vazio, printe "."
                printf(".\t");
            }
        }
    printf("\n");
    }
}

typedef struct{
    int vida;
    int posicaox;
    int posicaoy;
}Player;

int main() {
   char *mapa[10][10] = {{NULL}}; // Essencial setar o ponteiro como null antes de utilizar
   int i, j, menu;
   Player jogador;
   
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
   renderizarMapa(mapa);
    printf("\n");
    printf("Player sendo alterado... (TESTE)\n");
    
    mapa[2][2] = NULL; // Posição anterior fica vazia
    mapa[2][3] = "🏃"; // Nova posição atualizada com o personagem
    
    renderizarMapa(mapa);
    
    break;
}// Fim do case aqui
    return 0;
}
