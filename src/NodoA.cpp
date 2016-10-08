#include "NodoA.h"

NodoA::NodoA(int Dato)
{
	this->Dato = Dato;
	this->Padre = NULL;
}

NodoA::NodoA(int Dato , NodoA* padre)
{
	this->Dato = Dato;
	this->Padre = padre;
}
int NodoA::getDato(){
	return this->Dato;
}