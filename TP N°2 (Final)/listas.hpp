#ifndef LISTAS_HPP_INCLUDED
#define LISTAS_HPP_INCLUDED

template <typename T> struct Nodo {
	T dato; // valor que contiene el nodo
	Nodo<T>* sig; // puntero al siguiente nodo
};

template <typename T> struct Lista{
	Nodo<T>* primero = nullptr; //puntero al primer Nodo
	Nodo<T>* ultimo = nullptr; // puntero al ultimo Nodo
};

//PUSH = INSERTAR PRIMERO
template <typename T> void push(Lista<T> &lista, T valor){

	if (lista.primero == nullptr){
		Nodo<T>* nuevo = new Nodo<T>;
		nuevo->dato = valor;
		nuevo->sig = lista.primero;
		lista.primero = nuevo;
		lista.ultimo= nuevo;
	}else{
		Nodo<T>* nuevo = new Nodo<T>;
		nuevo->dato = valor;
		nuevo->sig = lista.primero;
		lista.primero = nuevo;
	}
};

// POP = BORRAR PRIMERO
template <typename T> T pop(Lista<T> &lista)
{
	if (lista.primero == nullptr) {
		std::cout << "Error: pop en pila vacia" << std::endl;
		exit(EXIT_FAILURE);
		//modo no recomendado de terminar, en particular si uso objetos
	}	
		T valor = lista.primero->dato;
		Nodo<T>* aux_elim = lista.primero;
		lista.primero = lista.primero->sig;
		delete aux_elim;
		return valor;
};

//AGREGAR = INSERTAR ULTIMO
template <typename T> void agregar(Lista<T> &lista, T valor)
{
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->dato = valor;
	nuevo->sig = nullptr;
	if (lista.primero == nullptr) {
		lista.primero = nuevo;
		lista.ultimo = lista.primero;
	} else {
		lista.ultimo->sig = nuevo;
		lista.ultimo = lista.ultimo->sig;
	}
};

template <typename T> T* buscar_lineal(T clave, Lista<T> lista, int (*criterio)(T, T))
{
	Nodo<T>* aux = new Nodo<T>;
	aux = lista.primero;
	while (aux != nullptr){
		if (criterio(aux->dato, clave) == 0)
			return &aux->dato;
		aux = aux->sig;
	}
	return nullptr;
};

#endif // LISTAS_HPP_INCLUDED
