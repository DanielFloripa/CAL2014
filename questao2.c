#include "main.h"

typedef struct agenda2 {
    int cod;
    char nome[30];
    char endereco[30];
    char fone[20];
    struct agenda2 *proximo;
} Agenda2, *pAgenda2, **ppAgenda2;

int inserirLista(ppAgenda2 agenda, int cod, char nome[30], char endereco[30], char fone[20]) {
    pAgenda2 aux;

    //Lista vazia
    if ((*agenda) == NULL) {
        (*agenda) = (pAgenda2) malloc(sizeof (Agenda2));
        if ((*agenda) == NULL) {
            return FRACASSO;
        }
        (*agenda)->cod = cod;
        strcpy((*agenda)->nome, nome);
        strcpy((*agenda)->endereco, endereco);
        strcpy((*agenda)->fone, fone);
        (*agenda)->proximo = NULL;

    } else {
        //Aux apontando para agenda
        aux = *agenda;

        //Percorrendo lista para achar a ultima posição              
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }

        aux->proximo = (pAgenda2) malloc(sizeof (Agenda2));
        if (aux->proximo == NULL) {
            return FRACASSO;
        }
        aux = aux->proximo;
        aux->cod = cod;
        strcpy(aux->nome, nome);
        strcpy(aux->endereco, endereco);
        strcpy(aux->fone, fone);
        aux->proximo = NULL;
    }
    return SUCESSO;
}

int removerLista(ppAgenda2 agenda, int cod) {
    pAgenda2 aux, auxProximo;
    aux = *agenda;

    if (aux == NULL) //Lista vazia
        return FRACASSO;
    if (aux->proximo == NULL) { //Lista com 1 elemento
        if (aux->cod == cod) {
            free(agenda);
            agenda = NULL;
            return SUCESSO;
        }
    } else {
        if (aux->cod == cod) {
            free(aux);
        } else {
            auxProximo = aux->proximo;
            while (auxProximo != NULL) {
                if (auxProximo->cod == cod) {
                    aux->proximo = auxProximo->proximo;
                    free(auxProximo);
                }
                aux = auxProximo;
                auxProximo = auxProximo->proximo;
            }
        }
    }
    return SUCESSO;
}

int buscarLista(ppAgenda2 agenda, int cod) {
    pAgenda2 aux, auxProximo;
    aux = *agenda;

    //Lista vazia
    if (aux == NULL)
        return FRACASSO;

    //Lista com 1 elemento reducao da complexidade
    if (aux->proximo == NULL) {
        if (aux->cod == cod) {
            printf("Codigo: %d \nNome: %s Endereco: %s Fone: %s \n", aux->cod, aux->nome, aux->endereco, aux->fone);
            return SUCESSO;
        }
    }        //Lista com mais de 1 elemento
    else {
        if (aux->cod == cod) {
            printf("Codigo: %d \nNome: %s Endereco: %s Fone: %s \n", aux->cod, aux->nome, aux->endereco, aux->fone);
            return SUCESSO;
        } else {
            auxProximo = aux->proximo;
            while (auxProximo != NULL) {
                if (auxProximo->cod == cod) {
                    printf("Codigo: %d \nNome: %s Endereco: %s Fone: %s \n", auxProximo->cod, auxProximo->nome, auxProximo->endereco, auxProximo->fone);
                    return SUCESSO;
                }
                aux = auxProximo;
                auxProximo = auxProximo->proximo;
            }
        }
    }
    return SUCESSO;
}

void questao2(void) {

    pAgenda2 agenda = NULL;
    int opc, cod;
    char nome[T_NOME],
            end[T_END],
            fone[T_FONE];
    do {
        do {
            system(" clear || cls");
            printf("---Questao 2 ---\n\n");
            printf("\t1) Inserir\n \t2) Buscar\n \t3) Remover\n \t0)Sair..\n Opcao:__");
            scanf("%d", &opc);
        } while (opc > 3 || opc < 0);
        switch (opc) {
            case 1:
            {
                printf("Entre com:\ncodigo: ");
                scanf("%i*c", &cod);
                printf("Nome: ");
                __fpurge(stdin);
                fgets(nome, T_NOME * sizeof (char), stdin);
                printf("Rua: ");
                __fpurge(stdin);
                fgets(end, T_END * sizeof (char), stdin);
                printf("Fone: ");
                __fpurge(stdin);
                fgets(fone, T_FONE * sizeof (char), stdin);

                if (!inserirLista(&agenda, cod, nome, end, fone))
                    printf("Problema na insercao de %d!\n", cod);
                else
                    printf("%d Inserido com sucesso!\n", cod);
            }
                break;
            case 2:
            {
                printf("Qual codigo quer buscar?\n");
                scanf("%d", &cod);

                if (!buscarLista(&agenda, cod))
                    printf("Contato %d nao encontrado!\n", cod);
            }
                break;
            case 3:
            {
                printf("Qual codigo quer remover?\n");
                scanf("%d", &cod);
                if (!removerLista(&agenda, cod))
                    printf("Problema ao remover %d!\n", cod);
                else
                    printf("%d Removido com sucesso!\n", cod);
            }
                break;
            case 0:  printf("Saindo...\n"); 
                break;
            default: printf("Opcao errada! Tente de 0 a 3\n");
        }
        printf("Pressione [ENTER] para continuar...\n");
        fflush(stdin);
        __fpurge(stdin);
        getchar();
    } while (opc != 0);
}
