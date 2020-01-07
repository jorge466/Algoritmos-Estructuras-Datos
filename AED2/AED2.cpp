#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string nombre, apellido;
int edad;
char r;

void pedirDatos();
void mostrarDatos();
string nombrearchivo;
ofstream archivoprueba;
int menu();

int main()

{
	
	cout << "Ingrese el nombre del archivo: ";
	getline(cin, nombrearchivo);
	archivoprueba.open(nombrearchivo.c_str(), ios::out);
	int opcion = menu();

	while (opcion != 0)
	{
		switch (opcion)
		{
		case 1:
			pedirDatos();
			break;

		case 2:
			mostrarDatos();
			break;

		}
		opcion = menu();

	}

	return 0;
}

void pedirDatos()
{
	cin.ignore();
	do
	{
		cout << "\tIngrese el nombre: ";
		getline(cin, nombre, '\n');
		cout << "\tIngrese el apellido: ";
		getline(cin, apellido, '\n');
		cout << "\tIngrese la edad: ";
		cin >> edad;
		archivoprueba << nombre << " " << apellido << " " << edad << endl;
		cout << "Desea ingresar otro contacto? : s/n ";
		cin >> r;
		cin.ignore();
	} while (r == 's');
	archivoprueba.close();
}

void mostrarDatos()
{
	ifstream archivolectura("contactos.txt");
	string texto;

	while (!archivolectura.eof())
	{
		archivolectura >> nombre >> apellido >> edad;

		if (!archivolectura.eof())
		{
			getline(archivolectura, texto);
			cout << "Nombre es: " << nombre << endl;
			cout << "Apellido es: " << apellido << endl;
			cout << "Edad es: " << edad << endl;
		}

	}
	archivolectura.close();

}


int menu()
{
	int op = -1;
	while ((op < 0 || op > 4))
	{
		cout << " 1.- Aniadir informacion " << endl;
		cout << " 2.- Mostrar informacion" << endl;
		cout << " 0.- Salir" << endl;
		cout << " Opcion: " << endl;
		cin >> op;
	}
	return op;

}