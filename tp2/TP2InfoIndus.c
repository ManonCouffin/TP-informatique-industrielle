//Manon COUFFIN
//Pauline JOBERT
//28/01/2022
//Objectif: Faire clignoter une LED

#include <c167.h>
#include <gnutrap.h>

//On indique l'interruption liee au timer T3 qui appelle la fonction clignoterLed
TRAP(0x23,clignoterLed);


//Fonction qui fait clignoter une led a chaque interruption 
void clignoterLed(){
	//si la led est allumee, on l'eteint 
	if (SFR_BIT(P3.0)==1){
		CLR_SFRBIT(P3.0);
		
    	}else                     //Sinon, on l'allume
		SET_SFRBIT(P3.0);
}

//On initialise le microcontroleur
void main(){
	//on met le port en mode sortie 
	SET_SFRBIT(DP3.0);
	//on active le port P3
	CLR_SFRBIT(P3.0);



	//(h+1)*p = periode
	//h= 240ms/6.4musec
	
	//On initialse le timer T3 en mode timer 
	T3=28036;
	T3CON =0x44;    //000 0000 0100 0100
	T3IC=0x44;

	//On initilise le compter T2 en mode rechargement 
	T2=28036;
	T2CON=0x27;     //  0010 0111
	
	while(1);



}
