//Nombre: Ihar Myshkevich
//Login: ihar.myshkevich134

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void mensaje(){
    printf("pr51 con pid %d. Mensaje 5\n",getpid());
};

void main(){
    // Declaramos las variables a usar
        int pidHijo1,pidHijo2,tub1[2],fifo,pid=getpid();
        mkfifo("f1",0666);
        pipe(tub1);
        signal(12,mensaje);
    // Código
        // Trabajamos con la fifo
            fifo = open("f1",O_RDWR);
            write(fifo,&pid,sizeof(pid));
        // Creamos las copias para ejecutar a los hijos
            pidHijo1=fork();
            if(pidHijo1==0){
                close(2);
                dup(tub1[1]);
                execl("pr52","pr52",NULL);
            };
            pidHijo2=fork();
            if(pidHijo2==0){
                close(2);
                dup(tub1[0]);
                execl("pr53","pr53",NULL);
            };
        // Ordenes de pr51
            printf("pr51 con pid %d. Mensaje 1\n",pid);
            sleep(1);
            kill(pidHijo1,12);
            pause();
            wait();
            wait();
            close(fifo);
            unlink("f1");
};