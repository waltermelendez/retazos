#include "C_lista.h"

C_lista::C_lista() {
	Cabeza = NULL;

}
nodos* C_lista::get_ultimo() {
	nodos* ultimo = get_cabeza();
	while (ultimo->get_enlace() != NULL)
	{
		ultimo = ultimo->get_enlace();
	}
	return ultimo;
}
void C_lista::agregar(nodos* neuvo) {
	if (get_cabeza() == NULL) {
		set_cabeza(neuvo);
	}
	else {
		get_ultimo()->set_enlace(neuvo);
	}
}
nodos* C_lista::get_cabeza() {
	return Cabeza;
}
void C_lista::set_cabeza(nodos* C) {
	Cabeza = C;
}

nodos* C_lista::buscar(string p){
	nodos* Buscar = get_cabeza();
	while ((Buscar!= NULL)&& (Buscar->get_artista()!= p))
	{
		Buscar = Buscar->get_enlace();

	}
	return Buscar;
}
void C_lista::eliminar(string A) {
	nodos* B = get_cabeza();
	nodos* C = NULL;
	if (B->get_artista() == A) {
		set_cabeza(get_cabeza()->get_enlace());
	}
	else {
		while ((B!=NULL)&&(B->get_artista()!=A))
		{
			C = B;
			B = B->get_enlace();
		}
		if (B != NULL) {
			C->set_enlace(B->get_enlace());
		}
	}
	delete B;
}
