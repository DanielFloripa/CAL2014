#include "questao4.h"



void menuQuatro(void) {
    int opcao;
    char metodo[20];
    AlgoOrd caso;
    do {
        system(LIMPA);
        printf("\tQ4 - ALGORITMOS DE ORDENACAO\n\n"
                "\t[1] Bubble Sort\n"
                "\t[2] Insertion Sort\n"
                "\t[3] Merge Sort\n"
                "\t[4] Quick Sort\n"
                "\t[5] Heap Sort\n"
                "\t[0] Voltar menu principal\n"
                "Opcao:__[");
        scanf(" %d", &opcao);
        switch (opcao) {
            case 1: strcpy(metodo, "BUBBLE SORT: ");
                break;
            case 2: strcpy(metodo, "INSERTION SORT: ");
                break;
            case 3: strcpy(metodo, "MERGE SORT: ");
                break;
            case 4: strcpy(metodo, "BUBBLE SORT: ");
                break;
            case 5: strcpy(metodo, "HEAP SORT: ");
                break;
            case 0: puts("Voltandooo...\n");
                break;
            default: puts("Escolha de 0 a 5\n");
        }
        if (opcao > 0 && opcao < 6)
            subMenuCasos(opcao, metodo);
    } while (opcao != 0);
    printf("Voltando... [ENTER] para continuar...\n");
    fflush(stdin);
    __fpurge(stdin);
    getchar();
}

void subMenuCasos(int numMet, char nomeMet[20]) {
    //Variaveis de controle
    char nomeCaso[20];
    int numCaso;

    do {
        system(LIMPA);
        printf("\t Q4 - ALGORITMOS DE ORDENACAO\n"
                "\t %d - %s\n\n"
                "\t[1] Ordenacao Crescente (melhor caso)\n"
                "\t[2] Ordenacao Decrescente (pior caso)\n"
                "\t[3] Ordenacao Aleatoria\n"
                "\t[0] Voltar ao Menu Q4\n"
                "Opcao:__[", numMet, nomeMet);
        scanf("%d", &numCaso);
        switch (numCaso) {
            case 1:
                strcpy(nomeCaso, "Melhor Caso\n");
                break;
            case 2:
                strcpy(nomeCaso, "Pior Caso\n");
                break;
            case 3:
                strcpy(nomeCaso, "Medio Caso\n");
                break;
            case 0: puts("Voltandooo...\n");
            break;
            default: puts("Escolha de 0 a 3\n");
        }
        if ((numCaso > 0) && (numCaso < 4))
            if (!teste(numCaso, nomeCaso, numMet, nomeMet))
                printf("Problemas no %s do %s", nomeCaso, nomeMet);
    } while (numCaso != 0);
}

int teste(int numCaso, char nomeCaso[20], int numMet, char nomeMet[20]) {
    //Variaveis para calculo de tempo
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    int tamVet = 60000;
    int i, j, *v;
    FILE *fp;

    fp = fopen(arq4, "a+t");
    if (fp == NULL)
        return FRACASSO;
    fprintf(fp, "\n%s%s\n", nomeMet, nomeCaso);
    fclose(fp);
    for (j = 0; j < 7; j++) {
        printf("\n\tTeste #%d"
                "\n\tTamanho do vetor: %d\n", j + 1, tamVet);
        int vet[tamVet];
        switch (numCaso) {
            case 1:
            {
                for (i = 0; i < tamVet; i++)
                    vet[i] = i;
            }
                break;
            case 2:
            {
                for (i = 0; i < tamVet; i++)
                    vet[i] = tamVet - i;
            }
                break;
            case 3:
            {
                for (i = 0; i < tamVet; i++)
                    vet[i] = rand() % 500000;
            }
                break;
            default:
            {
            }
        }
        v = vet;
        tempoInicial = clock();
        switch (numMet) {
            case 1: BubbleSort(v, tamVet);
                break;
            case 2: InsertionSort(v, tamVet);
                break;
            case 3: MergeSort(v, tamVet);
                break;
            case 4: QuickSort(v, tamVet);
                break;
            case 5: heapSort(v, tamVet);
                break;
            default:
            {
            }
        }
        tempoFinal = clock();
        tempoGasto = (tempoFinal - tempoInicial) / (double) CLOCKS_PER_SEC;
        fp = fopen(arq4, "a+t");
        if (fp == NULL)
            return FRACASSO;
        fprintf(fp, "%d; %.4f\n", tamVet, tempoGasto);
        fclose(fp);
        printf("\tTempo de execucao: %.4f segundos\n\n", tempoGasto);
        tamVet += 10000;
    }
    puts("[ENTER] para continuar\n");
    __fpurge(stdin);
    fflush(stdin);
    getchar();
    return SUCESSO;
}