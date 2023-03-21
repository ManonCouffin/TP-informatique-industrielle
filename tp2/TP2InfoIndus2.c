//Manon COUFFIN
//Pauline JOBERT
//28/01/2022
//Objectif faire un chenillard

#include <c167.h>
#include <gnutrap.h>

//Afficher cette serie de nombre sur 4 leds que l'on enverra dans la fonction chenillard
unsigned int cycle[20]={0,8,3,5};
int variable=0;

//On indique l'interruption liee au timer T3 qui appelle la fonction chenillard
TRAP(0x23,chenillard);


//On allume une suite de led qui represente une suite de nombre contenus dans le tableau "cycle"
void chenillard(){
//on allume la led 2 si le nombre decompose en base 2 necessite le premier bit de poids faible a 1
	if ((cycle[variable] & 0x1 )== 0x1){
			SET_SFRBIT(P3.0);
	 } else { //Sinon on l'eteint
		CLR_SFRBIT(P3.0);
	 }
//on allume la led 2 si le nombre decompose en base 2 necessite le deuxieme bit de poids faible a 1
	if ((cycle[variable] & 0x2 )== 0x2){
			SET_SFRBIT(P3.1);
	} else { //Sinon on l'eteint
		CLR_SFRBIT(P3.1);
	}
//on allume la led 2 si le nombre decompose en base 2 necessite le troisieme bit de poids faible a 1
	if ((cycle[variable] & 0x4 )== 0x4){
			SET_SFRBIT(P3.2);
	} else { //Sinon on l'eteint
		CLR_SFRBIT(P3.2);
	}

	//on allume la led 2 si le nombre decompose en base 2 necessite le quatrieme bit de poids faible a 1
	if ((cycle[variable] & 0x8 )== 0x8){
			SET_SFRBIT(P3.3);
	} else { //Sinon on l'eteint
		CLR_SFRBIT(P3.3);
	}

	//on passe a la variable suivante
	variable ++;
	//lorsque le l'on atteint la fin du tableau, on remet la variable a zero 
	if (variable > 7){
		variable=0;
	}
}


void main(){
	// initialisation des ports P3.0 à P3.3
	SET_SFRBIT(DP3.0);
	CLR_SFRBIT(P3.0);
	SET_SFRBIT(DP3.1);
	CLR_SFRBIT(P3.1);
	SET_SFRBIT(DP3.2);
	CLR_SFRBIT(P3.2);
	SET_SFRBIT(DP3.3);
	CLR_SFRBIT(P3.3);


	//(h+1)*p = periode
	//h= 240ms/6.4musec


	//T3=28036;
	T3CON =0x44;    //000 0000 0100 0100
	T3IC=0x44;

	T2=28036;
	T2CON=0x27;     //  0010 0111
	
	while(1);



}
