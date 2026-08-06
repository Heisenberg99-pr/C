
#ifndef GAME_INVENTORY_H
#define GAME_INVENTORY_H

struct Oggetto{
    char *nome;
}; 

typedef struct Oggetto Oggetto;

struct inventario{ 
    Oggetto *oggetto;
    int dim,pos;
}; 

typedef struct inventario inventario;


inventario inventario_crea(); // Prototipo della funzione
inventario raccogli_oggetto(inventario inv, char *nuovo_oggetto); 
char *mostra_oggetto(inventario inv,int posizione); 

#endif