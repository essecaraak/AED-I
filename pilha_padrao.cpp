#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int topo;
	float *pelem;
	int capa;
}pilha;

void criarpilha(pilha* p,int c){
	p->capa=c;
	p->topo=-1;
	p->pelem=(float*)malloc(p->capa*sizeof(float));	
};
void empilhar(pilha* p,float v){
	p->topo++;
	p->pelem[p->topo]=v;
	
};
float desempilhar(pilha* p){
	float aux=p->pelem[p->topo];
	p->topo--;
	return aux;	
};

main(){
}
