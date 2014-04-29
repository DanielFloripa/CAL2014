#include "questao4.h"

void menuQuatro(void) {
    int opcao;
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
            case 1: menuBubble();
                break;
            case 2: menuInsertion();
                break;
            case 3: menuMerge();
                break;
            case 4: menuQuick();
                break;
            case 5: menuHeap();
                break;
                break;
            default:
            {
            }
        }
        printf("Voltando... [ENTER] para continuar...\n");
        fflush(stdin);
        __fpurge(stdin);
        getchar();
    } while (opcao != 0);
}
