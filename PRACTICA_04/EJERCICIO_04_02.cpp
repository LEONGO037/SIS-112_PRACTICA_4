// Materia: Programacion I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creacion: 20/09/2023
// Fecha modificacion: 20/09/2023
// Numero de ejericio: 2
// Problema planteado: Lee por teclado la fecha actual y la fecha de nacimiento de una persona y calcula su edad
#include <iostream>
using namespace std;
// Funcion para calcular la edad a partir de la fecha de nacimiento y la fecha actual
int calcularEdad(int anioNacimiento, int mesNacimiento, int diaNacimiento, int anioActual, int mesActual, int diaActual);
int main()
{
    int anioNacimiento, mesNacimiento, diaNacimiento;
    int anioActual, mesActual, diaActual;
    cout << "Ingrese el anio de nacimiento: ";
    cin >> anioNacimiento;
    cout << "Ingrese el mes de nacimiento (1-12): ";
    cin >> mesNacimiento;
    cout << "Ingrese el dia de nacimiento (1-31): ";
    cin >> diaNacimiento;
    cout << "Ingrese el anio actual: ";
    cin >> anioActual;
    cout << "Ingrese el mes actual (1-12): ";
    cin >> mesActual;
    cout << "Ingrese el dia actual (1-31): ";
    cin >> diaActual;
    int edad = calcularEdad(anioNacimiento, mesNacimiento, diaNacimiento, anioActual, mesActual, diaActual);
    cout << "La edad actual es " << edad << " anios" <<endl;
    return 0;
}
int calcularEdad(int anioNacimiento, int mesNacimiento, int diaNacimiento, int anioActual, int mesActual, int diaActual)
{
    int edad = anioActual - anioNacimiento;
    if (mesActual < mesNacimiento || (mesActual == mesNacimiento && diaActual < diaNacimiento))
        edad--;
    return edad;
}
