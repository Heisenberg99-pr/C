
#ifndef GAME_INVENTORY_H
#define GAME_INVENTORY_H

struct Oggetto_arma{
    char *nome;
    int dmg;
}; 

struct Oggetto_armatura{
    char *nome;
    int prot;
};

typedef struct Oggetto_arma Oggetto_arma;
typedef struct Oggetto_armatura Oggetto_armatura; 

struct inventario{ 
    Oggetto_arma *oggetto;
    int dim,pos;
}; 

typedef struct inventario inventario;


inventario inventario_crea(); // Prototipo della funzione
inventario raccogli_oggetto(inventario inv, Oggetto_arma nuova_arma); 
char *mostra_oggetto(inventario inv,int posizione); 

#endif