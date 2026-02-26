#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string matricula;
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
    string carrera;
    string correo;
    string telefono;
};

// Función para dar de alta un estudiante
void alta(Estudiante catalogo[], int& indice) {
    cout << "Ingrese la matricula del estudiante: ";
    cin >> catalogo[indice].matricula;
    cin.ignore();  // Para ignorar el salto de línea después de la matricula
    cout << "Ingrese el nombre: ";
    getline(cin, catalogo[indice].nombre);
    cout << "Ingrese el apellido paterno: ";
    getline(cin, catalogo[indice].apellidoPaterno);
    cout << "Ingrese el apellido materno: ";
    getline(cin, catalogo[indice].apellidoMaterno);
    cout << "Ingrese la carrera: ";
    getline(cin, catalogo[indice].carrera);
    cout << "Ingrese el correo electrónico: ";
    getline(cin, catalogo[indice].correo);
    cout << "Ingrese el teléfono: ";
    getline(cin, catalogo[indice].telefono);

    indice++;
}

void baja(Estudiante catalogo[], int& indice) {
    string matricula;
    cout << "Ingrese la matricula del estudiante a eliminar: ";
    cin >> matricula;

    bool encontrado = false;
    int pos = -1;

    for (int i = 0; i < indice; i++) {
        if (catalogo[i].matricula == matricula) {
            encontrado = true;
            pos = i;
            break;
        }
    }

    if (encontrado) {
        cout << "Estudiante encontrado. Sus datos son:" << endl;
        cout << "Matrícula: " << catalogo[pos].matricula << endl;
        cout << "Nombre: " << catalogo[pos].nombre << endl;
        cout << "Apellido Paterno: " << catalogo[pos].apellidoPaterno << endl;
        cout << "Apellido Materno: " << catalogo[pos].apellidoMaterno << endl;
        cout << "Carrera: " << catalogo[pos].carrera << endl;
        cout << "Correo: " << catalogo[pos].correo << endl;
        cout << "Teléfono: " << catalogo[pos].telefono << endl;

        cout << "¿Está seguro de que desea eliminar al estudiante? 1. Para sí / 2. Para no: ";
        int confirmacion;
        cin >> confirmacion;

        if (confirmacion == 1) {
            for (int i = pos; i < indice - 1; i++) {
                catalogo[i] = catalogo[i + 1];
            }
            indice--;  
            cout << "Estudiante eliminado correctamente." << endl;
        }
        else {
            cout << "Eliminación cancelada." << endl;
        }
    }
    else {
        cout << "Estudiante no encontrado." << endl;
    }
}

void mostrarTodos(Estudiante catalogo[], int indice) {
    if (indice == 0) {
        cout << "No hay estudiantes registrados." << endl;
    }
    else {
        cout << "Lista de matrículas de estudiantes registrados:" << endl;
        for (int i = 0; i < indice; i++) {
            cout << "Matrícula: " << catalogo[i].matricula << endl;
        }
    }
}

void buscarEstudiante(Estudiante catalogo[], int indice) {
    string matricula;
    cout << "Ingrese la matricula del estudiante a buscar: ";
    cin >> matricula;

    bool encontrado = false;

    for (int i = 0; i < indice; i++) {
        if (catalogo[i].matricula == matricula) {
            encontrado = true;
            cout << "Estudiante encontrado. Sus datos son:" << endl;
            cout << "Matrícula: " << catalogo[i].matricula << endl;
            cout << "Nombre: " << catalogo[i].nombre << endl;
            cout << "Apellido Paterno: " << catalogo[i].apellidoPaterno << endl;
            cout << "Apellido Materno: " << catalogo[i].apellidoMaterno << endl;
            cout << "Carrera: " << catalogo[i].carrera << endl;
            cout << "Correo: " << catalogo[i].correo << endl;
            cout << "Teléfono: " << catalogo[i].telefono << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Estudiante no encontrado." << endl;
    }
}

void modificarEstudiante(Estudiante catalogo[], int indice) {
    string matricula;
    cout << "Ingrese la matricula del estudiante a modificar: ";
    cin >> matricula;

    bool encontrado = false;
    int pos = -1;

    for (int i = 0; i < indice; i++) {
        if (catalogo[i].matricula == matricula) {
            encontrado = true;
            pos = i;
            break;
        }
    }

    if (encontrado) {
        cout << "Estudiante encontrado. Ingrese los nuevos datos:" << endl;
        cout << "Ingrese el nuevo nombre: ";
        cin.ignore();  
        getline(cin, catalogo[pos].nombre);
        cout << "Ingrese el nuevo apellido paterno: ";
        getline(cin, catalogo[pos].apellidoPaterno);
        cout << "Ingrese el nuevo apellido materno: ";
        getline(cin, catalogo[pos].apellidoMaterno);
        cout << "Ingrese la nueva carrera: ";
        getline(cin, catalogo[pos].carrera);
        cout << "Ingrese el nuevo correo electrónico: ";
        getline(cin, catalogo[pos].correo);
        cout << "Ingrese el nuevo teléfono: ";
        getline(cin, catalogo[pos].telefono);

        cout << "Datos del estudiante modificados correctamente." << endl;
    }
    else {
        cout << "Estudiante no encontrado." << endl;
    }
}

void mostrarMenu() {
    cout << "Menú principal:" << endl;
    cout << "1. Alta de estudiantes" << endl;
    cout << "2. Baja de estudiantes" << endl;
    cout << "3. Modificaciones de estudiantes" << endl;
    cout << "4. Mostrar todos" << endl;
    cout << "5. Buscar estudiante" << endl;
    cout << "6. Salir" << endl;
}

int main() {
    const int MAX_ESTUDIANTES = 100;
    Estudiante catalogo[MAX_ESTUDIANTES];
    int indice = 0;
    int opcion;

    do {
        mostrarMenu();
        cout << "Ingrese su selección: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            alta(catalogo, indice);
            break;
        case 2:
            baja(catalogo, indice);
            break;
        case 3:
            modificarEstudiante(catalogo, indice);
            break;
        case 4:
            mostrarTodos(catalogo, indice);
            break;
        case 5:
            buscarEstudiante(catalogo, indice);
            break;
        case 6:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
        }
    } while (opcion != 6);

    return 0;
}