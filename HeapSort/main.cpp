#include <iostream>

using namespace std;

void ingresarElementos(int a[], int n);
void mostrarElementos(int a[], int n);
void ordenarElementosHeapSort(int a[], int n);

int main()
{
    int A[100],n;
    cout<<"Ingrese la cantidad de numeros que desea ordenar: ";
    cin>>n;
    ingresarElementos(A,n);
    cout << "Antes de ordenar: ";
    mostrarElementos(A, n);
    ordenarElementosHeapSort(A, n);
    cout << endl;
    cout << "Despues de ordenar: ";
    mostrarElementos(A, n);




    return 0;
}


void ingresarElementos(int a[], int n)
{
    for(int i=1; i<=n; i++)
    {
        cout<<"Elemento"<< " " << i <<": ";
        cin>>a[i];
    }
}

void ordenarElementosHeapSort(int a[], int n)
{
    int j,item,temp,k,i;
    for(k=n; k>0; k--)
    {
        for(i=1; i<=k; i++)
        {
            item=a[i];
            j=i/2;
            while(j>0&&a[j]<item)
            {
                a[i]=a[j];
                i=j;
                j=j/2;
            }
            a[i]=item;
        }
        temp=a[1];
        a[1]=a[k];
        a[k]=temp;
    }
}
void mostrarElementos(int a[], int n)
{
    for(int i=1; i<=n; i++)
    {
        cout << " " << a[i];
    }
}

