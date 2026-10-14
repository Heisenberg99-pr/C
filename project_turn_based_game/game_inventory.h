
#ifndef GAME_INVENTORY_H
#define GAME_INVENTORY_H

struct Arma{
    char *nome;
    int dmg;
}; 

struct Armatura{
    char *nome;
    int prot;
};

typedef struct Arma Arma;
typedef struct Armatura Armatura; 

struct inventario{ 
    Arma *oggetto;
    int dim,pos;
}; 

typedef struct inventario inventario;


inventario inventario_crea(); // Prototipo della funzione
inventario raccogli_oggetto(inventario inv, Arma nuova_arma); 
char *mostra_oggetto(inventario inv,int posizione); 

#endif