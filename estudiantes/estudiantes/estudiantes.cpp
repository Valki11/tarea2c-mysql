#include <iostream>
#include "estudiantes.h"

int main()
{
    string codigo, nombres, apellidos, direccion, fecha_nacimiento;
    int telefono,id_tipo_sangre,opcion;

    void mostrarMenu() {
        cout << "\nMENU PRINCIPAL\n";
        cout << "1. Insertar Estudiante\n";
        cout << "2. Editar Estudiante\n";
        cout << "3. Eliminar Estudiante\n";
        cout << "4. Mostrar Estudiantes\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opción: ";
    }
    int opcion;
    

        do {
            mostrarMenu();
            cin >> opcion;

            switch (opcion) {

            case 1:
                cout << "Ingrese el codigo: ";
                cin >> codigo;
                cout << "Ingrese el nombres: ";
                cin >> nombres;
                cout << "Ingrese el apellidos: ";
                cin >> apellidos;
                cout << "Ingrese el direccion: ";
                cin >> direccion;
                cout << "Ingrese el telefono: ";
                cin >> telefono;
                cout << "Ingrese el fecha nacimiento: ";
                cin >> fecha_nacimiento;
                cout << "Ingrese el tip sangre: ";
                cin >> id_tipo_sangre;
                estudiantes estu = estudiantes(codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre);
                estu.crear();

                break;

            case 2:
                cout << "Ingrese el codigo: ";
                cin >> codigo;
                cout << "Ingrese el nombres: ";
                cin >> nombres;
                cout << "Ingrese el apellidos: ";
                cin >> apellidos;
                cout << "Ingrese el direccion: ";
                cin >> direccion;
                cout << "Ingrese el telefono: ";
                cin >> telefono;
                cout << "Ingrese el fecha nacimiento: ";
                cin >> fecha_nacimiento;
                cout << "Ingrese el tip sangre: ";
                cin >> id_tipo_sangre;
                estudiantes estu = estudiantes(codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre);
                estu.actualizar();
                break;
            case 3:
                cout << "Ingrese el codigo: ";
                cin >> codigo;
                estudiantes estu = estudiantes(codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre);
                estu.borrar();
                break;
            case 4:
                estudiantes estu = estudiantes();
                estu.leer();
                break;
            case 0:
                cout << "\nSaliendo del programa...\n";
                break;
            default:
                cout << "\nOpción no válida.\n";
            }
        } while (opcion != 0);

        return 0;
    }
    
}

