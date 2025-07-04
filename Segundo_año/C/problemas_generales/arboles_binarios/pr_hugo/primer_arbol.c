#include <stdio.h>
#include <stdlib.h>

struct arbol{
    char elem;
    struct arbol *izq;
    struct arbol *der;
};

void preorden(struct arbol *);
void inorden(struct arbol *);
void postorden(struct arbol *);
void visitar(struct arbol *);
int alturaArbol(struct arbol *);
void mostrarHojas(struct arbol *);

int main(){
    struct arbol *raiz, *h, *m, *z, *k, *c, *j, *a, *i;
    struct arbol *n, *p, *y, *b, *e, *d, *x, *l;
    h=(struct arbol *)malloc(sizeof(struct arbol));
    m=(struct arbol *)malloc(sizeof(struct arbol));
    z=(struct arbol *)malloc(sizeof(struct arbol));
    k=(struct arbol *)malloc(sizeof(struct arbol));
    c=(struct arbol *)malloc(sizeof(struct arbol));
    j=(struct arbol *)malloc(sizeof(struct arbol));
    a=(struct arbol *)malloc(sizeof(struct arbol));
    i=(struct arbol *)malloc(sizeof(struct arbol));
    n=(struct arbol *)malloc(sizeof(struct arbol));
    p=(struct arbol *)malloc(sizeof(struct arbol));
    y=(struct arbol *)malloc(sizeof(struct arbol));
    b=(struct arbol *)malloc(sizeof(struct arbol));
    e=(struct arbol *)malloc(sizeof(struct arbol));
    d=(struct arbol *)malloc(sizeof(struct arbol));
    x=(struct arbol *)malloc(sizeof(struct arbol));
    l=(struct arbol *)malloc(sizeof(struct arbol));
    h->elem='h';
    h->izq=m;
    h->der=z;
    m->elem='m';
    m->izq=k;
    m->der=NULL;
    z->elem='z';
    z->izq=c;
    z->der=j;
    k->elem='k';
    k->izq=a;
    k->der=i;
    c->elem='c';
    c->izq=NULL;
    c->der=NULL;
    j->elem='j';
    j->izq=n;
    j->der=p;
    a->elem='a';
    a->izq=NULL;
    a->der=NULL;
    i->elem='i';
    i->izq=NULL;
    i->der=y;
    n->elem='n';
    n->izq=NULL;
    n->der=NULL;
    p->elem='p';
    p->izq=b;
    p->der=e;
    y->elem='y';
    y->izq=NULL;
    y->der=NULL;
    b->elem='b';
    b->izq=NULL;
    b->der=NULL;
    e->elem='e';
    e->izq=d;
    e->der=x;
    d->elem='d';
    d->izq=NULL;
    d->der=l;
    x->elem='x';
    x->izq=NULL;
    x->der=NULL;
    l->elem='l';
    l->izq=NULL;
    l->der=NULL;
    raiz=h;
    printf("\nPreorden: ");
    preorden(raiz);
    printf("\nInorden: ");
    inorden(raiz);
    printf("\nPostorden: ");
    postorden(raiz);
    printf("\nAltura del arbol: %d", alturaArbol(raiz));
    printf("\nNodos hojas: ");
    mostrarHojas(raiz);
    printf("\n\n<< Finalizado >>\n\n");
    return 0;
}

void preorden(struct arbol *nodo){
    if (nodo != NULL) {
        visitar(nodo);
        postorden(nodo->izq);
        postorden(nodo->der);
    }
}

void inorden(struct arbol *nodo){
    if (nodo != NULL) {
        postorden(nodo->izq);
        visitar(nodo);
        postorden(nodo->der);
    }
}

void postorden(struct arbol *nodo){
    if (nodo != NULL) {
        postorden(nodo->izq);
        postorden(nodo->der);
        visitar(nodo);
    }
}

void visitar(struct arbol *nodo){
    printf("%c ", nodo->elem);
}

int alturaArbol(struct arbol *nodo) {
    if (nodo == NULL) {
        return 0;
    } else {
        // Calcula la altura de los subárboles izquierdo y derecho
        int alturaIzquierda = alturaArbol(nodo->izq);
        int alturaDerecha = alturaArbol(nodo->der);

        // Devuelve la altura máxima más 1 (para la raíz actual)
        if (alturaIzquierda > alturaDerecha) {
            return (alturaIzquierda + 1);
        } else {
            return (alturaDerecha + 1);
        }
    }
}

void mostrarHojas(struct arbol *nodo) {
    if (nodo != NULL) {
        if (nodo->izq == NULL && nodo->der == NULL) {
            printf("%c ", nodo->elem);
        }
        mostrarHojas(nodo->izq);
        mostrarHojas(nodo->der);
    }
}