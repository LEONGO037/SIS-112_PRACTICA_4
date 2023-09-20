// Materia: Programacion I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creacion: 20/09/2023
// Fecha modificacion: 20/09/2023
// Numero de ejericio: 4
// Problema planteado: Escribir el programa para solicitar al usuario N calificaciones comprendidas en el rango
// de 1 a 100, calcular y presentar la sumatoria y promedio de estas N calificaciones. La
// entrada de valores es para las calificaciones, debe hacerlo mediante una función.
#include <iostream>
#include <vector>
using namespace std;
// Funcion para ingresar las calificaciones
vector<int> ingresarCalificaciones(int N);
int main()
{
    int N;
    cout << "Ingrese el numero de calificaciones: ";
    cin >> N;
    vector<int> calificaciones = ingresarCalificaciones(N);
    float sumatoria = 0.0;
    for (int i = 0; i < N; ++i)
        sumatoria += calificaciones[i];
    cout << "La sumatoria de las calificaciones es: " << sumatoria << endl;
    cout << "El promedio de las calificaciones es: " << sumatoria / N << endl;
    return 0;
}
vector<int> ingresarCalificaciones(int N)
{
    vector<int> calificaciones;
    for (int i = 0; i < N; ++i)
    {
        int calificacion;
        do
        {
            cout << "Ingrese la calificacion " << (i + 1) << " (entre 1 y 100): ";
            cin >> calificacion;
        } while (calificacion < 1 || calificacion > 100);

        calificaciones.push_back(calificacion);
    }
    return calificaciones;
}

