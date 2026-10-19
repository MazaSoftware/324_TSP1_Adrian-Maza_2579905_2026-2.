#include <iostream>

// Creamos la clase Persona para representar a cada persona en la cola
class Persona {
public:
    int numeroCorrelativo;
    int tipoOperacion;
    Persona* siguiente;

    Persona(int correlativo, int operacion) {
        numeroCorrelativo = correlativo;
        tipoOperacion = operacion;
        siguiente = nullptr;
    }
};

// Clase para la Cola
class Cola {
public:
    Persona* frente;
    Persona* fin;

    Cola() {
        frente = nullptr;
        fin = nullptr;
    }

    // Metodo para agregar elementos a la cola
    void encolar(int correlativo, int operacion) {
        Persona* nuevo = new Persona(correlativo, operacion);
        if (frente == nullptr) {
            frente = nuevo;
            fin = nuevo;
        } else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
    }

    // Metodo para extraer elementos de la cola
    bool desencolar(int& correlativo, int& operacion) {
        if (frente == nullptr) return false;
        Persona* temp = frente;
        correlativo = temp->numeroCorrelativo;
        operacion = temp->tipoOperacion;
        frente = frente->siguiente;
        if (frente == nullptr) fin = nullptr;
        delete temp;
        return true;
    }
};

// Funcion solicitada: Distribuir elementos en tres colas según el tipo de operación
void Distribuir(Cola& colaGeneral, Cola& cola1, Cola& cola2, Cola& cola3) {
    int correlativo, operacion;
    while (colaGeneral.desencolar(correlativo, operacion)) {
        if (operacion >= 1 && operacion <= 3) {
            cola1.encolar(correlativo, operacion);
        } else if (operacion >= 4 && operacion <= 6) {
            cola2.encolar(correlativo, operacion);
        } else if (operacion >= 7 && operacion <= 9) {
            cola3.encolar(correlativo, operacion);
        }
    }
}

// Prueba para verificar que la distribucion funciona correctamente
int main() {
    Cola colaGeneral, cola1, cola2, cola3;

    // Insertar datos de prueba (Correlativo, Operacion)
    colaGeneral.encolar(1, 2); // Va a Cola 1 (ops 1,2,3)
    colaGeneral.encolar(2, 5); // Va a Cola 2 (ops 4,5,6)
    colaGeneral.encolar(3, 8); // Va a Cola 3 (ops 7,8,9)

    // Ejecutar distribución
    Distribuir(colaGeneral, cola1, cola2, cola3);

    // Verificar resultado en terminal
    std::cout << "Distribucion completada con exito." << std::endl;
    if (cola1.frente != nullptr) 
        std::cout << "Cola 1 tiene al correlativo: " << cola1.frente->numeroCorrelativo << std::endl;
    if (cola2.frente != nullptr) 
        std::cout << "Cola 2 tiene al correlativo: " << cola2.frente->numeroCorrelativo << std::endl;
    if (cola3.frente != nullptr) 
        std::cout << "Cola 3 tiene al correlativo: " << cola3.frente->numeroCorrelativo << std::endl;

    return 0;
}