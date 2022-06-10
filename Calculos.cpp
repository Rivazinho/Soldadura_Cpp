#include <iostream>
using namespace std;
#include "Vectores.h"
#include <string>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>


Vector::Vector(double x_, double y_, double z_) { //Constructor que asigna los atributos al vector
	
	x = x_;
	y = y_;
	z = z_;
}

void Vector::visualiza()const { //Método que visualiza vectores

	cout << "(" << x << ", " << y << ", " << z << ")";

}

double Vector::modulo()const {

	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); //El método devuelve un double

}

Vector Vector::unitario() const { //Método de la clase Vector que devuelve un Vector

	Vector aux;
	double mod = modulo(); 
	aux.x = x / mod;
	aux.y = y / mod;
	aux.z = z / mod;
	return aux;

}

Vector operator + (const Vector& v1, const Vector& v2) { //Redefinimos el operador + para que sume vectores directamente

	Vector aux;
	aux.x = v1.x + v2.x;
	aux.y = v1.y + v2.y;
	aux.z = v1.z + v2.z;
	return aux;

}

Vector operator - (const Vector& v1, const Vector& v2) { //Redefinimos el operador - para que reste vectores directamente

	Vector aux;
	aux.x = v1.x - v2.x;
	aux.y = v1.y - v2.y;
	aux.z = v1.z - v2.z;
	return aux;

}

double Vector::distancia(const Vector& v1, const Vector& v2) { //Distancia entre dos puntos

	Vector aux;
	aux = v1 - v2;
	return aux.modulo();

}

Vector operator * (const double& x, const Vector& v1) { //Producto de un real por un vector

	Vector aux;
	aux.x = x * v1.x;
	aux.y = x * v1.y;
	aux.z = x * v1.z;
	return aux;

}

double operator * (const Vector& v1, const Vector& v2) { //Producto escalar
	
	double aux;
	aux = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	return aux;

}

Vector operator ^ (const Vector& v1, const Vector& v2) { //Producto vectorial

	Vector aux;
	aux.x = (v1.y * v2.z - v2.y * v1.z);
	aux.y = -(v1.x * v2.z - v2.x * v1.z);
	aux.z = (v1.x * v2.y - v2.x * v1.y);
	return aux;

}

double Vector::angulo(const Vector& v1) { //Ángulo entre 2 vectores

	return acos((v1 * *this) / (v1.modulo() * modulo())) * (360 / (2 * M_PI));

}

Recta::Recta(Vector director_, Vector punto_) { //Constructor que asigna los atributos a la recta

	director = director_;
	punto = punto_;
}

Plano::Plano(Vector normal_, Vector punto_) { //Constructor que asigna los atributos al plano

	normal = normal_;
	punto = punto_;

	//Cálculo de la ecuación del plano como Ax + By + Cz + D = 0
	a = normal.x;
	b = normal.y;
	c = normal.z;
	d = -(normal.x * punto.x + normal.y * punto.y + normal.z * punto.z);

}

Plano::Plano(Vector punto1_, Vector punto2_, Vector punto3_) { //Constructor que asigna los atributos al plano

	Vector aux1 = punto2_-punto1_;
	Vector aux2 = punto3_-punto1_;;
	normal = (aux2 ^ aux1);
	punto = punto1_;

	//Cálculo de la ecuación del plano como Ax + By + Cz + D = 0
	a = normal.x;
	b = normal.y;
	c = normal.z;
	d = -(a * punto.x + b * punto.y + c * punto.z);
}

double Recta::distanciaPuntoRecta(const Vector& p) const {

	Vector aux1;
	Vector aux2;
	
	aux1 = p - punto;
	aux2 = aux1 ^ director;
	return (aux2.modulo() / director.modulo());
}

double Plano::distanciaPuntoPlano(const Vector& v) const {

	return fabs(a * v.x + b * v.y + c * v.z + d) / normal.modulo();

}

Vector Recta::rotacionPuntoRecta(const Vector& p, const double& angulo_) const {

	Vector resultado;
	double angulo = angulo_ * (M_PI / 180);
	Vector director = this->director.unitario();

	resultado.x = (cos(angulo) + pow(director.x, 2) * (1 - cos(angulo))) * p.x + (director.x * director.y * (1 - cos(angulo)) - director.z * sin(angulo)) * p.y + (director.x * director.z * (1 - cos(angulo)) + director.y * sin(angulo)) * p.z;
	resultado.y = (director.y * director.x * (1 - cos(angulo)) + director.z * sin(angulo)) * p.x + (cos(angulo) + pow(director.y, 2) * (1 - cos(angulo))) * p.y + (director.y * director.z * (1 - cos(angulo)) - director.x * sin(angulo)) * p.z;
	resultado.z = (director.z * director.x * (1 - cos(angulo)) - director.y * sin(angulo)) * p.x + (director.z * director.y * (1 - cos(angulo)) + director.x * sin(angulo)) * p.y + (cos(angulo) + pow(director.z, 2) * (1 - cos(angulo))) * p.z;
	return resultado;

}
