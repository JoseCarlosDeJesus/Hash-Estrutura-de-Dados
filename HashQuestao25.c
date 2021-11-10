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
int sondagemQuadratica(int pos,int i,int TABLE_SIZE);
int insereHashEnderecoAberto(Hash*ha,int ina);

int main(){
    Hash* po;
    po=criaHash(7);
    int linear, quadratica,sondagem_li,sondagem_quadratica;

    linear=insereHashEnderecoAberto(po,4234);
    sondagem_li=sondagemLinear(chaveDivisao(4234,7),po->qtd,7);

    linear=insereHashEnderecoAberto(po,2839);
    sondagem_li=sondagemLinear(chaveDivisao(2839,7),po->qtd,7);

    linear=insereHashEnderecoAberto(po,430);
    sondagem_li=sondagemLinear(chaveDivisao(430,7),po->qtd,7);

    linear=insereHashEnderecoAberto(po,22);
    sondagem_li=sondagemLinear(chaveDivisao(22,7),po->qtd,7);

    linear=insereHashEnderecoAberto(po,397);
    sondagem_li=sondagemLinear(chaveDivisao(397,7),po->qtd,7);

    linear=insereHashEnderecoAberto(po,3920);
    sondagem_li=sondagemLinear(chaveDivisao(3920,7),po->qtd,7);


    //sondagem quadratica

    quadratica=insereHashEnderecoAberto(po,4234);
    sondagem_quadratica=sondagemQuadratica(chaveDivisao(4234,7),po->qtd,7);

    quadratica=insereHashEnderecoAberto(po,2839);
    sondagem_quadratica=sondagemQuadratica(chaveDivisao(2839,7),po->qtd,7);

    quadratica=insereHashEnderecoAberto(po,430);
    sondagem_quadratica=sondagemQuadratica(chaveDivisao(430,7),po->qtd,7);

    quadratica=insereHashEnderecoAberto(po,22);
    sondagem_quadratica=sondagemQuadratica(chaveDivisao(22,7),po->qtd,7);

    quadratica=insereHashEnderecoAberto(po,397);
    sondagem_quadratica=sondagemQuadratica(chaveDivisao(397,7),po->qtd,7);

    quadratica=insereHashEnderecoAberto(po,3920);
    sondagem_quadratica=sondagemQuadratica(chaveDivisao(3920,7),po->qtd,7);

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

int sondagemQuadratica(int pos,int i,int TABLE_SIZE){
    pos=pos+2*i+(i*i);
    return(pos&0x7FFFFFFF)%TABLE_SIZE;
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

