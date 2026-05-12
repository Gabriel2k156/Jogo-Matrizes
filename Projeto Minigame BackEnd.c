#include <stdio.h>
#include <stdlib.h>

#define PAREDE '1' // Definição de constantes para fácil utilização e leitura do código
#define POLICIAL '2'
#define MOEDA '$'
#define VAZIO '.'

typedef struct Player{ // Struct com nome Player (para ser lido corretamente pela função RenderizarMapa)
    int vida;
    int pontuacao;
    int posicaox;
    int posicaoy;
    int posicaoxtemp;
    int posicaoytemp;
} Player; // Alias da struct, para ser lido corretamente pelas demais funções

void renderizarMapa(char m[10][10], struct Player *p){ // Struct sendo passado como parâmetro para ser lido pelo laço for
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(i == p->posicaox && j == p->posicaoy){ // Se i e j forem iguais a posição do jogador, imprima 🏃
            printf("🏃\t");
        }
            else if(m[i][j] == MOEDA){ // Caso encontre um "$" no código, substitui pelo emoji
                printf("💰\t");
            }
            else if(m[i][j] == POLICIAL){  // Caso encontre um "2" no código, substitui pelo emoji
                printf("👮\t");
            }
            else if(m[i][j] == PAREDE){  // Caso encontre um "1" no código, substitui pelo emoji
                printf("█\t");
            }
            else if (m[i][j] == VAZIO){
            printf(".\t"); // Se o conteúdo da matriz não for vazio E NÃO FOR IGUAL A POSIÇÃO DO JOGADOR, imprima seu conteúdo
            }
            
            else{ // Caso esteja vazio, printe "."
                printf(".\t");
            }
        }
    printf("\n"); // Quebra de linha para organização
    }
}

void MoverParaCima(Player *c){ // Diminui o valor x da matriz em 1, fazendo com que o player vá para cima
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
   char mapa[10][10]; // Essencial setar o ponteiro como null antes de utilizar
   int i, j, menu;
   int escolha = 1;
   char direcao;
   
   for(i = 0; i < 10; i++){ // Inicializa a matriz, removendo o lixo de memória e o substituindo por "."
       for(j = 0; j < 10; j++){
           mapa[i][j] = VAZIO;
       }
   }
   
   Player p;
   
   /*👮█💰🏃*/
   
   p.posicaox = 1; // Cima para baixo
   p.posicaoy = 2; // Esquerda para direita
   
   mapa[2][3] = POLICIAL;
   mapa[0][0] = PAREDE;
   mapa[3][3] = MOEDA;
   
   mapa[0][1] = PAREDE;
   mapa[0][2] = PAREDE;
   

printf("——— Policia e Ladrão ———\nDigite 1 para jogar ou 0 para sair\n");
scanf("%d", &menu);

switch(menu){
    
    case 0:
        printf("Saindo...\n");
        break;
    
    case 1:
        while (escolha == 1){
            printf("\n");
            renderizarMapa(mapa, &p);
    
         printf("Para onde ir? Digite 'w a s d' e digite ENTER\n");
            scanf(" %c", &direcao);
    
            if(direcao == 'w'){
                if(mapa[p.posicaox - 1][p.posicaoy] != PAREDE){ // Verifica se o local que o player quer ir é uma parede
                    MoverParaCima(&p);
                }
                else{
                    printf("Bateu na parede, movimento invalido!\n");
                }
            }           
            
            if(direcao == 's'){
                if(mapa[p.posicaox + 1][p.posicaoy] != PAREDE){
                    MoverParaBaixo(&p);
                }
                else{
                    printf("Bateu na parede, movimento invalido!\n");
                }
            }
            
            if(direcao == 'a'){
                if(mapa[p.posicaox][p.posicaoy - 1] != PAREDE){
                    MoverParaEsquerda(&p);
                }
                else{
                    printf("Bateu na parede, movimento invalido!\n");
                }
            }
            
            if(direcao == 'd'){
                if(mapa[p.posicaox][p.posicaoy + 1] != PAREDE){
                    MoverParaDireita(&p);
                }
                else{
                    printf("Bateu na parede, movimento invalido!\n");
                }
            }
    
            printf("\nNova posicao X do player = %d\n", p.posicaox);
            printf("Nova posicao Y do player = %d\n", p.posicaoy);
        }
    
}// Fim do case aqui
    return 0;
}
