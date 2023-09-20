// Materia: Programacion I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creacion: 20/09/2023
// Fecha modificacion: 20/09/2023
// Numero de ejericio: 6
// Problema planteado: Escriba un programa que mediante una función determine el pago por el servicio de
// estacionamiento de coches en un parqueo, teniendo en cuenta que la primera hora de estadía se paga 8 Bs.,
// y las restantes 3 Bs. c/hora. Si el uso del servicio es menor a una hora se cobra por la hora y de igual manera
// si excede la hora se cobra por la hora siguiente.
#include <iostream>
using namespace std;
// Función para calcular el pago por el servicio de estacionamiento
int calcularPagoEstacionamiento(int horaEntrada, int minutoEntrada, int horaSalida, int minutoSalida);
int main()
{
    int horaEntrada, minutoEntrada, horaSalida, minutoSalida;
    cout<<"Hora de entrada: ";
    cin>>horaEntrada;
    cout<<"Minuto de entrada: ";
    cin>>minutoEntrada;
    cout<<"Hora de salida: ";
    cin>>horaSalida;
    cout<<"Minuto de salida: ";
    cin>>minutoSalida;
    int pago = calcularPagoEstacionamiento(horaEntrada, minutoEntrada, horaSalida, minutoSalida);
    int horas, aux;
    aux=pago-8;
    horas=(aux/3)+1;
    cout<<"Horas: "<<horas<<endl;
    cout << "Pago: " << pago << " Bs." << endl;
    return 0;
}
int calcularPagoEstacionamiento(int horaEntrada, int minutoEntrada, int horaSalida, int minutoSalida)
{
    const int tarifaPrimeraHora = 8;
    const int tarifaHoraAdicional = 3;
    int tiempoEstadia = 0;
    if (horaSalida > horaEntrada || (horaSalida == horaEntrada && minutoSalida >= minutoEntrada))
        tiempoEstadia = (horaSalida - horaEntrada) * 60 + ((60 - minutoEntrada) + minutoSalida);
    else
        tiempoEstadia = 60;
    // Calcular el pago
    int pago = tarifaPrimeraHora;
    if (tiempoEstadia > 60)
    {
        int horasAdicionales = (tiempoEstadia - 60) / 60;
        pago += horasAdicionales * tarifaHoraAdicional;
    }
    return pago;
}
