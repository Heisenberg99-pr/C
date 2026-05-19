#include <stdio.h> // Fondamentale 
#include <string.h>
#include <stdlib.h> // Fondamentale

void reverse(char *);
void *reverse_semplificato(char *); 

void reverse(char *str){ 
    int n = strlen(str);  // n contiene la lungezza della stringa
    for(int i = 0; i < n/2; i++){ // Per ogni elemento fino a n/2 
        char temp = str[i]; // Salva il primo elemento
        // sostituisce il carattere 
        str[i] = str[n-i-1]; 
        str[n-i-1] = temp; 
    }
}

void *reverse_semplificato(char *str){ // *Nome_funzione ritorna un punattore
    int n = strlen(str);
    char *reversed = malloc((n+1) * sizeof(char)); //+1 = carattere di terminazione [\0]

    for (int i = 0; i < n; i++){
        reversed[i] = str[n-i-1]; 
    }

    return reversed; 
}


int main(){
    char str[] = "mare"; 
    reverse(str);
    printf("La striinga invertita e': %s\n", str);
    printf("La stringa invertita e': %s\n", str);
    return 0;
}