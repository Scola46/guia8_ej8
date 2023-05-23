#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
    char letra;
    struct nodo* sig;
}nodo;
typedef nodo* Tlista;

void cargalista(Tlista* p1);
void elimina(Tlista* p1);
void recorrelista(Tlista p1);
int main()
{
    Tlista lista;
    cargalista(&lista);
    elimina(&lista);
    recorrelista(lista);
    return 0;
}
void cargalista(Tlista* p1)
{
    Tlista nuevo;
    *p1=NULL;
    FILE* arch_letra=fopen("caracter.txt","rt");
    nuevo=(Tlista)malloc(sizeof(nodo));
    while(fscanf(arch_letra,"%c",&nuevo->letra)==1){
        nuevo->sig=*p1;
        *p1=nuevo;
        nuevo=(Tlista)malloc(sizeof(nodo));
    }
    fclose(arch_letra);
}
void elimina(Tlista* p1)
{
    char letra;
    Tlista ant,act,elim;
    act=*p1;
    printf("caracter\n");scanf(" %c",&letra);
    while(act!=NULL && act->letra!=letra){
        ant=act;
        act=act->sig;
    }
    if(act!=NULL){
        ant=act;
        act=act->sig;
    }

    while(act!=NULL){
        if(act->letra==letra){
            elim=act;
            act=act->sig;
            ant->sig=act;
            free(elim);
        }else{
            ant=act;
            act=act->sig;
        }

    }

}
void recorrelista(Tlista p1)
{
    while(p1!=NULL){
        printf("%c",p1->letra);
        p1=p1->sig;
    }
}
