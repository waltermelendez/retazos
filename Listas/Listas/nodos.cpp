#include "nodos.h"
#include <cstdlib>
nodos::nodos() {
	this->insertar = " ";
	
	this->enlace = NULL;
}
void nodos::set_artista(string A) {
	this->insertar = A;
}

void nodos::set_enlace(nodos* E) {
	this->enlace = E;
}
nodos* nodos::get_enlace()
{
	return enlace;
}
string nodos::get_artista() {
	return insertar;
}

 
