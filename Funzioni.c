//Funzione dichiarazione: [tipo (duble,float,int...)] nome_funzione [parametri(array,int,double,float,sting...)]
#include <stdio.h>

double somma_e_distruggi(double v[], int size ){
    double totale = 0;
    for(int i=0; i < size; i++){
        totale += v[i];
        v[i] = 0;
    }
    return totale;
}

int main(){
    double a[] = {0,1,2,3,4,5,6,7,8,10};
    int n = sizeof(a)/sizeof(double);
    printf("size in main = %d\n", n);
    printf("%f\n", somma_e_distruggi(a, n));
    printf("%f\n", somma_e_distruggi(a, n));

    return 0;
}