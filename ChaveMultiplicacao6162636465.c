#include<stdio.h>
#include<string.h>

int chaveMultiplicacao(int chave,int TABLE_SIZE){
    float A=0.6180339887;//constante 0<A<1
    float val=chave *A;
    val=val-(int)val;
    return(int)(TABLE_SIZE*val);
}

int main(){
    int a,b,c,d,e;
    a=chaveMultiplicacao(61,1000);
    b=chaveMultiplicacao(62,1000);
    c=chaveMultiplicacao(63,1000);
    d=chaveMultiplicacao(64,1000);
    e=chaveMultiplicacao(65,1000);
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%d\n", d);
    printf("%d\n", e);

}
