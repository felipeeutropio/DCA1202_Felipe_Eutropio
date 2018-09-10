#include <gc.h>

struct lista {
    struct lista* primeiro;
};

int main() {
    GC_INIT();
    struct lista *ultimo = NULL;
    for ( ; ; ) {
        struct lista* n = GC_MALLOC(sizeof(struct lista));
        n->primeiro = NULL;
        if (ultimo) ultimo->primeiro = n;
        ultimo = n;
    }
}

