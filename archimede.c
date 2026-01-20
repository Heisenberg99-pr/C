#include <stdio.h>
#include <math.h> /* libreria matematica */

double archimede(int); // Dichiarazione funzione di archimende

int main(){
    double pi = archimede(12);
    printf("%f\n", pi);  
}

// Scrittura del metodo
double archimede(int iter_max){
    // Dichiarazione di variabili
    double L_i = sqrt(2), L_c = 2; // anziche float L_i = sqrt(2) [differenza double ha doppia precisione], L_c = 2
    int n = 4; //Dichiarazione + Inizializazione 
    double p_i, p_c; // Dichiarazione
    for(int c = 0; c < iter_max; c++){
        p_i = n*L_i/2;
        p_c = n*L_c/2; 
        printf("n = %4d; p_i = %.10f; p_c = %.10f\n", n, p_i, p_c);
        L_i = sqrt((2-sqrt(4-L_i*L_i))); 
        L_c = 2*L_i/sqrt(4-L_i*L_i);
        n *= 2;
    }

    return (p_i+p_c)/2;
}


