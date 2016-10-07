#include "ArbolP.h"
#include <stack>
ArbolP::ArbolP(int Dato)
{
	this->Raiz=Nodo(Dato);
}
bool ArbolP::AddNodo(int Dato,int ref)
{
	if(Raiz==NULL)
	{
		Raiz=Nodo(Dato);
		std::cout<<"El arbol esta vacio se agrego el elemento sin considerar referenecia"<<std::endl;
		return true;
	}
	Nodo* Padre=new BusqNodo(ref);
	if(Padre==NULL)
	{
		std::cout<<"no existe la referencia"<<std::endl;
		return false;
	}else
	{
	 	Nodo* hijo =Nodo(Dato,Padre);
	 	Padre->Hijos.push_back(hijo);
	}
	return true;
}
bool ArbolP::ElimNodo(int ref)
{
	if (Raiz==NULL)
	{
		std::cout<<"No existe el valor en el arbol"<<std::endl;
	}
	Nodo* aux=new BusqNodo(ref);
	if (aux==NULL)
	{
		std::cout<<"No existe la Referencia"<<std::endl;
	}
	for(int i=0;i<aux->Hijos.size();i++)
	{
		aux->Padre.Hijos.push_back(aux->Hijos[i]);
		aux.Hijos[i].setPadre(aux->Padre);
	}
	aux->Hijos.erase(Hijos.begin(),Hijos.begin()+i);
	aux->Padre=NULL;
	for (int i = 0; i < aux->Padre.Hijos.size(); ++i)
	{
		if(aux==aux->Padre.Hijos[i])
		{
			aux->Padre.Hijos.pop_back(aux);
		}
	}
}
Nodo* Arbolp::BuscarNodo(int ref)
{
	if (Raiz==NULL)
	{
		std:cout<<"NO HAY NINGUN ELEMENTO "<<std::endl;
		return NULL;
	}
	return  BusqRec(ref,Raiz);
}
Nodo* Arbolp::BusqRec(int ref,Nodo* aux)
{
	Nodo* Res;
	if(aux.getDato()==ref)
	{
		return aux;
	}
	if (Hijos.empty())
	{
		return NULL;
	}
	for (int i = 0; i < Hijos.length(); ++i)
	{
		Res=BusqRec(Ref,Hijos[i]);
	}
	if(Res!=NULL)
	{
		return Res;
	}
	return NULL;
}
std::stack<NodoA*> ArbolP::Camino(NodoA* aux)
{
	stack<Nodo*> Camino;
	while(aux!=Raiz)
	{
		Camino.push(aux);
		aux=aux->Padre;
	}
	return Camino;
}

void ArbolP::Creararbol(int Raiz)
{
	AddNodo(2,Raiz);
	AddNodo(3,Raiz);
	AddNodo(4,2);
	AddNodo(5,2);
	AddNodo(9,5);
	AddNodo(8,5);
	AddNodo(6,3);
	AddNodo(7,3);
	AddNodo(10,3);
}