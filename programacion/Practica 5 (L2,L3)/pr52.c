//Nombre: Ihar Myshkevich
//Login: ihar.myshkevich134


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void mensaje(){
    printf("pr52 con pid %d. Mensaje 2\n",getpid());
}

void main(){
    // Declaramos las variables a usar
        int pid;
        signal(12,mensaje);
    // Código
        pause();
        pid = fork();
        if(pid == 0){
            execl("pr54","pr54",NULL);
        };
        write(2,&pid,sizeof(pid));
        wait();
}