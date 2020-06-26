//Nombre: Ihar Myshkevich
//Login: ihar.myshkevich134

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int numero = 0;

void* aleatorio(){
  while(numero != -1){
    srand(time(NULL));
    printf("%d\n",numero+rand());
    sleep(1);
  };
};

void* pedirNumero(){
  while(numero != -1){
    scanf("%d",&numero);
  };
};

main(){
 pthread_t h1,h2;
 pthread_create(&h1,NULL,(void *) &aleatorio,NULL);
 pthread_create(&h2,NULL,(void *) &pedirNumero,NULL);
 pthread_join(h1,NULL);
 pthread_join(h2,NULL);
 while(numero != -1){
 };
  printf("El programa termino con exito\n");
};
