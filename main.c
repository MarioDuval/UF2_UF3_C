#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "funciones.h"

void main () {
    char ans;

    head();

    do{
        data();

        date();

        insert();

        repeat();

        ans = getchar();
        fflush(stdin);
    } while (ans == 'y');
}
