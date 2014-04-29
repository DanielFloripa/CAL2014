//Insertion Sort
#include "questao4.h"

void InsertionSort(int *v, int n){
    int i,j,aux;
    
    for(i=1;i<n;i++){
        aux = v[i];
        j = i-1;
        
        while(j>=0 && v[j] > aux){
            v[j+1] = v[j];
            j--;
        }
        v[j] = aux;
    }
}

void menuInsertion(){
    //Variaveis para calculo de tempo
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    //Variaveis de controle
    int tamVet;
    int i;
    int *v;
    char opcao;
    do {
        system(LIMPA);
        printf("\tQ4 - ALGORITMOS DE ORDENACAO  \n");
        printf("\t 2 - INSERTION SORT\n\n"); 
        printf("\t[1] Ordenacao Crescente (melhor caso)\n");
        printf("\t[2] Ordenacao Decrescente (pior caso)\n");
        printf("\t[3] Ordenacao Aleatoria\n");
        printf("\t[4] Apresentar resultados\n");
        printf("\t[0] Voltar ao Menu Q4\n");             
        printf("Opcao:__[");
        __fpurge(stdin);
        fflush(stdin); 
        opcao = getchar();
        
        switch(opcao){
            case '1': {
                printf("\n\n\t\t Informe o tamanho do vetor: ");
                scanf("%d",&tamVet);
                int vet[tamVet];
                
                for(i=0;i<tamVet;i++){
                    vet[i] = i;      
                }
                v = vet;
                
                tempoInicial = clock();
                InsertionSort(v,tamVet);
                tempoFinal = clock();
                
                tempoGasto = (tempoFinal - tempoInicial)/(double)CLOCKS_PER_SEC;
                printf("\t\t Tempo de execucao: %.3f segundos\n\n",tempoGasto);
                 __fpurge(stdin);
				fflush(stdin);
                getchar();
            }; break;
            
            case '2': {
                printf("\n\n\t\t Informe o tamanho do vetor: ");
                scanf("%d",&tamVet);
                int vet[tamVet];
                
                for(i=0;i<tamVet;i++){
                    vet[i] = tamVet-i;      
                }
                v = vet;
                
                tempoInicial = clock();
                InsertionSort(v,tamVet);
                tempoFinal = clock();
                
                tempoGasto = (tempoFinal - tempoInicial)/(double)CLOCKS_PER_SEC;
                printf("\t\t Tempo de execucao: %.3f segundos\n\n",tempoGasto);
                 __fpurge(stdin);
				fflush(stdin);
                getchar();
            }; break;
            
            case '3': {
                printf("\n\n\t\t Informe o tamanho do vetor: ");
                scanf("%d",&tamVet);
                int vet[tamVet];
                
                for(i=0;i<tamVet;i++){
                    vet[i]= rand()%5000; 
                }
                v = vet;
                
                tempoInicial = clock();
                InsertionSort(v,tamVet);
                tempoFinal = clock();
                
                tempoGasto = (tempoFinal - tempoInicial)/(double)CLOCKS_PER_SEC;
                printf("\t\t Tempo de execucao: %.3f segundos\n\n",tempoGasto);
                 __fpurge(stdin);
				fflush(stdin);
                getchar();
            }; break;
            
            case '4': {
                printf("\n\n\t\t Complexidade melhor caso: O(n)");
                printf("\n\n\t\t Complexidade pior caso:   O(n^2)");
                printf("\n\n\t\t Complexidade caso medio:  O(n^2)");
                 __fpurge(stdin);
				fflush(stdin);
                getchar();
            }; break;
            
            default: {
            }
        }
    }
    while(opcao != '0');
}
