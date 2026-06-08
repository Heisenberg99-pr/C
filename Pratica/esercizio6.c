/*
Problema: stringa a e b, b sottostringa di a, rimuovere da a la stringa b

es: a[] = "programmazioni dei calcolatori" b[] = "azione"

la funzione restituisce 0 se b non è sottostringa di a, 1 altrimenti

la memoria supplementare deve essere costante

risultato = "programm dei calcolatori"

protoipo della funzione: int rimuovi_stringa(char *a, char *b);

usare solo la funzione strlen(), dalla libreria string 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipo

int rimuovi_stringa(char *a, char *b);

//Funzione

int rimuovi_stringa(char *a, char *b){
    int len_a = strlen(a); 
    int len_b = strlen(b);
    int found = 0; 

    for(int i = 0; i <= len_a - len_b; i++){
        int j; 
        for(j = 0; j < len_b; j++){
            if(a[i+j] != b[j]){
                break; 
            }
        }
        if(j == len_b){
            found = 1; 
            for(int k = i; k <= len_a - len_b; k++){
                a[k] = a[k + len_b]; 
            }
            len_a -= len_b; 
            a[len_a] = '\0'; 
            i--;
        }
    }
    return found;
}

int main(){
    char a[]="programmazione dei calcolatori";
    char b[]="azione";
    printf("Stringa iniziale: %s\n",a);
    int found = rimuovi_stringa(a,b);
    if(found == 1){
        printf("La stringa '%s' e' stata rimossa.\n",b);
        printf("Nuova stringa 'a': %s\n",a);
    } else {
        printf("La stringa '%s' non e' sottostringa di '%s'.\n",b,a);
    }
    return 0;
}