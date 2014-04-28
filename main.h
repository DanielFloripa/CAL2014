/* 
 * File:   main.h
 * Author: Daniel e Wesklei
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <time.h>
#include <dirent.h>
#include <stdbool.h>
#include <unistd.h>
#include "Q4/questao4.h"
//#include <curses.h> // para windows
#define T_NOME 30
#define T_END 30
#define T_FONE 20

typedef struct {
    int cod;
    char nome[T_NOME];
    char end[T_END];
    char fone[T_FONE];
}Agenda;

#define SUCESSO         1
#define FRACASSO        0
#define TRUE            1
#define FALSE           0
#define MAIOR           1
#define IGUAL           0
#define MENOR           -1
#define DIREITA         1
#define ESQUERDA        0
#define AMBOS           2


#define arq1 "file1.dat"
#define arq2 "file2.dat"
#define arq3 "file3.dat"


   extern int questao1();
   extern int questao2();
   extern int questao3();
   extern int menuQuatro();
   extern int questao5();


