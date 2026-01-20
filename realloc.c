#include <stdio.h>
#include <stdlib.h>

int main(){
    double *a = NULL; // Creazione di un puntatore nullo
    int i, n = 3; 
    
    a = malloc(3*sizeof(double));

    if( a == NULL ){
        return 0;
    } // Termina il programma se la funzione malloc() non ha avuto successo

    a[0] = 3.1415;
    a[1] = 2*3.1415;
    a[2] = 3*3.1415;

    for(i = 0; i < n; i++){
        printf("%f\n", a[i]);
    }

    printf("==================================\n");

    n++;
    a = realloc(a,n*sizeof(double)); // Complessità temporale O(n), nel caso peggiore

    if (a == NULL){
        return 0;
    }

    a[3] = 4*3.1415;

    for(i = 0; i < n; i++){
        printf("%f\n", a[i]);
    }

    free(a);
}