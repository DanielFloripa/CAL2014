//Bubble sort
#include "questao4.h"
#include <math.h>

int teste(int caso, char *metodo);

void BubbleSort(int *v, int n) {
    int i, j, aux;

    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
}

void menuBubble() {
    //Variaveis de controle
    char opcao, *metodo;
    strcpy(metodo, "BUBBLE SORT: ");

    do {
        system(LIMPA);
        printf("\t Q4 - ALGORITMOS DE ORDENACAO\n"
                "\t 1 - %s\n\n"
                "\t[1] Ordenacao Crescente (melhor caso)\n"
                "\t[2] Ordenacao Decrescente (pior caso)\n"
                "\t[3] Ordenacao Aleatoria\n"
                "\t[4] Apresentar resultados\n"
                "\t[0] Voltar ao Menu Q4\n"
                "Opcao:__[", metodo);
        __fpurge(stdin);
        fflush(stdin);
        opcao = getchar();

        switch (opcao) {
            case '1':
            {
                if(!teste(1, metodo))
                    printf("Problemas no caso %c\n",opcao);
            };
                break;

            case '2':
            {
                if(!teste(2, metodo))
                    printf("Problemas no caso %c\n",opcao);
            };
                break;

            case '3':
            {
                if(!teste(2, metodo))
                    printf("Problemas no caso %c\n",opcao);
            };
                break;

            case '4':
            {
                printf("\n\t\t Complexidade melhor caso: O(n^2)");
                printf("\n\t\t Complexidade pior caso:   O(n^2)");
                printf("\n\t\t Complexidade caso medio:  O(n^2)");
                __fpurge(stdin);
                fflush(stdin);
                getchar();
            };
                break;
            default:
            {
            }
        }
    } while (opcao != '0');
}

int teste(int caso, char *metodo) {
    //Variaveis para calculo de tempo
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    int tamVet, i, j, *v;
    FILE *fp;

    tamVet = 60000;
    fp = fopen(arq4, "a+t");
    if(fp == NULL)
        return FRACASSO;
    fprintf(fp, "%s\n", metodo);
    fclose(fp);
    for (j = 0; j < 7; j++) {
        printf("\n\tTeste #%d"
                "\n\tTamanho do vetor: %d\n", j + 1, tamVet);
        //scanf("%d", &tamVet);
        int vet[tamVet];
        switch (caso) {
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
            case 3:
            {
                for (i = 0; i < tamVet; i++)
                    vet[i] = rand() % 5000;
            }
            default:
            {
            }
        }
        v = vet;
        tempoInicial = clock();
        BubbleSort(v, tamVet);
        tempoFinal = clock();
        tempoGasto = (tempoFinal - tempoInicial) / (double) CLOCKS_PER_SEC;
        fp = fopen(arq4, "a+t");
        if(fp==NULL)
            return FRACASSO;
        fprintf(fp, "%d: %f\n", tamVet, tempoGasto);
        fclose(fp);
        printf("\tTempo de execucao: %.3f segundos\n\n", tempoGasto);
        tamVet += 10000;
    }
    puts("[ENTER] para continuar\n");
    __fpurge(stdin);
    fflush(stdin);
    getchar();
    return SUCESSO;
}