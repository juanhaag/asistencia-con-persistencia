#include <iostream>;
#include <fstream>;
#include <sstream>;
#include <string>;

using namespace std;
struct stEstudiante
{
    string nombre;
    string dni;
};
void cargarEstudiante(string nombreArchivo, stEstudiante estudiante);
void leerArchivo(string nombreArchivo);
void crearMateria();

int main(int argc, char const *argv[])
{

    stEstudiante estudiante;
    estudiante.nombre = "Marcelo,";
    estudiante.dni = "43.2323.245,";
    cargarEstudiante("datos.csv", estudiante);
    leerArchivo("datos.csv");
    crearMateria();
    return 0;
}
void crearMateria()
{
    string nombreMateria = "";
    cout << "Ingrese el nombre de la materia que quiere crear" << endl;
    // Se le pide a el usuario que introduzca el nombre de la materia
    // Y se le concatena la extension.csv
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
    }
}
void cargarEstudiante(string nombreArchivo, stEstudiante estudiante)
{
    // Le decimos un append y agregamos al final
    ofstream archivo(nombreArchivo, ios::app);
    string datosEstudiante = estudiante.nombre + estudiante.dni + "0\n";
    if (archivo.is_open())
    {
        archivo << datosEstudiante;
    }
    archivo.close();
}

void leerArchivo(string nombreArchivo)
{
    ifstream archivo(nombreArchivo);
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