#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "funciones.h"


struct date{
    int day;
    int month;
    int year;           //estructura de la data, el mes, l'any, hora, minuts i segons, per introduir al fitxer
    int hour;
    int minutes;
    int seconds;
};

struct registry{
char name[40];
char address[40];       //estructura per el registre de dades
long phoneNumber;
struct date stDate;
};
struct registry reg;

FILE *stream;
void head(){
        stream = fopen("C:/Users/mario/ClionProjects/UF2_UF3-C/registres.txt", "a"); //per obrir el fitxer i afegir contingut
        char header[] = { "Nom, Adreça, Telèfon, Data, Hora\n" };  //la capçalera
        if (access(stream, F_OK)==-1)  {
            fputs(header, stream);          //condició de si no existeix el fitxer escrigui la capçalera
        }
}

void data(){
    printf("Nom: \n");
    fflush(stdout);
    gets(reg.name);
    printf("Adreça: \n");
    fflush(stdout);                 //funció de introducció de les dades per teclats
    gets(reg.address);
    printf("Telèfon: \n");
    fflush(stdout);
    scanf("%ld", &reg.phoneNumber);
    fflush(stdin);
}

void date() {
    time_t segundos;
    time(&segundos);
    struct tm *tp;
    tp = localtime(&segundos);
    reg.stDate.day = tp->tm_mday;
    reg.stDate.month = tp->tm_mon + 1;          //funció per la data i l'hora
    reg.stDate.year = tp->tm_year + 1900;
    reg.stDate.hour = tp->tm_hour;
    reg.stDate.minutes = tp->tm_min;
    reg.stDate.seconds = tp->tm_sec;
}

void insert(){  //funció per afegir el contingut introduit per teclat al fitxer
    fprintf(stream, "%s, %s, %ld, %d/%d/%d %d:%d:%d \n", reg.name, reg.address, reg.phoneNumber, reg.stDate.day, reg.stDate.month, reg.stDate.year, reg.stDate.hour, reg.stDate.minutes, reg.stDate.seconds);
}


void repeat(){      //funció per consultar si vol tornar a afegir un registre nou
    printf("Vols afegir un altre registre? (y/n): \n");
    fflush(stdout);
}