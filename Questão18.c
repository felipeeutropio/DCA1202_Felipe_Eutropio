#include <stdio.h>
#include <assert.h>

float somadosvetores(int *veta, int *vetb, int *vetc, int tamanho) {

	int i;

	for(i=0;i<tamanho;i++) {
		vetc[i]=0;
		vetc[i] = veta[i]+vetb[i];
	}

	return 1;
}
#define MAX 5
int main() {

	int veta[MAX],vetb[MAX],vetc[MAX];
	int i,n;

	printf("Digite o tamanho dos vetores");
	scanf("%d",&n);

	printf("Digite o valor das elementos do veta ");
	for(i=0;i<n;i++) {
		scanf("%d",&veta[i]);
	}
	printf("Digite o valor das elementos do vetb ");
	for(i=0;i<n;i++){
		scanf("%d",&vetb[i]);
	}
	somadosvetores(veta,vetb,vetc,5);
	for(i=0;i<n;i++) {
		printf("A soma do(s) %do. elemento(s) é: %d\n",i+1,vetc[i]);
	}

	return 0;
}
