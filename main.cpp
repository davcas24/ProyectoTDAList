#include <iostream>
#include <cstdlib>
#include "tdalist.h"
#include "linkedlist.h"
#include "integer.h"
#include "FSArraylist.h"
#include "cursorlist.h"

using namespace std;

/*
* Programa de Prueba para el TDALista implementado con LinkedList
* -- Listas Doblemente Enlazadas --
* Se prueban las siguientes operaciones:
*  - Inserción
*  - Eliminación
*  - Listado
*  - Búsqueda
*/


int menu();

int main(int argc, char *argv[])
{
    // En el caso de que quisieramos utilizar otra implementación
    // SÓLO se tendría que cambiar esta línea.
    //TDAList* lista = new LinkedList();
    Integer* intTemp;
    TDAList* list = new CursorList(10);
    int val, pos;
    bool flag = true;
    list->insert(new Integer(0), 0);
    list->insert(new Integer(1), 1);
    list->insert(new Integer(2), 2);
 	/*
    list->insert(new Integer(3), 3);
    list->insert(new Integer(4), 4);
    list->insert(new Integer(5), 5);
    list->insert(new Integer(6), 6);
    */	
    while (flag)
    {
    	cout<<list->getCapacity()<<endl;
        switch(menu())
        {
           case 1:
               cout << "Valor a Insertar: " ;
               cin >> val;
               cout << "Posicion a Insertar: ";
               cin >> pos;
               if (list->insert(new Integer(val), pos))
                  cout << "Exito en la Insercion" << endl;
               else
                  cout << "Fracaso en la Insercion" << endl;
               break;
           case 2:
               cout << "Posicion de la que quiere Borrar: ";
               cin >> pos;
               if (list->erase(pos))
                  cout << "Exito en el Borrado" << endl;
               else
                  cout << "Fracaso en el Borrado" << endl;
               break;
           case 3:
               list->print();
               break;
           case 4:
               cout << "Valor del Elemento a Buscar: ";
               cin >> val;
               intTemp = new Integer(val);
               pos = list->indexOf(intTemp);
               delete intTemp;
               cout << "El Elemento esta en la posicion = " << pos << endl;
               break;
           case 9:
               flag = false;
        }
    }
    delete list;

    return 0;
}
int menu()
{
    cout << "1. Insertar "  << endl;
    cout << "2. Borrar "  << endl;
    cout << "3. Listar " << endl;
    cout << "4. Buscar " << endl;
    cout << "9. Salir " << endl;
    cout << endl << "Opcion? ";
    int opcion;
    cin >> opcion;
    return opcion;
}
