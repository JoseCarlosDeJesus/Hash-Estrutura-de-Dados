#include<stdio.h>
#include<stdlib.h>

struct hash{
    int qtd,TABLE_SIZE;
    int **itens;
};
typedef struct hash Hash;

int chaveDivisao(int chave,int TABLE_SIZE){
    return(chave & 0x7FFFFFFF)%TABLE_SIZE;
}

Hash*criaHash(int TABLE_SIZE){
    Hash* ha=(Hash*)malloc(sizeof(Hash));
    if(ha!=NULL){
       int i;
       ha->TABLE_SIZE=TABLE_SIZE;
       ha->itens=(int**)malloc(TABLE_SIZE*sizeof(int*));
       if(ha->itens==NULL){
          free(ha);
          return NULL;
       }
       ha->qtd=0;
       for(i=0;i<ha->TABLE_SIZE;i++)
           ha->itens[i]=NULL;
    }
    return ha;
}

void liberaHash(Hash *ha){
     if(ha!=NULL){
        int i;
        for(i=0;i<ha->TABLE_SIZE;i++){
            if(ha->itens[i]!=NULL)
               free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
     }
}

int insereHash(Hash*ha,int con){
    if(ha==NULL || ha->qtd==ha->TABLE_SIZE)
       return 0;
    int chave=con;
    int i, pos,newPos;
    pos=chaveDivisao(chave,ha->TABLE_SIZE);
    for(i=0;i<ha->TABLE_SIZE;i++){
        int*novo;
        novo=(int*)malloc(sizeof(int));
        if(novo==NULL)
           return 0;
        *novo=con;
        ha->itens[newPos]=novo;
        ha->qtd++;
        return 1;
    }
    return 0;
}

int main(){
    Hash* bora;
    bora=criaHash(9);
    int x=insereHash(bora,5);
    x=insereHash(bora,28);
    printf("%d\n", x);
    x=insereHash(bora,19);
    printf("%d\n", x);
    x=insereHash(bora,15);
    printf("%d\n", x);
    x=insereHash(bora,20);
    printf("%d\n", x);
    x=insereHash(bora,33);
    printf("%d\n", x);
    x=insereHash(bora,7);
    printf("%d\n", x);
    x=insereHash(bora,10);
    printf("%d\n", x);
    liberaHash(bora);
    bora=criaHash(11);
    x=insereHash(bora,5);
    x=insereHash(bora,28);
    printf("%d\n", x);
    x=insereHash(bora,19);
    printf("%d\n", x);
    x=insereHash(bora,15);
    printf("%d\n", x);
    x=insereHash(bora,20);
    printf("%d\n", x);
    x=insereHash(bora,33);
    printf("%d\n", x);
    x=insereHash(bora,7);
    printf("%d\n", x);
    x=insereHash(bora,10);
    printf("%d\n", x);
    liberaHash(bora);

    return 0;
}
