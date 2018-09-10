#include <gc.h>
//Mesmo programa da questão anterior, mas responde o que se pede.
struct lista {
    struct lista* primeiro;
};

int main() {
    GC_INIT();
    struct lista *ultimo = NULL;
    for (;;) {
       //UTILIZACAO DA FUNCAO MALLOC
	struct lista* n = GC_MALLOC(sizeof(struct lista));
        n->primeiro = NULL;
        if (ultimo) ultimo->primeiro = n;
        ultimo = n;
    }
}
