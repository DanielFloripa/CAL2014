/* 
 * File:   main.c
 * Author: Daniel e Wesklei
 */

#include "main.h"

void main(void)
{
    
    int opc;
    do{
        system (" clear || cls");
        printf("\t---MENU PRINCIPAL---\n\n");
        printf("Deseja executar qual questao?\n "
                "\t1) Q1 -> Merge do Agenda\n "
                "\t2) Q2 -> Lista encadeada\n "
                "\t3) Q3 -> Arvore Binaria de Pesquisa\n "
                "\t4) Q4 -> Metodos de ordenacao\n"
                "\t5) Q5 -> Dijkstra\n"
                "\t0) Sair..."
                "\n Opcao:__");
        scanf("%d", &opc);
        switch(opc){
            
            case 1: {
                if(!questao1())
                    printf("Problemas com a questao 1...\n");
            }
                break;
            case 2: {
                if(!questao2())
                    printf("Problemas com a questao 2...\n");
            }
            break;
            case 3: {
                if(!questao3())
                    printf("Problemas com a questao 3...\n");
            }
            break;
            case 4: {
                if(!menuQuatro())
                    printf("Problemas com a questao 4...\n");
                }				
            break;
            default: {
                printf("Opcao errada!\n Saindo...\n");
                sleep(2);
            }
        }
    }while(opc > 0 && opc < 5);
    exit (EXIT_SUCCESS);
}

