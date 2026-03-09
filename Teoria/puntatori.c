#include <stdio.h>
#include <stdlib.h> // Libreria per la gestione della memoria dinamica
#include <string.h> // Libreria per la gestione delle stringhe

int main(){
    /*
        Puntatori in C:

        I puntatori in C, ci aiutao a gestire la memoria in modo efficace.
        Infatti la un putatore è una variabile, che contiene l'indirizzo
        di memoria di un'altra variabile.

        ma come possiamo prendere l'indirizzo di una variabile ?

        tramite l'operatore &, che sta per address of, per esempio:
    */
    int Numero = 10;
    
    printf("Numero: %d\n", Numero);
    printf("L'indirizzio di Numero e': %p\n", &Numero); // %p è il formato per stampare un indirizzo di memoria"

    /* Ora vediamo come possiamo inzializare un puntatore */
    double *puntatoreDouble = NULL; // Puntatore Nullo 
    int *puntatore = &Numero; // il puntatore punta all'indirizzo di Numero
    printf("%p\n", puntatore); // Stampa indizio di memoria del puntatore
    printf("%d\n", *puntatore); // Stampa Numero 

    /* 
        Come possiamo allocare un puntatore dinamicamente? 
        tramite la funzione malloc() e realloc(), vedremo come 
        come questo è possibile, vediamolo subito:
    */

    int *p_Numero = malloc(sizeof(int)); // Allocazione dinamica di un intero
    /*Possiamo vedere questi puntatori come array, quindi*/

    p_Numero[0] = 10; // Assegnazione del valore 10 al primo elemento dell'array puntato da p_Numero
    printf("%d\n", p_Numero[0]); // Stampa il valore del primo

    p_Numero = realloc(p_Numero, 2*sizeof(int)); // Riassegnazione di memoria per un array di 2 interi
    p_Numero[1] = 20; // Assegnazione del valore 
    printf("%d\n", p_Numero[1]); // Stampa il valore del secondo elemento dell'array puntato da p_Numero

    /*Possiamo "liberare" una memoria che è stata allocata con free()*/
    free(p_Numero); // Libera la memoria allocata per p_Numero

}