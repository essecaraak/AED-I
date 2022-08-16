#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int capacidade;
	float *dados;
	int nitens;
	int primeiro;
	int ultimo;
}fila;

void criarfila(fila *f, int c){
	f->capacidade=c;
	f->dados=(float*)malloc(f->capacidade*sizeof(float));
	f->primeiro=0;
	f->ultimo=-1;
	f->nitens=0;
	
};

void inserirfila(fila *f,int v){
	if(f->ultimo==f->capacidade-1){
		f->ultimo=-1;
		f->nitens--;
	};
	f->ultimo++;
	f->dados[f->ultimo]=v;
	f->nitens++;
	
};
int removerfila(fila *f){
	float temp=f->dados[f->primeiro++];
	if(f->primeiro==f->capacidade){
		f->primeiro=0;	
	};
	f->nitens--;
	return temp;
};
void mostrarfila(fila *f){
	int cont,i;
	for(cont=0,i=f->primeiro;cont<f->nitens;cont++){
		printf("%.2f\n\n",f->dados[i++]);
 		if (i == f->capacidade){
		 		i=0;
		}
	};
}

main(){
	fila f;
	int x=-1;
	criarfila(&f,3);
	do{
		scanf("%d",&x);
		if(x==4){
			removerfila(&f);
		}else if(x==5){
			mostrarfila(&f);
		}else{
			
			inserirfila(&f,x);	
		};
		
	}while(x!=0);
}
