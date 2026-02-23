#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

// Operaciones
float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) {
    if (b == 0) {
        cerr << "Error: División por cero no permitida." << endl;
        exit(1);
    }
    return a / b;
}

typedef float (*Operation)(float, float);

int main() {
    float op1, op2;
    string operador;

    cout << "Ingrese el primer número: ";
    cin >> op1;
    cout << "Ingrese el operador (+, -, *, x, /): ";
    cin >> operador;
    cout << "Ingrese el segundo número: ";
    cin >> op2;

    map<string, Operation> operations = {
        {"+", add},
        {"-", subtract},
        {"*", multiply},
        {"x", multiply},
        {"X", multiply},
        {"/", divide}
    };

    if (operations.find(operador) == operations.end()) {
        cerr << "Error: Operador no válido. Use +, -, *, x o /" << endl;
        return 1;
    }

    Operation callback = operations[operador];
    float resultado = callback(op1, op2);

    cout << op1 << " " << operador << " " << op2 << " = " << resultado << endl;
    return 0;
}
