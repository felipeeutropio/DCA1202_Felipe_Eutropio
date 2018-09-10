#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

void ordene(float n,float *p);

int main() {
    float tempo;
    time_t t_ini, t_fim;

    float n;
    float *p;

    t_ini=time(NULL);

    printf("digite o valor de n\n");
    scanf("%f",&n);

    ordene(n,p);

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
    for(i=0;i<n;i++) {
        for(j=0;j<=i;j++) {
            if(*(p+i)<*(p+j)) {
                t = *(p+i);
                *(p+i)= *(p+j);
                *(p+j) = t;
            }
        }
    }

    printf("\nOrdem crescente = ");

        for(i=0;i<n;i++) {
            printf("%.2f ",*(p+i));
        }
}
