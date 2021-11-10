#include<stdio.h>
#include<stdlib.h>

struct hash{
    int qtd,TABLE_SIZE;
    int **itens;
};
typedef struct hash Hash;

Hash*criaHash(int TABLE_SIZE);
void liberaHash(Hash *ha);
int chaveDivisao(int chave, int TABLE_SIZE);

int main(){
    Hash* bora;
    bora=criaHash(11);
    int x=insereHash(bora,12);
    x=insereHash(bora,44);
    x=insereHash(bora,13);
    x=insereHash(bora,88);
    x=insereHash(bora,23);
    x=insereHash(bora,94);
    x=insereHash(bora,11);
    x=insereHash(bora,39);
    x=insereHash(bora,20);
    x=insereHash(bora,16);
    x=insereHash(bora,5);

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

int chaveDivisao(int chave, int TABLE_SIZE){
    return((2*chave+5) & 0x7FFFFFFF)%TABLE_SIZE;
}
