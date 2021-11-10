#include<stdio.h>
#include<stdlib.h>
struct hash{
    int qtd, TABLE_SIZE;
    int**itens;
};
typedef struct hash Hash;
Hash*criaHash(int TABLE_SIZE);
void liberaHash(Hash *ha);
int chaveDivisao(int chave, int TABLE_SIZE);
int sondagemLinear(int pos,int i,int TABLE_SIZE);
int sondagemQuadraticaSimples(int pos,int i,int TABLE_SIZE);
int sondagemQuadratica2(int pos,int i,int TABLE_SIZE);
int duploHash(int chave,int i,int TABLE_SIZE);
int insereHashEnderecoAberto(Hash*ha,int ina);

int main(){
    Hash* po;
    po=criaHash(10);
    int linear, quadratica,q2,hashduplo;

    //sondagem linear
    linear=insereHashEnderecoAberto(po,371);
    int sondagemL=sondagemLinear(chaveDivisao(371,10),po->qtd,10);
    printf("%d\n", sondagemL);
    linear=insereHashEnderecoAberto(po,121);
    sondagemL=sondagemLinear(chaveDivisao(121,10),po->qtd,10);
    printf("%d\n", sondagemL);
    linear=insereHashEnderecoAberto(po,173);
    sondagemL=sondagemLinear(chaveDivisao(173,10),po->qtd,10);
    printf("%d\n", sondagemL);
    linear=insereHashEnderecoAberto(po,203);
    sondagemL=sondagemLinear(chaveDivisao(203,10),po->qtd,10);
    printf("%d\n", sondagemL);
    linear=insereHashEnderecoAberto(po,11);
    sondagemL=sondagemLinear(chaveDivisao(11,10),po->qtd,10);
    printf("%d\n", sondagemL);
    linear=insereHashEnderecoAberto(po,24);
    sondagemL=sondagemLinear(chaveDivisao(24,10),po->qtd,10);
    printf("%d\n", sondagemL);

    //primeira sondagem quadratica (k+i*i)%M
    printf("Sondagem quadratica 'k+i*i'");
    quadratica=insereHashEnderecoAberto(po,371);
    int sondagemQ=sondagemQuadraticaSimples(chaveDivisao(371,10),po->qtd,10);
    printf("%d\n", sondagemQ);
    quadratica=insereHashEnderecoAberto(po,121);
    sondagemQ=sondagemQuadraticaSimples(chaveDivisao(121,10),po->qtd,10);
    printf("%d\n", sondagemQ);
    quadratica=insereHashEnderecoAberto(po,173);
    sondagemQ=sondagemQuadraticaSimples(chaveDivisao(173,10),po->qtd,10);
    printf("%d\n", sondagemQ);
    quadratica=insereHashEnderecoAberto(po,203);
    sondagemQ=sondagemQuadraticaSimples(chaveDivisao(203,10),po->qtd,10);
    printf("%d\n", sondagemQ);
    quadratica=insereHashEnderecoAberto(po,11);
    sondagemQ=sondagemQuadraticaSimples(chaveDivisao(11,10),po->qtd,10);
    printf("%d\n", sondagemQ);
    quadratica=insereHashEnderecoAberto(po,24);
    sondagemQ=sondagemQuadraticaSimples(chaveDivisao(24,10),po->qtd,10);
    printf("%d\n", sondagemQ);

    //segunda sondagem quadratica (k+2i+i*i)%M
    printf("Sondagem quadratica 'k+2i+i*i'");
    q2=insereHashEnderecoAberto(po,371);
    int sondagemQ2=sondagemQuadratica2(chaveDivisao(371,10),po->qtd,10);
    printf("%d\n", sondagemQ2);
    q2=insereHashEnderecoAberto(po,121);
    sondagemQ2=sondagemQuadratica2(chaveDivisao(121,10),po->qtd,10);
    printf("%d\n", sondagemQ2);
    q2=insereHashEnderecoAberto(po,173);
    sondagemQ2=sondagemQuadratica2(chaveDivisao(173,10),po->qtd,10);
    printf("%d\n", sondagemQ2);
    q2=insereHashEnderecoAberto(po,203);
    sondagemQ2=sondagemQuadratica2(chaveDivisao(203,10),po->qtd,10);
    printf("%d\n", sondagemQ2);
    q2=insereHashEnderecoAberto(po,11);
    sondagemQ2=sondagemQuadratica2(chaveDivisao(11,10),po->qtd,10);
    printf("%d\n", sondagemQ2);
    q2=insereHashEnderecoAberto(po,24);
    sondagemQ2=sondagemQuadratica2(chaveDivisao(24,10),po->qtd,10);
    printf("%d\n", sondagemQ2);

    //Duplo Hash
    printf("Duplo Harsh: \n");
    hashduplo=insereHashEnderecoAberto(po,371);
    int hash2=duploHash(371,po->qtd,10);
    printf("%d\n", hash2);
    hashduplo=insereHashEnderecoAberto(po,121);
    hash2=duploHash(121,po->qtd,10);
    printf("%d\n", hash2);
    hashduplo=insereHashEnderecoAberto(po,173);
    hash2=duploHash(173,po->qtd,10);
    printf("%d\n", hash2);
    hashduplo=insereHashEnderecoAberto(po,203);
    hash2=duploHash(203,po->qtd,10);
    printf("%d\n", hash2);
    hashduplo=insereHashEnderecoAberto(po,11);
    hash2=duploHash(11,po->qtd,10);
    printf("%d\n", hash2);
    hashduplo=insereHashEnderecoAberto(po,24);
    hash2=duploHash(24,po->qtd,10);
    printf("%d\n", hash2);



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

int chaveDivisao(int chave,int TABLE_SIZE){
    return(chave & 0x7FFFFFFF)%TABLE_SIZE;
}

int sondagemLinear(int pos,int i,int TABLE_SIZE){
    return((pos+i)& 0x7FFFFFFF)%TABLE_SIZE;
}

int sondagemQuadraticaSimples(int pos,int i,int TABLE_SIZE){
    pos=pos+(i*i);
    return(pos&0x7FFFFFFF)%TABLE_SIZE;
}
int sondagemQuadratica2(int pos,int i,int TABLE_SIZE){
    pos=pos+2*i+(i*i);
    return(pos&0x7FFFFFFF)%TABLE_SIZE;
}

int duploHash(int chave,int i,int TABLE_SIZE){
    int H1=chaveDivisao(chave,TABLE_SIZE);
    int H2=7-(chave%7);
    return((H1+i*H2)& 0x7FFFFFFF)%TABLE_SIZE;
}

int insereHashEnderecoAberto(Hash*ha,int ina){
    if(ha==NULL || ha->qtd==ha->TABLE_SIZE)
       return 0;
    int chave=ina;
    int i, pos,newPos;
    pos=chaveDivisao(chave,ha->TABLE_SIZE);
    for(i=0;i<ha->TABLE_SIZE;i++){
        int*novo;
        novo=(int*)malloc(sizeof(int));
        if(novo==NULL)
           return 0;
        *novo=ina;
        ha->itens[newPos]=novo;
        ha->qtd++;
        return 1;
    }
    return 0;
}
