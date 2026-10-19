#include <iostream>

using namespace std;

/*Codifico la estructura de datos como una clase publica
 (se me hace mas facil para acceder a los atributos) para el nodo de la lista circular*/

class NodoCiudad {
public:
    int idCiudad;             // Numero de la ciudad (i)
    int distanciaSiguiente;   // Distancia hacia la ciudad siguiente (d_ij)
    NodoCiudad* siguiente;    // Puntero al nodo de la siguiente ciudad

    // Constructor para inicializar el nodo fácilmente
    NodoCiudad(int id, int distancia) {
        idCiudad = id;
        distanciaSiguiente = distancia;
        siguiente = nullptr;
    }
};

// b. Funcion Recorrido para imprimir la ruta y calcular la distancia total como pide el ejercicio
void Recorrido(NodoCiudad* cabeza) {
    if (cabeza == nullptr) {
        cout << "La ruta esta vacia." << endl;
        return;
    }

    NodoCiudad* actual = cabeza;
    int distanciaTotal = 0;

    cout << "Ruta del agente de ventas: ";
    
    // Recorremos la lista circular usando un ciclo do-while
    do {
        // Acceso directo a los atributos 
        cout << actual->idCiudad;
        distanciaTotal += actual->distanciaSiguiente;
        actual = actual->siguiente;

        if (actual != cabeza) {
            cout << " -> ";
        }
    } while (actual != cabeza);

    // Muestra el cierre del circuito regresando al origen
    cout << " -> " << cabeza->idCiudad << " (Regreso al origen)" << endl;
    cout << "Distancia total a recorrer: " << distanciaTotal << " km" << endl;
}

// Función principal (main) para probar el funcionamiento
int main() {
    // Ejemplo basado en la ruta: (2 -> 3 -> 9 -> 4 -> 6 -> 2
    NodoCiudad* nodo2 = new NodoCiudad(2, 15);
    NodoCiudad* nodo3 = new NodoCiudad(3, 25);
    NodoCiudad* nodo9 = new NodoCiudad(9, 10);
    NodoCiudad* nodo4 = new NodoCiudad(4, 20);
    NodoCiudad* nodo6 = new NodoCiudad(6, 30);

    // Enlazamos los nodos directamente modificando el atributo 'siguiente'
    nodo2->siguiente = nodo3;
    nodo3->siguiente = nodo9;
    nodo9->siguiente = nodo4;
    nodo4->siguiente = nodo6;
    nodo6->siguiente = nodo2; // El último apunta al primero cerrando el círculo

    // Ejecutamos la función solicitada
    Recorrido(nodo2);

    // Liberación de memoria dinámica, esto es una buena practica aunque no es estrictamente necesario en este ejemplo simple
    delete nodo2;
    delete nodo3;
    delete nodo9;
    delete nodo4;
    delete nodo6;

    return 0;
}