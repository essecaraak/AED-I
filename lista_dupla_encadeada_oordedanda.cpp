#include <stdio.h>
#include <stdlib.h>


struct node{
	int num;
	struct node *prox;
	struct node *ant;
};
typedef struct node node;

void inicia(node *lista){
	lista->prox=NULL;
	lista->ant=NULL;
	lista->num=-1;
}

int vazia(node *lista){
	if(lista->prox == NULL){	
		return 1;
		}else{
		return 0;
		};

};

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

void exibe(node *lista){
	if(vazia(lista)){
		printf("Lista vazia!\n\n");
		return ;
	}
	node *tmp;
	tmp=lista->prox;
	while(tmp!=lista){
		printf("%5d",tmp->num);
			tmp=tmp->prox;
		}
	printf("\n\n");
}

void exibeinversa(node *lista){

	if(vazia(lista)){
		printf("Lista vazia!\n\n");
		return ;
	}
	node *tmp;
	tmp=lista->ant;
	while(tmp!=lista){
		printf("%5d",tmp->num);
			tmp=tmp->ant;
		}
	printf("\n\n");
}

node *buscaordenada(node*lista,int x,node **ant){
	node *ptr ; *ant = lista; ptr = NULL ;
 	if(vazia(lista)){
		return NULL ;
	}else{	
 		if (x>lista->ant->num){
		 	*ant=lista->ant;
		 	return NULL ;
		}else{
			ptr = lista->prox;
 			while (ptr != lista){
				if(ptr->num < x){
					*ant=ptr;
 					ptr=ptr->prox;
				}else{
					if(ptr->num == x){
						return ptr ;
					}else{
						return (NULL);
						break;
					}
				}
		  	
 			}
 		}	 
	}	
}

void insere(node *lista,int x){
	node *tmp1=NULL,*ant;
	node *novo=(node*)malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	};
	tmp1=buscaordenada(lista,x,&ant);
	if(tmp1==NULL){
		novo->num=x;
		if(vazia(lista)){
			lista->prox=novo;
			novo->ant=lista;
			lista->ant=novo;
			novo->prox=lista;
		}else{
			node *tmp=ant->prox;
			ant->prox=novo;
 			novo->ant=ant;
			novo->prox=tmp;
 			tmp->ant=novo; 
		}
	}else{
			printf("ta na lista ja fi\n\n");
		}
}

void retira(node *lista,int x){
	node *tmp = NULL , *ant ;
 	tmp = buscaordenada(lista,x,&ant) ;
 	if(tmp==NULL ){
		printf("\nElemento n'ao Existe!\n\n");
	}else{
		if (lista->prox->prox == lista){
			node *tmp = lista->prox;
		 	lista->prox = NULL ;
			lista->ant = NULL ;
			free(tmp);
		}else{
			node *aux1 = tmp->prox;
			node *aux2 = tmp->ant;
			aux2->prox= aux1;
			aux1->ant = aux2; ;
			free(tmp);
 		}	
 	}
}
int menu(void){ 
	int opt;
	printf("Escolha a opcao\n");
	printf("1. Exibir lista\n");
	printf("2. Exibir lista inversa\n");
	printf("3. BUsca\n");
	printf("4. Inserir\n");
	printf("5. retirar\n");
	printf("6. zerar lista\n");
	printf("7. sair\n");
	printf("Opcao: "); scanf("%d", &opt);
	return opt;
}

void opcao(node *lista, int op){ 
	int x ; node *ptr=NULL, *ant=NULL;
	switch(op){
		case 1: 
			exibe(lista);
			break;
		case 2: 
			exibeinversa(lista);
			break;
	    case 3: 
			printf("\n BUSCA elemento: ");
			scanf("%d", &x); 
			ptr=buscaordenada(lista,x,&ant);
			if(ptr==NULL){
				printf(" \n Elemento nao encontrado %d \n\n",ant->num);
			}else{
				printf("\n elemento: %d \n \n ",ptr->num);
			}
 			break;
		case 4: 
			printf("\n Novo elemento: ");
			scanf("%d", &x);
			insere(lista,x); 
			printf("\n");
			break;
		case 5:
			printf("\n BUSCA elemento: ");
			scanf("%d",&x);
			retira(lista,x);
			printf("\n");
			break;
		case 6: ;
			libera(lista);
			break;
		case 7:
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
		}while(opt!=7);
	free(lista);
	return 0;

}
