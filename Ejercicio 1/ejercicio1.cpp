#include <iostream>

using namespace std;

class CadenaBinaria {
public:
    int bits[8]; // El TAD correcto es un rreglo publico de 8 elementos para almacenar los bits (0 o 1)

    // Tenemos que tener un constructor por defecto: inicializa la cadena en ceros
    CadenaBinaria() {
        for (int i = 0; i < 8; i++) {
            bits[i] = 0;
        }
    }

    // Este es el metodo para imprimir la cadena por pantalla
    void mostrar() const {
        for (int i = 0; i < 8; i++) {
            cout << bits[i];
        }
        cout << endl;
    }

    // Ahora si la funcion que aplica la Transformación Gray usando directamente el operador XOR como me pidio el ejercicio
    CadenaBinaria calcularGray() const {
        CadenaBinaria resultado;
        
        // El primer bit (indice 0) se queda igual: G_0 = b_0
        resultado.bits[0] = bits[0];
        
        // A partir del segundo bit, aplicamos la formula: G_i = XOR(b_i, b_{i-1})
        for (int i = 1; i < 8; i++) {
            resultado.bits[i] = bits[i] ^ bits[i - 1];
        }
        
        return resultado;
    }
};

int main() {
    // 1. Creamos nuestra instancia de la clase
    CadenaBinaria miCadena;

    // 2. Asignamos los valores de prueba directamente accediendo al arreglo publico
    int valoresPrueba[8] = {1, 0, 1, 1, 0, 1, 0, 1};
    for (int i = 0; i < 8; i++) {
        miCadena.bits[i] = valoresPrueba[i];
    }

    cout << "Cadena Original : ";
    miCadena.mostrar();

    // 3. Aplicamos la función Gray usando el metodo de nuestra clase
    CadenaBinaria cadenaGray = miCadena.calcularGray();

    cout << "Cadena en Gray  : ";
    cadenaGray.mostrar();

    return 0;
}