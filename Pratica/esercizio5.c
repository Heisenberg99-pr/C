#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *prefix(char *a,int n);

char *prefix(char *a, int n){
    int len_a = strlen(a); 

    if(n >= len_a){
        char *result = malloc((len_a+1)*sizeof(char));

        for (int i = 0; i < len_a; i++){
            result[i] = a[i]; 
        }
        result[len_a] = '\0'; 
        return result;
    }else{

        char *result = malloc((n+1)*sizeof(char));

        for(int i = 0; i < n; i++){
            result[i] = a[i]; 
        }
        result[n] = '\0'; 
        return result; 
    }
}

int main(){
    char a[] = "mare";
    int n = 6;

    char *result = prefix(a,n); 
    printf("%s\n", result);
}

// Costo della funzione prefix ==> Temporale = O(len_a) Spaziale = O(min(n,len_a)) 