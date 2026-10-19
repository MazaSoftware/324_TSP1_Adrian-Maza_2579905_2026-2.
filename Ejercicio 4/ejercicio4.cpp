#include <iostream>

class ArbolBinarioBusqueda {
private:
    // Clase privada interna para el nodo 
    class Nodo {
    private:
        int dato;
        Nodo* izq;
        Nodo* der;

    public:
        Nodo(int valor) : dato(valor), izq(nullptr), der(nullptr) {}

        // aqui ya aplique este recurso que me permite a la clase contenedora acceder directamente a los miembros privados
        friend class ArbolBinarioBusqueda;
    };

    Nodo* raiz;

    // Metodo auxiliar recursivo para insertar manteniendo el orden de ABB estricto
    Nodo* insertarRecursivo(Nodo* nodo, int valor) {
        if (nodo == nullptr) {
            return new Nodo(valor);
        }
        if (valor < nodo->dato) {
            nodo->izq = insertarRecursivo(nodo->izq, valor);
        } else if (valor > nodo->dato) {
            nodo->der = insertarRecursivo(nodo->der, valor);
        }
        return nodo;
    }

    // Funcion recursiva para buscar el nodo y calcular su grado (0, 1 o 2)
    int calcularGrado(Nodo* nodo, int busqueda) {
        if (nodo == nullptr) {
            return -1; // Indicador de que no se encontró
        }
        if (busqueda == nodo->dato) {
            // Suma booleana para contar cuantos hijos no nulos posee el nodo
            return (nodo->izq != nullptr) + (nodo->der != nullptr);
        }
        if (busqueda < nodo->dato) {
            return calcularGrado(nodo->izq, busqueda);
        } else {
            return calcularGrado(nodo->der, busqueda);
        }
    }

public:
    // Constructor
    ArbolBinarioBusqueda() : raiz(nullptr) {}

    // Metodo para insertar valores respetando la propiedad de ABB
    void insertar(int valor) {
        raiz = insertarRecursivo(raiz, valor);
    }

    // Método público para evaluar el grado y emitir el mensaje requerido si no existe
    void evaluarGrado(int busqueda) {
        int resultado = calcularGrado(raiz, busqueda);
        if (resultado == -1) {
            std::cout << "El árbol binario, no es necesariamente completo y no presenta números repetidos\n";
        } else {
            std::cout << "El grado del nodo " << busqueda << " es: " << resultado << "\n";
        }
    }
};

int main() {
    ArbolBinarioBusqueda arbol;

    // Construcción automática del árbol asegurando el comportamiento de ABB 
    // (Valores basados en la estructura analizada del examen)
    arbol.insertar(18);
    arbol.insertar(11);
    arbol.insertar(23);
    arbol.insertar(7);
    arbol.insertar(15);
    arbol.insertar(20);
    arbol.insertar(25);
    arbol.insertar(13);

    std::cout << "--- PRUEBAS DE GRADO EN EL ARBOL ---" << std::endl;
    
    // Pruebas solicitadas
    arbol.evaluarGrado(11); // Debe retornar Grado 2 (hijos 7 y 15)
    arbol.evaluarGrado(7);  // Debe retornar Grado 0 (nodo hoja)
    arbol.evaluarGrado(15); // Debe retornar Grado 1 (hijo 13)
    arbol.evaluarGrado(18); // Debe retornar Grado 2 (hijos 11 y 23)
    
    // Prueba de valor inexistente (dispara el mensaje reglamentario)
    arbol.evaluarGrado(99); 

    return 0;
}