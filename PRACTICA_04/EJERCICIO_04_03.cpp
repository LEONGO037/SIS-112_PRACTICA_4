// Materia: Programacion I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creacion: 20/09/2023
// Fecha modificacion: 20/09/2023
// Numero de ejericio: 3
// Problema planteado: Lee por teclado la fecha actual y la fecha de nacimiento de una persona y calcula su edad
#include <iostream>
#include <string>
using namespace std;
// Definición de la estructura para representar a una persona
struct Persona
{
    string nombre;
    int edad;
    float estatura;
    float peso;
};
int main()
{
    Persona personas[12];
    int edadMinima = 100;
    string nombreMenorEdad;
    float sumaEstaturas = 0.0, sumaPesos = 0.0;
    // Leer los datos de las personas
    for (int i = 0; i < 12; i++)
    {
        cout << "Ingrese los datos de la persona " << (i + 1) << ":" << endl;
        cout << "Nombre: ";
        cin >> personas[i].nombre;
        cout << "Edad: ";
        cin >> personas[i].edad;
        cout << "Estatura (en metros): ";
        cin >> personas[i].estatura;
        cout << "Peso (en kilogramos): ";
        cin >> personas[i].peso;
        if (personas[i].edad < edadMinima)
        {
            edadMinima = personas[i].edad;
            nombreMenorEdad = personas[i].nombre;
        }
        sumaEstaturas += personas[i].estatura;
        sumaPesos += personas[i].peso;
    }
    cout << "La persona de menor edad es: " << nombreMenorEdad << endl;
    cout << "El promedio de estaturas es: " << sumaEstaturas / 12 << " metros" << endl;
    cout << "El promedio de pesos es: " << sumaPesos / 12 << " kilogramos" << endl;
    return 0;
}

