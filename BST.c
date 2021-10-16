#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore{
    int chave;
    struct NoArvore *e, *d;
}NoA;

NoA *insere(NoA *raiz, int chave){
    if(raiz == NULL){
        NoA *novo = (NoA*)malloc(sizeof(NoA));
        novo->chave = chave;
        novo->e = NULL;
        novo->d = NULL;
        return novo;
    }
    else{
        if(chave < raiz->chave)
            raiz->e = insere(raiz->e, chave);
        if(chave > raiz->chave)
            raiz->d = insere(raiz->d, chave);
        return raiz;
    }
}

NoA *busca(NoA *raiz, int chave){
    if(raiz == NULL){
        printf("Value %d not found.\n", chave);
        return NULL;
    }
    else if(raiz->chave == chave){
        printf("Value %d found.\n", chave);
        return raiz;
    }else if(chave < raiz->chave){
        return busca(raiz->e, chave);
    }else{
        return busca(raiz->d, chave);
    }
}

void imprime(NoA *raiz){
    if (raiz==NULL) return;
    imprime(raiz->e);
    printf("%d\n", raiz->chave);
    imprime(raiz->d);
}

int main(){
    NoA *raiz = NULL;
    int op, valor;
    do{
        printf("--- FUNCTIONS ---\n1. Insert\n2. Search\n3. Print\n0. Exit\n");
        scanf("%d", &op);
        switch(op){
            case 1:
            printf("Enter a number to create: ");
            scanf("%d", &valor);
            raiz = insere(raiz, valor);
            break;
            case 2:
            printf("Enter a number to search: ");
            scanf("%d", &valor);
            busca(raiz, valor);
            break;
            case 3:
            printf("\n");
            if(raiz == NULL){
                printf("Empty tree.\n");
            }else{
                imprime(raiz);
            }
            break;
            default:
            printf("Exiting...");
            break;
        }
    }while(op != 0);
    return 0;
}