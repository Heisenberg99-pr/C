#include <stdio.h> // Libreria standard di c 
#include  <string.h> // Libreria stringa 

// prototipi 


int len(char a[]); // Dichiarazione di una funzione 
void upper_expensive(char a[]); // Dichiarazione di una funzione
void upper(char a[]); // Dichiarazione di una funzione

int len(char a[]){
    int i;
    for(i = 0; a[i] != '\0'; i++){
        //noops
    }
    return i; 
    /*
    Complessità temporale: O(n) dove n è la
    lunghezza della stringa
    */

}
void upper_expensive(char a[]){
    int i; 

    for( i = 0; i < len(a); i++){
        if( a[i] >= 'a' && a[i] <= 'z') // marcatori di concatenzione && and; || or; ! not
        a[i] = 'A' + (a[i] - 'a');
        /*
        Complessità temporale: O(n^2) perché len() ha costo lineare e viene eseguita n volte.
        */
    }
}

void upper(char a[]){
    int i,n = len(a);
    for(i = 0; i < n; i++){
        if( a[i] >= 'a' && a[i]<='z')
        a[i] = 'A' + (a[i] - 'a');
    }
    /* costo temporale O(n)*/
}

int main(){
    char a[] = "stringa c";
    printf("%s\n", a);

    int n = sizeof(a)/sizeof(char);
    printf("%d\n", n);

    a[4] = '\0'; 
    /* Inserimento di un carattere di tipo (NULL), il quale serve ad inidicare il carattere di fine stringa
    ['/0'] esistono diversi metodi per iniserire il carattere di fine stringa che sono: 
   - a[strlen(a)] = '\0'; (inutile se non già presente un carattere che segna il fine stringa)
   - a[N] = '\0'; Metodo manuale usato nel segunete esercizio 
   - int i = 0;
    while (condizione) {
        a[i++] = qualche_carattere;
    }
    a[i] = '\0'; Metodo automatico */
    n = sizeof(a)/sizeof(char);
    printf("%s, %d, %d\n", a, n, len(a));

    upper(a);
    printf("%s,%d,%d\n", a ,n, len(a));

    upper(a);
    printf("%s\n", a);

    printf("%ld\n", strlen(a)); //Funzione della libreria string


}