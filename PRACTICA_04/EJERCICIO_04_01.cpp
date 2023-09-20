// Materia: Programacion I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creacion: 20/09/2023
// Fecha modificacion: 20/09/2023
// Numero de ejericio: 1
// Problema planteado: Lee por teclado un año y calcula y muestra si es bisiesto
#include <iostream>
using namespace std;
// Función para determinar si un año es bisiesto
bool esBisiesto(int year);
int main()
{
    int anio;
    cout << "Ingrese un anio: ";
    cin >> anio;
    if (esBisiesto(anio))
        cout << anio << " es un anio bisiesto." << endl;
    else
        cout << anio<< " no es un anio bisiesto." << endl;
    return 0;
}
bool esBisiesto(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}
