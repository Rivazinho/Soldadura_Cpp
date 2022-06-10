#pragma once
#include <iostream>
using namespace std;

class Vector { //Creaci�n de la clase vector

public: 
	
	double x, y, z;
	Vector(double x = 0, double y = 0, double z = 0); //Constructor de objetos de la clase vector

	void visualiza() const; //M�todo para visualizar vectores

	double modulo() const; //M�todo que calcula el m�dulo de un vector

	Vector unitario() const; //M�todo que calcula el unitario del vector 

	friend  Vector operator + (const Vector&, const Vector&); //Referencias constantes para no modificar los operandos

	friend  Vector operator - (const Vector&, const Vector&); //Referencias constantes para no modificar los operandos

	double distancia(const Vector&, const Vector&); //M�todo para calcular la distancia entre dos puntos
	
	friend Vector operator * (const double&, const Vector&); //M�todo para calcular el producto de un real por un vector

	friend double operator * (const Vector&, const Vector&); //M�todo para calcular el producto escalar de dos vectores

	friend Vector operator ^ (const Vector&, const Vector&); //M�todo para calcular el producto vectorial de dos vectores

    double angulo(const Vector&); //M�todo para calcular el �ngulo entre dos vectores
};

class Recta { //Creaci�n de la clase recta

public:

	Vector punto;
	Vector director;

	Recta(Vector director = Vector (0,0,0), Vector punto = Vector (0,0,0)); //Construye objetos vac�os

	double distanciaPuntoRecta(const Vector& p) const; //M�todo para calcular la distancia de un punto a una recta
	Vector rotacionPuntoRecta(const Vector&, const double&) const; //M�todo para calcular la rotaci�n de un vector sobre un eje, un determinado �ngulo
};


class Plano { //Creaci�n de la clase plano

public:

	Vector normal;
	Vector punto;
	double a, b, c, d;

	Plano(Vector normal, Vector punto); //Constructor de objetos de la clase plano a partir de vector normal y punto
	Plano(Vector punto1, Vector punto2, Vector punto3); //Constructor de objetos de la clase plano a partir de 3 puntos

	double distanciaPuntoPlano(const Vector& v) const; //M�todo para calcular la distancia de un punto a un plano

};



