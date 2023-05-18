#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

// Definición de una estructura para representar un estudiante
struct stEstudiante
{
    string dni;
    string nombre;
    string materia;
    string fecha;
    string asistencia;
};

// Verifica si el archivo existe, de lo contrario lo crea con las cabeceras
void verificarArchivo(string nombreArchivo);

// Crea un estudiante y lo devuelve
stEstudiante crearEstudiante();

// Agrega un registro de asistencia al archivo
void pasarAsistencia(string nombreArchivo, stEstudiante estudiante);

// Muestra los registros de asistencia de un estudiante para una materia específica
void mostrarEstudiante(string nombreArchivo, string dniEstudiante);

// Verifica si existe un estudiante con el DNI dado y muestra su asistencia
void existeEstudiante(string nombreArchivo, string dniEstudiante);

int main(int argc, char const *argv[])
{
    string nombreArchivo = "estudiantes.csv";
    verificarArchivo(nombreArchivo);
    // pasarAsistencia(nombreArchivo, crearEstudiante());
    existeEstudiante("estudiantes.csv", "41314722");
    return 0;
}

// Verifica si el archivo existe, de lo contrario lo crea con las cabeceras
void verificarArchivo(string nombreArchivo)
{
    ifstream archivoAverificar(nombreArchivo);
    if (!archivoAverificar.good())
    {
        ofstream archivoNuevo(nombreArchivo);
        archivoNuevo << "DNI,"
                     << "Nombre,"
                     << "Materia,"
                     << "Fecha,"
                     << "Asistencia\n";
        archivoNuevo.close();
    }
    else
    {
        archivoAverificar.close();
    }
}

// Crea un estudiante y lo devuelve
stEstudiante crearEstudiante()
{
    stEstudiante estudiante;
    int opcion;

    // Obtiene la fecha y hora actual
    auto t = time(nullptr);
    auto tm = *localtime(&t);
    // Transforma la fecha y hora actual en un string formateado
    ostringstream fechaStringeada;
    fechaStringeada << put_time(&tm, "%d-%m-%Y %H-%M-%S");
    string fechaActual = fechaStringeada.str();

    cout << "Ingrese el DNI del estudiante: ";
    cin >> estudiante.dni;
    cout << "Ingrese el nombre del estudiante: ";
    cin >> estudiante.nombre;
    cout << "Ingrese la materia del estudiante:\n(1)Algoritmo y Estructura de datos\n(2)Arquitectura\n "
         << "(3)Algebra\n(4)Analisis Matematico\n(5)Practicas Profesionales\n(6)Ingles1\n";
    cin.ignore();
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        estudiante.materia = "Algoritmo y Estructura de datos";
        break;
    case 2:
        estudiante.materia = "Arquitectura";
        break;
    case 3:
        estudiante.materia = "Algebra";
        break;
    case 4:
        estudiante.materia = "Analisis Matematico";
        break;
    case 5:
        estudiante.materia = "Practicas Profesionales";
        break;
    case 6:
        estudiante.materia = "Ingles 1";
        break;
    default:
        cout << "No ingresaste ninguna opción correcta";
        break;
    }
    estudiante.fecha = fechaActual;
    estudiante.asistencia = "true";
    return estudiante;
}

// Agrega un registro de asistencia al archivo
void pasarAsistencia(string nombreArchivo, stEstudiante estudiante)
{
    ofstream archivo(nombreArchivo, ios::app);
    if (archivo.is_open())
    {
        archivo << "\n"
                << estudiante.dni
                << ","
                << estudiante.nombre
                << "," << estudiante.materia
                << "," << estudiante.fecha
                << ","
                << estudiante.asistencia;
    }
    archivo.close();
}

// Muestra los registros de asistencia de un estudiante para una materia específica
void mostrarEstudiante(string nombreArchivo, string dniEstudiante)
{
    ifstream archivo(nombreArchivo);
    char delimitador = ',';
    string linea;
    int contador = 0;
    int opcion;
    string materia;

    cout << "Ingrese la materia del estudiante para ver sus asistencias:\n(1)Algoritmo y Estructura de datos\n(2)Arquitectura\n "
         << "(3)Algebra\n(4)Analisis Matematico\n(5)Practicas Profesionales\n(6)Ingles1\n";
    int flag = 0;
    do
    {
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            flag = 1;
            materia = "Algoritmo y Estructura de datos";
            break;
        case 2:
            flag = 1;
            materia = "Arquitectura";
            break;
        case 3:
            flag = 1;
            materia = "Algebra";
            break;
        case 4:
            flag = 1;
            materia = "Analisis Matematico";
            break;
        case 5:
            flag = 1;
            materia = "Practicas Profesionales";
            break;
        case 6:
            flag = 1;
            materia = "Ingles 1";
            break;
        default:
            cout << "No ingresaste ninguna opción correcta";
            break;
        }
    } while (flag != 1);

    if (archivo.is_open())
    {
        while (getline(archivo, linea))
        {
            stringstream stringToStream(linea);
            string nombre, dni, materiaArchivo, fecha, asistencia;
            // Almacena cada campo en las variables correspondientes
            getline(stringToStream, dni, delimitador);
            getline(stringToStream, nombre, delimitador);
            getline(stringToStream, materiaArchivo, delimitador);
            getline(stringToStream, fecha, delimitador);
            getline(stringToStream, asistencia, delimitador);
            if (dni == dniEstudiante && materiaArchivo == materia)
            {
                cout << "DNI: " << dni << endl;
                cout << "Nombre: " << nombre << endl;
                cout << "Materia: " << materia << endl;
                cout << "Fecha y hora: " << fecha << endl;
                cout << "Asistencia: " << asistencia << endl;
                contador++;
            }
            if (materiaArchivo != materia)
            {
                // Utiliza la misma variable que se utilizó en el switch
                flag = 2;
            }
        }
        // Utiliza el valor 2 como condición sin justificación
        if (flag == 2)
        {
            cout << "El alumno no asistio a ninguna clase de dicha materia" << endl;
        }
        if (contador > 0)
        {
            cout << "Asistio: " << contador << endl;
        }
    }
    archivo.close();
}

// Verifica si existe un estudiante con el DNI dado y muestra su asistencia
void existeEstudiante(string nombreArchivo, string dniEstudiante)
{
    ifstream archivo(nombreArchivo);
    char delimitador = ',';
    string linea;
    bool existe = false;

    if (archivo.is_open())
    {
        while (getline(archivo, linea) && existe != true)
        {
            stringstream stringToStream(linea);
            string dni;
            getline(stringToStream, dni, delimitador);

            if (dni == dniEstudiante)
            {
                existe = true;
                mostrarEstudiante(nombreArchivo, dniEstudiante);
            }
        }
        if (existe == false)
        {
            cout << "No se encontró a nadie con ese DNI" << endl;
        }
    }
    archivo.close();
}