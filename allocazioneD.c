#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *StrCat(char *, char*); 

int main(){
    char str0[] = "programmazione";
    char str1[] = "dei calcolatori";
    char *str2; 

    //strcat(str0,str1); /// PERICOLO!!!
    
    str2 = StrCat(str0,str1);
    printf("%s\n", str2); 

}
/* La funzione [strcat()] è pericolosa, perché richide che l'array su cui
si esegue la concatenazione abbia memoria sufficete, al contrario la funzione 
[StrCat()] gestisce il tutto in maniera dinamica*/

/*StrCat(): Date due stringhe, ritorna una nuova stringa contenente la 
concatenazione delle due*/

char *StrCat(char *s0,char *s1){
    int len_s0 = strlen(s0); /*Metodo che calcola la lunghezza della stringa fino a '/0'*/
    int len_s1 = strlen(s1);  
    char *cat = malloc((len_s0+len_s1+1)*sizeof(char)); //Allocazione in memoria dell'array cat

    strcpy(cat,s0);  // copia s0 all'interno di cat
    strcat(cat,s1); // concatena s1 all'interno di cat
    
    return cat; // ritorna cat 

    // Costo complessivo temporale O(n)
}

/*char cat[len_s0+len_s1+1];
non è corretto perché la funzione ritornerebbe l'indirizzo di una variabile locale, cat, che al termine della funzione viene deallocata. 
La memoria allocata con malloc (e realloc) viene deallocata esplicitamente chiamando una apposita funzione (free),
oppure al termine del programma.

Al posto di strcat(cat, s1) è piu conveniente usare strcpy(cat+len_s0, s1). Il perché alla prossima lezione.*/