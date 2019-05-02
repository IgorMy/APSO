#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// Recibe la señal 10 y envia la 12

void vacio(){};

void main(){
    // Variables a usar
        signal(10,vacio);
        int pid,fifo=open("f1",O_RDWR);
    // Codigo
        pause();
        read(fifo,&pid,sizeof(pid));
        printf("Tercer Mensaje\n");
        sleep(3);
        printf("Cuarto Mensaje\n");
        kill(pid,12);
        close(fifo);
};
