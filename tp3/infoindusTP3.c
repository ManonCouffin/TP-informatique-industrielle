//COUFFIN MANON
//JOBERT PAULINE
//TP3 Partie 1

#include <c167.h>
#include <gnutrap.h>

//Objectif : Controler l'angle que prends le servo moteur en fonction d'une duree d'impulsion 
int main(){


	//on initialise le port p7 en sortie 
	SET_SFRBIT(DP7.0);
	CLR_SFRBIT(P7.0);

	//on calcule PP0 avec TPWMO=20ms et tr =3.2microsec
	PP0=6249; 



	//on initalise PWMCON0 = 0000 0000 0001 0001
	PWMCON0= 0x11;
	//on initialise PWMCON1 =  0000 0000 0000 0001
	PWMCON1=0x1;

	while(1){
	//on calcule les PWX associés aux angles -90°, -45°, 0°, 45°, 90° 
	//avec temps bas = 20ms - temps haut et leurs temps haut respectifs 
	//0.6 ms, 1.05ms, 1.5ms, 1.95ms, 2.4ms
		PW0=6060;

		PW0=5932;

		PW0=5781;

		PW0=5634;

		PW0=5500;

	}

}
