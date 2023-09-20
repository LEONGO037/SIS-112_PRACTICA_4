// Materia: Programacion I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creacion: 20/09/2023
// Fecha modificacion: 20/09/2023
// Numero de ejericio: 13
// Problema planteado: Una empresa efectúa el control de asistencia de sus empleados mediante un lector biométrico, el horario
// en la entrada es a las 8:00 a.m y la salida es a las 16:00 p.m. El empleado tiene una tolerancia de 10 minutos en la entrada, si
// llega más allá de los 10 minutos de tolerancia se penaliza todos los minutos de atraso (es decir si llega a las 8:12 se penalizan
// los 12 minutos). De igual forma no puede salir antes del horario establecido en la salida, (si lo hace se penaliza los minutos
// faltantes), pero si el empleado entra antes o sale después de sus horarios el sistema solo toma en cuenta las 8 horas laborales de trabajo.
#include <iostream>
#include <vector>
#include<iomanip>
using namespace std;
// Estructura para representar los datos de un empleado
struct Empleado
{
    string codigo;
    int horaEntrada;
    int minutoEntrada;
    int horaSalida;
    int minutoSalida;
    int penalizacion;
};
// Función para calcular la penalización de un empleado
void calcularPenalizacion(Empleado &empleado);
int main()
{
    int numEmpleados;
    cout << "Ingrese el numero de empleados: ";
    cin >> numEmpleados;
    vector<Empleado> empleados(numEmpleados);
    for (int i = 0; i < numEmpleados; ++i)
    {
        cout << "Ingrese los datos del empleado " << (i + 1) << ":" << endl;
        cin.ignore(); // Limpia el buffer del teclado
        cout << "Codigo: ";
        getline(cin, empleados[i].codigo);
        cout << "Hora de entrada: ";
        cin >> empleados[i].horaEntrada;
        cout << "Minuto de entrada: ";
        cin >> empleados[i].minutoEntrada;
        cout << "Hora de salida: ";
        cin >> empleados[i].horaSalida;
        cout << "Minuto de salida: ";
        cin >> empleados[i].minutoSalida;
        calcularPenalizacion(empleados[i]);
    }
    cout << "Codigo Empleado   Penalizacion            Fecha" << endl;
    for (const Empleado &empleado : empleados)
        cout << empleado.codigo << setw(15) << empleado.penalizacion << " minutos" <<setw(20)<<"12/01/2011" << endl;
    return 0;
}
void calcularPenalizacion(Empleado &empleado)
{
    const int horaEntradaEsperada = 8;
    const int horaSalidaEsperada = 16;
    const int toleranciaEntrada = 10;
    const int minutosPorHora = 60;
    empleado.penalizacion = 0;
    // Verificar la hora de entrada
    if (empleado.horaEntrada > horaEntradaEsperada)
        empleado.penalizacion += (horaEntradaEsperada - empleado.horaEntrada) * minutosPorHora + empleado.minutoEntrada;
    else if (empleado.horaEntrada == horaEntradaEsperada && empleado.minutoEntrada > toleranciaEntrada)
        empleado.penalizacion += empleado.minutoEntrada;
    // Verificar la hora de salida
    if (empleado.horaSalida < horaSalidaEsperada)
        empleado.penalizacion += (horaSalidaEsperada - empleado.horaSalida) * minutosPorHora + empleado.minutoSalida;
}
