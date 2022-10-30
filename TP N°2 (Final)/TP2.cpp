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

// ============ Pizza buscando por GUSTO
int criterio_pizza(Pizza a, Pizza b)
{
	if (a.gusto == b.gusto)
		return 0;
	else
		return a.gusto > b.gusto ? 1 : -1;
}

template <typename T> void mostrar(Lista<T> lista)
{
	Nodo<T>* aux = new Nodo<T>;
	aux = lista.primero;
	while (aux != nullptr){
        cout << aux->dato << endl;
	    aux = aux->sig;
	}
};

ostream& operator << (ostream &os, Pizza& p)
{
	os << p.gusto << " : " << p.cant;
	return os;
}

int main(){
    
	Lista<int> pila;
	pila.primero = nullptr;
	pila.ultimo = nullptr;
	push(pila, 1);
	push(pila, 2);
	push(pila, 3);
	cout << "Pila (1 2 3)" << endl;
	mostrar(pila);

	cout << endl << "Eliminamos" << endl;
	while (pila.primero != nullptr)
		cout << pop(pila) << endl;
	cout << endl << "Confirmamos pila vacía:" << endl;
	mostrar(pila);
	cout << "fin mostrar pila" << endl;
	cout << "-----------------" << endl;

	Lista<string> cola;
	cola.primero = nullptr;
	cola.ultimo = nullptr;
	agregar(cola, "uno"s);
	agregar(cola, "dos"s);
	agregar(cola, "tres"s);
	cout << endl << "Cola (uno dos tres)" << endl;
	mostrar(cola);
	cout << endl << "Eliminamos" << endl;
	while (cola.primero != nullptr)
		cout << pop(cola) << endl;
	cout << endl << "Confirmamos cola vacía:" << endl;
	mostrar(cola);
	cout << "fin mostrar cola" << endl;
	cout << "-----------------" << endl;

	agregar(cola,  "Juan"s);
	agregar(cola,  "Pedro"s);
	agregar(cola, "Maria"s);
	cout << endl << "Datos para la búsqueda" << endl;
	mostrar(cola);
	string nombre;

	bool si {true};
	do{
		cout << endl << "Ingrese el nombre a buscar: ";
		cin >> nombre;
		if (buscar_lineal(nombre, cola, criterio_str) != nullptr)
			cout << nombre << " SI está en la lista" << endl;
		else
			cout << nombre << " NO está en la lista" << endl;
		cout << "Queres buscar a ptra persona? 1/si 0/no";
		cin >> si;
	}while(si);

	cout << endl << "-----------------" << endl;

	Lista<Pizza> lista;
	lista.primero = nullptr;
	lista.ultimo = nullptr;
	agregar(lista,  {"Muza", 4});
	agregar(lista,  {"Fugazzeta", 1});
	agregar(lista,  {"Especial", 3});
	agregar(lista,  {"Pizzaiola", 2});
	cout << endl << "Pedidos en la lista:" << endl;
	mostrar(lista);
	Pizza pizzaClave;
	Pizza *ptrPizza;
	cout << endl << "Ingrese el gusto a buscar: ";
	while (cin >> pizzaClave.gusto) {
		ptrPizza = buscar_lineal(pizzaClave, lista, criterio_pizza);
		if (ptrPizza != nullptr)
			cout << pizzaClave.gusto << " SI está en la lista ==> " << *ptrPizza << endl;
		else
			cout << pizzaClave.gusto << " NO está en la lista" << endl;
		cout << "Ingrese el nombre a buscar: ";
	}
	return EXIT_SUCCESS;
}


    