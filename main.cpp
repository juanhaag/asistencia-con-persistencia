#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
struct stEstudiante
{
    string nombre;
    string dni;
    int presentes;
};
void cargarEstudiante(string nombreArchivo);
void leerArchivo(string nombreArchivo);
void crearMateria();
void pasarPresente(string nombreArchivo);

// Menu
void menuInicial();
void menuProfesor();
void seleccionMateria();

int main(int argc, char const *argv[])
{

    /*

    cargarEstudiante("datos.csv", estudiante);
    leerArchivo("datos.csv");
    crearMateria(); */
    // leerArchivo("datos.csv");
    pasarPresente("datos.csv");
    menuInicial();
    return 0;
}
void crearMateria()
{
    string nombreMateria = "";
    cout << "Ingrese el nombre de la materia que quiere crear" << endl;
    // Se le pide a el usuario que introduzca el nombre de la materia
    // Y se le concatena la extension.csv
    cin.ignore();
    getline(cin, nombreMateria);
    nombreMateria += ".csv";
    cout << nombreMateria;
    ifstream archivo(nombreMateria);
    if (archivo.good())
    {
        cout << "Ya existe la materia que usted desea agregar." << endl;
    }
    else
    {
        archivo.close();
        ofstream archivoNuevo(nombreMateria);
        archivoNuevo << "Nombre,Dni,Asistencias\n";
        archivoNuevo.close();
        menuProfesor();
    }
}
void cargarEstudiante(string nombreArchivo)
{
    stEstudiante estudiante;
    cin.ignore();
    cout << "Ingrese el nombre del estudiante:\n";
    cin >> estudiante.nombre;
    cout << "Ingrese el dni del estudiante:\n";
    cin >> estudiante.dni;
    // Le decimos un append y agregamos al final
    ofstream archivo(nombreArchivo, ios::app);
    string datosEstudiante = "\n" + estudiante.nombre + "," + estudiante.dni + "," + "0";
    if (archivo.is_open())
    {
        archivo << datosEstudiante;
    }
    archivo.close();
}

void leerArchivo(string nombreArchivo)
{
    fstream archivo(nombreArchivo, ios::in | ios::out);
    // La linea va a ser encargada de leer cada linea del csv
    string linea;
    // El delimitador va a ser el caracter que nos va a separar los strings almacenados en cada linea
    char delimitador = ',';
    // Leemos una linea
    getline(archivo, linea);
    // Vamos moviendo la ubicacion del puntero para que vaya recorriendo el archivo
    cout << "Nombre "
         << "DNI "
         << "Asistencias " << endl;
    while (getline(archivo, linea))
    {
        // Convertimos el string a un stream para manipular
        stringstream stringToStream(linea);
        string nombre, dni, materias;
        // Almacenamos en los string cada linea
        getline(stringToStream, nombre, delimitador);
        getline(stringToStream, dni, delimitador);
        getline(stringToStream, materias, delimitador);

        cout << nombre << "|" << dni << "|" << materias << endl;
    }
    archivo.close();
}
void pasarPresente(string nombreArchivo)
{
    vector<stEstudiante> vectorEstudiantes;
    fstream archivo(nombreArchivo, ios::in | ios::out);
    // La linea va a ser encargada de leer cada linea del csv
    string linea;
    // El delimitador va a ser el caracter que nos va a separar los strings almacenados en cada linea
    char delimitador = ',';
    // Leemos una linea
    getline(archivo, linea);
    // Vamos moviendo la ubicacion del puntero para que vaya recorriendo el archivo
    while (getline(archivo, linea))
    {
        stEstudiante estudianteTemporal;
        // Convertimos el string a un stream para manipular
        stringstream stringToStream(linea);
        string nombre, dni, materias;
        // Almacenamos en los string cada linea
        getline(stringToStream, nombre, delimitador);
        getline(stringToStream, dni, delimitador);
        getline(stringToStream, materias, delimitador);

        // Se verifica que el dni sera igual y si es igual se parsea materias para que sea int y luego pushea en el vector
        // Para luego cargar el vector en el archivo original
        if (dni == "41314722")
        {
            estudianteTemporal.nombre = nombre;
            estudianteTemporal.dni = dni;
            estudianteTemporal.presentes = stoi(materias);
            estudianteTemporal.presentes = estudianteTemporal.presentes + 1;
            vectorEstudiantes.push_back(estudianteTemporal);
        }
        else
        {
            estudianteTemporal.nombre = nombre;
            estudianteTemporal.dni = dni;
            estudianteTemporal.presentes = stoi(materias);
            vectorEstudiantes.push_back(estudianteTemporal);
        }
    }
    archivo.close();

    ofstream archivoModificado(nombreArchivo, ios::trunc);
    cout << vectorEstudiantes.size();

    for (int i = 0; i < vectorEstudiantes.size(); i++)
    {
        cout << vectorEstudiantes[i].nombre;
        cout << vectorEstudiantes[i].dni;
        cout << vectorEstudiantes[i].presentes;
        string datosEstudiante = "\n" + vectorEstudiantes[i].nombre + "," + vectorEstudiantes[i].dni + "," + to_string(vectorEstudiantes[i].presentes);
        if (archivoModificado.is_open())
        {
            archivoModificado << datosEstudiante;
        }
    }
    archivoModificado.close();
}

void menuInicial()
{
    int opcion = 0;
    cout << "Bienvenido al sistema de asistencias:\n";

    cout << "(1)Profesores\n(2)Alumnos\n(3)Salir" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        menuProfesor();
        break;
    case 2:
        /* code */
        break;
    case 4:
        system("exit");
        break;
    default:
        menuInicial();
        break;
    }
}

void menuProfesor()
{
    system("cls");
    int opcion = 0;
    cout << "Bienvenido al sistema de asistencias:\n";
    cout << "(1)Crear Materia\n(2)Cargar Alumno\n(3)Cargar presentes\n(4)Volver al inicio" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        crearMateria();
        break;
    // Se llama a seleccion materia para verificar que exista la materia
    case 2:
        seleccionMateria();
        break;

    case 3:
        // crearMateria();
        break;
    case 4:
        menuInicial();
        break;

    default:
        break;
    }
}
// Funcion que se encarga de verificar que exista la materia para poder agregar al estudiante
void seleccionMateria()
{
    string nombreMateria = "";
    cout << "Ingrese el nombre de su materia para continuar:" << endl;
    cin.ignore();
    getline(cin, nombreMateria);
    nombreMateria += ".csv";
    cout << nombreMateria;
    ifstream archivo(nombreMateria);
    if (archivo.good())
    {
        archivo.close();
        cargarEstudiante(nombreMateria);
    }
    else
    {
        int seleccion;
        cout << "\nNo existe la materia desea ir al menu principal y crearla?\n (1)Volver al menu\n(2)Salir" << endl;
        cin >> seleccion;
        switch (seleccion)
        {
        case 1:
            menuProfesor();
            break;
        case 2:
            // Alguna funcion para salir del programa
            break;

        default:
            menuProfesor();
            break;
        }
    }
}