#include <stdio.h>
#include <stdlib.h>

int *pos_dei_minori(int *a,int n, int k, int *m);

int *pos_dei_minori(int *a,int n,int k, int *m){
    int count = 0; 
    int pos = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < k){
            count++; 
        }
    }
    *m = count; 
    int *res = malloc(count*sizeof(int)); 
    for(int i = 0; i < n; i++){
        if(a[i] < k){
            res[pos++] = i; 
        }
    }
    return res; 
}

int main(){
    int a[] = {1,2,4,5,3}; 
    int n = sizeof(a)/sizeof(int); 
    int m; 
    int *b = pos_dei_minori(a,n,4,&m); 
    for(int i = 0; i < m; i++){
        printf("%d\n", b[i]); 
    }
}

/*
Complessità temporale della funzione: O(n) + O(n) = O(n), in quanto è necessario sfuttare
per calcolare il numero di interi all'interno di a strettamente minori di k e il necessario
scandire di a per trovare le singole posizioni dei numeri strettamente minori di k
Complessità spaziale della funzione: O(n), in quanto stiamo utilizando delle strutture dati di grandezza dipendente
dal numero di elementi presenti in a che sono strettamente minori di k
*/