#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) {
    // Verificar que se proporcionen suficientes argumentos
    if (argc != 3) {
        cout << "Ejecutar como ./main <n> <seed>" << endl;
        return 1;
    }

    int n = atoi(argv[1]); // Tamaño de la matriz
    int seed = atoi(argv[2]);
    srand(seed); // Semilla para la generación de números aleatorios


    return 0;
}
