//MergeSort
#include "questao4.h"

void intercala(int *vet, int p, int q, int r) {
    int i, j, k, *w;
    w = (int *) malloc((r - p) * sizeof (int));

    i = p;
    j = q;
    k = 0;
    while (i < q && j < r) {
        if (vet[i] <= vet[j]) w[k++] = vet[i++];
        else w[k++] = vet[j++];
    }
    while (i < q) {
        w[k++] = vet[i++];
    }
    while (j < r) {
        w[k++] = vet[j++];
    }
    for (i = p; i < r; ++i) {
        vet[i] = w[i - p];
    }
    free(w);
}

// A funcao mergesort rearranja o vetor v[p..r-1] em ordem crescente.

void Merge(int *vet, int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        Merge(vet, p, q);
        Merge(vet, q + 1, r);
        intercala(vet, p, q, r);
    }
}

void MergeSort(int *v, int n) {
    Merge(v, 0, n - 1);
}


void menuMerge(){
    //Variaveis para calculo de tempo
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    
    //Variaveis de controle
    int tamVet;
    int i;
    int *v;
    
    char opcao;
    
    do {
        system("clear");
        printf("\t\t ALGORITMOS DE ORDENACAO  \n");
        printf("\t 3 - MERGE SORT \n"); 
        printf("[1] Ordenacao Crescente (melhor caso)   \n");
        printf("[2] Ordenacao Decrescente (pior caso)   \n");
        printf("[3] Ordenacao Aleatoria          \n");
        printf("[4] Apresentar resultados        \n");
        printf("[0] Voltar ao Menu Principal     \n");             
        printf("         Escolha a opcao: ");
        opcao = getchar();
        __fpurge(stdin);
        fflush(stdin);    
        
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
                MergeSort(v,tamVet);
                tempoFinal = clock();
                
                tempoGasto = (tempoFinal - tempoInicial) / (double) CLOCKS_PER_SEC;
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
                MergeSort(v,tamVet);
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
                    vet[i] = rand()%5000000;
                }
                v = vet;
                
                tempoInicial = clock();
                MergeSort(v,tamVet);
                tempoFinal = clock();
                
                tempoGasto = (tempoFinal - tempoInicial)/(double)CLOCKS_PER_SEC;
                printf("\t\t Tempo de execucao: %.3f segundos\n\n",tempoGasto);
                 __fpurge(stdin);
				fflush(stdin);
                getchar();
            }; break;
            
            case '4': {
                printf("\n\n\t\t Complexidade melhor caso: O(n logn)");
                printf("\n\n\t\t Complexidade pior caso:   O(n logn)");
                printf("\n\n\t\t Complexidade caso medio:  O(n logn)");
                 __fpurge(stdin);
				fflush(stdin);
                getchar();
            }; break;
            
            default: {
                printf("\nOpcao incorreta, tente de 0 a 4\n");
            }
        }
    }
    while(opcao != '0');
}
