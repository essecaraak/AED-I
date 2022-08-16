#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int part(int * vet,int prim,int ult){
	int piv,i,j,aux;
	piv=vet[ult];
	i=prim-1;
	for(j=prim;j<ult;j++){
		if(vet[j]<piv){
			i++;
			aux=vet[i];
			vet[i]=vet[j];
			vet[j]=aux;
		}
	}
	aux=vet[i+1];
	vet[i+1]=vet[ult];
	vet[ult]=aux;
	
	return (i+1);
}
void quicksort(int* vet,int prim,int ult){
	int ponto;
	if(prim<ult){
		ponto=part(vet,prim,ult);
		quicksort(vet,prim,ponto-1);
		quicksort(vet,ponto+1,ult);
	}
}

int menu(void){ 
	int opt;
	printf("Escolha a opcao\n");
	printf("1. exibir\n");
	printf("2. randomizar\n");
	printf("3. ordenar\n");
	printf("4. sair\n");
	printf("Opcao: "); scanf("%d", &opt);
	return opt;
}

void opcao(int*vet,int op,int n,int x){ 
	int i,j,aux,min;
	clock_t begin,end;
	switch(op){
		case 1: 
			for(i=0;i<n;i++){
				printf("%d\n",*vet);
				vet++;
			}
			system("pause");
			system("cls");
			break;
		case 2: 
			for(i=0;i<n;i++){
				*vet=rand(); 
				vet++;
			}
			system("cls");
			break;
	    case 3: 
		    switch(x){
				case 1:
					begin=clock();
					for(i=n-1;i>0;i--){
						for(j=0;j<i;j++){
							if(vet[j]>vet[j+1]){
								aux=vet[j];
								vet[j]=vet[j+1];
								vet[j+1]=aux;
							}
						}
					}
					end=clock();
					printf("o tempo de ordenacao foi de %.9f\n",((double)(end-begin)/CLOCKS_PER_SEC));
					system("pause");
				break;
				case 2:
					begin=clock();
					for(i=0;i<n-1;i++){
						min=i;
						for(j=i+1;j<n;j++){
							if(vet[j]<vet[min]){
								min=j;
							}	
						}
						if(i!=min){
							aux=vet[i];
							vet[i]=vet[min];
							vet[min=aux];
						}
					}
					end=clock();
					printf("o tempo de ordenacao foi de %.9f\n",((double)(end-begin)/CLOCKS_PER_SEC));
					system("pause");
					break;
				case 3:
					begin=clock();
					for(i=1;i<n;i++){
						min=vet[i];
						j=i-1;
						while((j>=0) && (min<vet[j])){
							vet[j+1]=vet[j];
							j--;
						}
						vet[j+1]=min;
					}
					end=clock();
					printf("o tempo de ordenacao foi de %.9f\n",((double)(end-begin)/CLOCKS_PER_SEC));
					system("pause");
					
					break;
				case 4:
					begin=clock();
					quicksort(vet,0,n-1);
					end=clock();
					printf("o tempo de ordenação foi de %.9f\n",((double)(end-begin)/CLOCKS_PER_SEC));
					system("pause");
					
					break;
			}
			system("cls");
 			break;
		case 4: 
			system("cls");
			break;
		default:printf("Comando invalido\n\n");system("pause");system("cls");
}
}
main(){
	srand(time(NULL));
	int opt,opt1,opt2;
	int* v1;
	int* v2;
	int* v3;
	
	do{
		printf("Escolha a opcao\n");
		printf("1. bubblesort\n");
		printf("2. selectionsort\n");
		printf("3. insertionsort\n");
		printf("4. quicksort\n");
		printf("5. sair\n");
		scanf("%d",&opt1); 
		if(opt1<5 && opt1>0){	
		system("cls");	
			do{
				printf("Escolha a opcao\n");
				printf("1. utilizar vetor de 100 posicoes\n");
				printf("2. utilizar vetor de 1000 posicoes\n");
				printf("3. utilizar vetor de 10000 posicoes\n");	
				printf("4. sair\n");
				scanf("%d",&opt); 
				switch(opt){
					case 1:	
						system("cls");
						v1=(int*)malloc(100*sizeof(int));
						do{
							opt2=menu();
							opcao(v1,opt2,100,opt1);
						}while(opt2!=4);
						free(v1);
						break;
					case 2:
						system("cls");
						v2=(int*)malloc(1000*sizeof(int));
						do{
							opt2=menu();
							opcao(v2,opt2,1000,opt1);
						}while(opt2!=4);
						free(v2);
						break;
					case 3:
						system("cls");
						v3=(int*)malloc(10000*sizeof(int));
						do{
							opt2=menu();
							opcao(v3,opt2,10000,opt1);
						}while(opt2!=4);
						free(v3);
						break;
					case 4:
						system("cls");
						break;	
					default:printf("Comando invalido\n\n");system("pause");system("cls");
				}
			}while(opt!=4);
		}else{
			if(opt1==5){
				system("cls");
				break;
			}else{
				printf("Comando invalido\n\n");
				system("pause");
				system("cls");
			}
		}	
	}while(opt1!=5);
}
			
	
	

