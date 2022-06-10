#pragma once
#include <iostream>
using namespace std;

class Vector { //Creación de la clase vector

public: 
	
	double x, y, z;
	Vector(double x = 0, double y = 0, double z = 0); //Constructor de objetos de la clase vector

	void visualiza() const; //Método para visualizar vectores

	double modulo() const; //Método que calcula el módulo de un vector

	Vector unitario() const; //Método que calcula el unitario del vector 

	friend  Vector operator + (const Vector&, const Vector&); //Referencias constantes para no modificar los operandos

	friend  Vector operator - (const Vector&, const Vector&); //Referencias constantes para no modificar los operandos

	double distancia(const Vector&, const Vector&); //Método para calcular la distancia entre dos puntos
	
	friend Vector operator * (const double&, const Vector&); //Método para calcular el producto de un real por un vector

	friend double operator * (const Vector&, const Vector&); //Método para calcular el producto escalar de dos vectores

	friend Vector operator ^ (const Vector&, const Vector&); //Método para calcular el producto vectorial de dos vectores

    double angulo(const Vector&); //Método para calcular el ángulo entre dos vectores
};

class Recta { //Creación de la clase recta

public:

	Vector punto;
	Vector director;

	Recta(Vector director = Vector (0,0,0), Vector punto = Vector (0,0,0)); //Construye objetos vacíos

	double distanciaPuntoRecta(const Vector& p) const; //Método para calcular la distancia de un punto a una recta
	Vector rotacionPuntoRecta(const Vector&, const double&) const; //Método para calcular la rotación de un vector sobre un eje, un determinado ángulo
};


class Plano { //Creación de la clase plano

public:

	Vector normal;
	Vector punto;
	double a, b, c, d;

	Plano(Vector normal, Vector punto); //Constructor de objetos de la clase plano a partir de vector normal y punto
	Plano(Vector punto1, Vector punto2, Vector punto3); //Constructor de objetos de la clase plano a partir de 3 puntos

	double distanciaPuntoPlano(const Vector& v) const; //Método para calcular la distancia de un punto a un plano

};



