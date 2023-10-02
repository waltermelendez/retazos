

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
NODO* lista = NULL;
int main()
{
   
    
   
    menu();
    
    return 0;
}
void menu() {
    int op,d;
    do
    {
        cout << "menu\n";
        cout << "insertar datos\n";
        cout << "mostrar los elementos de la lsita\n";
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
        default:
            exit(1);
           
        }
        system("cls");
    } while (op!=3);
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
    while (actual!=NULL)
    {
        cout << actual->dato << " -> \n ";
       actual= actual->siguiente;
    }
}
