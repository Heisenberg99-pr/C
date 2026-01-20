/*Una lista concatenata è una struttura lineare
formata da nodi. Ogni nodo contiene l'informazione e
un riferimento per il nodo successivo. 

Il primo nodo di una lista è detto testa e permette
di accedere a tutti gli altri nodi seguendo i riferimenti.

L'ultimo nodo ha un riferimento nullo, indica il fine lista

Questo tipo di struttura permette l'aggiunta,crecare
e rimuovere elemnti scorrendo i nodi uno dopo l'altro, senza
richiedere che la memoria sia contigua*/

#include <stdio.h>
#include <stdlib.h>

struct nodo{
    double info; // Informazione del nodo 
    struct nodo *next; // Puntatore al nodo successivo
}; 

typedef struct nodo nodo;
typedef nodo* lista; 

void mostra_lista(nodo*);
nodo *inserisci_inTesta(nodo*,double);
nodo *cancella(nodo*,double);  

int main(){
    nodo *L = NULL; // lista concatenata vuota; oppure lista L = NULL

    for(int i=0; i < 10; i++){
        L = inserisci_inTesta(L, i);
    }

    mostra_lista(L);

    L = cancella(L, 4); // cancellazione al centro
    mostra_lista(L);
    L = cancella(L, 9); // cancellazione in testa
    mostra_lista(L);
    L = cancella(L, 0); // cancellazione in coda
    mostra_lista(L);
    L = cancella(L, 10); // tentativo di cancellazione
    mostra_lista(L);
}
/*stampa il contenuto della lista*/
void mostra_lista(nodo *L){
    nodo *p = L; 
    
    printf("["); 
    while(p != NULL ){
        printf("%f", p->info); 
        p = p -> next; 
    }

    printf("]\n"); 
}
/*Inserimento di un nuovo nodo con informazioni v in testa alla lista*/

nodo *inserisci_inTesta(nodo *L,double v){

    nodo *p = malloc (sizeof(nodo)); 
    if(p==NULL){
        return L; //Malloc non è andata a buon fine
    }
    p->info = v; 
    p->next = L; 
    return p; 
}

/*Cancella dalla lista il primo nodo contenente l'informazione v

si distinguono i casi: 

La lista è vuota: viene restituito NULL

Il nodo da cancellare è il primo della lista: viene ritornato il puntatore al nodo successivo a L

La lista contiene solo un nodo: la lista non viene modificata

La lista non contiene il valore v: la lista non viene modificata

La lista contiene v in una posizione che non è la prima: viene posizionato un puntatore p al nodo 
precedente in modo da modificare il campo next del nodo puntato da p, bypassando quello contenente v.

Nei casi in cui ci sia effettivamente una cancellazione, la memoria utilizzata dal nodo eliminato 
viene deallocata con la funzione free.*/

nodo *cancella(nodo *L,double v){
    nodo *t, *p; 
    if (L == NULL){
        return NULL; 
    }
    if(L -> info == v){
        //cancella il primo nodo della lista
        t = L; 
        L = L->next; 
        free(t); 
        return L; 
    }

    if(L -> next == NULL) // non ci sono altri nodi oltre al primo
    return L; 

    p = L; 
    // ricerca del nodo precedente a quello contenente v, perché in una lista singola non si può tornare indietro

    while( p->next != NULL && p -> next->info != v){
       p = p->next;  
    }

    if(p -> next != NULL){ // Il nodo da cancellare non esiste 
        t = p->next; 
        p->next = p->next->next; 
        free(t);
    }
    return L; 
}