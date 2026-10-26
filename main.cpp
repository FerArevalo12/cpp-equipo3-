#include <iostream>

using namespace std;

int main() {
    int opcion = 0;

    do {
        cout << "\n====================================\n";
        cout << "   SISTEMA DE CAJA - TIENDA BARRIO  \n";
        cout << "====================================\n";
        cout << "1. Registrar venta\n";
        cout << "2. Ver resumen parcial del dia\n";
        cout << "3. Cerrar caja y salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = -1;
        }

        if (opcion == 1) {
            cout << "\n[Opcion 1 seleccionada: Registro de venta en construccion]\n";
        } else if (opcion == 2) {
            cout << "\n[Opcion 2 seleccionada: Resumen del dia en construccion]\n";
        } else if (opcion == 3) {
            cout << "\nCierre de caja completado. Salida del sistema.\n";
        } else {
            cout << "\nError: Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 3);

    return 0;
}