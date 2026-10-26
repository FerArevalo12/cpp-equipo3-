#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int opcion = 0;

    // Acumuladores del dia
    int totalVentasDia = 0;
    double totalMontoVendidoDia = 0.0;
    double totalDescuentosDia = 0.0;
    double ventaMayor = 0.0;
    double ventaMenor = 0.0;

    cout << fixed << setprecision(2);

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

            if (subtotalVenta > 0) {
                // Cálculo de Descuento
                double porcentajeDescuento = 0.0;
                if (subtotalVenta < 100.0) {
                    porcentajeDescuento = 0.0;
                } else if (subtotalVenta < 500.0) {
                    porcentajeDescuento = 0.05;
                } else {
                    porcentajeDescuento = 0.10;
                }

                double montoDescuento = subtotalVenta * porcentajeDescuento;
                double montoConDescuento = subtotalVenta - montoDescuento;
                double iva = montoConDescuento * 0.12;
                double totalPagar = montoConDescuento + iva;

                // Cobro al cliente
                double pagoCliente = 0.0;
                cout << "\nTotal a pagar: Q" << totalPagar << "\n";
                cout << "Monto recibido del cliente: Q";
                cin >> pagoCliente;

                while (cin.fail() || pagoCliente < totalPagar) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Error: El pago debe cubrir el total (Q" << totalPagar << "). Intente de nuevo: Q";
                    cin >> pagoCliente;
                }

                double cambio = pagoCliente - totalPagar;

                // Recibo
                cout << "\n====================================\n";
                cout << "          RECIBO DE VENTA           \n";
                cout << "====================================\n";
                cout << "Subtotal:            Q" << setw(10) << subtotalVenta << "\n";
                cout << "Descuento (" << (porcentajeDescuento * 100) << "%):     -Q" << setw(10) << montoDescuento << "\n";
                cout << "IVA (12%):           Q" << setw(10) << iva << "\n";
                cout << "Total a Pagar:       Q" << setw(10) << totalPagar << "\n";
                cout << "Monto Pagado:        Q" << setw(10) << pagoCliente << "\n";
                cout << "Cambio:              Q" << setw(10) << cambio << "\n";
                cout << "====================================\n";

                // Acumuladores diarios
                totalVentasDia++;
                totalMontoVendidoDia += totalPagar;
                totalDescuentosDia += montoDescuento;

                if (totalVentasDia == 1) {
                    ventaMayor = totalPagar;
                    ventaMenor = totalPagar;
                } else {
                    if (totalPagar > ventaMayor) ventaMayor = totalPagar;
                    if (totalPagar < ventaMenor) ventaMenor = totalPagar;
                }
            } else {
                cout << "Venta cancelada (sin productos).\n";
            }

        } else if (opcion == 2) {
            cout << "\n====================================\n";
            cout << "      RESUMEN PARCIAL DEL DIA       \n";
            cout << "====================================\n";
            if (totalVentasDia == 0) {
                cout << "Aun no se han registrado ventas el dia de hoy.\n";
            } else {
                double promedioVentas = totalMontoVendidoDia / totalVentasDia;
                cout << "Numero de ventas realizadas: " << totalVentasDia << "\n";
                cout << "Total vendido (con IVA):     Q" << totalMontoVendidoDia << "\n";
                cout << "Venta mayor:                 Q" << ventaMayor << "\n";
                cout << "Venta menor:                 Q" << ventaMenor << "\n";
                cout << "Promedio por venta:          Q" << promedioVentas << "\n";
                cout << "Total de descuentos dados:   Q" << totalDescuentosDia << "\n";
            }
            cout << "====================================\n";

        } else if (opcion == 3) {
            cout << "\nCierre de caja completado. Salida del sistema.\n";
        } else {
            cout << "\nError: Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 3);

    return 0;
}