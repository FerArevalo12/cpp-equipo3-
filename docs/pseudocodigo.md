# Análisis y Pseudocódigo - Sistema de Caja para Tienda

## 1. Análisis del Problema

El programa busca administrar las ventas diarias de una tiendita de barrio mediante un menú iterativo en consola. Debe permitir registrar compras con múltiples productos, aplicar descuentos según el subtotal, calcular el IVA (12%), cobrar al cliente calculando su cambio, y llevar un registro acumulado de las métricas del día (total vendido, número de ventas, venta mayor/menor, promedio y descuentos otorgados).

### Entradas
- Opción del menú principal (1: Registrar venta, 2: Ver resumen, 3: Salir).
- Para cada producto: Precio unitario (>= 0) y Cantidad (entero entre 1 y 100).
- Pago del cliente (debe ser mayor o igual al total a pagar).

### Restricciones y Validaciones
- No usar arreglos, funciones propias, clases, archivos ni recursión.
- Validar entradas erróneas sin que el programa finalice de forma abrupta.
- Evitar división entre cero en el resumen del día si no hay ventas.

---

## 2. Pseudocódigo

```text
Inicio
    // Variables acumuladoras del día
    totalVentasDia <- 0
    totalMontoVendidoDia <- 0.0
    totalDescuentosDia <- 0.0
    ventaMayor <- 0.0
    ventaMenor <- 0.0
    
    Repetir
        Escribir "=== MENÚ PRINCIPAL ==="
        Escribir "1. Registrar venta"
        Escribir "2. Ver resumen parcial del día"
        Escribir "3. Cerrar caja y salir"
        Leer opcion

        Si opcion == 1 Entonces
            subtotalVenta <- 0.0
            
            Repetir
                Escribir "Ingrese precio del producto (0 para terminar):"
                Leer precio
                
                Mientras precio < 0 Hacer
                    Escribir "Error: El precio no puede ser negativo. Ingrese de nuevo:"
                    Leer precio
                FinMientras

                Si precio > 0 Entonces
                    Escribir "Ingrese cantidad (1 a 100):"
                    Leer cantidad
                    
                    Mientras cantidad < 1 O cantidad > 100 Hacer
                        Escribir "Error: La cantidad debe estar entre 1 y 100. Ingrese de nuevo:"
                        Leer cantidad
                    FinMientras
                    
                    subtotalVenta <- subtotalVenta + (precio * cantidad)
                FinSi
            Hasta Que precio == 0

            Si subtotalVenta > 0 Entonces
                // Cálculo de descuento
                Si subtotalVenta < 100 Entonces
                    porcentajeDescuento <- 0.0
                Sino Si subtotalVenta < 500 Entonces
                    porcentajeDescuento <- 0.05
                Sino
                    porcentajeDescuento <- 0.10
                FinSi

                montoDescuento <- subtotalVenta * porcentajeDescuento
                montoConDescuento <- subtotalVenta - montoDescuento
                iva <- montoConDescuento * 0.12
                totalPagar <- montoConDescuento + iva

                Escribir "Total a pagar: Q", totalPagar
                Escribir "Ingrese pago del cliente:"
                Leer pagoCliente

                Mientras pagoCliente < totalPagar Hacer
                    Escribir "Error: El pago debe cubrir el total. Ingrese de nuevo:"
                    Leer pagoCliente
                FinMientras

                cambio <- pagoCliente - totalPagar

                // Imprimir Recibo
                Escribir "--- RECIBO DE VENTA ---"
                Escribir "Subtotal: Q", subtotalVenta
                Escribir "Descuento: Q", montoDescuento
                Escribir "IVA (12%): Q", iva
                Escribir "Total: Q", totalPagar
                Escribir "Pago: Q", pagoCliente
                Escribir "Cambio: Q", cambio

                // Acumuladores diarios
                totalVentasDia <- totalVentasDia + 1
                totalMontoVendidoDia <- totalMontoVendidoDia + totalPagar
                totalDescuentosDia <- totalDescuentosDia + montoDescuento

                Si totalVentasDia == 1 Entonces
                    ventaMayor <- totalPagar
                    ventaMenor <- totalPagar
                Sino
                    Si totalPagar > ventaMayor Entonces
                        ventaMayor <- totalPagar
                    FinSi
                    Si totalPagar < ventaMenor Entonces
                        ventaMenor <- totalPagar
                    FinSi
                FinSi
            Sino
                Escribir "Venta cancelada."
            FinSi

        Sino Si opcion == 2 Entonces
            Escribir "=== RESUMEN DEL DÍA ==="
            Si totalVentasDia == 0 Entonces
                Escribir "Aún no hay ventas registradas."
            Sino
                promedioVenta <- totalMontoVendidoDia / totalVentasDia
                Escribir "Número de ventas: ", totalVentasDia
                Escribir "Total vendido: Q", totalMontoVendidoDia
                Escribir "Venta mayor: Q", ventaMayor
                Escribir "Venta menor: Q", ventaMenor
                Escribir "Promedio por venta: Q", promedioVenta
                Escribir "Total de descuentos: Q", totalDescuentosDia
            FinSi

        Sino Si opcion == 3 Entonces
            Escribir "Cerrando caja..."
        Sino
            Escribir "Opción inválida. Intente de nuevo."
        FinSi

    Hasta Que opcion == 3
Fin