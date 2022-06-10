#include "Vectores.h"
#include <iostream>
using namespace std;


int main() {
	
	//Puntos
	Vector P1(5.07, 3.28, 2.16);
	Vector P2(10.53, 12.19, 17.72);
	Vector P3(21.01, 15.63, 6.97);
	Vector P4(-3.15, 4.96, 0.32);
	
	//Línea de soldadura
	Recta lineasoldado(P2 - P1, P1);
	
	//Planchas a soldar
	Plano Plancha1(P1, P2, P3);
	Plano Plancha2(P1, P4, P2);
	
	//Variables
	double distanciaPtos = lineasoldado.director.modulo();
	double anguloPlanchas = 180 - Plancha1.normal.angulo(Plancha2.normal);
	unsigned int i;
	
	//Variables auxiliares para el electrodo
	const double distanciaSoldado = 0.2;
	const unsigned int nDivisionesElec = 19;
	double intervaloElec = distanciaPtos / nDivisionesElec;
	Vector despElectrodo;
	Vector auxSuma;
	Vector elevaElectrodo;
	Vector Electrodo;

	//Variables auxiliares para la cámara
	const uint8_t nDivisionesCam = 9;
	double intervaloCam = distanciaPtos / nDivisionesCam;
	Vector desplazaCamara;
	Vector elevaCamara;
	Vector rotaCamara1;
	Vector rotaCamara2;
	double anguloRotacion;
	Vector Camara1;
	Vector Camara2;

	/*****************************************************/
	/******************** Electrodo **********************/
	/*****************************************************/

	despElectrodo = intervaloElec * lineasoldado.director.unitario();
	auxSuma = Plancha1.normal.unitario() + Plancha2.normal.unitario();
	elevaElectrodo = distanciaSoldado * auxSuma.unitario();

	//Impresión por pantalla

	cout << "Posiciones del electrodo, distancia a la linea de soldadura y distancia a las planchas: \r\n";
	for (i = 0; i < 20; i++) {
		
		Electrodo = P1 + elevaElectrodo + (i * despElectrodo);
		Electrodo.visualiza();

		cout << "\t" << lineasoldado.distanciaPuntoRecta(Electrodo);
		cout << "\t" << Plancha1.distanciaPuntoPlano(Electrodo);
		cout << "\t" << Plancha2.distanciaPuntoPlano(Electrodo);
		cout << "\r\n";

	}

	cout << "\nAngulo entre planchas = " << anguloPlanchas << "\n";

	/*****************************************************/
	/********************** Cámara ***********************/
	/*****************************************************/

	desplazaCamara = intervaloCam * despElectrodo.unitario();
	elevaCamara = elevaElectrodo.unitario();
	anguloRotacion = (anguloPlanchas / 2.0) - (anguloPlanchas / 3.0);
	rotaCamara1 = lineasoldado.rotacionPuntoRecta(elevaCamara, anguloRotacion);
	rotaCamara2 = lineasoldado.rotacionPuntoRecta(elevaCamara, -(anguloRotacion));

	//Impresión por pantalla

	cout << "\r\nPosiciones de la camara y distancias a linea de soldadura: \r\n";
	for (i = 0; i < 10; i++){

		Camara1 = P1 + (i * desplazaCamara) + rotaCamara1;
		Camara2 = P1 + (i * desplazaCamara) + rotaCamara2;
		
		Camara1.visualiza();
		cout << "\t";
		Camara2.visualiza();
		cout << "\t";
		cout << lineasoldado.distanciaPuntoRecta(Camara1) << "\t";
		cout << lineasoldado.distanciaPuntoRecta(Camara2) << "\t";
		cout << "\r\n";

	}
	return 0;
}
