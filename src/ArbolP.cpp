#include "ArbolP.h"

ArbolP::ArbolP(int Dato)
{
	this->Raiz= new NodoA(Dato);
}
bool ArbolP::AddNodo(int Dato,int ref)
{
	if(Raiz==NULL)
	{
		this->Raiz= new NodoA(Dato);
		std::cout<<"El arbol esta vacio se agrego el elemento sin considerar referenecia"<<std::endl;
		return true;
	}
	NodoA* Padre=BusqNodo(ref);
	if(Padre==NULL)
	{
		std::cout<<"no existe la referencia"<<std::endl;
		return false;
	}else
	{
	 	NodoA* hijo = new NodoA(Dato,Padre);
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
	NodoA* aux= BusqNodo(ref);
	if (aux==NULL)
	{
		std::cout<<"No existe la Referencia"<<std::endl;
	}
	for(int i=0;i<aux->Hijos.size();i++)
	{
		aux->Padre->Hijos.push_back(aux->Hijos[i]);
		aux->Hijos[i]->Padre =aux->Padre;
	}
	aux->Hijos.erase(aux->Hijos.begin(),aux->Hijos.end());
	aux->Padre=NULL;
	for (int i = 0; i < aux->Padre->Hijos.size(); ++i)
	{
		if(aux==aux->Padre->Hijos[i])
		{
			aux->Padre->Hijos.pop_back();
		}
	}
}
NodoA* ArbolP::BusqNodo(int ref)
{
	if (Raiz==NULL)
	{
		std::cout<<"NO HAY NINGUN ELEMENTO "<<std::endl;
		return NULL;
	}
	return  BusqRec(ref,Raiz);
}
NodoA* ArbolP::BusqRec(int ref,NodoA* aux)
{
	NodoA* Res;
	if(aux->getDato()==ref)
	{
		return aux;
	}
	if (aux->Hijos.empty())
	{
		return NULL;
	}
	for (int i = 0; i < aux->Hijos.size(); ++i)
	{
		Res=BusqRec(ref,aux->Hijos[i]);
	}
	if(Res!=NULL)
	{
		return Res;
	}
	return NULL;
}
std::stack<NodoA*> ArbolP::Camino(NodoA* aux)
{
	std::stack<NodoA*> Camino;
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
void ArbolP::imprimir()
{
		
	if (Raiz==NULL)
	{
		std::cout<<"NO HAY NINGUN ELEMENTO "<<std::endl;
	}
	std::cout<<Raiz->getDato()<<std::endl;
	return imprimirRec(Raiz);

}
void ArbolP::imprimirRec(NodoA* aux)
{
	NodoA* a=aux;
	for(int i=0;i<a->Hijos.size();++i)
	{
		std::cout<<a->Hijos[i]->getDato()<<std::endl;
		imprimirRec(a->Hijos[i]);
	}
}