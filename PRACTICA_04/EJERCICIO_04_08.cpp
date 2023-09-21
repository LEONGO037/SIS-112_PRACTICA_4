// Materia: Programacion I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creacion: 20/09/2023
// Fecha modificacion: 20/09/2023
// Numero de ejericio: 8
// Problema planteado: En una fábrica de computadoras se planea ofrecer a los clientes un descuento que
// dependerá del número de computadoras que compre. Si las computadoras son menos de
// cinco se les dará un 10% de descuento sobre el total de la compra; si el número de
// computadoras es mayor o igual a cinco pero menos de diez se le otorga un 20% de
// descuento; y si son 10 o más se les da un 40% de descuento. El precio de cada
// computadora es un valor que el usuario ingrese desde el teclado. Se debe obtener el
// precio total que el cliente debe pagar y el valor del descuento.
#include<iostream>
using namespace std;
//Funcion que calcula el descuento
void Descuento(float total, int porcentaje);
int main ()
{
    int cantidad;
    cout<<"Ingrese la cantidad de computadoras que compro: ";
    cin>>cantidad;
    float computadora[cantidad];
    float suma=0.0;
    for(int i=0;i<cantidad;i++)
    {
        cout<<"Ingrese el precio de la computadora "<<i+1<<": ";
        cin>>computadora[i];
        suma+=computadora[i];
    }
    if(cantidad<5)
        Descuento(suma, 10);
    else if (cantidad>=5 && cantidad<10)
        Descuento(suma, 20);
    else if (cantidad>=10)
        Descuento(suma, 40);
}
void Descuento(float total, int porcentaje)
{
    cout<<"El total a pagar es de "<<total<<endl;
    float descuento=total*(porcentaje/100.0);
    cout<<"El "<<porcentaje<<"% del total es "<<descuento<<endl;
    total-=descuento;
    cout<<"El total a pagar con un "<<porcentaje<<"% de descuento es "<<total<<endl;
}
