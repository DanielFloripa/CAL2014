/* retirado de 
 * http://olinux.uol.com.br/imagens/programacao/curso_c/45/aula_33/heapsort.c*/

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

void main() {
  int N=10000;       // numero de elementos
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
