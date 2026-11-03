# sistema de caja - Tienda Barrio 
**Curso:** Algoritmos 
**Grupo:** Equipo 3 

##Integrantes:
* **Fernanda Jeannette Hernández Arévalo** - Carnet `2790-26-17695`
* **Denisse del Rocío Cordón Mazariegos** - Carnet `2790-26-14805`
* **Daniel David Benitez Herrera** - Carnet `2790-26-18458`
* **Hugo Josué Ocampo Paz** - Carnet `2790-26-16794`
* **Diego José Pérez Duque** - Carnet `2790-26-16676`
**Fecha:** 2/11/2026

## 1: Análisis del Problema:
El proyecto consiste en la automatización del proceso de cobro y control de caja para una tienda de barrio. El sistema permite registrar ventas continuas de múltiples productos, aplicando automáticamente esquemas de descuento por tramos según el monto comprado, calculando el impuesto al valor agregado (IVA del 12%), validando que el pago entregado por el cliente sea sufuciente y calculando el cambio a devolver. Adicionalmente, el programa acumula métricas globales de la jornada (total vendido, número de ventas, venta mayor, venta menor y promedio por venta) para desplegar un resumen parcial y realizar el cierre definitico de la caja

## 2: Pseudocódigo
```text
Algoritmo SistemaCajaTiendaBarrio

    Definir opcion Como Entero
    Definir totalVentasDia Como Entero
    Definir totalMontoVendidoDia, totalDescuentosDia Como Real
    Definir ventaMayor, ventaMenor Como Real

    totalVentasDia <- 0
    totalMontoVendidoDia <- 0.0
    totalDescuentosDia <- 0.0
    ventaMayor <- 0.0
    ventaMenor <- 0.0

    Hacer
        Escribir "===================================="
        Escribir "   SISTEMA DE CAJA - TIENDA BARRIO  "
        Escribir "===================================="
        Escribir "1. Registrar venta"
        Escribir "2. Ver resumen parcial del dia"
        Escribir "3. Cerrar caja y salir"
        Escribir "Seleccione una opcion: "
        Leer opcion

        Si ERROR_LECTURA Entonces
            opcion <- -1
        FinSi

        Si opcion == 1 Entonces
            Definir subtotalVenta, precio Como Real
            subtotalVenta <- 0.0
            precio <- -1.0

            Escribir "--- REGISTRO DE VENTA ---"

            Mientras Verdadero Hacer
                Escribir "Precio del producto (Q): "
                Leer precio

                Mientras ERROR_LECTURA o precio < 0 Hacer
                    Escribir "Error: El precio debe ser mayor o igual a 0. Intente de nuevo: Q"
                    Leer precio
                FinMientras

                Si precio == 0 Entonces
                    Romper
                FinSi

                Definir cantidad Como Entero
                Escribir "Cantidad (1 a 100): "
                Leer cantidad

                Mientras ERROR_LECTURA o cantidad < 1 o cantidad > 100 Hacer
                    Escribir "Error: La cantidad debe estar entre 1 y 100. Intente de nuevo: "
                    Leer cantidad
                FinMientras

                subtotalVenta <- subtotalVenta + (precio * cantidad)
            FinMientras

            Si subtotalVenta > 0 Entonces
                Definir porcentajeDescuento, montoDescuento Como Real
                Definir montoConDescuento, iva, totalPagar Como Real
                Definir pagoCliente, cambio Como Real

                Si subtotalVenta < 100.0 Entonces
                    porcentajeDescuento <- 0.0
                Sino Si subtotalVenta < 500.0 Entonces
                    porcentajeDescuento <- 0.05
                Sino
                    porcentajeDescuento <- 0.10
                FinSi

                montoDescuento <- subtotalVenta * porcentajeDescuento
                montoConDescuento <- subtotalVenta - montoDescuento
                iva <- montoConDescuento * 0.12
                totalPagar <- montoConDescuento + iva

                Escribir "Total a pagar: Q", totalPagar
                Escribir "Monto recibido del cliente: Q"
                Leer pagoCliente

                Mientras ERROR_LECTURA o pagoCliente < totalPagar Hacer
                    Escribir "Error: El pago debe cubrir el total. Intente de nuevo: Q"
                    Leer pagoCliente
                FinMientras

                cambio <- pagoCliente - totalPagar

                // Emisión de Recibo
                Escribir "===================================="
                Escribir "          RECIBO DE VENTA           "
                Escribir "===================================="
                Escribir "Subtotal:            Q", subtotalVenta
                Escribir "Descuento:          -Q", montoDescuento
                Escribir "IVA (12%):           Q", iva
                Escribir "Total a Pagar:       Q", totalPagar
                Escribir "Monto Pagado:        Q", pagoCliente
                Escribir "Cambio:              Q", cambio
                Escribir "===================================="

                // Actualización de métricas diarias
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
                Escribir "Venta cancelada (sin productos)."
            FinSi

        Sino Si opcion == 2 Entonces
            Escribir "===================================="
            Escribir "       RESUMEN PARCIAL DEL DIA      "
            Escribir "===================================="
            Si totalVentasDia == 0 Entonces
                Escribir "Aun no se han registrado ventas el dia de hoy."
            Sino
                Definir promedioVentas Como Real
                promedioVentas <- totalMontoVendidoDia / totalVentasDia

                Escribir "Numero de ventas realizadas: ", totalVentasDia
                Escribir "Total vendido (con IVA):     Q", totalMontoVendidoDia
                Escribir "Venta mayor:                 Q", ventaMayor
                Escribir "Venta menor:                 Q", ventaMenor
                Escribir "Promedio por venta:          Q", promedioVentas
                Escribir "Total de descuentos dados:   Q", totalDescuentosDia
            FinSi
            Escribir "===================================="

        Sino Si opcion == 3 Entonces
            Escribir "Cierre de caja completado. Salida del sistema."
        Sino
            Escribir "Error: Opcion invalida. Intente de nuevo."
        FinSi

    Hasta Que opcion == 3

FinAlgoritmo
```