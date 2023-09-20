// Materia: Programacion I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creacion: 20/09/2023
// Fecha modificacion: 20/09/2023
// Numero de ejericio: 7
// Problema planteado: Escribir un programa que lea el salario de un empleado y mediante una función
// efectué un incremento salarial en base a la siguiente escala:
// • Si el salario es menor < 1000 Bs. incremente en un 20%
// • Si el salario es mayor o igual a 1000 pero es menor a 3000 Bs. Incremente en un 15%
// • Si el salario es mayor o igual a 3000 pero es menor a 6000 Bs. Incremente en un 10%
// • Si el salario es mayor o igual a 6000 Bs. Incremente en un 5%
// La función debe obtener el incremento y el nuevo salario.
#include<iostream>
using namespace std;
//Funcion que obtiene el nuevo salario
void Incremento(float salario, int porcentaje);
int main ()
{
    float salario;
    cout<<"Ingrese el salario del empleado: ";
    cin>>salario;
    if(salario<1000)
        Incremento(salario, 20);
    else if (salario>=1000 && salario<3000)
        Incremento(salario, 15);
    else if (salario>=3000 && salario<6000)
        Incremento(salario,10);
    else if (salario>=6000)
        Incremento(salario, 5);
    return 0;
}
void Incremento(float salario, int porcentaje)
{
    salario+=(salario*(porcentaje/100.0));
    cout<<"El incremento es del "<<porcentaje<<"%"<<endl;
    cout<<"El nuevo salario es "<<salario<<endl;
}

