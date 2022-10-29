#ifndef LISTAS_HPP_INCLUDED
#define LISTAS_HPP_INCLUDED

template <typename T> struct Nodo
{
  T dato;
  Nodo<T>* sig;
};

template <typename T> struct punteros 
{
  Nodo<T>* primero;
  Nodo<T>* ultimo;
};

template <typename T> void push(T valor, punteros<T> &lista, Nodo<T>* &pila)
{
	Nodo<T>* ultpila = new Nodo<T>;
	ultpila->dato = valor;
	ultpila->sig = lista.ultimo;
    if (lista.primero == nullptr) {
        lista.primero = ultpila;
        lista.ultimo = ultpila;
    }
    else {
        lista.ultimo = ultpila;
        pila = ultpila;
    }
}

template <typename T> void agregar(T valor, punteros<T> &lista, Nodo<T>* &cola)
{
    Nodo<T>* ultcola = new Nodo<T>;
    ultcola->dato = valor;
    ultcola->sig = nullptr;
    if (lista.primero == nullptr) {
        lista.primero = ultcola;
        lista.ultimo = ultcola;
        cola = lista.primero;
    } else {
        lista.ultimo = ultcola;
        Nodo<T>* aux = lista.primero;
        while (aux->sig != nullptr)
            aux = aux->sig;
        aux->sig = lista.ultimo;
    }
}

template <typename T> T pop(punteros<T> &lista, Nodo<T>* &listaN)
{
	if (listaN == nullptr) {
		std::cout << "Error: pop en pila vacia" << std::endl;
		exit(EXIT_FAILURE);
	}
    T valor = listaN->dato;
    Nodo<T>* aux_ult = listaN;
	lista.ultimo = aux_ult->sig;
    listaN = lista.ultimo;
	delete aux_ult;
	return valor;
}

template <typename T> T* buscar_lineal(T clave, Nodo<T>* lista, int (*criterio_pizza)(T, T))
{
    while (lista != nullptr) {
        if (criterio_pizza(lista->dato, clave) == 0)
            return &lista->dato;
        lista = lista->sig;
    }
    return nullptr;
}

template <typename T> void mostrar(Nodo<T>* &lista)
{
    while (lista != nullptr) {
        std::cout<< lista->dato<<std::endl;
        lista = lista->sig;
    }
}

#endif