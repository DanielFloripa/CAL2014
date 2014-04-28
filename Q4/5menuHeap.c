//HeapSort
#include "questao4.h"


void menuHeap(){
    //Variaveis para calculo de tempo
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    //Variaveis de controle
    int tamVet;
    int i;
    int *v;
    char opcao;

    do {
        system("clear || cls");
        printf("\t\t ALGORITMOS DE ORDENACAO  \n");
        printf("\t 5 - HEAP SORT \n");
        printf("[1] Ordenacao Crescente (melhor caso)   \n");
        printf("[2] Ordenacao Decrescente (pior caso)   \n");
        printf("[3] Ordenacao Aleatoria          \n");
        printf("[4] Apresentar resultados        \n");
        printf("[0] Voltar ao Menu Principal     \n");
        printf("         Escolha a opcao: ");
        opcao = getchar();
        __fpurge(stdin);
        fflush(stdin);

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
                //QuickSort(v, tamVet);
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
                //QuickSort(v, tamVet);
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
                //QuickSort(v, tamVet);
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
                /*printf("\n\n\t\t Complexidade melhor caso: O(n*logn)");
                printf("\n\n\t\t Complexidade pior caso:   O(n^2)");
                printf("\n\n\t\t Complexidade caso medio:  O(n*logn)");*/
                __fpurge(stdin);
                fflush(stdin);
                getchar();
            };
                break;

            default:
            {
                printf("\nOpcao incorreta, tente de 0 a 4\n");
            }
        }
    }    while (opcao != '0');
}
