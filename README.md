# cpp-equipo3-
# Sistema de Caja para una Tienda (Consola C++)

Programa desarrollado en C++ para simular la caja registradora de una tienda de barrio. Permite registrar ventas, validar datos de entrada, calcular descuentos e IVA (12%), emitir recibos y generar un resumen financiero del día.

## Lenguaje y Herramientas
- **Lenguaje:** C++
- **Compilador recomendado:** g++ / MinGW / VS Code / MSVC

## Cómo compilar y ejecutar

1. Abre la terminal en la carpeta del proyecto.
2. Compila el archivo ejecutable:
   ```bash
   g++ main.cpp -o sistema_caja

Ejecuta el programa:

En Windows (PowerShell):
.\sistema_caja.exe

Casos de Prueba Verificados
Venta < Q100 (sin descuento): Q99.99 aplica 0% de descuento.

Venta Q100 a Q499.99 (5% descuento): Q100.00 aplica correctamente 5%.

Venta >= Q500 (10% descuento): Q500.00 aplica correctamente 10%.

Validaciones: Se probó ingresar precios negativos, cantidades mayores a 100 (ej. 101), cantidad 0 y opciones de menú inválidas (ej. "9") sin provocar fallos en el programa.

Resumen sin ventas: Muestra mensaje de alerta sin intentar dividir entre cero.

Pago menor al total: El sistema exige reingresar el monto hasta cubrir la compra.

Uso de IA
Herramienta utilizada: Gemini

Preguntas realizadas:

Solicitud de estructura de control de flujo para menú repetitivo y validación de entradas no numéricas en C++.

Apoyo en la generación del pseudocódigo para la entrega en la carpeta docs/.

Guía de comandos para la correcta secuenciación de commits en Git.

Lo que acepté:

La estructura básica del ciclo do-while y la lógica con cin.fail() para limpiar el buffer de entrada.

La fórmula de lógica acumuladora para encontrar la venta mayor y menor.

Lo que rechacé o ajusté:

Se rechazaron sugerencias que utilizaban arreglos o funciones personalizadas para cumplir estrictamente con las restricciones del curso.