//HeapSort
#include "questao4.h"

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// troca o valor de duas variaveis
void troca(float *data1,float *data2) {
  float temp;
  temp=*data1;
  *data1=*data2;
  *data2=temp;
}

// devolve o índice do filho esquerdo no no de indice i
int filho_esq(int i) {
  return 2*i;
}

// devolve o indice do filho direito do no de indice i
int filho_dir(int i) {
  return 2*i+1;
}

// efetua um push down no no de indice i
void pushDown(int i,float heap[],int tam) {
  int ha_esq=0,ha_dir=0;

  if (filho_esq(i)<=tam) ha_esq=1;
  if (filho_dir(i)<=tam) ha_dir=1;

  if (ha_esq&&!ha_dir) {
    if (heap[i]<heap[filho_esq(i)]) {
       troca(&heap[filho_esq(i)],&heap[i]);
       pushDown(filho_esq(i),heap,tam);
    }
  }
  else
  if (ha_esq&&ha_dir) {
    if ((heap[i]<heap[filho_esq(i)])||(heap[i]<heap[filho_dir(i)])) {
      if (heap[filho_esq(i)]>heap[filho_dir(i)]) {
	troca(&heap[filho_esq(i)],&heap[i]);
	i = filho_esq(i);
      }
      else {
	troca(&heap[filho_dir(i)],&heap[i]);
	i = filho_dir(i);
      }
      pushDown(i,heap,tam);
    }
  }
}

// funcao para fazer a montagem da heap
void montaHeap(float heap[],int tam) {
  int i;
  for (i=tam/2;i>=1;i--) {
    pushDown(i,heap,tam);
  }
}

// funcao para fazer a desmontagem da heap
void desmontaHeap(float heap[],int tam) {
  int i;
  int n=tam;
  for (i=1;i<=n;i++) {
    troca(&heap[1],&heap[tam]);
    tam--;
    pushDown(1,heap,tam);
  }
}

// heapSort: funcao que ordena uma lista dada, chamando, em ordem,
// a rotina que monta a heap e a que efetua a desmontagem
void heapSort(float lista[],int tam) {
  montaHeap(lista,tam);
  desmontaHeap(lista,tam);
}
/*
void main() {
  int N=10;       // numero de elementos
  int i; 
  float *numeros; // vetor que armazena os elementos
  int segundos;

  numeros=(float*)malloc((N+1)*sizeof(float));

  // inicializa o gerador de numeros aleatorios com o relogio da maquina
  segundos=time(NULL);
  srand(segundos);

  printf ("Antes:\n");
  for (i=1;i<=N;i++) {
    // artificio para gerar numeros entre 0 e 1000
    // RAND_MAX e uma constante definida na biblioteca stdlib.h
    // e que indica o maximo valor retornado por rand()
    numeros[i]=rand()/(RAND_MAX/1000);
    printf ("%g\n",numeros[i]);
  }
  printf ("\n");
  heapSort(numeros,N);
  printf ("Depois do heapSort:\n");
  for (i=1;i<=N;i++) {
    printf ("%g\n",numeros[i]);
  }
}
*/

void menuHeap(){
    //Variaveis para calculo de tempo
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    //Variaveis de controle
    int tamVet;
    int i;
    int *v;
    char opcao;

    do {
        system("clear || cls");
        printf("\t\t ALGORITMOS DE ORDENACAO  \n");
        printf("\t 5 - HEAP SORT \n");
        printf("[1] Ordenacao Crescente (melhor caso)   \n");
        printf("[2] Ordenacao Decrescente (pior caso)   \n");
        printf("[3] Ordenacao Aleatoria          \n");
        printf("[4] Apresentar resultados        \n");
        printf("[0] Voltar ao Menu Principal     \n");
        printf("         Escolha a opcao: ");
        opcao = getchar();
        __fpurge(stdin);
        fflush(stdin);

        switch (opcao) {
            case '1':
            {
                printf("\n\n\t\t Informe o tamanho do vetor: ");
                scanf("%d", &tamVet);
                int vet[tamVet];

                for (i = 0; i < tamVet; i++) {
                    vet[i] = i;
                }
                v = vet;

                tempoInicial = clock();
                //QuickSort(v, tamVet);
                tempoFinal = clock();

                tempoGasto = (tempoFinal - tempoInicial) / (double) CLOCKS_PER_SEC;
                printf("\t\t Tempo de execucao: %.3f segundos\n\n", tempoGasto);
                __fpurge(stdin);
                fflush(stdin);
                getchar();
            };
                break;

            case '2':
            {
                printf("\n\n\t\t Informe o tamanho do vetor: ");
                scanf("%d", &tamVet);
                int vet[tamVet];

                for (i = 0; i < tamVet; i++) {
                    vet[i] = tamVet - i;
                }
                v = vet;

                tempoInicial = clock();
                //QuickSort(v, tamVet);
                tempoFinal = clock();

                tempoGasto = (tempoFinal - tempoInicial) / (double) CLOCKS_PER_SEC;
                printf("\t\t Tempo de execucao: %.3f segundos\n\n", tempoGasto);
                __fpurge(stdin);
                fflush(stdin);
                getchar();
            };
                break;

            case '3':
            {
                printf("\n\n\t\t Informe o tamanho do vetor: ");
                scanf("%d", &tamVet);
                int vet[tamVet];

                int j, t;
                srand(time(NULL));
                for (i = 0; i < tamVet; i++)
                    vet[i] = i;
                for (i = 0; i < tamVet; i++) {
                    j = rand() % (tamVet - i) + i;
                    t = vet[j];
                    vet[j] = vet[i];
                    vet[i] = t;
                }
                v = vet;

                tempoInicial = clock();
                //QuickSort(v, tamVet);
                tempoFinal = clock();

                tempoGasto = (tempoFinal - tempoInicial) / (double) CLOCKS_PER_SEC;
                printf("\t\t Tempo de execucao: %.3f segundos\n\n", tempoGasto);
                __fpurge(stdin);
                fflush(stdin);
                getchar();
            };
                break;
            case '4':
            {
                /*printf("\n\n\t\t Complexidade melhor caso: O(n*logn)");
                printf("\n\n\t\t Complexidade pior caso:   O(n^2)");
                printf("\n\n\t\t Complexidade caso medio:  O(n*logn)");*/
                __fpurge(stdin);
                fflush(stdin);
                getchar();
            };
                break;

            default:
            {
                printf("\nOpcao incorreta, tente de 0 a 4\n");
            }
        }
    }    while (opcao != '0');
}
