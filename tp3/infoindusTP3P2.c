//COUFFIN MANON
//JOBERT PAULINE
//TP3 Partie 2

#include <c167.h>
#include <gnutrap.h>
unsigned int valeurAddat;

TRAP(0x3F,lecture)

//Objectif : Controler l'angle que prends le servo moteur
// en fonction d'une tension amenée avec le potentiomètre

//on reprends le tp 1 ou on convertie un signal en valeur de 0 à 1023
void lecture(){
	CLR_SFRBIT(ADCIR);
	SET_SFRBIT(ADST);
	WAIT_UNTIL_BIT_SET(ADCIR);
	valeurAddat = ADDAT & 0x3FF;
	CLR_SFRBIT(PIR0);


}


int main(){

	//initialisation ADCON
	ADCON = 0x5;
	SET_SFRBIT(DP3.10);
	SET_SFRBIT(P3.10);

	//on initialise le port p7 en sortie 
	SET_SFRBIT(DP7.0);
	CLR_SFRBIT(P7.0);

	//on calcule PP0 avec TPWMO=20ms et tr =3.2microsec

	PP0=6249; 

	//initialisation de PWMIC
	PWMIC = 0x4C;



	//on initalise PWMCON0 = 0000 0001 0001 0001
	PWMCON0= 0x111;
	//on initialise PWMCON1 =  0000 0000 0000 0001
	PWMCON1=0x1;
	
	
	while(1){
	//on calcule PM0 en fonction de la valeur convertie lors de la lecture 
		//5500 correspond à la valeure de PW0 à -90°
		//1024 est le nombre max qui sort du convertisseur 
		// Valeur max de PW0 - valeur min de PW0 = 562	
		PW0=5500 +( 0.55*valeurAddat); //0.55=1024/562
		
	
	}




}
