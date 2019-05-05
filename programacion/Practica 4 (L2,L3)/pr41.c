//Nombre: Ihar Myshkevich
//Login: ihar.myshkevich134

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>

int pid1,pid2;
void vacio(){};
void mensaje5(){
    printf("Pr41 y mi pid es: %d.Mensaje 5\n",getpid());
}

void main(){
    // Preparamos el codigo para las señales
        int pid1,pid2;
        signal(12,vacio);
        signal(10,mensaje5);
    // codigo
    pid1 = fork();
    if(pid1 == 0){
        execl("pr42","pr42",NULL);
    }else{
        pid2 = fork();
        if(pid2 == 0){
            execl("pr43","pr43",NULL);
        };
    };
    sleep(1);
    printf("Soy pr41 y mi pid es: %d.Mensaje 1\n",getpid());
    kill(pid1,10);
    pause();
    kill(pid2,10);
    pause();
    kill(pid1,9);
    kill(pid2,9);
}