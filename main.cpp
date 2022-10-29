#include <iostream>
#include "listas.hpp"

using namespace std;

struct Pizza {
  string gusto;
  int cant;
};

// ============ ENTEROS
int criterio_int(int a, int b)
{
    return a - b;
}

// ============ STRING
int criterio_str(string a, string b)
{
    return (a < b) ? -1 : (a > b);
}

int criterio_pizza(Pizza a, Pizza b)
{
    if (a.gusto == b.gusto)
        return 0;
    else 
        return a.gusto > b.gusto ? 1 : -1;
}

ostream& operator << (ostream &os, Pizza& p)
{
    os << p.gusto << " : " << p.cant;
    return os;
}

int main()
{
    punteros <int> lista;
    Nodo<int>* pila = nullptr;
    lista.primero = pila;
    lista.ultimo = pila;
    push(1, lista, pila);
    push(2, lista, pila);
    push(3, lista, pila);
    Nodo<int>* mostrarlista = lista.ultimo; // si pongo mostrar(lista.ultimo) se desordenan los datos
    mostrar(mostrarlista);
    cout << "El valor del ultimo nodo es : " << lista.ultimo->dato << endl;
    cout << endl << "Eliminamos" << endl;
    while (lista.ultimo != nullptr)
        cout << pop(lista, pila) << endl;
    cout << "fin mostrar pila" << endl;
    if (pila == nullptr)
        cout << "Puntero al ultimo nodo : nullptr" << endl;
    cout << "-----------------" << endl;

    punteros <string> listaS;
    Nodo<string>* cola = nullptr;
    listaS.primero = cola;
    listaS.ultimo = cola;
    agregar("uno"s, listaS, cola);
    agregar("dos"s, listaS, cola);
    agregar("tres"s, listaS, cola);
    cout << endl << "Cola (uno dos tres)" << endl;
    Nodo<string>* mostrarlistaS = listaS.primero;
    mostrar(mostrarlistaS);
    cout << "El valor del ultimo nodo es : " << listaS.ultimo->dato << endl;
    cout << endl << "Eliminamos" << endl;
    while(cola != nullptr)
        cout << pop(listaS, cola) << endl;

    cout << "-----------------" << endl;

    punteros <string> listaN;
    Nodo<string>* colaN = nullptr;
    listaN.primero = colaN;
    listaN.ultimo = colaN;
    agregar("Juan"s, listaN, colaN);
    agregar("Pedro"s, listaN, colaN);
    agregar("María"s, listaN, colaN);
    cout << endl << "Datos para la búsqueda" << endl;
    Nodo<string>* mostrarlistaN = listaN.primero;
    mostrar(listaN.primero);
    string nombre;
    cout << endl << "Ingrese el nombre a buscar: ";
    while (cin >> nombre) {
        if (buscar_lineal(nombre, colaN, criterio_str) != nullptr)
            cout << nombre << " SI está en la lista" << endl;
        else
            cout << nombre << " NO está en la lista" << endl;
        cout << "Ingrese el nombre a buscar: ";
    }

    cin.clear(); // como force EOF debo limpiar los bits de error
    cout << "-----------------" << endl;
    punteros<Pizza> listaP;
    Nodo<Pizza>* colaP = nullptr;
    listaP.primero = colaP;
    listaP.ultimo = colaP;
    agregar({"Muza", 4}, listaP, colaP);
    agregar({"Fugazzeta", 1}, listaP, colaP);
    agregar({"Especial", 3}, listaP, colaP);
    agregar({"Pizzaiola", 2}, listaP, colaP);
    cout << endl << "Pedidos en la lista: " << endl;
    Nodo<Pizza>* MostrarListaP = listaP.primero; // si pongo mostrar(listaP.ultimo) se desordenan los datos
    mostrar(MostrarListaP);
    Pizza pizzaClave;
    Pizza *ptrPizza;
    cout << endl << "Ingrese el gusto a buscar: ";
    while (cin >> pizzaClave.gusto) {
        ptrPizza = buscar_lineal(pizzaClave, listaP.primero, criterio_pizza);
        if (ptrPizza != nullptr)
            cout << pizzaClave.gusto << " SI esta en la lista ==> " << *ptrPizza << endl;
        else
            cout << pizzaClave.gusto << " NO esta en la lista" << endl;
        cout << "Ingrese el nombre a buscar: ";
    }
}