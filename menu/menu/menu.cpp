#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <cstdlib>
#include <algorithm>


using namespace std;


void lectura();
int main() {
    std::vector<std::string> elementos;
    queue<string> colaLineas;

    int opcion,op;
    bool ver = false;



    cout << "Bienvenido al Reproductor de Musica :)" << endl;
    cout << " " << endl;
    cout << "seleccione su carpeta donde esta sus archivos\n";
    cout << "1.documentos\n";
    cout << "2.descargas\n";

    cout << "3.carpeta no seleccionada\n";
    cin >> op;
    if (op == 1) {
    	//puede dar fallo segun el idioma del usuario
        system(" start %USERPROFILE%\\Documents");
           
        cout << "vaya y copie la dirreccion del documento\n";
        
    }
    else if (op == 2) {
    	
        cout << "vaya y copie la dirreccion del documento\n";
        system("start  %USERPROFILE%\\Downloads");
        
    }
    
    else if (op ==3){
        system("start %USERPROFILE%");
        cout << "vaya y copie la dirreccion del documento\n";
        
    }
    else {
        cout << "carpeta desconocida\n";
    }
    
    lectura();

        while (true) {
            bool col = true;
            bool col2 = true;
            bool col3 = true;
            bool col4 = true;

            cout << "Menu de opciones:" << endl;
            cout << "1. Agregar Cancion" << endl;
            cout << "2. Ver Cola de Reproduccion" << endl;
            cout << "3. Reproduccion Actual" << endl;
            cout << "4. Siguiente Reproduccion" << endl;
            cout << "5. Ordenar" << endl;
            cout << "6. Salir del reproductor" << endl;

            cout << " " << endl;

            cout << "Selecciona una opcion (1-6): ";
            cout << " " << endl;
            cin >> opcion;

            switch (opcion) {
           
            case 1:
                cout << "Agregar Cancion" << endl;
                cout << " " << endl;


                system("cls");
                break;
            case 2:
                cout << "Ver Cola de Reproduccion" << endl;
                cout << " " << endl;

                while (col == true) {

                    queue<string> temp = colaLineas;
                    while (temp.empty() == false) {
                        cout << temp.front() << endl;
                        temp.pop();
                    }


                    char respuesta1;
                    cout << " " << endl;
                    cout << "Desea seguir viendo la cola? (s/n): ";
                    cin >> respuesta1;
                    if (respuesta1 != 's' && respuesta1 != 'S') {
                        col = false;
                    }


                }

                system("cls");
                break;
            case 3:
                cout << "Reproduccion Actual" << endl;
                cout << " " << endl;
                if (!colaLineas.empty()) {
                    cout << "Actualmente esta escuchando: " << colaLineas.front() << endl;
                }
                else {
                    cout << "No se esta reproduciendo nada actualmente" << endl;
                }

                char respuesta2;
                cout << " " << endl;
                cout << "Desea seguir viendo la reproduccion actual? (s/n): ";
                cin >> respuesta2;
                if (respuesta2 != 's' && respuesta2 != 'S') {
                    col2 = false;
                }

                system("cls");
                break;
            case 4:
                cout << "Siguiente Reproduccion" << endl;
                cout << " " << endl;
                colaLineas.pop();

                if (!colaLineas.empty()) {
                    cout << "Actualmente esta escuchando: " << colaLineas.front() << endl;
                }
                else {
                    cout << "No se esta reproduciendo nada actualmente" << endl;
                }

                char respuesta3;
                cout << " " << endl;
                cout << "Desea seguir viendo la reproduccion actual? (s/n): ";
                cin >> respuesta3;
                if (respuesta3 != 's' && respuesta3 != 'S') {
                    col3 = false;
                }

                system("cls");
                break;
            case 5:
                cout << "Ordenar" << endl;
                cout << " " << endl;

                while (!colaLineas.empty()) {
                    elementos.push_back(colaLineas.front());
                    colaLineas.pop();
                }


                std::sort(elementos.begin(), elementos.end());


                for (const std::string& elemento : elementos) {
                    colaLineas.push(elemento);
                }


                cout << "Cola ordenada:" << endl;
                while (!colaLineas.empty()) {
                    cout << colaLineas.front() << endl;
                    colaLineas.pop();
                }

                char respuesta4;
                cout << " " << endl;
                cout << "Desea seguir viendo la cola? (s/n): ";
                cin >> respuesta4;
                if (respuesta4 != 's' && respuesta4 != 'S') {
                    col4 = false;
                }

                system("cls");
                break;
            case 6:
                cout << "Saliendo del reproductor de musica" << endl;
                return 0;
            default:
                cout << "Opción no válida. Por favor, selecciona una opción válida (1-6)." << endl;
                exit(1);
            }
        }

        return 0;
    
    
}
void lectura() {
    ifstream archivo;
    string texto;
    string s;
    int linea = 0, arr = 0, ay = 0;

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

    archivo.close();
    arr++;

}