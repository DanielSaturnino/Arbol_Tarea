#include <stack>
#include "NodoA.h"


class ArbolP
{
private:
	NodoA* BusqRec(int ref, NodoA* aux);
	void imprimirRec(NodoA* aux);
public:
	NodoA* Raiz;
	ArbolP(int Dato);
	NodoA* BusqNodo(int ref);
	bool AddNodo(int Dato,int ref);
	bool ElimNodo(int ref);
	std::stack<NodoA*> Camino(NodoA* aux);
	void Creararbol(int Raiz);
	void imprimir();

};