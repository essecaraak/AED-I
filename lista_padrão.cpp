#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int capacidade;
	float *dados;
	int pos;
	int nitens;
	
}lista;
void criarlista(lista *f,int c){
	f->capacidade=c;
	f->dados=(float*)malloc(f->capacidade*sizeof(float));	
	f->pos=-1;
	f->nitens=0;
};
int inserir(lista* f,int v){
	if(f->pos==f->capacidade-1){
		return(0);
	}else{
		f->pos++;
		f->dados[f->pos]=v;
		f->nitens++;
		return(1);
	}
	
};
void listar(lista*f){
	int i;
	for(i=0;i<f->capacidade;i++){
		printf("%.2f \n\n",f->dados[i]);
	};
	
};

main(){
	int x;
	lista f;
	
	criarlista(&f,3);
	scanf("%d",&x);
	inserir(&f,x);
	scanf("%d",&x);
	inserir(&f,x);
	scanf("%d",&x);
	inserir(&f,x);
	listar(&f);
	
	
	
}
