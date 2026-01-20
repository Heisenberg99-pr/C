/*In C gli elementi di un array sono tutti dello stesso tipo.
Per creare un array con più tipi di elementi, una soluzione versatile, può essere quella di
creare un array di puntatori. Quindi ogni elemento dell'array non è altro
che l'inidirizzo dell'elemento effettivo*/
#include <stdio.h>
#include <stdlib.h>

struct lista{
    void **a; // Array di puntatori generici (void*)
    char *tipo; // specifica il tipo di dato nella lista, 'i' per int; 'd' double
    int n,c; // Numero di elementi nella lista e capacità dell'array
};

typedef struct lista lista; 

lista nuova_lista(); 
lista append(lista,void*,char); // Dovrà prendere un parametro aggiuntivo char, per la specifica del tipo
void mostra_lista(lista);

/* La funzione che ritorna la lista vuota deve definire anche il tipo*/
lista nuova_lista(){
    lista lst = {NULL,NULL,0,0}; 
    return lst; 
}

/* La funzione append, eventualmente ridimensiona anche il campo tipo*/
lista append(lista lst, void *x, char t){
    if ( lst.c == lst.n ){
        lst.c = 2*lst.c+1;
        lst.a = realloc(lst.a, lst.c*sizeof(void*));
        lst.tipo = realloc(lst.tipo, lst.c*sizeof(char));
    }
    lst.a[lst.n] = x;
    lst.tipo[lst.n] = t;
    (lst.n)++;
    return lst;
}

/* La funzione mostra lista dovrà distinguedere come effetuare la stampa
in funzione del tipo, se int %d se double %f. 
L'operazione che permette di ottenere il valore memorizzato all'indirizzo indicato da puntare si chiama dereferenziazione e si esegue tramite [*], 
ad esempio, se la variabile p è un puntatore float, allora [*p] rappresenta il float puntato da p,cioè il valore memorizzato nell'inidrizzo p.
Poiché lst.a[i] è un puntatore, *(lst.a[i]) sarebbe il valore puntato da lst.a[i], tuttavia essendo un puntatore void
il paramentro non può essere dereferenziato direttamente. Per poter accedere al dato occorre prima effetuare una opreazione di casting
tramite seguente sintassi [(nuovo_tipo)valore]*/

void mostra_lista(lista lst){
    printf("["); 
    for(int i = 0; i < lst.n; i++){
        if(lst.tipo[i] == 'i'){
            printf("%d\n", *(int*)(lst.a[i]));
        }
        else if(lst.tipo[i] == 'd'){
            printf("%f\n",*(double*)(lst.a[i])); 
        }
        printf("]"); 
        printf("\n\tc = %d; n = %d\n", lst.c,lst.n); 
    }
}

/*La funzione main crea un piccola lista contenente due double e un int, 
memorizati in tre variablìili. Alla funzione append dobbiamo passare l'inidrizzo di memoria in cui sono memorizzati questi valori, 
cioè l'indirizzo a cui fanno riferimento le variabili stesse. Per ottenere l'idirizzo di una variabile 
si utilizza l'operatore &: se x è una variabile, allora &x è
l'indirizzo di memoria in cui x è memorizzata*/

int main (){
    lista L = nuova_lista(); 
    double pi = 3.1415; 
    double e = 2.71; 
    int k = 60; 
    L = append(L, &pi, 'd');
    L = append(L, &k, 'i');
    L = append(L, &e, 'd');

    mostra_lista(L); 
}