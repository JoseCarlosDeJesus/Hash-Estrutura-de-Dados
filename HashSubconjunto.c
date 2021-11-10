truct hash{
    int qtd, TABLE_SIZE;
    int*itens;
};
typedef struct hash Hash;

//busca o valor de T em S
int buscaHashEnderecoAberto(Hash* ha,int mat,int* al){
    if(ha==NULL)
       return 0;
    int i,pos,newPos;
    pos=chaveDivisao(mat,ha->TABLE_SIZE);
    for(i=0;i<ha->TABLE_SIZE;i++){
        newPos=sondagemLinear(pos,i,ha->TABLE_SIZE);
        if(ha->itens[newPos]==NULL)
            return 0;
        if(ha->itens[newPos]->==mat){
           *al=*(ha->itens[newPos]);
           return 1;
        }
    }
    return 0;
}

int subconjuntoHash(Hash* S,Hash* T){
    int i;
    int compara;
    tamanho tabelaT=T->TABLE_SIZE;
    for(i=0;i<T->TABLE->SIZE;i++){
        compara=buscaHashEnderecoAberto(S,T->itens[i],T->itens);
        if(compara==0){
            return 0;
        }
    }
    return 1;
}
