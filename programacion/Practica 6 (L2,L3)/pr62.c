//Nombre: Ihar Myshkevich
//Login: ihar.myshkevich134

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <errno.h>

struct Mensaje_caracter{
    long Id_Mensaje;
    char caracter;
};

void main(){
    // Variables a usar
        key_t clave;
        int idCola,espera,i;
        struct Mensaje_caracter ms;
    // Codigo
        clave = ftok("./ihar.mysh.prac6",1);
        idCola = msgget(clave,0777|IPC_CREAT);
        for(i=1;i<11;i++){
            srand (time(NULL));
            ms.Id_Mensaje = i;
            ms.caracter = 'a' + rand() % (('z' - 'a') + 1);
            printf("Caracter nº %d es %c\n",i,ms.caracter);
            msgsnd (idCola, (struct msgbuf *)&ms, sizeof(ms)-sizeof(long),IPC_NOWAIT);
            espera = rand() % 8 + 8;
            sleep(espera);
        };
};