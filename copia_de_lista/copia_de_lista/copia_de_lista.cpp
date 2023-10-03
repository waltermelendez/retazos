

#include <iostream>
#include <conio.h>
#include<list>
#include <stdlib.h>
using namespace std;
struct  NODO
{
	int dato;
	NODO* siguiente;
};
void insertarlista(NODO*&, int);
void mostrarlista(NODO*);
void menu();
void buscarlista(NODO* lista, int);
void eliminarnodo(NODO*&, int);

NODO* lista = NULL;
int main()
{



	menu();

	return 0;
}
void menu() {
	int op, d;
	do
	{
		cout << "menu\n";
		cout << "insertar datos\n";
		cout << "mostrar los elementos de la lsita\n";
		cout << "buscar numero\n";
		cout << "eleiminar dato\n";
		cout << "salir\n";
		cin >> op;
		switch (op)
		{
		case 1:

			cout << "de un numero ";
			cin >> d;
			insertarlista(lista, d);
			cout << "\n";
			cout << "presione enter para reiniciar\n";
			system("pause");

			break;

		case 2:
			mostrarlista(lista);
			cout << "\n";
			cout << "presione enter para reiniciar\n";
			system("pause");

			break;
		case 3:
			cout << "diga el numero a buscar\n";
			cin >> d;
			buscarlista(lista, d);
			cout << "\n";
			system("pause");
			break;
		case4:
			cout << "escriba el elemento a borrar\n";
			cin >> d;
			eliminarnodo(lista, d);
			cout << "\n";
			system("pause");
			break;
		default:
			exit(1);

		}
		system("cls");
	} while (op != 5);
}
void insertarlista(NODO*& lista, int n) {
	NODO* nuevo_ndo = new NODO();
	nuevo_ndo->dato = n;
	NODO* aux1 = lista;
	// NODO* aux2;
	while ((aux1 != NULL) && (aux1->dato < n))
	{
		//aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if (lista == aux1) {
		lista = nuevo_ndo;
	}
	else {
		//aux2->siguiente = nuevo_ndo;
	}
	nuevo_ndo->siguiente = aux1;
	cout << "\t elemento " << n << "fue insertado\n ";
}
void mostrarlista(NODO* lista) {
	NODO* actual = new NODO();
	actual = lista;
	while (actual != NULL)
	{
		cout << actual->dato << " ->  ";
		actual = actual->siguiente;
	}
}
void buscarlista(NODO* lista, int n) {
	bool b = false;
	NODO* actual = new NODO();
	actual = lista;

	while ((actual != NULL) && (actual->dato <= n))
	{
		if (actual->dato == n) {
			b = true;
		}
		actual = actual->siguiente;
	}
	if (b == true) {
		cout << "se ha encontrado a " << n << endl;
	}
	else {
		cout << "no se ha encontrado ningun numero \n";
	}
}
void eliminarnodo(NODO*& lista, int n) {
	if (lista != NULL) {
		NODO* aux_borar;
		NODO* anterorir = NULL;
		aux_borar = lista;
		while ((aux_borar != NULL) && (aux_borar->dato != n)) {
			anterorir = aux_borar;
			aux_borar = aux_borar->siguiente;
		}
		if (aux_borar == NULL) {
			cout << "no ha sido encontrado\n";
		}
		else if (anterorir == NULL) {
			lista = lista->siguiente;
			delete aux_borar;
		}
		else {
			anterorir->siguiente = aux_borar->siguiente;
			delete aux_borar;
		}
	}
}
