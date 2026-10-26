#include <iostream>
#include <iomanip>

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
            double subtotalVenta = 0.0;
            double precio = -1.0;

            cout << "\n--- REGISTRO DE VENTA ---\n";
            cout << "Ingrese productos (Precio = 0 para terminar)\n";

            while (true) {
                cout << "\nPrecio del producto (Q): ";
                cin >> precio;

                while (cin.fail() || precio < 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Error: El precio debe ser mayor o igual a 0. Intente de nuevo: Q";
                    cin >> precio;
                }

                if (precio == 0) {
                    break;
                }

                int cantidad = 0;
                cout << "Cantidad (1 a 100): ";
                cin >> cantidad;

                while (cin.fail() || cantidad < 1 || cantidad > 100) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Error: La cantidad debe estar entre 1 y 100. Intente de nuevo: ";
                    cin >> cantidad;
                }

                subtotalVenta += (precio * cantidad);
            }

            cout << "\nSubtotal acumulado de la venta: Q" << subtotalVenta << "\n";

        } else if (opcion == 2) {
            cout << "\n[Resumen diario en construccion]\n";
        } else if (opcion == 3) {
            cout << "\nCierre de caja completado. Salida del sistema.\n";
        } else {
            cout << "\nError: Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 3);

    return 0;
}