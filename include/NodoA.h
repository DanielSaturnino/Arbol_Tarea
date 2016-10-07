#include <iostream>
#include <vector>

class NodoA
{
public:
	int Dato;
	std::vector<NodoA*> Hijos;
	NodoA* Padre;
	NodoA(int Dato);
	NodoA(int Dato , NodoA* padre);
	int getDato();
};