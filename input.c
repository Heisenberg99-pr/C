#include <stdio.h>
int main(){
    char testo[100]; 
    float pi; 
    printf("Digita un testo qualsiasi: ");
    scanf("%s",testo); /*Funzione che richiede un input all'utente sintassi [scanf(%[d,s o f],variabile contenitore, se array no &)]*/
    printf("%s\n", testo); 
    printf("Digita le prime tre cifre del pi greco: ");
    scanf("%f", &pi); /*Funzione che richiede un input all'utente sintassi [scanf(%[d,s o f],&variabile contenitore)]*/
    printf("%f\n", pi); 

    int giorno,mese,anno; 
    printf("Inserisci data di nascita [g-m-a]... ");
    int conversioni = scanf("%d-%d-%d", &giorno, &mese, &anno); // Inserimento di 3 input differenti  
    /* In conversioni viene inserito il numero delle variabili lette
    In questo caso se = 3 allora la funzione scanf è andata a buon fine
    altrimenti no*/
    if(conversioni == 3){ 
        printf("Giorno: %d\n",giorno);                   
        printf("Mese: %d\n",mese); 
        printf("Anno: %d\n",anno); 
    }
}