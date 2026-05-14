#include <stdio.h>
#include <stdlib.h>

#define PAREDE '1' // Definição de constantes para fácil utilização e leitura do código
#define POLICIAL '2'
#define MOEDA '$'
#define VAZIO '.'

int  altura, largura; // Variáveis de altura e largura do mapa, declaradas de forma global para que sejam lidas pelas funções

typedef struct Player { // Struct com nome Player (para ser lido corretamente pela função RenderizarMapa)
	int vida;
	int pontuacao;
	int posicaox;
	int posicaoy;
	int posicaoxtemp;
	int posicaoytemp;
} Player; // Alias da struct, para ser lido corretamente pelas demais funções

void renderizarMapa(char *m, struct Player *p) { // Struct sendo passado como parâmetro para ser lido pelo laço for
	for(int i = 0; i < altura; i++) {
		for(int j = 0; j < largura; j++) {
			if(i == p->posicaox && j == p->posicaoy) { // Se i e j forem iguais a posição do jogador, imprima 🏃
				printf("🏃\t");
			}
			else if(m[i * largura + j] == MOEDA) { // Caso encontre um "$" no código, substitui pelo emoji
				printf("💰\t");
			}
			else if(m[i * largura + j] == POLICIAL) { // Caso encontre um "2" no código, substitui pelo emoji
				printf("👮\t");
			}
			else if(m[i * largura + j] == PAREDE) { // Caso encontre um "1" no código, substitui pelo emoji
				printf("█\t");
			}
			else if (m[i * largura + j] == VAZIO) {
				printf(".\t"); // Se o conteúdo da matriz não for vazio E NÃO FOR IGUAL A POSIÇÃO DO JOGADOR, imprima seu conteúdo
			}

			else { // Caso esteja vazio, printe "."
				printf(".\t");
			}
		}
		printf("\n"); // Quebra de linha para organização
	}
}

void MoverParaCima(Player *c, char *m) {
	if(m[(c->posicaox - 1) * largura + c->posicaoy] != PAREDE) {
		c->posicaox--;
	}
	else {
		printf("Bateu na parede, movimento invalido!\n");
	}
}

void MoverParaBaixo(Player *c,char *m) {
	if(m[(c->posicaox + 1) * largura + c->posicaoy] != PAREDE) {
		c->posicaox++;
	}
	else {
		printf("Bateu na parede, movimento invalido!\n");
	}
}

void MoverParaEsquerda(Player *c, char *m) {
	if(m[(c->posicaox) * largura + c->posicaoy - 1] != PAREDE) {
		c->posicaoy--;
	}
	else {
		printf("Bateu na parede, movimento invalido!\n");
	}
}

void MoverParaDireita(Player *c, char *m) {
	if(m[(c->posicaox) * largura + c->posicaoy + 1] != PAREDE) {
		c->posicaoy++;
	}
	else {
		printf("Bateu na parede, movimento invalido!\n");
	}
}

int main() {
	char *mapa;
	int i, j, menu;
	int escolha = 1;
	char direcao;
	FILE *nivel;

	//JOGADOR
	Player p;
	p.posicaox = 4; // Posição vertical do jogador
	p.posicaoy = 3; // Posição horizontal do jogador


	nivel = fopen("nivel1.txt", "r"); // Abre o arquivo com o mapa

	if(nivel == NULL) {
		printf("Erro ao abrir arquivo\n");
		return 1; // Retorna um erro caso não seja possível abrir o arquivo
	}

	fscanf(nivel, " %d %d", &largura, &altura); // Lê os primeiros dois números do arquivo e os considera como tamanho da altura e da largura, alocando cada valor nas variáveis  altura e largura, respectivamente


	mapa = (char*)malloc(largura * altura * sizeof(char)); // Aloca memória o suficiente no ponteiro mapa, de acordo com os valores de altura e largura


	for(i = 0; i < altura; i++) {
		for(j = 0; j < largura; j++) {
			if(fscanf(nivel, " %c", &mapa[(i * largura + j)]) != 1) { // Caso a leitura do arquivo não retorne um caractere válido (True) imprima um texto de erro
				printf("Erro na leitura do mapa!");
				break;
			}
		}
	}



	/*👮█💰🏃*/


	printf("——— Policia e Ladrão ———\nDigite 1 para jogar ou 0 para sair\n");
	scanf("%d", &menu);

	switch(menu) {

	case 0:
		printf("Saindo...\n");
		break;

	case 1:
		while (escolha == 1) {
			printf("\n");
			renderizarMapa(mapa, &p);

			printf("Para onde ir? Digite 'w a s d' e digite ENTER - Digite 0 para SAIR\n");
			scanf(" %c", &direcao);

			if(direcao == 'w' || direcao == 'W') {
				MoverParaCima(&p, mapa);
			}

			if(direcao == 's' || direcao == 'S') {
				MoverParaBaixo(&p, mapa);
			}

			if(direcao == 'a' || direcao == 'A') {
				MoverParaEsquerda(&p, mapa);
			}

			if(direcao == 'd'|| direcao == 'D') {
				MoverParaDireita(&p, mapa);
			}
        
            if(direcao == '0'){
                printf("Saindo...\n");
                free(mapa);
                return 0;
            }

			printf("\nNova posicao X do player = %d\n", p.posicaox);
			printf("Nova posicao Y do player = %d\n", p.posicaoy);
		}
	default: // Caso seja digitado algo além de 1 ou 0 no menu, retorne erro
	    printf("Erro: Digite um valor válido!\n");
	    return 1;
		
	}// Fim do case aqui
	return 0;
}
