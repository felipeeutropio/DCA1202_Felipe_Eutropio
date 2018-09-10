#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

//Funcoes para ordenar o vetor
void ordene(float n,float *p);
int ordemcrescente(const void* x, const void* y);

int main() {

    float tempo;
    time_t t_ini, t_fim;

    float n;
    float *p;
//Variavel do tempo inicial de execucao
    t_ini=time(NULL);

    printf("digite o valor de n\n");
    scanf("%f",&n);

    ordene(n,p);
//Variavel do tempo final de execucao
    t_fim=time(NULL);
    tempo=difftime(t_fim,t_ini);
    printf("SEM QSORT\nTempo de Execucao: %.3f segundos",tempo);

    getch();
    return 0;
}

void ordene(float n,float *p) {
    int i,j,t;
    p=(float *)malloc(n *sizeof(float));

    for(i=0;i<n;i++) {
        scanf("%f", (p+i));
    }

//qsort para ordenar o vetor
    qsort(p,n,sizeof(float),ordemcrescente);

    printf("\nOrdem crescente= ");

        for(i=0;i<n;i++) {
            printf("%.2f ",*(p+i));
        }
}

int ordemcrescente(const void* x, const void* y) {
    if(*(const float*)x < *(const float*)y)
        return -1;
    return *(const float*)x > *(const float*)y;
}

