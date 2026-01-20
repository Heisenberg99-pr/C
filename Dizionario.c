/*Per l'implementazione del dizionario in c, faremo uso delle liste
concatenate per rappresentare le liste di trabocco dei dizionari

i nodi della lista conterrano nel cambo informazioni le coppie chiave-valore.
Inoltre Assumiamo per semplicità e senza perdita di generalità che le chiavi
siano stringhe ed i valori siano double*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Esempio di def della coppia chiave-valore*/

struct chiave_valore{
    char *chiave; 
    double valore;
};

typedef struct chiave_valore chiave_valore;

struct nodo{
    chiave_valore info; 
    struct nodo *next; 
}; 

typedef struct nodo nodo; 
typedef nodo* lista; 

struct dizionario{
    lista *a; 
    int m; 
};
typedef struct dizionario dizionario; 


/*Prototipi delle funzioni*/
dizionario init_dizionario(int); 
dizionario inserisci_dizionario(dizionario,chiave_valore); 
dizionario cancella_dizionario(dizionario, char*); 
void mostar_dizionario(dizionario); 
void mostra_lista(nodo*); // Mostra la lista a video 
nodo *inserisci_inTesta(nodo*,chiave_valore); // Permette l'inserimento in testa alla lista
nodo *cancella(nodo*,char*); //Cancellazione rispetto alla chiave  
nodo *cerca(nodo*,char*); // Permette la ricerca di una data coppia
void aggiorna(nodo*,char*,double); // Permette l'aggiornamento solo se presente nella lista
nodo *inserisci(nodo*,chiave_valore); // Permette l'inserimento

//Implementazione di una funzione has giocattolo per dizionari con 2 liste

/*Una funzione hash è una funzione che prende un dato di dimensione arbitraria 
(per esempio una stringa o un numero) e lo trasforma in un valore di dimensione 
fissa, chiamato hash.*/
int h(char *k){
    return k[0] % 2; 
}

/*Funzione che ritorna un dizionario vuoto con m liste di trabocco*/
dizionario init_dizionario(int m){
    dizionario d; 
    d.m = m; 
    d.a = malloc(sizeof(lista)*m); 
    for (int i = 0; i < m; i++){
        d.a[i] = NULL; 
    }
    return d; 
}

/*Se in d è presente un elemento e tale che e.chiave
è uguale a elem.chiave, aggiorna e.valore con elem.valore.
Altrimenti aggiunge elem al dizionario*/

dizionario inserisci_dizionario(dizionario d,chiave_valore elem){
    int p = h(elem.chiave); // La lista che deve contenere elem
    d.a[p] = inserisci(d.a[p], elem); // aggiorna o inserisce nella lista
    return d; 
}

/*Se in d è presente un elemento e tale che e.chiave è uguale a k,
lo elimina dal dizionario. ALtrimenti lascia tutto invariato.*/

dizionario cancella_dizionario(dizionario d, char *k){
    int p = h(k); 

    d.a[p] = cancella(d.a[p], k); // verifica incorporata nella funzione cancella

    return d; 
}
/*Stampa tutti gli elementi di d, lista per lista*/
void mostra_dizionario(dizionario d){
    printf("=================================\n");
    for(int i = 0; i < d.m; i++){
        mostra_lista(d.a[i]); 
    }
}
nodo *inserisci(nodo *L, chiave_valore v ){
    nodo *p = cerca(L, v.chiave); 
    if( p != NULL){
        p->info.valore = v.valore; 
    } else{
        L = inserisci_inTesta(L,v);
    }

    return L;
}

void aggiorna(nodo* L,char* k, double v){
    nodo *p = cerca(L,k);
    if(p != NULL){
        p -> info.valore = v; 
    }
} 

nodo *cerca (nodo* L, char *k){
    nodo *p = L; 
    while( p != NULL){
        if(strcmp(p->info.chiave,k) == 0){ //confronta se le stringhe sono uguali
            return p; 
        }
        p = p->next; 
    }
    return NULL; 
}

nodo *inserisci_inTesta(nodo *L, chiave_valore v){
    nodo *p = malloc( sizeof(nodo) ); 
    if(p==NULL){
        return L; 
    }

    p->info = v; 
    p->next = L;
    return p; 
}

nodo *cancella( nodo *L, char *k){
    nodo *t,*p; 
    if(L == NULL){
        return NULL;
    }
    if(strcmp(L->info.chiave,k) == 0){ // Cancella il primo nodo della lista
        t = L;
        L = L->next;
        free(t); 
        return L; 
    }

    if(L ->next == NULL)
        return L; 

    p = L; 
    while( p -> next != NULL && strcmp(p->next->info.chiave, k) != 0){
        p = p->next;
    }
    if( p->next != NULL){ // Il nodo da cancellare esiste
        t = p->next; 
        p->next = p->next->next; 
        free(t); 
    }
    return L; 
}

void mostra_lista(nodo *L){
    nodo *p = L; 

    printf("["); 
    while( p != NULL ){
        printf("(%s,%.2f)", p->info.chiave,p->info.valore);
        p = p->next; 
    }
    printf("]\n"); 
}
int main(){
    dizionario d = init_dizionario(2);

    chiave_valore v0 = {"zero", 0};
    chiave_valore v1 = {"uno", 1};
    chiave_valore v2 = {"due", 2};
    chiave_valore v3 = {"tre", 3};
    chiave_valore v4 = {"quattro", 4};
    chiave_valore vn = {"zero", 0.5};

    d = inserisci_dizionario(d, v0);
    d = inserisci_dizionario(d, v1);
    d = inserisci_dizionario(d, v2);
    d = inserisci_dizionario(d, v3);
    d = inserisci_dizionario(d, v4);
    d = inserisci_dizionario(d, vn);

    mostra_dizionario(d);

    d = cancella_dizionario(d, "due");
    d = cancella_dizionario(d, "nove");
    mostra_dizionario(d);
}