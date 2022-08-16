#include <stdio.h>
#include <stdlib.h>


struct node{
	int num;
	struct node *prox;
	
};
typedef struct node node;

void inicia(node *lista){
	lista->prox=NULL;
}

int vazia(node *lista){
	if(lista->prox == NULL){	
		return 1;
		}else{
		return 0;
		};

};

void inserefim(node *lista, int x){
	node *novo=(node*)malloc(sizeof(node));
	if(!novo){
	printf("Sem memoria disponivel!\n");
	exit(1);
	};
	novo->prox=NULL;
	novo->num=x;
	if(vazia(lista)){
		lista->prox=novo;
	}else{
		node *tmp=lista->prox;
		while(tmp->prox!=NULL){
			tmp=tmp->prox;
		}
		tmp->prox=novo;
		}
};

void insereinicio(node * lista,int x){
	node *novo=(node*)malloc(sizeof(node));
	if(!novo){
	printf("Sem memoria disponivel!\n");
	exit(1);
	};
	node *oldhead=lista->prox;
	lista->prox=novo;
	novo->num=x;
	novo->prox=oldhead;
};

void exibe(node *lista){
	if(vazia(lista)){
		printf("Lista vazia!\n\n");
		return ;
	}
	node *tmp;
	tmp=lista->prox;
	while(tmp!=NULL){
		printf("%5d",tmp->num);
			tmp=tmp->prox;
		}
	printf("\n\n");
}

void libera(node *lista){
	if(!vazia(lista)){
		node *proxnode,*atual;
		atual=lista->prox;
		while(atual!=NULL){
			proxnode=atual->prox;
			free(atual);
			atual=proxnode;
		}
	}
}

node * busca(node *lista, int x,node **ant){
	node *ptr ;
 	*ant=lista ;
 	if(vazia(lista)) 
		return NULL ;
 		else{ 
			ptr = lista->prox;
			while(ptr != NULL){
				if(ptr->num != x){ 
					*ant = ptr ;
 					ptr = ptr->prox ;
				}else{
					return ptr;
				}
			break;
			}
		}

}

int remove(node *lista,int x){
	node *ant;
	node *aux=busca(lista,x,&ant);
	if(aux){
		ant->prox=aux->prox;
		free(aux);
		return (1);
	}else{
		return(0);
	}
}

int menu(void){
	int opt;
	printf("Escolha a opcao\n");
	printf("1. Exibir lista\n");
	printf("2. Adicionar node no inicio\n");
	printf("3. Adicionar node no final\n");
	printf("4. Zerar lista\n");
	printf("5. Sair\n");
	printf("6. retirar\n");
	printf("Opcao: "); scanf("%d", &opt);
	return opt;
}

void opcao(node *lista, int op){ 
	int x ;
	switch(op){
		case 1: 
			exibe(lista);
			break;
		case 2: 
			printf("Novo elemento: "); scanf("%d", &x);
	 		insereinicio(lista,x);
			break;
	    case 3: 
			printf("Novo elemento: "); scanf("%d", &x);
 			inserefim(lista,x);
 			break;
		case 4: libera(lista);
			break;
		case 5: libera(lista);
			break;
		case 6: ;
			printf("elemento a retirar: "); scanf("%d", &x);
 			remove(lista,x);
			break;
		default:printf("Comando invalido\n\n");
}
};

main(){
	int op;
	node *lista=(node*)malloc(sizeof(node));
	if(!lista){
		printf("Sem memoria disponivel!\n");
 		exit(1);
	}
	inicia(lista);
	int opt;
	do{
		opt=menu();
		opcao(lista,opt);
		}while(opt!=5);
	free(lista);
	return 0;

}
