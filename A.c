#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main(){
    // Variables a usar
        int pid1,pid2,tuberia[2];
        pipe(tuberia);
        mkfifo("f1",0777);
    // Codigo
        pid1=fork();
        if(pid1==0){
            close(2);
            dup(tuberia[0]);
            execl("B","B",NULL);
        };
        pid2=fork();
        if(pid2==0){
            execl("C","C",NULL);
        };
        sleep(1); // Necesario para que los 3 se coloquen en su punto de partida,sino no funciona
        printf("Primer Mensaje\n");
        write(tuberia[1],&pid2,sizeof(pid2));
        wait();
        wait();
        printf("Último Mensaje\n");
        unlink("f1");
}; 
