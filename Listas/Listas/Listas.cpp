

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<string>
#include"C_lista.h"
#include"nodos.h"
#include<conio.h>
#include<Windows.h>

using namespace std;
void lectura();
nodos* aux = NULL, * temporal;
C_lista* Cadena = new C_lista();
int main()
{
	char o = ' ';
	

	string insertar=" ", buscar, eliminar;
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
			
			/*cin >> insertar;
			lectura();
			aux->set_artista(insertar);
			Cadena->agregar(aux);*/
		
			
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
void lectura() {
	ifstream archivo;
	string texto;
	string s;
	int linea = 0;

	cout << "Nota por cada '/' debe cambiar por un '\\\'  y debe de agregar 'txt.' al final";
	cout << "diga en nombre de ubicacion: ";
	//es con el nombre del archivo
	cin.ignore();
	getline(cin, s);


	archivo.open(s.c_str(), ios::in);//abrir arcito en modo lectura
	if (archivo.fail()) {
		cout << "El archivo no esiste";
		exit(1);
	}
	while (!archivo.eof()) {//mientras QUE NO sea el final del arhico
		getline(archivo, texto);
		linea++;// conatdor lineas del texto.
		/*cout << texto << endl;*/
		//string g = "Hells Bells||AC/DC||5:12";
		int encontrar = texto.find("||");
		int pimero = 0;


		while (encontrar != string::npos)//mientras que encontrar no sea igual a encontar al caracter divisor seguira buscando el dato hasta la segundaa parte
		{/*por que la segunda parte porque, pirmero necesitamos convertir los numeros para poder usarlos, segundo su limite es cuando sea igual
		 npos indica la posicion maxima que se puede guarda*/
		 //El elemento fue encontrado, la posición se almacena en find
			string grupo = texto.substr(pimero, encontrar - pimero);//pimero, donde empiza; encontrar - pimero la cantiadad de caracteres
			cout << grupo << " ";
			pimero = encontrar + 2;
			encontrar = texto.find("||", pimero);

		}
		string numero = texto.substr(pimero);
		cout << numero << endl;
		int espaico = texto.find("\n");
		int pri = 0;
	}

	cout << "sus canciones subidas son: " << linea << endl;//para saber cuantas canciones fueron subidas.
	cout << "numero de canciones" << s << endl;// nombre del CD
	cin>> 
	archivo.close();
	

}