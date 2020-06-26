//Nombre: Ihar Myshkevich
//Login: ihar.myshkevich134

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void mensaje(){
    printf("pr54 con pid %i. Mensaje 4\n",getpid());
}

void main(){
    // Declaramos las variables a usar
        signal(12,mensaje);
        int fifo = open("f1",O_RDWR),pid;
    // Codigo
        pause();
        read(fifo,&pid, sizeof(pid));
        kill(pid,12);
        close(fifo);
}