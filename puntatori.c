#include <stdio.h>
#include <stdlib.h> 
/* Libreria che permette la gestione della memoria tramite le seguenti funzioni:
malloc() -> Alloca size byte e restituisce un puntatore alla memoria allocata
calloc() -> Alloca in memoria per n elementi inizializando tutto a 0
realloc() -> Ridimensiona un blocco già creato, può spostarlo in un altra locazione
free() -> Libera la memoria allocata, fare solo se non serve più il puntatore

Peremette la conversione di strighe tramite:
atoi() -> Converte la stringa in intero, Non gestisce gli errori
atof() -> Converte una stringa in double
strtol() -> Converte la stringa in long, Gestisce gli errori
strtod() -> Converte la stringa in double, Gestisce gli errori

Permette il controllo del programma tramite:
exit() -> Termina il programma es. [exit(0)] se 0 = successo se altro = errore
abort() -> Termina il programma immediatamente, Usata per errori gravi
atexit() -> Registra una funzioe da chiamare alla fine del programma

Utilità varie sono invece: 
rand() -> estrae un numero pseudo-casuale
srand() -> imposta il seme del generatore casuale
qsort() -> qsort(void *base, size_t n, size_t size, int (*cmp)(const void*, const void*)) Oridina un array generico (cioè di qualsiasi tipo)
bserch() -> bsearch(const void *key, const void *base, size_t n, size_t size, int (*cmp)(const void*, const void*)) Ricerca binaria di un array ordinato 
*/

int main(){
    double *a = NULL; // Puntatore nullo, come fosse -1

    a = malloc(sizeof(double)); // Creazione di un puntatore alla locazione di memoria con size double
    a[0] = 3.14; // Si può vedere come un vettore di un elemento
    printf("%f\n", a[0]);
}