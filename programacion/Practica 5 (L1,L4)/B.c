#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// Recibe la señal 12 y envia la 10

void vacio(){};

void main(){
    // Variables a usar
        signal(12,vacio);
        int pidH,fifo = open("f1",O_RDWR),pid=getpid();
    // Código
        write(fifo,&pid,sizeof(pid));
        read(2,&pidH,sizeof(pidH));
        printf("Segundo Mensaje\n");
        kill(pidH,10);
        pause();
        printf("Quinto Mensaje\n");
        close(fifo);
}
