#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
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
void limpiarConsola();
// Verifica si el archivo existe, de lo contrario lo crea con las cabeceras
void verificarArchivo(string nombreArchivo);

// Crea un estudiante y lo devuelve
stEstudiante crearEstudiante();

// Agrega un registro de asistencia al archivo
void pasarAsistencia(string nombreArchivo, stEstudiante estudiante);

// Muestra los registros de asistencia de un estudiante para una materia específica
void mostrarEstudiante(string nombreArchivo);

// Verifica si existe un estudiante con el DNI dado y muestra su asistencia
void existeEstudiante(string nombreArchivo);

void menuPrincipal();

int main(int argc, char const *argv[])
{
    menuPrincipal();
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
    fechaStringeada << put_time(&tm, "%d-%m-%Y Hora:%H-%M-%S");
    string fechaActual = fechaStringeada.str();

    cout << "Ingrese el DNI del estudiante: ";
    cin >> estudiante.dni;
    cout << "Ingrese el nombre del estudiante: ";
    cin >> estudiante.nombre;
    cout << "Ingrese la materia del estudiante:\n(1)Algoritmo y Estructura de datos\n(2)Arquitectura\n"
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
    menuPrincipal();
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
    limpiarConsola();
    cout << "Ingrese la materia del estudiante para ver sus asistencias:\n(1)Algoritmo y Estructura de datos\n(2)Arquitectura\n"
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
    limpiarConsola();
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
        }

        if (contador > 0)
        {
            cout << "Asistio a  " << contador << " clases" << endl;
        }
    }
    archivo.close();
}

// Verifica si existe un estudiante con el DNI dado y muestra su asistencia
void existeEstudiante(string nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    char delimitador = ',';
    string linea;
    bool existe = false;
    string dniEstudiante;
    cout << "Ingrese el DNI:" << endl;
    cin >> dniEstudiante;
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
    cout << "Pulse enter para continuar" << endl;
    cin.ignore();
    cin.get();
    menuPrincipal();
}

void menuPrincipal()
{

    int opcion = 0;
    string nombreArchivo = "estudiantes.csv";
    verificarArchivo(nombreArchivo);
    limpiarConsola();
    while (opcion != 1 && opcion != 2 && opcion != 3)
    {
        cout << "1. Agregar asistencia" << endl;
        cout << "2. Mostrar asistencia" << endl;
        cout << "3. Salir" << endl;
        cin >> opcion;
    }
    switch (opcion)
    {
    case 1:
        pasarAsistencia(nombreArchivo, crearEstudiante());
        break;
    case 2:
        // Funcion que verifica que exista estudiante y llama a mostrar el estudiante
        existeEstudiante(nombreArchivo);
        break;
    case 3:
        limpiarConsola();
        cout << "Saliendo..." << endl;
        exit(0);
        break;
    }
}

void limpiarConsola()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}