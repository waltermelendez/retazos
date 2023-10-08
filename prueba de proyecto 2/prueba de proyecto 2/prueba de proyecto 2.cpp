#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <cstdlib>
#include <algorithm>


using namespace std;


void agregarLinea(queue<string>& colaLineas, const string& linea) {
    colaLineas.push(linea);

    cout << "Cancion agregada a la cola: " << linea << endl;
}

void lectura(queue<string>& colaLineas) {
    ifstream archivo;
    string s;

    cout << " " << endl;
    cout << "Nota: Ingrese la ubicacion del archivo .txt" << endl;
    cout << " " << endl;
    cout << "Ejemplo: /ruta/a/tu/archivo.txt" << endl;
    cout << " " << endl;
    cout << "Ingrese la ubicacion del archivo: ";

    cin.ignore();
    getline(cin, s);

    archivo.open(s.c_str(), ios::in);
    if (archivo.fail()) {
        cout << "El CD no existe" << endl;
        return;
    }

    string texto;
    int linea = 0;

    system("cls");
    cout << "Contenido del CD:" << endl;
    cout << " " << endl;
    while (getline(archivo, texto)) {
        linea++;
        cout << linea << ": " << texto << endl;
    }

    cout << " " << endl;
    cout << "Ingrese el numero de la cancion que desea agregar: ";
    int numeroLinea;
    cin >> numeroLinea;

    archivo.clear();  // Restablecer el estado del archivo
    archivo.seekg(0); // Volver al principio del archivo

    for (int i = 0; i < numeroLinea - 1; i++) {
        getline(archivo, texto);
    }

    getline(archivo, texto);

    system("cls");
    cout << " " << endl;
    cout << "Cancion seleccionada: " << texto << endl;
    cout << " " << endl;
    agregarLinea(colaLineas, texto); // Agregar la línea seleccionada a la cola

    cout << " " << endl;
    cout << "Canciones subidas: " << linea << endl;
    cout << " " << endl;
    cout << "Ubicacion del archivo: " << s << endl;
    cout << " " << endl;

    archivo.close();
}


int main() {
    std::vector<std::string> elementos;
    queue<string> colaLineas;

    int opcion, op;
    bool ver = false;



    cout << "Bienvenido al Reproductor de Musica :)" << endl;
    cout << " " << endl;


    while (true) {
        bool col = true;
        bool col2 = true;
        bool col3 = true;
        bool col4 = true;

        cout << "Menu de opciones:" << endl;
        cout << " " << endl;
        cout << "1. Agregar Cancion" << endl;
        cout << "2. Ver Cola de Reproduccion" << endl;
        cout << "3. Reproduccion Actual" << endl;
        cout << "4. Siguiente Reproduccion" << endl;
        cout << "5. Ordenar" << endl;
        cout << " " << endl;
        cout << "6. Salir del reproductor" << endl;

        cout << " " << endl;

        cout << "Selecciona una opcion (1-6): ";
        cout << " " << endl;
        cin >> opcion;

        switch (opcion) {

        case 1:
            system("cls");
            cout << "Agregar Cancion" << endl;
            cout << " " << endl;

            cout << "Seleccione la carpeta donde se encuentran sus CDs:\n";
            cout << " " << endl;
            cout << "1.Documentos\n";
            cout << "2.Descargas\n";
            cout << "3.Carpeta no seleccionada\n";
            cout << " " << endl;
            cout << "Escriba el numero de opcion (1-3): ";
            cin >> op;

            system("cls");
            if (op == 1) {
                //puede dar fallo segun el idioma del usuario
                system(" start %USERPROFILE%\\Documents");

                cout << "Copie la dirreccion del documento en el siguiente espacio\n";

            }
            else if (op == 2) {

                cout << "Copie la dirreccion del documento en el siguiente espacio\n";
                system("start  %USERPROFILE%\\Downloads");

            }

            else if (op == 3) {
                system("start %USERPROFILE%");
                cout << "Copie la dirreccion del documento en el siguiente espacio\n";

            }
            else {
                cout << "Carpeta desconocida\n";
            }


            lectura(colaLineas);




            break;
        case 2:
            system("cls");
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
            colaLineas.push(colaLineas.front());
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
            cout << " " << endl;

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
            cout << "Opcion no valida. Por favor, selecciona una opcion valida (1-6)." << endl;
            exit(1);
        }
    }

    return 0;


}
