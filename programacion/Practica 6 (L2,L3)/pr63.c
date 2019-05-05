//Nombre: Ihar Myshkevich
//Login: ihar.myshkevich134

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <errno.h>

struct Mensaje_numerico{
    long Id_Mensaje;
    int numero;
};

void main(){
    // Variables a usar
        key_t clave;
        int idCola,espera,i;
        struct Mensaje_numerico ms;
    // Codigo
        clave = ftok("./ihar.mysh.prac6",1);
        idCola = msgget(clave,0777|IPC_CREAT);
        for(i=11;i<21;i++){
            srand (time(NULL));
            ms.Id_Mensaje = i;
            ms.numero = rand();
            printf("Numero nº %d es %d\n",i-10,ms.numero);
            msgsnd (idCola, (struct msgbuf *)&ms, sizeof(ms)-sizeof(long),IPC_NOWAIT);
            espera = rand() % 10 + 3;
            sleep(espera);
        };
};