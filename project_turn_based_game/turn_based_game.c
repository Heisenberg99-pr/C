#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#include "game_inventory.h"



struct mostro{
    char *nome;
    int vita,attacco,difesa,velocita;
};

struct personaggio{
    char *classe;
    bool parato;
    int vita,attacco,difesa,velocita;
}; 

typedef struct personaggio personaggio; 

typedef struct mostro mostro; 

#pragma region Metodi Universali
int attacco(int danno,int difesa); 
int parata(int difesa);
bool fuga(int vel_eroe,int vel_mostro,int ind_vel);



int attacco(int danno, int difesa){
    int result = danno - ((danno*difesa)/100); 
    if(result <= 9){
        return 10; 
    }
    return result; 
}

#pragma endregion

#pragma region Metodi Eroe
int parata(int difesa){
    difesa = difesa + ((difesa*50)/100); 
    return difesa;
}

bool fuga(int vel_eroe,int vel_mostro,int ind_vel){
    
    int prob_successo = 1 + rand() % 100;
    int prob_fuga = 50 + (ind_vel * 5) + (vel_eroe - vel_mostro);
    
    return prob_successo < prob_fuga; 
}

#pragma endregion


int main(){
    
    int ind_vel = 0; 
    int scelta;
    bool fuggito = false; 
    srand(time(NULL)); 


    #pragma region def_mostri
    mostro mostro1 = {"Ignis", 150, 45, 30, 40};
    mostro mostro2 = {"Gorgone", 110, 35, 55, 30};
    mostro mostro3 = {"Demone", 80, 60, 20, 65};
    mostro mostro4 = {"Golem", 200, 25, 70, 15};
    mostro mostro5 = {"Idra", 95, 50, 25, 45};
    #pragma endregion


    #pragma region def_eroi
    personaggio eroe1 = {"Guerriero", false, 180, 40, 50, 25};
    personaggio eroe2 = {"Mago", false, 90, 70, 15, 35};
    personaggio eroe3 = {"Ladro", false, 110, 55, 25, 75};
    personaggio eroe4 = {"Chierico", false, 140, 35, 40, 30};
    personaggio eroe5 = {"Paladino", false, 160, 45, 60, 20};
    #pragma endregion
    

    #pragma region def_armi
    Oggetto_arma arma_eroe1 = {"Spadone a Due Mani", 75};
    Oggetto_arma arma_eroe5 = {"Martello da Guerra", 70};
    Oggetto_arma arma_eroe3 = {"Pugnali Gemelli", 55};
    Oggetto_arma arma_eroe4 = {"Mazza Chiodata", 45};
    Oggetto_arma arma_eroe2 = {"Bastone di Legno", 25};
    #pragma endregion
        
    personaggio giocatore; 
    int Selezione_eroe;
    bool selezionato = false; 
    
    #pragma region Selezione Personaggi
    while(selezionato == false){
        
        printf("Seleziona la classe dell'eroe...\n"
               "1) Guerriero: In armatura di piastre il Guerriero e' molto vitale, forte e resistente\n"
               "2) Mago: Adatto al combattimento a distanza, il Mago sfrutta la sua potente magia per infliggere danni ingenti e sopperire alla sua debolezza fisica\n"
               "3) Ladro: Agile e scaltro, il Ladro usa la furbizia per sfruttare ogni debolezza dell'avversario\n"
               "4) Chierico: Devoto nel suo dio, il Chierico usa il potere divino per sconfiggere l'oscurita' nel mondo\n"
               "5) Paladino: Un combattente di chiesa, il Paladino sfrutta la sua resistenza e vitalità per proteggere il regno dall'oscurita'\n"
               "Scelta: ");

        scanf("%d", &Selezione_eroe); 

        switch(Selezione_eroe){
            case 1:
                giocatore = eroe1; 
                selezionato = true;
                break;
            case 2:
                giocatore = eroe2; 
                selezionato = true;
                break;
            case 3:
                giocatore = eroe3; 
                selezionato = true;
                break;
            case 4:
                giocatore = eroe4; 
                selezionato = true;
                break;
            case 5:
                giocatore = eroe5; 
                selezionato = true;
                break;
            default:
                printf("L'eroe selezionato non esiste\n");
        }
    }

    printf("Hai selezionato %s Caratteristiche: \n Vita: %d \n Attacco: %d \n Difesa: %d \n Velocità: %d \n", giocatore.classe,giocatore.vita, giocatore.attacco, giocatore.difesa,giocatore.velocita); 

    mostro nemico; 
    int mostro_scelto = 1 + rand() % 5;

    switch(mostro_scelto) {
        case 1: nemico = mostro1; break;
        case 2: nemico = mostro2; break;
        case 3: nemico = mostro3; break;
        case 4: nemico = mostro4; break;
        case 5: nemico = mostro5; break;
    }
    #pragma endregion
        
    printf("Attenzione ti sta attaccando un %s, sta iniziando il combattimento...\n", nemico.nome);
    
    #pragma region Combattimento
    
    while(nemico.vita > 0 && giocatore.vita > 0 && fuggito == false){

        if(giocatore.parato == true){
            giocatore.difesa = (giocatore.difesa*100)/150;
            giocatore.parato = false; 
        }

        printf("Info: \n Vita Eroe: %d \n Vita %s: %d", giocatore.vita,nemico.nome,nemico.vita); 
        printf("E' il tuo turno, seleziona l'azione: \n 1) Attacco \n 2) Usa oggetto \n 3) Parata \n 4) Fuggi \n "); 
        scanf("%d", &scelta);
        
        switch(scelta) {
            case 1: 
                nemico.vita = nemico.vita - attacco(giocatore.attacco, nemico.difesa);
                printf("Il %s ha %d hp\n", nemico.nome, nemico.vita);
                break;
            case 2: /* Usa Oggetto */ break;
            case 3:
                giocatore.difesa = parata(giocatore.difesa); 
                giocatore.parato = true;  
                break;
            case 4: 
                fuggito = fuga(giocatore.velocita,nemico.velocita,ind_vel);
                if(fuggito == false){
                    if(ind_vel >= 5){
                        break;
                    }
                    ind_vel += 1;   
                } 
                break;
        }

        // Controllo fuori dallo switch: interrompe il ciclo while correttamente
        if(nemico.vita <= 0) { 
            break; 
        }

        printf("E' il turno del nemico...");

        scelta = 1;  

        switch(scelta) {
            case 1: 
                printf("Il nemico sta attaccando...\n");
                giocatore.vita = giocatore.vita - attacco(nemico.attacco, giocatore.difesa); 
                printf("Ti rimangono %d hp\n", giocatore.vita);
                break; 
            case 2: /* ... */ break;
            case 3: /* ... */ break;
            case 4: /* ... */ break;
        }

        // Controllo fuori dallo switch: interrompe il ciclo while se il giocatore muore
        if(giocatore.vita <= 0) {
            break; 
        }
    }
    #pragma endregion

    printf("\n Il combattimento è terminato\n"); 

    if(fuggito == true){
        printf("Sei fuggito"); 
    }else{
        printf("%s\n", (giocatore.vita <= 0) ? "Game Over" : "Hai Vinto!!!");
    }
    
    
    return 0; 
}