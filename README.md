# Sistema de Control de Asistencia 

Este es un programa de consola en C++ que permite llevar el control de asistencia de estudiantes desarrollado como trabajo evaluativo para el ISFT 151 Practicas Profesinalizantes.
. El programa utiliza un archivo CSV para almacenar los datos de los estudiantes y las asistencias registradas.

## Funcionalidades

El programa ofrece las siguientes funcionalidades:

1. Agregar asistencia: Permite ingresar los datos de un estudiante y registrar su asistencia en un archivo CSV.
2. Mostrar asistencia: Permite buscar un estudiante por su número de DNI y mostrar su historial de asistencias.
3. Mostrar estudiantes por materia: Permite seleccionar una materia y mostrar el listado de estudiantes que han asistido a dicha materia.
4. Salir: Cierra el programa.

## Requisitos

El programa requiere tener instalado un compilador de C++ compatible con el estándar C++11.

## Uso

1. Descarga el código fuente del programa.
2. Abre una terminal y navega hasta el directorio donde se encuentra el archivo del programa.
3. Compila el programa ejecutando el siguiente comando:
g++ main.cpp -o asistencia
4. Ejecuta el programa con el siguiente comando:
5. ./asistencia
6.##Datos fake para cargar el archivo estudiantes.csv
DNI,Nombre,Materia,Fecha,Asistencia

41314722,juan,Arquitectura,18-05-2023 10-56-04,true
41314722,juan,Algebra,18-05-2023 11-48-45,true
456457,Marino,Ingles 1,18-05-2023 11-49-00,true
41314722,juan,Practicas Profesionales,18-05-2023 11-49-21,true
452323,Lose,Analisis Matematico,18-05-2023 11-50-59,true
41314722,juan,Arquitectura,18-05-2023 12-00-19,true
41314722,juan,Algebra,18-05-2023 12-01-05,true
41314722,juan,Algoritmo y Estructura de datos,18-05-2023 12-04-52,true
41314722,juan,Analisis Matematico,19-05-2023 Hora:09-25-33,true
41314722,juan,Arquitectura,19-05-2023 Hora:09-37-05,true
41314722,juan,Practicas Profesionales,19-05-2023 Hora:09-37-49,true
41314722,juan,Practicas Profesionales,19-05-2023 Hora:09-39-20,true
456456,raul,Algebra,19-05-2023 Hora:09-46-19,true
41314722,Juan,Algoritmo y Estructura de datos,19-05-2023 Hora:09-51-47,true
41314722,juan,Algebra,20-05-2023 Hora:15-27-51,true
