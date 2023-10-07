

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<string>
#include"C_lista.h"
#include"nodos.h"
#include<conio.h>
#include<Windows.h>

using namespace std;

int main()
{
	char o = ' ';
	nodos* aux = NULL,*temporal;
	C_lista* Cadena = new C_lista();
//	nodos* auxCacnion= NULL;
	//nodos* auxT = NULL;
//	C_lista* cadena_cancio= new C_lista();
	//C_lista* cadenaTiempo = new C_lista();
	string Artsita=" ", cacnion= " ", Tiempo=" ",buscar, eliminar;
	do {
		cout << "de una opcion" << endl;
		cout << "1.agregar\n";
		cout << "2.mostrar\n";
		cout << "3.bsucar\n";
		cout << "4.eliminar\n";
		cin >> o;
		switch (o)
		{
		case '1':
			cout << "agregar " << endl;
			aux = new nodos();
			cout << "de un artista" << endl;
			cin >> Artsita;
			aux->set_artista(Artsita);
			Cadena->agregar(aux);
			/*cout << "numero add\n";
			cout << "de un nombre de una canion\n";
			cin >> cacnion;*/
			/*auxCacnion->set_cacnion(cacnion);
			cadena_cancio->agregar(auxCacnion);
			cout << "numero add\n";
			cout << "de un tiempo de la cacnion\n";
			cin >> Tiempo;
			auxT->set_tiempo(Tiempo);
			cadenaTiempo->agregar(auxT);*/
			
			break;
		case '2':
			cout << "2.mostrar\n";
			temporal = Cadena->get_cabeza();
			while (temporal!=NULL)
			{
				cout << temporal->get_artista() << ", " << endl;
				temporal = temporal->get_enlace();
			}
			system("pause");
			break;
		case '3':
			cout << "3.bsucar\n";
			cout << "de la palabra a buscar\n";
			cin >> buscar;
			temporal = Cadena->buscar(buscar);
			if (temporal != NULL) {
				cout << "palabra encontrda "<< temporal->get_artista()<<endl ;
			
			}
			else {
				cout << "palabra no encontrada\n";
			}
			system("pause");
			break;
		case'4':
			cout << "eliminar\n";
			cout << "ingrese la palabra a eliminar\n";
			cin >> eliminar;
			temporal = Cadena->buscar(eliminar);
			if (temporal != NULL) {
				Cadena->eliminar(eliminar);
				cout << "palabra eliminada " <<  endl;

			}
			else {
				cout << "palabra no existente\n";
			}
			system("pause");
			break;
		default:
			cout << "programa cerrado\n";
			exit(1);
			break;
		}
		system("cls");
	} while (o != '5');

	
	return 0;
}
