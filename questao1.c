#include "main.h"

int inserirElemento1(void *aux, char *arq) {
    FILE *pF = fopen(arq, "ab+");
    if (!pF) {
        printf("Problema no %s!", arq);
        return FRACASSO;
    }
    fwrite(aux, sizeof (Agenda), 1, pF);
    fclose(pF);
    return SUCESSO;
}

void intercalaElementos() {
    Agenda a1;
    Agenda a2;
    Agenda m;

    FILE *pF1 = fopen(arq1, "rb");
    FILE *pF2 = fopen(arq2, "rb");
    FILE *pF3 = fopen(arq3, "w+b");

    fread(&a1, sizeof (Agenda), 1, pF1);
    fread(&a2, sizeof (Agenda), 1, pF2);
    while (!feof(pF1) && !feof(pF2)) {
        if (a1.cod < a2.cod) {
            printf("a1 = %d menor a2 = %d\n", a1.cod, a2.cod);
            fwrite(&a1, sizeof (Agenda), 1, pF3);
            printf("Inserindo a1 = %d no arq3\n", a1.cod);
            fread(&a1, sizeof (Agenda), 1, pF1);
            if (feof(pF1)) {
                while (!feof(pF2)) {
                    printf("Arq1 acabou\nInserindo a2 = %d no arq3\n", a2.cod);
                    fwrite(&a2, sizeof (Agenda), 1, pF3);
                    fread(&a2, sizeof (Agenda), 1, pF2);
                }
            }
        } else {
            printf("a1 = %d maior a2 = %d\n", a1.cod, a2.cod);
            fwrite(&a2, sizeof (Agenda), 1, pF3);
            printf("Inserindo a2 = %d no arq3\n", a2.cod);
            fread(&a2, sizeof (Agenda), 1, pF2);
            if (feof(pF2)) {
                while (!feof(pF1)) {
                    printf("Arq2 acabou\nInserindo a1 = %d no arq3\n", a1.cod);
                    fwrite(&a1, sizeof (Agenda), 1, pF3);
                    fread(&a1, sizeof (Agenda), 1, pF1);
                }
            }
        }
        printf("\n---Elementos mesclados---:\n");
    }
    fclose(pF1);
    fclose(pF2);
    fclose(pF3);
    /*Reabre pra leitura*/
    pF3 = fopen(arq3, "rb");
    while (fread(&m, sizeof (Agenda), 1, pF3)) {
        printf("Codigo:\t%d \nNome : \t%sRua  : \t%sFone : \t%s",
                m.cod, m.nome, m.end, m.fone);
    }
    fclose(pF3);
}

int questao1(void) {
    Agenda a, a1;
    int opc, ag_num, ret;

    do {
        system(LIMPA);
        printf("\tQ1 - MERGE SORT\n\n");
        printf(" \t[1] Inserir na agenda...\n "
                "\t[2] Merge entre agendas\n "
                "\t[3] Remover Agendas\n "
                "\t[0] Voltar programa principal\n"
                "Opcao:__[");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
            {
                printf("Qual agenda? (1 ou 2):__");
                scanf("%d", &ag_num);
                printf("Entre com:\n\tCodigo:__");
                scanf("%i*c", &a.cod);
                printf("\tNome:__");
                __fpurge(stdin);
                fgets(a.nome, T_NOME * sizeof (char), stdin);
                printf("\tRua:__");
                __fpurge(stdin);
                fgets(a.end, T_END * sizeof (char), stdin);
                printf("\tFone:__");
                __fpurge(stdin);
                fgets(a.fone, T_FONE * sizeof (char), stdin);
                if (ag_num == 1)
                    ret = inserirElemento1(&a, arq1);
                else if (ag_num == 2)
                    ret = inserirElemento1(&a, arq2);
                else {
                    printf("Valor errado... Tente 1 ou 2\n");
                    break;
                }
                if (!ret) {
                    printf("Problema na insercao de %d!\n", a.cod);
                    return;
                } else
                    printf("Elemento [%d] inserido em 'file%i.dat'.\n", a.cod, ag_num);
            }
                break;
            case 2: intercalaElementos();
                break;
            case 3:
            {
                ag_num = 0;
                char comando[20] = "rm -f ";
                printf("Deseja remover qual agenda? (1,2,3,4=todas)\nOpcao__");
                scanf("%d", &ag_num);
                switch (ag_num) {
                    case 1:
                    {
                        strcat(comando, arq1);
                        system(comando);
                        printf("comando = %s\n", comando);
                    }
                        break;
                    case 2:
                    {
                        strcat(comando, arq2);
                        system(comando);
                        printf("comando = %s\n", comando);
                    }
                        break;
                    case 3:
                    {
                        strcat(comando, arq3);
                        system(comando);
                        printf("comando = %s\n", comando);
                    }
                        break;
                    case 4:
                    {
                        system("rm -f *.dat");
                        printf("comando = rm -f *.dat\n");
                    }
                    default:
                    {
                    } //printf("Escolha de 1 a 4\n");
                }
            }
                break;
            default:
            {
            }//printf("Opcao errada!\n");
        }
        printf("[ENTER] para continuar...\n");
        fflush(stdin);
        __fpurge(stdin);
        getchar();
    } while (opc != 0);
    return SUCESSO;
}
