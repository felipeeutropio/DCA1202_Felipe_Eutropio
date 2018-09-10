#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

void multiplicacaoMatrizes();
void linhaecol(int *linha, int *col, char *matriz);
int *criarMatriz(int *linha, int *col);
void MatrizValores(int *source, int linha, int col, char *nome);
int *destroirMatriz(int *matriz);
void printMatriz(const int *source, int linha, int col);

int main() {

	multiplicacaoMatrizes();

	return(0);
}

void multiplicacaoMatrizes() {

	int umlinha, umCol, doislinha, doisCol, i, j, k;

	linhaecol(&umlinha, &umCol, "Matriz 1");
	linhaecol(&doislinha, &doisCol, "Matriz 2");

	if(umCol != doislinha) {
		printf("O numero de colunas da primeira matriz deve ser igual ao numero de linhas da segunda matriz.\n");
		exit(EXIT_FAILURE);
	}

	int *umMatriz = criarMatriz(&umlinha, &umCol);
	int *doisMatriz = criarMatriz(&doislinha, &doisCol);
	int *multiplicadaMatriz = criarMatriz(&umlinha, &doisCol);

	int *inicialumMatriz, *inicialdoisMatriz, *inicialMultiplicadaMatriz;
	inicialumMatriz = umMatriz;
	inicialdoisMatriz = doisMatriz;
	inicialMultiplicadaMatriz = multiplicadaMatriz;

	MatrizValores(umMatriz, umlinha, umCol, "Matriz 1");
	MatrizValores(doisMatriz, doislinha, doisCol, "Matriz 2");

	for(i = 0; i < umlinha; i++) {
		for(j = 0; j < doisCol; j++) {
			umMatriz += (umCol * i);
			doisMatriz += j;
			for(k = 0; k < umCol; k++) {
				*multiplicadaMatriz += *umMatriz * *doisMatriz;
				umMatriz++;
				doisMatriz += doisCol;
			}
			multiplicadaMatriz++;
			umMatriz = inicialumMatriz;
			doisMatriz = inicialdoisMatriz;
		}
	}
	multiplicadaMatriz = inicialMultiplicadaMatriz;
	printf("\n");
	printMatriz(umMatriz, umlinha, umCol);
	printf("\n*\n\n");
	printMatriz(doisMatriz, doislinha, doisCol);
	printf("\n=\n\n");
	printMatriz(multiplicadaMatriz, umlinha, doisCol);
	destroirMatriz(umMatriz);
	destroirMatriz(doisMatriz);
	destroirMatriz(multiplicadaMatriz);

	return;

}

void linhaecol(int *linha, int *col, char *matriz)
{

	printf("Entre com o numero de linhas da %s\n", matriz);

	scanf("%d", linha);

	printf("Entre com o numero de colunas da %s\n", matriz);

	scanf("%d", col);
}

int *criarMatriz(int *linha, int *col)
{

	int *novaMatriz = calloc(*linha * *col, sizeof(int));

	if(!novaMatriz)
{
	printf("Falsa alocacao de memoria.\n");
	exit(EXIT_FAILURE);
}

	return(novaMatriz);
}

void MatrizValores(int *source, int linha, int col, char *nome) {
	int i, j;

	for(i = 0; i < linha; i++) {
		for(j = 0; j < col; j++) {
			printf("Entre com o valor do vetor %d %d da %s\n", i, j, nome);
			scanf("%d", source++);
		}
	}
}

	int *destroirMatriz(int *matriz) {
	if(matriz) {
		free(matriz);
	}
	return(NULL);
}

void printMatriz(const int *source, int linha, int col) {
	int i, j;

	for(i = 0; i < linha; i++) {
		printf("|");
		for(j = 0; j < col; j++) {
			printf("%5d", *source++);
		}
	printf("|\n");
	}
}
