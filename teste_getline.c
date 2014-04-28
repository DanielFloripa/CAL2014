#include <stdio.h>
#include <stdlib.h>

typedef struct agenda1 {
    int cod;
    char *nome;
    char *end;
    char *fone;
} Agenda;

int main(){
	
	Agenda a;
	
  int bytes_read;
  int nbytes = 30;
  char *my_string;
  
  //printf("tamanho: %d", sizeof(a.nome)/sizeof(char*));

  puts ("Please enter a line of text.");

  /* These 2 lines are the heart of the program. */
  a.nome = (char *) malloc (nbytes + 1);
  getline (&my_string, &nbytes, stdin);


      puts ("You typed:");
      puts (my_string);


  return 0;
}
