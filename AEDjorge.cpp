#include <iostream>
#include <ctime>
#include<stdlib.h>
#include <fstream>

using namespace std;

const int N = 100;
ofstream archivo;
string nombreA;

struct Nodo
{
	int dato;
	Nodo* derecho;
	Nodo* izquierdo;
};

Nodo* creatNodoPadresHijo(int n);
Nodo* arbolbinario = NULL;

void insertarNodosEnArbolBinario(Nodo*& arbolbinario, int n);
void mostrarArbolBinario(Nodo*& arbolbinario, int separador);
void preOrden(Nodo*& arbolbinario);
void inOrden(Nodo*& arbolbinario);
void posOrden(Nodo*& arbolbinario);

int main()
{

	int n;
	for (int i = 0; i < 9; i++)
	{
		cout << "insertar nodos:" << endl;
		cin >> n;
		insertarNodosEnArbolBinario(arbolbinario, n);
	}
	mostrarArbolBinario(arbolbinario, 0);
	cout << endl;
	cout << "recorrido pre:" << endl;
	preOrden(arbolbinario);
	cout << endl;
	cout << "recorrido in:" << endl;
	inOrden(arbolbinario);
	cout << endl;
	cout << "recorrido pos:" << endl;
	posOrden(arbolbinario);
	cout << endl;



	return 0;


}

Nodo* crearNodoPadresHijo(int n)
{
	Nodo* nuevo = new Nodo();
	nuevo->dato = n;
	nuevo->derecho = NULL;
	nuevo->izquierdo = NULL;

	return nuevo;
}

void insertarNodosEnArbolBinario(Nodo*& arbolbinario, int n)
{
	if (arbolbinario == NULL)
	{
		Nodo* nuevo = crearNodoPadresHijo(n);
		arbolbinario = nuevo;
	}
	else {
		int datoRaiz = arbolbinario->dato;
		if (n < datoRaiz)
		{
			insertarNodosEnArbolBinario(arbolbinario->izquierdo, n);
		}
		else {
			insertarNodosEnArbolBinario(arbolbinario->derecho, n);
		}
	}
}

void mostrarArbolBinario(Nodo*& arbolbinario, int separador)
{
	if (arbolbinario == NULL)
	{
		return;
	}
	else
	{
		mostrarArbolBinario(arbolbinario->derecho, separador + 1);
		for (int i = 0; i < separador; i++)
		{
			cout << "  ";
		}
		cout << arbolbinario->dato << endl;
		mostrarArbolBinario(arbolbinario->izquierdo, separador + 1);
	}
}

void preOrden(Nodo*& arbolbinario)
{
	if (arbolbinario == NULL)
	{
		return;
	}
	else {
		cout << arbolbinario->dato << "-";
		preOrden(arbolbinario->izquierdo);
		preOrden(arbolbinario->derecho);
	}
}

void inOrden(Nodo*& arbolbinario)
{
	if (arbolbinario == NULL)
	{
		return;
	}
	else {
		preOrden(arbolbinario->izquierdo);
		cout << arbolbinario->dato << "-";
		preOrden(arbolbinario->derecho);

	}
}

void posOrden(Nodo*& arbolbinario)
{
	if (arbolbinario == NULL)
	{
		return;
	}
	else {
		preOrden(arbolbinario->izquierdo);
		preOrden(arbolbinario->derecho);
		cout << arbolbinario->dato << "-";

	}
}