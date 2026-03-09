#include "dizionario.h" /*Struttura definita in precedenza*/

/* Nel progamma sono stati introdotti: 
il campo n: contine il numero di elementi nel dizionario
il campo h contente il puntatore alla funzione hash
*/
int hash_djb2(char *key, int size){
   /*dichiarazone che evita il problema di overflaw
   h è un variabile che accumula l'hash*/
    unsigned int h = 5381;

    while(*key){ /*equivale a while (*key != '\0')*/
        h = ((h << 5) + h) + *key; 
       /*
       h << 5: operazione bit a bit, shift a sinistra di 5 bit -> h *32 
       (h << 5)+h:  h * 33 
       + *key Aggiunge il valore ascii del carattere
       */ 
        key++; /*Passa al carattere successivo*/
    }

    return h % size; /*Ritorna l'indice*/

   
}

 dizionario init_dizionario(int m){
        dizionario d; 
        d.m = m; 
        d.n = 0; 
        d.h = hash_djb2;
        d.a = malloc(sizeof(lista)*m); 
        for(int i = 0; i < m; i++){
            d.a[i] = NULL; 
        }
        return d; 
}

dizionario inserisci_dizionario(dizionario d, chiave_valore elem){
    int p = d.h(elem.chiave,d.m);
    nodo *u = cerca(d.a[p], elem.chiave); 

    if(u == NULL){
        d.a[p] = inserisci_inTesta(d.a[p],elem);
        d.n++;
        if(d.n> 10*d.m){
            /*
            TODO: 
            gestire il ridimensionamento dell'array delle liste
            di trabocco
            */
        }else{
            u->info.vaolre = elem.valore; 
        }

    }

    return d; 
}

dizionario cancella_dizionario(dizionario d,char *k){
    int p = d.h(k, d.m); 

    d.a[p] = cancella(d.a[p], k); 

    return d; 
}

void mostra_dizionario(dizionario d){
    printf("=================================\n");
    for(int i = 0; i < d.m; i++){
        printf("* %3d - ",i); 
        mostra_lista(d.a[i]); 
    }
    printf("Dimensione Dizionario: %d\n", d.n); 
}

/*Ritorna 1 se k è una chiave di d, 0 altrimenti*/
int in_dizionario(){
    int p = (d.h(k,d.m));

    if(cerca(d.a[p], k) == NULL)
        return 0;
    return 1; 
}

double ottieni_valore_dizionario(dizionario d, char *k){
    int p = d.h(k,d.m); 

    nodo *u = cerca(d.a[p], k); 

    return u->info.valore; 
}

int main() {
    /* Inizializza il dizionario con una capacità iniziale di 128 elementi */
    dizionario d = init_dizionario(128);

    /* Buffer utilizzato da getline per leggere le righe */
    char *word = NULL;
    unsigned long len = 0;
    int nread;

    char *temp;

    /*
     * Legge dallo standard input (tastiera) una riga alla volta.
     * Ogni riga rappresenta una chiave del dizionario.
     *
     * La funzione getline alloca dinamicamente (o rialloca)
     * il buffer 'word' e vi memorizza la riga letta.
     * Il valore di ritorno è il numero di caratteri letti,
     * oppure -1 in caso di EOF.
     */
    while ((nread = getline(&word, &len, stdin)) != -1) {

        /* Rimuove il carattere di newline finale, se presente */
        if (nread > 0 && word[nread - 1] == '\n')
            word[nread - 1] = '\0';

        /* Recupera il numero di occorrenze già presenti
        (se esiste la chiave) */
        int occorrenze = 0;
        if (in_dizionario(d, word) == 1) {
            occorrenze = ottieni_valore_dizionario(d, word);
        }

        /*
         * Crea una copia della stringa 'word'.
         * Questo è necessario perché la funzione inserisci_dizionario
         * salva direttamente il puntatore alla stringa nel nodo,
         * e 'word' viene riutilizzato ad ogni chiamata di getline.
         */
        temp = malloc(strlen(word) + 1);
        strcpy(temp, word);

        /* Inserisce (o aggiorna) la coppia chiave-valore nel dizionario */
        chiave_valore v = { temp, occorrenze + 1 };
        d = inserisci_dizionario(d, v);
    }

    /* Stampa il contenuto finale del dizionario */
    mostra_dizionario(d);
}
/*Comando di esecuzione essendo stato usato un file esistente si fa 
gcc nomefile.c (corrisponde al file.h) nomefileSeguente.c*/
