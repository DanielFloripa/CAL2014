#include "main.h"

void questao5(void) {
    char opcao;
    do {
        system(LIMPA);
        printf("\tQ5 - ALGORITMO DE DIJKSTRA\n\n"
                "\t[1] Carregar matriz de arquivo\n"
                "\t[2] Entrar com matriz\n"
                "\t[3] Calcular Caminho mais curto\n"
                "\t[4] Mostra coplexidade\n"
                "\t[0] Sair\n"
                "Opcao:__[");
        __fpurge(stdin);
        fflush(stdin);
        opcao = getchar();
        switch (opcao) {
            case 1:
                break;
            case 2:
                break;

            default:
            {
            }
        }
    } while (opcao != 0);
}
