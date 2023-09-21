// Materia: Programacion I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creacion: 21/09/2023
// Fecha modificacion: 21/09/2023
// Numero de ejericio: 11
// Problema planteado: Realice una función que enviándole dos numero calcule el máximo común divisor con el algoritmo de Euclides.
#include <iostream>
using namespace std;
// Funcion para calcular el maximo comun divisor usando el algoritmo de Euclides
int Euclides(int num1, int num2);
int main()
{
    int numero1, numero2;
    cout<<"Ingrese los 2 numeros de los que desea obtener el maximo comun divisor"<<endl;
    cin>>numero1>>numero2;
    int mcd=Euclides(numero1, numero2);
    cout<<"El maximo comun divisor es "<<mcd<<endl;
}
int Euclides(int num1, int num2)
{
    while (num2 != 0)
    {
        int auxiliar = num2;
        num2 = num1 % num2;
        num1 = auxiliar;
    }
    return num1;
}
