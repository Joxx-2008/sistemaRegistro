/*

Nombre del estudiante:
Fecha: 29/07/2026
Tema: Sistema de registro y análisis de notas
Entrada: cantidad, nombres, notas, opción del menú y nombre a buscar
Proceso: validar, almacenar, recorrer, calcular y buscar
Salida: reporte general y resultado de búsqueda

*/

#include <iostream>
#include <string>

using namespace std;

void menuPrincipal(int &opcion, string nombre[], double nota[], int &cantidad);
void registrarNotas(string nombre[], double nota[], int &cantidad);
void mostrarReporte(string nombre[], double nota[], int cantidad);
void buscarEstudiante(string nombre[], double nota[], int cantidad);

int main(){

    int opcion;
    string nombre[20];
    double nota[20];
    int cantidad = 0;

    menuPrincipal(opcion, nombre, nota, cantidad);

    return 0;
}

void menuPrincipal(int &opcion, string nombre[], double nota[], int &cantidad){

    do{

        cout << "==== REGISTRO DE NOTAS ====" << endl;
        cout << "1. Registrar Estudiantes y Notas" << endl;
        cout << "2. Mostrar reporte general" << endl;
        cout << "3. Buscar estudiante" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ingrese una opcion numerica" << endl;
            continue;
        }

        switch(opcion){

            case 1:
                registrarNotas(nombre, nota, cantidad);
                break;

            case 2:
                mostrarReporte(nombre, nota, cantidad);
                break;

            case 3:
                buscarEstudiante(nombre, nota, cantidad);
                break;

            case 4:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion invalida" << endl;
                break;
        }

    }while(opcion != 4);
}

void registrarNotas(string nombre[], double nota[], int &cantidad){

    if(cantidad >= 20){
        cout << "Se ha alcanzado el limite de estudiantes registrados" << endl;
        return;
    }

    cout << "Ingrese lo siguiente:" << endl;
    cout << "Nombre: ";
    cin >> nombre[cantidad];

    cout << "Nota: ";
    cin >> nota[cantidad];

    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ingrese una nota numerica valida" << endl;
        return;
    }

    cantidad++;

    cout << "Registro exitoso" << endl;
}

void mostrarReporte(string nombre[], double nota[], int cantidad){

    cout << "=== REPORTE GENERAL ===" << endl;

    if(cantidad == 0){
        cout << "No existen nombres registrados" << endl;
        return;
    }

    for(int i = 0; i < cantidad; i++){
        cout << "Nombre: " << nombre[i] << endl;
        cout << "Nota: " << nota[i] << endl;
    }
}

void buscarEstudiante(string nombre[], double nota[], int cantidad){

    string estudianteBuscado;
    bool encontrado = false;

    cout << "Ingrese el nombre del estudiante que desea buscar: ";
    cin >> estudianteBuscado;

    for(int i = 0; i < cantidad; i++){

        if(nombre[i] == estudianteBuscado){

            cout << "Estudiante encontrado:" << endl;
            cout << "Nombre: " << nombre[i] << endl;
            cout << "Nota: " << nota[i] << endl;

            encontrado = true;
            break;
        }
    }

    if(encontrado == false){
        cout << "Estudiante no encontrado" << endl;
    }
}
