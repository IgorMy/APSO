//Nombre: Ihar Myshkevich
//Login: ihar.myshkevich134

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main(){
    // Declaramos las variables a usar
        int pid;
    // Codigo
        read(2,&pid,sizeof(pid));
        printf("pr53 con pid %i. Mensaje 3\n",getpid());
        sleep(1);
        kill(pid,12);
};