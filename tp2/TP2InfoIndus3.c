//Manon COUFFIN
//Pauline JOBERT
//28/01/2022
//Objectif: Faire clignoter une LED

#include <c167.h>
#include <gnutrap.h>

//variables globales
unsigned int cycle[20];
unsigned int periodeCycle=0;
unsigned int cptCycle=-1;
int variable=0;
unsigned int lancementChenillard;

TRAP(0x2B, ChenSerie);

//on remet en place l'interruption faite a la partie 2 
TRAP(0x23,chenillard);

//on reprend la fonction codee durant la partie 2
void chenillard(){
	
		if ((cycle[variable] & 0x1 )== 0x1){ 
				SET_SFRBIT(P3.0);
		 } else { 
			CLR_SFRBIT(P3.0);
		 }

		if ((cycle[variable] & 0x2 )== 0x2){
				SET_SFRBIT(P3.1);
		} else { 
			CLR_SFRBIT(P3.1);
		}

		if ((cycle[variable] & 0x4 )== 0x4){
				SET_SFRBIT(P3.2);
		} else { 
			CLR_SFRBIT(P3.2);
		}
		if ((cycle[variable] & 0x8 )== 0x8){
				SET_SFRBIT(P3.3);
		} else { 
			CLR_SFRBIT(P3.3);
		}

		variable ++;
		if (variable > 7){
			variable=0;
		}
	
}


void ChenSerie(){

	if (cptCycle==-1){ //si on n'a pas encore commencé aucun cycle 
		CLR_SFRBIT(T3R); //on initialise T3R et la periode du cycle
		periodeCycle=S0RBUF;
		cptCycle++;
	} else {

		if (cptCycle<periodeCycle){ //cycle en cours
			cycle[cptCycle]=S0RBUF; // on ajoute une nouvelle valeur au cycle
			cptCycle++;
		} 
		if (cptCycle==periodeCycle){ //si on est a la fin de notre cycle
			SET_SFRBIT(T3R);
			cptCycle=-1; // on réinitialise le compteur et le nombre de variable
			variable=0;
			

		}
			
			
	}	

}


void main(){

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

	S0BG=32;
	//S0BRS=0;
	S0CON=0x8011;
	S0RIC = 0x04C;
	SET_SFRBIT(IEN);
	CLR_SFRBIT(DP3.11);
	
	while(1);



}
