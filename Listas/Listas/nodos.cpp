#include "nodos.h"
#include <cstdlib>
nodos::nodos() {
	this->artista = " ";
	this->cancion = " ";
	this->tiempo = " ";
	this->enlace = NULL;
}
void nodos::set_artista(string A) {
	this->artista = A;
}
void nodos::set_cacnion(string C) {
	this->cancion = C;
}
void nodos::set_tiempo(string T) {
	this->tiempo = T;
}
void nodos::set_enlace(nodos* E) {
	this->enlace = E;
}
nodos* nodos::get_enlace()
{
	return enlace;
}
string nodos::get_artista() {
	return artista;
}
string nodos::get_cacnion() {
	return cancion;
}
string nodos::get_tiempo() {
	return tiempo;
}	
 
