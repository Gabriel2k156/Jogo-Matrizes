#include <stdio.h>
#include <stdlib.h>
#include <string.h> // A ser usado futuramente para validação da colisão do mapa

typedef struct Player{ // Struct com nome Player (para ser lido corretamente pela função RenderizarMapa)
    int vida;
    int pontuacao;
    int posicaox;
    int posicaoy;
} Player; // Alias da struct, para ser lido corretamente pelas demais funções

void renderizarMapa(char *m[10][10], struct Player *p){ // Struct sendo passado como parâmetro para ser lido pelo laço for
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(i == p->posicaox && j == p->posicaoy){ // Se i e j forem iguais a posição do jogador, imprima 🏃
            printf("🏃\t");
        }
            else if (m[i][j] != NULL){
            printf("%s\t", m[i][j]);// Se o conteúdo da matriz não for vazio, imprima seu conteúdo
            }
            
            else{ // Caso esteja vazio, printe "."
                printf(".\t");
            }
        }
    printf("\n"); // Quebra de linha para organização
    }
}

void MoverParaCima(Player *c){
    c->posicaox--;
}

void MoverParaBaixo(Player *c){
    c->posicaox++;
}

void MoverParaEsquerda(Player *c){
    c->posicaoy--;
}

void MoverParaDireita(Player *c){
    c->posicaoy++;
}

int main() {
   char *mapa[10][10] = {{NULL}}; // Essencial setar o ponteiro como null antes de utilizar
   int i, j, menu;
   char direcao;
   
   Player p;
   
   p.posicaox = 1; // Cima para baixo
   p.posicaoy = 2; // Esquerda para direita
   
   mapa[0][0] = "👮";
   mapa[1][1] = "█";
   mapa[3][3] = "💰";

printf("——— Policia e Ladrão ———\nDigite 1 para jogar ou 0 para sair\n");
scanf("%d", &menu);

switch(menu){
    
    case 0:
        printf("Saindo...\n");
        break;
    
    case 1:
    printf("\n");
    renderizarMapa(mapa, &p);
    printf("Para onde ir? Digite 'w a s d' e digite ENTER\n");
    scanf(" %c", &direcao); // Teste
    
    if(direcao == 's'){
        MoverParaBaixo(&p);
    }
    
   renderizarMapa(mapa, &p);
   printf("Nova posicao X do player = %d", p.posicaox);

    
}// Fim do case aqui
    return 0;
}
