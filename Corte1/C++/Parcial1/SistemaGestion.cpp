#include <iostream>
#include <string>
#include <iomanip>    // Para setw(), left, fixed, setprecision
#include <windows.h>
using namespace std;

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
#define ROJO       12
#define BLANCO     15   
#define CYAN       11

const int MAX_ESTUDIANTES = 5;
const int NUM_NOTAS = 3;

// Clase Estudiante 
class Estudiante {
public:
    string codigo;
    string nombre;
    int edad;
    float notas[NUM_NOTAS];

    // Constructor por defecto, arreglo de estudiantes para llenar despues, sin tener aun los datos
    Estudiante() {
        codigo = "";
        nombre = "";
        edad = 0;
        for (int i = 0; i < NUM_NOTAS; i++) {
            notas[i] = 0.0;
        }
    }

    // Constructor con parámetros, estudiantes con datos que ya se conocen
    Estudiante(string _codigo, string _nombre, int _edad) {
        codigo = _codigo;
        nombre = _nombre;
        edad = _edad;
        for (int i = 0; i < NUM_NOTAS; i++) {
            notas[i] = 0.0;
        }
    }

    // metodo para calcular el promedio
    float calcularPromedio() {
        float suma = 0;
        for (int i = 0; i < NUM_NOTAS; i++) {
            suma += notas[i];
        }
        return suma / NUM_NOTAS;
    }

    // metodo para mostrar información del estudiante 
    //este metodo luego se utilizara para la opcion de buscar un estudiante por codigo
    void mostrarInfo() {
        cout << "Codigo: " << codigo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Notas: ";
        for (int i = 0; i < NUM_NOTAS; i++) {
            cout << notas[i];
            if (i < NUM_NOTAS - 1) cout << ", ";// para que las notas queden organizadas con comas
        }
        cout << endl;
        cout << "Promedio: " << calcularPromedio() << endl;
    }
};

// Clase gestora del sistema
class SistemaGestion {
private:
    Estudiante estudiantes[MAX_ESTUDIANTES];//clase estudiante, arreglo estudiantes de tamaño fijo ma_estudiantes
    // Este arreglo almacena hasta MAX_ESTUDIANTES objetos Estudiante
    float matrizNotas[MAX_ESTUDIANTES][NUM_NOTAS];//matriz de notas filas est columnas notas
    int totalEstudiantes;

public:
    // Constructor
    SistemaGestion() {
        totalEstudiantes = 0;
        // Inicializar la matriz de notas en 0
        for (int i = 0; i < MAX_ESTUDIANTES; i++) {
            for (int j = 0; j < NUM_NOTAS; j++) {
                matrizNotas[i][j] = 0.0;
            }
        }
    }

    // metodo para registrar un estudiante
    bool registrarEstudiante() {
        if (totalEstudiantes >= MAX_ESTUDIANTES) {
            cout << "No se pueden registrar mas estudiantes" << MAX_ESTUDIANTES << endl;
            return false;
        }

        string codigo, nombre;
        int edad;
        setColor(CYAN);
        cout << "\n ---Registrar Estudiante ---" << endl;
        setColor(BLANCO);
        cout << "Ingrese codigo del estudiante: ";
        cin >> codigo;

        // validar si el código ya existe
        for (int i = 0; i < totalEstudiantes; i++) {
            if (estudiantes[i].codigo == codigo) {
                cout <<"Ya existe un estudiante con ese codigo." << endl;
                return false;
            }
        }

        cout << "Ingrese nombre del estudiante: ";
        cin.ignore();//espacios
        getline(cin, nombre);
        
        cout << "Ingrese edad del estudiante: ";
        cin >> edad;
        
        // Crear el estudiante
        estudiantes[totalEstudiantes] = Estudiante(codigo, nombre, edad);//Crea un objeto Estudiante temporal usando el constructor 
        //objeto se copia a la posición totalEstudiantes,que inicia en 0, del arreglo estudiantes[]
        
        // Inicializar sus notas en la matriz
        for (int i = 0; i < NUM_NOTAS; i++) {
            matrizNotas[totalEstudiantes][i] = 0.0;// solo notas
            estudiantes[totalEstudiantes].notas[i] = 0.0;//aqui se amacena notas junto con datos del estudiante
        }
        
        totalEstudiantes++;
        return true;
    }

    int buscarEstudiante(string codigo) {
        for (int i = 0; i < totalEstudiantes; i++) {
            if (estudiantes[i].codigo == codigo) //accede al atributo codigo de ese estudiante
			{ 
                return i;
            }
        }
        return -1;// se utiliza como un indicador si no se encuentra un estudiante con este codigo
    }

    // Método para buscar y mostrar un estudiante
    void buscarYMostrarEstudiante() {


        string codigo;
        cout << "\n--- Buscar Estudiante ---" << endl;
        cout << "Ingrese el código del estudiante: ";
        cin >> codigo;

        int indice = buscarEstudiante(codigo);
        
        if (indice != -1) {
            cout << "\nEstudiante:" << endl;
            estudiantes[indice].mostrarInfo();//indice es como la posicion del estudiante encontrado
        } else {
            cout << "No se encontro un estudiante con ese codigo: " << codigo << endl;
        }
    }

    // Método para asignar o actualizar notas
    bool asignarNotasEstudiante() {

        string codigo;
        setColor(CYAN);
        cout << "\n--- Asignar Notas ---" << endl;
        setColor(BLANCO);
        cout << "Ingrese el codigo del estudiante: ";
        cin >> codigo;

        int indice = buscarEstudiante(codigo);
        
        if (indice == -1) {
            cout << "No se encontro un estudiante con ese codigo: " << codigo << endl;
            return false;
        }

        cout << "Estudiante: " << estudiantes[indice].nombre << endl;
        
        // Asignar las 3 notas
        for (int i = 0; i < NUM_NOTAS; i++) {
            float nota;
            cout << "Ingrese nota " << i+1 << " 0-50: ";
            cin >> nota;

            
            // Asignar nota directamente
            estudiantes[indice].notas[i] = nota;
            matrizNotas[indice][i] = nota;
            cout << "Nota " << i+1 << " asignada: " << nota << endl;
        }
        
        cout << "Notas actualizadas" << endl;
        return true;
    }

    // Método para mostrar el promedio de un estudiante
    void mostrarPromedioEstudiante() {

        string codigo;
        setColor(CYAN);
        cout << "\n--- Promedio de Estudiante ---" << endl;
        setColor(BLANCO);
        cout << "Ingrese el código del estudiante: ";
        cin >> codigo;

        int indice = buscarEstudiante(codigo);
        
        if (indice != -1) {
            float promedio = estudiantes[indice].calcularPromedio();
            cout << "Estudiante: " << estudiantes[indice].nombre << endl;
            cout << "Promedio: " << promedio << endl;
            
        } else {
            cout << "No se encontró un estudiante con el código: " << codigo << endl;
        }
    }

    void mostrarMatrizNotas() {
    setColor(CYAN);
    cout << "\n--- Matriz de Notas ---\n";
    cout << "------------------------------------------------------------\n";
    setColor(BLANCO);
    
    cout << left 
         << setw(20) << "Estudiante" 
         << setw(8)  << "Nota 1" 
         << setw(8)  << "Nota 2" 
         << setw(8)  << "Nota 3" 
         << setw(10) << "Promedio" 
         << "\n";
    setColor(CYAN);
    cout << "------------------------------------------------------------\n";
    setColor(BLANCO);
    for (int i = 0; i < totalEstudiantes; i++) {
        cout << left 
             << setw(20) << estudiantes[i].nombre 
             << setw(8)  << fixed << setprecision(1) << matrizNotas[i][0]
             << setw(8)  << fixed << setprecision(1) << matrizNotas[i][1]
             << setw(8)  << fixed << setprecision(1) << matrizNotas[i][2]
             << setw(10) << fixed << setprecision(2) << estudiantes[i].calcularPromedio()
             << "\n";
    }
    setColor(CYAN);
    cout << "------------------------------------------------------------\n";
    setColor(BLANCO);
}
};

// Función para mostrar el menú principal
void mostrarMenu() {
	setColor(CYAN);
    cout << "Menu principal" << endl;
    setColor(BLANCO);
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Buscar estudiante por codigo" << endl;
    cout << "3. Asignar o actualizar notas" << endl;
    cout << "4. Mostrar promedio de estudiante" << endl;
    cout << "5. Mostrar matriz de notas" << endl;
    cout << "6. salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    // Mensaje de bienvenida
    
    cout<< "~ Bienvenido/a al sistema de gestion de estudiantes y calificaciones de POO ~" << endl; 
    SistemaGestion sistema;
    int opcion;
    
    while (true) {
        mostrarMenu();
        cin >> opcion;
        
        if (opcion == 1) {
            sistema.registrarEstudiante();
        } 

        else if (opcion == 2) {
            sistema.buscarYMostrarEstudiante();
        } 
        else if (opcion == 3) {
            sistema.asignarNotasEstudiante();
        } 
        else if (opcion == 4) {
            sistema.mostrarPromedioEstudiante();
        } 
        else if (opcion == 5) {
            sistema.mostrarMatrizNotas();
        } 
        else if (opcion == 6) {
        	setColor(ROJO);
            cout << "Salio del sistema" << endl;
            setColor(BLANCO);
            break;
        } 
        else {
            cout << "Debes seleccionar una opción entre 1 y 7" << endl;
        }
    }
    
    return 0;
}