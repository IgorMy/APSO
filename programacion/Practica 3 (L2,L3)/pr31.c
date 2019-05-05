//Nombre: Ihar Myshkevich
//Login: ihar.myshkevich134

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
  printf("Soy pr31 y mi pid es: %d\n",getpid());
  int pid = fork();
  if(pid == 0){
    sleep(1);
    execl("pr32","pr32",NULL);
  }else{
    pid = fork();
    if(pid == 0){
      printf("Soy la copia de pr31 y mi pid es: %d\n",getpid());
      sleep(5);
      printf("Fin de la copia de pr31\n");
    }else{
    sleep(6);
    printf("Fin pr31\n");
    };
  };
};