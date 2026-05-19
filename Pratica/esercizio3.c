#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *intersezione(char str1[],char str2[]); 

char *intersezione(char str1[], char str2[]){
    int k = 0; 
    int len_str1 = strlen(str1); 
    int len_str2 = strlen(str2);
    int min_len = (len_str1 < len_str2) ? len_str1 : len_str2; // Condizione on-line -> Calcola il minimo tra le lunghezze 
    char *result = malloc(min_len*sizeof(char)); 
    for(int i = 0; i<len_str1;i++){
        for(int j = 0; j < len_str2; j++){
           if(str1[i] == str2[j]){
             result[k++] = str1[i]; 
             break; 
           }
        }
    }
    result[k] = '\0'; 
    return result; 
}

int main(){
    char str1[] = "mamma"; 
    char str2[] = "mare";
    printf("Stringa 1: %s\n", str1);  
    printf("Stringa 2: %s\n", str2);  
    char *result = intersezione(str1,str2);
    printf("Intersezione: %s\n", result);
}