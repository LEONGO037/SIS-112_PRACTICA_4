// Materia: Programacion I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creacion: 21/09/2023
// Fecha modificacion: 21/09/2023
// Numero de ejericio: 9
// Problema planteado:  A un trabajador se le paga según las horas que trabaja en la semana, una tarifa de
// pago por hora. Si la cantidad de horas trabajadas es mayor a 40, la tarifa se incrementa
// en un 50%. Calcular el salario total del trabajador, además considere que si existe un
// anticipo se debe restar este valor al salario total. Al total debe descontar un 10% para
// el pago de impuestos. Se debe obtener:
// - Total ganado
// - Total descuentos
// - Pago neto
#include<iostream>
using namespace std;
//Funcion que calcula el pago su es mas de 40 horas
void MasDe40 (float &pago);
//Funcion que imprime todo lo pedido en el ejercicio
void Imprimir (float pago, int horas);
//Funcion que ve si hay un anticipo de pago o no
float Anticipo (float &total);
int main ()
{
    float pagoHora;
    int horas;
    cout<<"Ingrese el pago por hora: ";
    cin>>pagoHora;
    cout<<"Ingrese las horas trabajadas: ";
    cin>>horas;
    if(horas>40)
        MasDe40(pagoHora);
    Imprimir(pagoHora, horas);
    return 0;
}
void MasDe40 (float &pago)
{
    pago+=(pago*0.5);
}
void Imprimir (float pago, int horas)
{
    float total=pago*horas;
    cout<<"El total ganado es "<<total<<endl;
    cout<<"El descuento por impuestos del 10% es de "<<total*0.1<<endl;
    total-=(total*0.1);
    float anti=Anticipo(total);
    if(anti>0.0)
        cout<<"El pago neto es "<<total<<" contando el anticipo de "<<anti<<endl;
    else
        cout<<"El pago neto es "<<total<<endl;
}
float Anticipo (float &total)
{
    cout<<"¿Se dio un pago por anticipado?\n"<<"1. Si\n"<<"2. No\n";
    int decicion;
    cin>>decicion;
    if(decicion==1)
    {
        float adelanto;
        cout<<"Ingrese de cuanto fue el adelanto: ";
        cin>>adelanto;
        total-=adelanto;
        return adelanto;
    }
    return 0.0;
}
