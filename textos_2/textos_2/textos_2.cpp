

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<string>
#include<filesystem>
#include <vector>

 // 



using namespace std;
//void h();
void lectura();
int main()
{



	/*int long_ = g.length()+1;
	char largo[long_];
	const char* a = '';
	for (int i = 0; i < g.length();i++) {
		cout << *a<<endl;
	}*/
	/*char palabra[] = "Come Together||The Beatles||4:19";
	int j = 0;
	while (palabra[j]=='|')
	{
		if (palabra[j] == '|') {
			for (int i = j;i < j; i--) {
				cout << palabra<<endl;
			}
		}
	}*/
	lectura();
	



}
//void h(){
//	string linea;
//	string letas[3];
//	string L = "Come Together||The Beatles||4:19";
//	fstream archivo;
//	archivo.open("Abbey Road.txt");
//	int veses = 0;
//	size_t posiicion;
//	while (getline(archivo, linea));
//	{
//		while ((posiicion = linea.find("|")) != string::npos)
//		{
//			letas[veses] = linea.substr(0, posiicion);
//			linea.erase(0, posiicion + 1);
//			veses++;
//		}
//		veses = 0;
//		
//	}
//	archivo.close();
//}
void lectura() {
	ifstream archivo;
	string s;
	int x = 1;
	cout << "link del porgrama";
	cin >> x;
	for (int i = 0;i < x;i++)
	{

	}
	string texto;
	int linea = 0;
	//string nombre_artista, n_cancion, duracion;
	int arrr = 1,ARR;
	cout << "diga el numero de archivos\n";
	getline(cin, ARR);
	
	while (ARR==arrr)
	{
		cout << "------------------------\n";
		cout << "diga en nombre de ubicacion. Nota por cada debe de agregar '\\\' debe poner un'/' y al final poner '.txt' " << endl;
		//es con el nombre del archivo
		getline(cin, s);
		while (!archivo.eof())
		{
			archivo.open(s.c_str(), ios::in);//abrir arcito en modo lectura
			if (archivo.fail()) {
				cout << "El archivo no esiste";
				exit(1);
			}
			else {
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

				int n = s.find_last_of("/\\");
				if (n != std::string::npos) {
					cout << s.substr(n + 1);
				}
				archivo.close();
			}

		}
	}
		
	
	
	


}


