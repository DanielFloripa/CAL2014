//QuickSort
#include "questao4.h"

int Particione(int *v, int esquerda, int direita){
    //Criando ponto de pivo
    int x = v[(esquerda+direita)/2];
    int aux;
    
    int alto = direita;
    int baixo = esquerda;
    
    while(baixo < alto){
        while(x < v[alto]){
            alto--;
        }
        while(x > v[baixo]){
            baixo++;
        }
        if(baixo < alto){
            aux = v[baixo];
            v[baixo] = v[alto];
            v[alto] = aux;
        }
        else {
            return alto;
        }
    }
}

void Quick(int *v, int esquerda, int direita){
    int i;
    
    if(esquerda < direita){
        i = Particione(v, esquerda, direita);
        Quick(v,esquerda,i-1);
        Quick(v,i+1,direita);
    }
}

void QuickSort(int *v, int n){
    Quick(v, 0, n-1);
}

/**/
void menuQuick() {
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
        printf("\tQ4 - ALGORITMOS DE ORDENACAO\n");
        printf("\t 4 - QUICK SORT \n\n");
        printf("\t[1] Ordenacao Crescente (melhor caso)\n");
        printf("\t[2] Ordenacao Decrescente (pior caso)\n");
        printf("\t[3] Ordenacao Aleatoria\n");
        printf("\t[4] Apresentar resultados\n");
        printf("\t[0] Voltar ao Menu Q4\n");
        printf("Opcao:__[");
        __fpurge(stdin);
        fflush(stdin);
        opcao = getchar();
        
        switch (opcao) {
            case '1':
            {
                printf("\n\n\t\t Informe o tamanho do vetor: ");
                scanf("%d", &tamVet);
                int vet[tamVet];

                for (i = 0; i < tamVet; i++) {
                    vet[i] = i;
                }
                v = vet;

                tempoInicial = clock();
                QuickSort(v, tamVet);
                tempoFinal = clock();

                tempoGasto = (tempoFinal - tempoInicial) / (double) CLOCKS_PER_SEC;
                printf("\t\t Tempo de execucao: %.3f segundos\n\n", tempoGasto);
                __fpurge(stdin);
                fflush(stdin);
                getchar();
            };
                break;

            case '2':
            {
                printf("\n\n\t\t Informe o tamanho do vetor: ");
                scanf("%d", &tamVet);
                int vet[tamVet];

                for (i = 0; i < tamVet; i++) {
                    vet[i] = tamVet - i;
                }
                v = vet;

                tempoInicial = clock();
                QuickSort(v, tamVet);
                tempoFinal = clock();

                tempoGasto = (tempoFinal - tempoInicial) / (double) CLOCKS_PER_SEC;
                printf("\t\t Tempo de execucao: %.3f segundos\n\n", tempoGasto);
                __fpurge(stdin);
                fflush(stdin);
                getchar();
            };
                break;

            case '3':
            {
                printf("\n\n\t\t Informe o tamanho do vetor: ");
                scanf("%d", &tamVet);
                int vet[tamVet];

                int j, t;
                srand(time(NULL));
                for (i = 0; i < tamVet; i++)
                    vet[i] = i;
                for (i = 0; i < tamVet; i++) {
                    j = rand() % (tamVet - i) + i;
                    t = vet[j];
                    vet[j] = vet[i];
                    vet[i] = t;
                }
                v = vet;

                tempoInicial = clock();
                QuickSort(v, tamVet);
                tempoFinal = clock();

                tempoGasto = (tempoFinal - tempoInicial) / (double) CLOCKS_PER_SEC;
                printf("\t\t Tempo de execucao: %.3f segundos\n\n", tempoGasto);
                __fpurge(stdin);
                fflush(stdin);
                getchar();
            };
                break;
            case '4':
            {
                printf("\n\n\t\t Complexidade melhor caso: O(n*logn)");
                printf("\n\n\t\t Complexidade pior caso:   O(n^2)");
                printf("\n\n\t\t Complexidade caso medio:  O(n*logn)");
                __fpurge(stdin);
                fflush(stdin);
                getchar();
            };
                break;

            default:
            {
                //printf("\nOpcao incorreta, tente de 0 a 4\n");
            }
        }
    }    while (opcao != '0');
}
