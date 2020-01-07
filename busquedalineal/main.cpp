#include <iostream>
#include <fstream>

using namespace std;

void ingresar(int a[], int n);
void buscar(int a[], int n);
void mostrar(int a[], int n);
int dato, n;


int main()
{

    cout << "Ingrese el tamanio del arreglo: ";
    cin >> n;
    int arreglo1[n];
    ingresar(arreglo1, n);
    cout << "Ingrese el valor a buscar: ";
    cin >> dato;
    mostrar(arreglo1, n);
    cout << endl;
    buscar(arreglo1, n);


    return 0;
}
void ingresar(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void buscar(int a[], int n)
{
    bool c = false;
    ofstream archivoprueba;
    string nombrearchivo;
    cin.ignore();
    cout << "Ingrese el nombre del archivo: ";
    getline(cin,nombrearchivo);
    archivoprueba.open(nombrearchivo.c_str(), ios::out);
    for (int i = 0; i < n; i++)
    {
        if(a[i] == dato)
        {
            cout << "Elemento encontrado"<< endl;
            cout << "En la posicion:" << i + 1 ;
            archivoprueba << "Elemento encontrado" << endl;
            archivoprueba << "En la posicion: " << i + 1 << endl;
            c = true;
        }
    }
    if(c == false)
    {
        cout <<"No existe";
        archivoprueba << "No existe" << endl;
    }

     archivoprueba << "Los elementos del arreglo son: ";
for (int i = 0; i < n; i++)
    {

     archivoprueba <<" " << a[i] << " ";
    }
}

void mostrar(int a[], int n)
{
    cout << "Los elementos del arreglo son: ";

for (int i = 0; i < n; i++)
    {
        cout << " " << a[i] << " ";

    }
}
