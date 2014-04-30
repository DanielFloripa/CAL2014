#ifndef _QUESTAO4_H_
#define _QUESTAO4_H_
#include "../main.h"

extern void menuQuatro(void);
extern void subMenuCasos(int opcao, char metodo[20]);
extern int teste(int numCaso, char nomeCaso[20], 
        int numMet, char nomeMet[20]);

typedef struct{
    char mel[5];
    char med[5];
    char pio[5];
}AlgoOrd;

#endif