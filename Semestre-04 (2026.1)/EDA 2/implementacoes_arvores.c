#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *esq;
    struct celula *dir;
} celula;

void preordem(celula *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);   // Visita a Raiz
        preordem(raiz->esq);         // Desce pela Esquerda
        preordem(raiz->dir);         // Desce pela Direita
    }
}

void emordem(celula *raiz) {
    if (raiz != NULL) {
        emordem(raiz->esq);          // Desce pela Esquerda
        printf("%d ", raiz->dado);   // Visita a Raiz
        emordem(raiz->dir);          // Desce pela Direita
    }
}

void posordem(celula *raiz) {
    if (raiz != NULL) {
        posordem(raiz->esq);         // Desce pela Esquerda
        posordem(raiz->dir);         // Desce pela Direita
        printf("%d ", raiz->dado);   // Visita a Raiz
    }
}