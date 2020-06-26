//Nombre: Ihar Myshkevich
//Login: ihar.myshkevich134

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>

void mensaje(){
    printf("Pr42 y mi pid es: %d.Mensaje 2\n",getpid());
}

void main(){
    // Preparamos para recibir la señal
        int pid = getppid();
        struct sigaction s1,s2;
        s1.sa_flags=0;
        s1.sa_handler=mensaje;
        sigaction(10,&s1,NULL);
    // Codigo
    pause();
    kill(pid,12);
    pause();
};