/* 
 * File:   main.h
 * Author: Daniel e Wesklei
    */
#ifndef _MAIN_H_
#define _MAIN_H_
    /*INCLUDES*/
   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   #include <stdio_ext.h>
   #include <ctype.h>
   #include <time.h>
   #include <dirent.h>
   #include <stdbool.h>
   #include <unistd.h>
   #include <math.h>
   //#include "Q4/questao4.h"
   //#include <curses.h> // para windows

    /*DEFINICOES*/
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
   #define LIMPA "clear || cls"
   #define T_NOME 30
   #define T_END 30
   #define T_FONE 20

   typedef struct{ /*Para o Merge e Arvore*/
       int cod;
       char nome[T_NOME];
       char end[T_END];
       char fone[T_FONE];
    } Agenda;
    
    typedef struct agenda2{ /*Para a Lista*/
       int cod;
       char nome[T_NOME];
       char end[T_END];
       char fone[T_FONE];
       struct agenda2 *proximo;
    }Agenda2, *pAgenda2, **ppAgenda2;

    extern int questao1();
    extern void questao2();
    extern void questao3();
    extern void menuQuatro();
    extern void questao5();
   
#endif