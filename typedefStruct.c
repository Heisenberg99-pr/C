#include <stdio.h>
#include <stdlib.h>

/* La funzione seguente crea un tipo di dato composto che contiene più avlori correlati, in questo caso, un punto cartesiano con coordinate x e y
e ad ogni variabile di tipo struct punto avrà due double in memoria, uno per x e uno per y*/
struct punto{
    double x;
    double y;
    // Ouppure si può scrivere anche double x,y;
};

/* La funzione typedef che segue crea un alias del tipo cosi da poter scrivere punto invece di struct punto, riducendo il codice e lo rende più leggibile*/
typedef struct punto punto;

int main(){
    struct punto p0 = {2.1,0.5}; 
    punto p1 = {0,1}; // Creazione dei due punti
    p0.y = p0.x + p0.y; // Aggiorna p0.y con la somma di p0.x+p0.y

    // In seguito segue la stampa a video 
    printf("(%f,%f)\n",p0.x,p0.y);
    printf("(%f,%f)\n", p1.x,p1.y);
}