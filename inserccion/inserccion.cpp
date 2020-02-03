
#include <iostream>

using namespace std;
const int MAX= 50;
typedef int tArreglo[MAX];

void ingresar(tArreglo arreglo, int &contador);
void ordenar(tArreglo arreglo, int contador);
void mostrar(tArreglo arreglo, int contador);


int main()
{
	tArreglo valor;
	int contador = 0;

	ingresar(valor, contador);
	ordenar(valor, contador);
	 mostrar(valor, contador);


    

	return 0;
}

void ingresar(tArreglo arreglo, int &contador)
{
	double numero;
	cout << "Ingrese valores(0 terminar): ";
	cin >> numero;
	while (numero != 0)
	{
		arreglo[contador] = numero;
		contador++;
		cout << "Ingrese valor(0 terminar): ";
		cin >> numero;
	}

}

void ordenar(tArreglo arreglo , int contador)

{
	for (int i = 1; i < contador; i++)
	{
		int pos = i;
		while ((pos > 0) && (arreglo[pos - 1] > arreglo[pos]))
		{
			int temp = arreglo[pos];
			arreglo[pos] = arreglo[pos - 1];
			arreglo[pos - 1] = temp;
			pos--;
		}

		
	}



}

void mostrar(tArreglo arreglo, int contador)
{
	for (int i = 0; i < contador;i++)
	{
		cout << arreglo[i] << "  ";
	}
}

