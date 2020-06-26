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
    printf("Pr43 y mi pid es: %d.Mensaje 3\n",getpid());
}

void mensajeAlarma(){
    printf("Pr43 con pid %d.Ha saltado el alarm.Mensaje 4\n",getpid());
}

void main(){
    // Preparamos para recibir la señal
        int pid = getppid();
        struct sigaction s1,s2;
        s1.sa_flags=0;
        s1.sa_handler=mensaje;
        sigaction(10,&s1,NULL);
        signal(SIGALRM,mensajeAlarma);
    // Codigo
    pause();
    alarm(10);
    pause();
    kill(pid,10);
    pause();
};