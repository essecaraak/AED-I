#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100000
void rand(int* vet,long int n){
	int i;
	for(i=0;i<n;i++){
		*vet=rand(); 
		vet++;
	}
}
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
			
			system("cls");
			break;
	    case 3: 
		    switch(x){
				case 1:
					
					system("pause");
				break;
				case 2:
			
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
	int i,j,aux,min,g=1,ver;
	int n;
	int *vet;
	clock_t begin,end;
	do{
		n=0;
		while(n<1 || n>100000){
			printf("Escolha o tamanho do seu vetor, com o maximo de 100000 \n");	
			scanf("%d",&n);
			if(n<1 || n>100000){
				puts("numero invalido");
				system("pause");
			}
			system("cls");
		}
		vet=(int*)malloc(max*sizeof(int));
		rand(vet,n);
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
		printf("o tempo de ordenacao do metodo bubblesort foi de %.9f\n\n",((double)(end-begin)/CLOCKS_PER_SEC));
		rand(vet,n);
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
		printf("o tempo de ordenacao do metodo selectionsort foi de %.9f\n\n",((double)(end-begin)/CLOCKS_PER_SEC));
		rand(vet,n);
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
		printf("o tempo de ordenacao do metodo insertionsort foi de %.9f\n\n",((double)(end-begin)/CLOCKS_PER_SEC));
		rand(vet,n);
		begin=clock();
		do {
	  		g=3*g+1;
		}while(g<n);
		do { 
			g/=3;
			for(i=g;i<n;i++){
	   			aux=vet[i];
	   			j=i-g;
	   			while(j>=0 && aux<vet[j]) {
	    			vet[j+g]=vet[j];
	    		j-=g;
	   			}
	   			vet[j+g]=aux;
	  		}
	 	}while(g>1);
		end=clock();
		printf("o tempo de ordenação do metodo shellsort foi de %.9f\n\n",((double)(end-begin)/CLOCKS_PER_SEC));
		rand(vet,n);
		begin=clock();
		quicksort(vet,0,n-1);
		end=clock();
		printf("o tempo de ordenação do metodo quicksort foi de %.9f\n\n",((double)(end-begin)/CLOCKS_PER_SEC));
		printf("para parar digite 0, digite qualquer outro numero para continuar ");
		scanf("%d",&ver);
		system("cls");
	}while(ver!=0);
}
			
	
	

