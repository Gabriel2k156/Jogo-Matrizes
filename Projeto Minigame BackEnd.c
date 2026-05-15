#include <stdio.h>
#include <stdlib.h>

#define PAREDE '1' // Definição de constantes para fácil utilização e leitura do código
#define POLICIAL '2'
#define MOEDA '$'
#define VAZIO '.'

int  altura, largura; // Variáveis de altura e largura do mapa, declaradas de forma global para que sejam lidas pelas funções

typedef struct Player { // Struct com nome Player (para ser lido corretamente pela função RenderizarMapa)
	int vida;
	int pontuacao; // Pontuação: É aumentada com a coleta de moedas
	int posicaox;
	int posicaoy;
} Player; // Alias da struct, para ser lido corretamente pelas demais funções

void pontuacao(struct Player *p) { // Funcao para exibir a pontuacao atual do jogador durante a partida
	printf("Pontuação: %d\n", p->pontuacao);
}

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
	if(m[(c->posicaox - 1) * largura + c->posicaoy] != PAREDE && m[(c->posicaox - 1) * largura + c->posicaoy] != POLICIAL) { // Caso o novo movimento não seja no mesmo local de uma parede ou policial, mova o jogador
		c->posicaox--;
	}
	else if (m[(c->posicaox - 1) * largura + c->posicaoy] == POLICIAL) { // Caso o novo movimento seja no mesmo local do policial, o jogo é encerrado
		printf("———G A M E  O V E R ———\nVocê foi pego! Reinicie o programa para tentar novamente\n");
		free(m); // Libera a memória alocada
		exit(0); // Encerra o programa
	}
}

void MoverParaBaixo(Player *c,char *m) {
	if(m[(c->posicaox + 1) * largura + c->posicaoy] != PAREDE && m[(c->posicaox + 1) * largura + c->posicaoy] != POLICIAL) {
		c->posicaox++;
	}
	else if (m[(c->posicaox + 1) * largura + c->posicaoy] == POLICIAL) {
		printf("———G A M E  O V E R ———\nVocê foi pego! Reinicie o programa para tentar novamente\n");
		free(m);
		exit(0);
	}
}

void MoverParaEsquerda(Player *c, char *m) {
	if(m[c->posicaox * largura + (c->posicaoy - 1)] != PAREDE && m[c->posicaox * largura + (c->posicaoy - 1)] != POLICIAL) {
		c->posicaoy--;
	}

	else if (m[c->posicaox * largura + (c->posicaoy - 1)] == POLICIAL) {
		printf("———G A M E  O V E R ———\nVocê foi pego! Reinicie o programa para tentar novamente\n");
		free(m);
		exit(0);
	}
}

void MoverParaDireita(Player *c, char *m) {
	if(m[(c->posicaox) * largura + c->posicaoy + 1] != PAREDE && m[(c->posicaox) * largura + c->posicaoy + 1] != POLICIAL) {
		c->posicaoy++;
	}
	else if (m[(c->posicaox) * largura + c->posicaoy + 1] == POLICIAL) {
		printf("———G A M E  O V E R ———\nVocê foi pego! Reinicie o programa para tentar novamente\n");
		free(m);
		exit(0);
	}
}

int main() {
	char *mapa;
	int i, j, menu;
	int escolha = 1;
	char direcao;
	FILE *nivel;

	//JOGADOR;
	Player p;
	p.posicaox = 4; // Posição vertical do jogador
	p.posicaoy = 3; // Posição horizontal do jogador
	p.pontuacao = 0; // Inicializa a pontuação para evitar uma variável com lixo de memória


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
				free(mapa);
				return 1;
			}
		}
	}
	fclose(nivel); // Fecha o arquivo após a leitura
	/*👮█💰🏃*/


	printf("——— Policia e Ladrão ———\nDigite 1 para jogar ou 0 para sair\n");
	scanf("%d", &menu);

	switch(menu) {

	case 0:
		printf("Saindo...\n");
		free(mapa); // Libera a memoria alocada, evitando um vazamento de memoria
		return 0; // Encerra o programa

	case 1:
		while (1) {
			system("clear"); // Limpa o terminal
			printf("\n");
			pontuacao(&p);
			renderizarMapa(mapa, &p);

			printf("Para onde ir? Digite 'w a s d' e digite ENTER - Digite 0 para SAIR\n");
			scanf(" %c", &direcao);

			if(direcao == 'w' || direcao == 'W') {
				MoverParaCima(&p, mapa);
			}

			else if(direcao == 's' || direcao == 'S') {
				MoverParaBaixo(&p, mapa);
			}

			else if(direcao == 'a' || direcao == 'A') {
				MoverParaEsquerda(&p, mapa);
			}

			else if(direcao == 'd'|| direcao == 'D') {
				MoverParaDireita(&p, mapa);
			}

			else if(direcao == '0') {
				printf("Saindo...\n");
				free(mapa);
				return 0;
			}


		}
	default: // Caso seja digitado algo além de 1 ou 0 no menu, retorne erro
		printf("Erro: Digite um valor válido!\n");
		free(mapa); // Libera a memória alocada
		return 1; // Encerra o programa com um erro

	}// Fim do case aqui

	return 0;
}
