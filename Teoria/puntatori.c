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
        (& non può essere usato su costanti,espressioni o variabili di classe register )
    */
    int Numero = 10;
    
    printf("Numero: %d\n", Numero);
    printf("L'indirizzio di Numero e': %p\n", &Numero); // %p è il formato per stampare un indirizzo di memoria"

    /*
    Operatori
        [&]: Address of - restituisce l'indirizzo di una variabile
        [*]: Dereference - restituisce il valore alla quale un puntatore punta
    ! Gli operatori & e * hanno diritto di precedenza sugli operatori aritmetici
    */
 
    /*Esempio di utilizzo dei puntatori*/
    int x = 1, y = 2;
    int z[10];
    int *pi; // Dichiarazione puntatore a intero (specificato da int)
    pi = &x; // pi punta ad x
    y = *pi; // y prende il valore di x (y = 1) puntato da pi
    pi = z[0]; // pi ora punta al primo elemento di z

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

    /* Puntatori e funzioni */
    void swap(int *x,int *y ); //(Prototipo) Passaggio degli indirizzi di a e b alla funzione swap

    void swap(int *x, int*y){
        int temp = *x;
        *x = *y; 
        *y = temp; 
    }

    int x = 5, Y = 2;  
    if(x > y ){
        swap(&x,&y); // Se x è maggiore di y, scambiamo i loro valori
    }


}