// Materia: Programacion I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creacion: 20/09/2023
// Fecha modificacion: 20/09/2023
// Numero de ejericio: 5
// Problema planteado: Elabore un programa para registro académico de la UCB, que solicite el nombre de una
// materia, el paralelo, el docente y sus correspondientes notas de periodo. Al final, se
// muestra la nota final y si aprobó o reprobo el curso. (realizar con estructuras)
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Definicion de la estructura para representar una materia y sus notas de periodo
struct Materia {
    string nombre;
    int paralelo;
    string docente;
    float parcial1;
    float parcial2;
    float examenFinal;
    float notaFinal;
    bool aprobado;
};
// Funcion para calcular la nota de habilitacion
void calcularNotaFinal(Materia &materia);
// Funcion que calcula si aprobo o no
void Aprobado(Materia &materia);
int main()
{
    int numMaterias;
    cout << "Ingrese el numero de materias: ";
    cin >> numMaterias;
    vector<Materia> materias(numMaterias);
    for (int i = 0; i < numMaterias; ++i) {
        cout << "Ingrese los datos de la materia " << (i + 1) << ":" << endl;
        cout << "Nombre de la materia: ";
        cin.ignore();
        getline(cin, materias[i].nombre);
        cout << "Paralelo: ";
        cin>> materias[i].paralelo;
        cout << "Docente: ";
        cin.ignore();
        getline(cin, materias[i].docente);
        cout << "Nota del primer parcial: ";
        cin >> materias[i].parcial1;
        cout << "Nota del segundo parcial: ";
        cin >> materias[i].parcial2;
        calcularNotaFinal(materias[i]);
        if (materias[i].aprobado)
        {
            cout << "Nota del examen final: ";
            cin >> materias[i].examenFinal;
        }
        else
            materias[i].examenFinal=0;
    }
    // Mostrar los resultados
    cout << "\nResultados del registro academico:\n" << endl;
    for (int i = 0; i < numMaterias; ++i) {
        cout << "Materia: " << materias[i].nombre << " (Paralelo: " << materias[i].paralelo << ")" << endl;
        cout << "Docente: " << materias[i].docente << endl;
        if (materias[i].aprobado)
        {
            Aprobado(materias[i]);
            if (materias[i].aprobado)
                cout << "Estado: Aprobado" << endl;
            else
                cout << "Estado: Reprobado" << endl;
            cout << "Nota final: " << materias[i].notaFinal << endl;
        }
        else
            cout << "Estado: No habilitado" << endl;
    }
    return 0;
}
void calcularNotaFinal(Materia &materia)
{
    materia.notaFinal = (materia.parcial1 + materia.parcial2) / 2;
    if (materia.notaFinal < 60) {
        materia.aprobado = false;
    } else {
        materia.aprobado = true;
    }
}
void Aprobado(Materia &materia)
{
    materia.notaFinal = (materia.notaFinal + materia.examenFinal)/2;
    if (materia.notaFinal < 51) {
        materia.aprobado = false;
    } else {
        materia.aprobado = true;
    }
}
