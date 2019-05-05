//Nombre: Ihar Myshkevich
//Login: ihar.myshkevich134

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <errno.h>
#include <unistd.h>

struct Mensaje_numerico{
    long Id_Mensaje;
    int numero;
};

struct Mensaje_caracter{
    long Id_Mensaje;
    char caracter;
};

void main(){
    // Variables a usar
        key_t clave;
        int pid1,pid2,idCola;
        struct Mensaje_numerico ms_n;
        struct Mensaje_caracter ms_c;
    // Codigo
        clave = ftok("./ihar.mysh.prac6",1);
        idCola = msgget(clave,0777|IPC_CREAT);
        pid1 = fork();
        if(pid1==0){
            execl("pr62","pr62",NULL);
        };
        pid2 = fork();
        if(pid2==0){
            execl("pr63","pr63",NULL);
        };
        msgrcv (idCola, (struct msgbuf *)&ms_c, sizeof(ms_c)-sizeof(long), 1, 0);
        printf(" -- El primer caracter de Pr62 es: %c\n",ms_c.caracter);

        msgrcv (idCola, (struct msgbuf *)&ms_n, sizeof(ms_n)-sizeof(long), 11, 0);
        printf(" -- El primer numero de Pr63 es: %d\n",ms_n.numero);

        msgrcv (idCola, (struct msgbuf *)&ms_c, sizeof(ms_c)-sizeof(long), 2, 0);
        printf(" -- El segundo caracter de Pr62 es: %c\n",ms_c.caracter);

        msgrcv (idCola, (struct msgbuf *)&ms_n, sizeof(ms_n)-sizeof(long), 12, 0);
        printf(" -- El segundo numero de Pr63 es: %d\n",ms_n.numero);
        wait();
        wait();
        msgctl (idCola, IPC_RMID, (struct msqid_ds *)NULL);
};