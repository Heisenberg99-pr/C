#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *StrCat(char *,char*); 

int main(){
    char str0[] = "programmazione"; 
    char str1[] = "dei calcolatori";
    char *str2; 

    str2 = StrCat(str0,str1);

    printf("%s\n", str2);
    free(str2);


    printf("%s\n", str0+1); // Indirizzo del byte successivo

    char str3[] = "012"; 
    strcpy(str0+1,str3); //copia/sovrascrive a partire dal secondo byte di str0
    printf("%s\n", str0); 

    printf("%c\n", *(str1+5)); // equivale a print("%c\n", str1[5])
    
    /*Se p è un puntatore ad un array, p + 2 è la posizione del terzo elemento puntato da p.
    L'indirizzo effettivo dipende dalla dichiarazione di p, ovvero dal tipo dell'elemento puntato da p.*/
    int a[10] = {3,1,2};
    printf("%d\n", *(a+2)); 

    for(int i = 0; i < 10; i++){
        printf("%d\n", *(a+i)); 
    }
}

char *StrCat(char *s0,char *s1){
    int lens0 = strlen(s0); 
    int lens1 = strlen(s1); 
    char *cat = malloc((lens0+lens1+1)*sizeof(char));


    strcpy(cat,s0); 
    strcpy(cat+lens0, s1); // // cat+len_s0 è l'indirizzo dell'elemento len_s0-esimo di cat
    return cat; 
}

