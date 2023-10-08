#pragma once
#include "nodos.h"
using namespace std;
#include <string>
class C_lista
{
	private:
		nodos* Cabeza;
		//nodos* next;
	public:
		void set_cabeza(nodos*);
		nodos* get_cabeza();
		C_lista();
		nodos* get_ultimo();
		void agregar(nodos*);
		/*void get_next();
		nodos* set_next(nodos*);*/
		nodos* buscar(string);
		void eliminar(string);
};

