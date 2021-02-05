#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "funciones.h"

void main () {
    char ans; //variable on guardem si vol introduir mes registres

    head(); //crida a la funció per afegir la capçalera

    do{
        data(); //crida a la funció per introduir les dades per teclat

        date(); //crida a la funció per la data i l'hora

        insert(); //crida a la funció per afegir el contingut introduit per teclat al fitxer

        repeat(); //crida a la funció per consultar si vol tornar a afegir un registre nou

        ans = getchar(); //guardem el caracter que ha introduit en la variable
        fflush(stdin);
    } while (ans == 'y');  //si l'usuari introdueix una "y" es torna a repetir, si introdueix "n" finalitza

}
