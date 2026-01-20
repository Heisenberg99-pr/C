#include <stdio.h>
#include <stdlib.h>

struct lista{
    double *a; // La sequenza è memorizata in questo array
    int n,c; // Numero di elementi nella lista e capacità dell'array
};
typedef struct lista lista;

lista nuova_lista();
lista append(lista,double);
lista rm_last(lista); 
void mostra_lista(lista);


int main(){
    lista L = nuova_lista(); 
    for( int i = 0; i < 10; i++){
        L = append(L,i*3.1415);
        mostra_lista(L);
    }
}
 /*Creazione di una nuova lista*/
lista nuova_lista(){
    lista lst = {NULL, 0, 0};
    return lst;
}
/*Aggiunta di un nuovo elemento nella lista e ritorna la lista modificata*/
lista append(lista lst, double x){
    if(lst.c == lst.n){ //Nel caso  la lista fosse nella sua capienza massima
        lst.c = 2*lst.c+1;
        lst.a = realloc(lst.a, lst.c*sizeof(double)); // Costo O(n)
    }

    lst.a[lst.n] = x; // Aggiunge un nuovo elemento nella lista nella posizione n
    lst.n++; // Incrementa il l'inidice n
    return lst; 
}

/*Stampa le informazioni sulla lista e i suoi elementi*/
void mostra_lista(lista lst){
    printf("[");

    for(int i = 0; i < lst.n; i++){ // Scorre tutti gli elementi della lista
        printf("%f\n", lst.a[i]); 
    }

    printf("]");
    printf("\n\tc = %d; n = %d\n", lst.c,lst.n);
}

/*Eliminare l'ultimo elemento*/
lista rem_last(lista lst){
    if ( lst.n <= lst.c/4){// dimezza se lo spazio usato e minore di 1/4 dello spazio totale cosi da non sprecare memoria
        lst.c = lst.c/2+1; 
        lst.a = realloc(lst.a,lst.c*sizeof(double));
    }
    lst.n--;
    return lst; 
}