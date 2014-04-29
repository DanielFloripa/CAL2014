#include "questao4.h"

void menuQuatro(void) {
    char opcao;
    do {
        system(" clear || cls");
        printf("\tALGORITMOS DE ORDENACAO  \n");
        printf("\t\tMENU PRINCIPAL\n");
        printf("[1] Bubble Sort\n");
        printf("[2] Insertion Sort\n");
        printf("[3] Merge Sort\n");
        printf("[4] Quick Sort\n");
        printf("[5] Heap Sort\n");
        printf("[0] Sair\n");
        printf("\t\tEscolha a opcao: ");
        opcao = getchar();
        __fpurge(stdin);
        fflush(stdin);

        switch (opcao) {
            case '1': menuBubble();
                break;
            case '2': menuInsertion();
                break;
            case '3': menuMerge();
                break;
            case '4': menuQuick();
                break;
            case '5': menuHeap();
                break;
            case '0':
            {
                printf("Voltando para menu principal\n");
                sleep(2);
                return;
            } break;
            default: printf("\nOpcao incorreta, escolha de 0 a 5\n\n");
        }
    } while (opcao < 0 || opcao > 5);
}
