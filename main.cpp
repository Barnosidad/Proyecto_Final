#include <iostream>

struct Nodo
{
    // type
    int dato;
    // pointer to next nodo, if is the first node points to null
    Nodo *siguiente;
};

void print_menu();
void pedirDatosV(int *ptr_value);
void agregar_pila(Nodo *&pila, int n);

int main()
{
    // Pilas
    Nodo *pila_original = NULL;
    Nodo *pila_no_repetidos = NULL;
    Nodo *pila_pares = NULL;
    Nodo *pila_impares = NULL;
    Nodo *pila_positivos = NULL;
    Nodo *pila_negativos = NULL;
    // Variables
    int n = 0, *ptr_n = &n;

    print_menu();
    return 0;
}

void agregar_pila(Nodo *&pila, int n)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    std::cout << "Elemento " << n << " agregado a la pila.\n";
}

void pedirDatosV(int *ptr_value)
{
    std::cout << "Ingresa un numero para la pila: " << std::endl;
    std::cin >> *ptr_value;
}

void print_menu()
{
    std::cout << "Hola tonotos!" << std::endl;
    std::cout << "1. Agregar Nodos" << std::endl;
    std::cout << "2. Adios" << std::endl;
}