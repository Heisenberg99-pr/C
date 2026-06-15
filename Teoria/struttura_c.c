// dichiarazione delle libererie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct Oggetto{
    char *nome;
}; 

typedef struct Oggetto Oggetto;

struct inventario{ 
    Oggetto *oggetto;
    int dim,pos;
}; 

typedef struct inventario inventario;


inventario intentario_crea(); // Prototipo della funzione
inventario raccogli_oggetto(inventario inv, char *nuovo_oggetto); 
char *mostra_oggetto(inventario inv,int posizione); 

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

int main(){ //corpo della parte pricipale del programma 

    inventario inv = inventario_crea(); 

    inv = raccogli_oggetto(inv,"Piccone");
    inv = raccogli_oggetto(inv,"Ascia");
    
    printf("%s\n",mostra_oggetto(inv,0));
    printf("%s\n",mostra_oggetto(inv,1));
    printf("%s\n",mostra_oggetto(inv,2));
    printf("%s\n",mostra_oggetto(inv,11));
    printf("%s\n",mostra_oggetto(inv,-1));
    return 0;
}