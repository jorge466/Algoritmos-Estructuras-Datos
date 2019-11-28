#include <iostream>

using namespace std;

const int arreglo2 = 5;
typedef int tFuncion[arreglo2];
tFuncion numero;
void secuencia();

int main()
{
    numero;
   for(int i = 0; i < arreglo2; i++)
   {
     cout << "Ingrese los valores: ";
     cin >> numero[i];
   }
    secuencia();

}

void secuencia()
{
    int aux, min;

    for(int i = 0; i < arreglo2; i++)
    {
        min = i;
        for(int j = i + 1; j < arreglo2; j++)
        {
            if(numero[j] < numero[min])
            {
                min = j;
            }
        }
        aux = numero[i];
        numero[i] = numero[min];
        numero[min]= aux;
    }

    for(int i = 0; i < 5; i++)
    {
        cout << numero[i];
    }

}


