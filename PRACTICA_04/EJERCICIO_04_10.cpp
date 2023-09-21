// Materia: Programacion I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creacion: 21/09/2023
// Fecha modificacion: 21/09/2023
// Numero de ejericio: 10
// Problema planteado:  Construir las funciones para ordenar un vector de N elementos aleatorios y los ordene por.
// • Por selección
// • Por inserción
// • Por el método burbuja
// • Por el método Shell
// • Por QuickSort
#include<iostream>
#include<vector>
#include<random>
#include<cstdlib>
#include<ctime>
using namespace std;
//Funcion que muestra el vector
void Mostrar(vector<int> ar);
//Funcion que ordena por burbuja
vector<int> Burbuja (vector<int>& are);
//Funcion que ordena por insersion
vector<int> Insersion (vector<int>& are);
//Funcion que ordena por seleccion
vector<int> Seleccion (vector<int>& Arreglo);
//Funcion que ordena por sell
vector<int> Shell (vector<int> &arr);
//Funciones que ordenan por QuickSort
void QuickSort (vector<int>&are, int inicio, int final);
int Particion (vector<int>&are, int inicio, int final);
int main ()
{
    int N;
    cout<<"Ingrese la longitud del vector: ";
    cin>>N;
    srand(time(0));
    vector<int> Arreglo(N);
    for(int i=0;i<N;i++)
        Arreglo[i]=rand()%(100-1)+1;
    cout<<"El vector es:\n";
    Mostrar(Arreglo);
    int eleccion;
    cout<<"Ingrese por que metodo desea ordenar\n"<<"1. Seleccion\n"<<"2. Insercion\n"<<"3. Metodo Burbuja\n"<<"4. Metodo Shell\n"<<"5. QuickSort\n";
    cin>>eleccion;
    switch(eleccion)
    {
    case 1:
        Seleccion(Arreglo);
        break;
    case 2:
        Arreglo=Insersion(Arreglo);
        break;
    case 3:
        Burbuja(Arreglo);
        break;
    case 4:
        Arreglo=Shell(Arreglo);
        break;
    case 5:
        QuickSort(Arreglo,0,Arreglo.size()-1);
        break;
    default:
        cout<<"Ningun metodo seleccionado\n";
        break;
    }
    cout<<"El vector ordenado es:\n";
    Mostrar(Arreglo);
    return 0;
}
void Mostrar(vector<int> ar)
{
    for(int i=0;i<ar.size();i++)
        cout<<ar[i]<<" ";
    cout<<"\n";
}
vector<int> Burbuja (vector<int>& are)
{
    for(int i=0;i<are.size();i++)
    {
        for(int j=0;j<are.size()-1-i;j++)
        {
            if(are[j]>are[j+1])
            {
                int aux=are[j];
                are[j]=are[j+1];
                are[j+1]=aux;
            }
        }
    }
}
vector<int> Insersion (vector<int>& are)
{
    vector<int> ordenado;
    ordenado.push_back(are[0]);
    for(int i=1;i<are.size();i++)
    {
        int posi=0;
        for(int j=0;j<ordenado.size();j++)
        {
            if(are[i]>ordenado[j])
                posi++;
        }
        if(posi==ordenado.size())
            ordenado.push_back(are[i]);
        else
        {
            std::vector<int>::iterator posicion = ordenado.begin() + posi;
            ordenado.insert(posicion, are[i]);
        }
    }
    return ordenado;
}
vector<int> Seleccion (vector<int>& Arreglo)
{
    for(int i=0;i<Arreglo.size();i++)
    {
        int mini=100,posi;
        for(int j=i;j<Arreglo.size();j++)
        {
            if(Arreglo[j]<mini)
            {
                mini=Arreglo[j];
                posi=j;
            }
        }
        swap(Arreglo[i],Arreglo[posi]);
    }
}
vector<int> Shell (vector<int>& arr)
{
    int n = arr.size();
    bool band;
    while(n>1)
    {
        n/=2;
        band=true;
        while(band==true)
        {
            band=false;
            for(int i=0;i+n<=arr.size();i++)
            {
                if(arr[i]>arr[i+n])
                {
                    int aux=arr[i];
                    arr[i]=arr[i+n];
                    arr[i+n]=aux;
                    band=true;
                }
            }
        }
    }
    return arr;
}
void QuickSort (vector<int>&are, int inicio, int fin)
{
    if(inicio<fin)
    {
        int pivote=Particion(are, inicio, fin);
        QuickSort(are, inicio, pivote-1);
        QuickSort(are, pivote, fin);
    }
}
int Particion (vector<int>&are, int inicio, int fin)
{
    int pivote=are[fin];
    int i=fin-1;
    for(int j=i;j>=inicio;j--)
    {
        if(are[j]>pivote)
        {
            swap(are[i],are[j]);
            i--;
        }
    }
    swap(are[fin], are[i+1]);
    return i+1;
}


