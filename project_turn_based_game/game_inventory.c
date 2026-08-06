
#include <stdio.h>
#include <stdlib.h>
#include "game_inventory.h"

inventario inventario_crea(){ //Stesura della funzione, corpo
    inventario inv = {NULL,10,10};
    inv.oggetto = (Oggetto *)malloc(sizeof(Oggetto)*inv.dim); 
    return inv; 
}

inventario raccogli_oggetto(inventario inv,char *str){
    for(int i = 0; i < inv.dim; i++){
        if(inv.oggetto[i].nome == NULL){
            inv.pos = i; 
            break; 
        }
    }

    inv.oggetto[inv.pos].nome = str; 
    return inv; 
}


char *mostra_oggetto(inventario inv,int posizione){
    if(posizione>=inv.dim || posizione < 0){
        return "mano";
    }
    inv.pos = posizione; 

    if(inv.oggetto[inv.pos].nome == NULL){
        return "mano";
    }else{
        return inv.oggetto[inv.pos].nome; 
    }
}