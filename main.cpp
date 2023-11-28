#include <iostream>

struct Nodo
{
    // type
    int dato;
    // pointer to next nodo, if is the first node points to null
    Nodo *siguiente;
};

void print_menu(int *ptr_value);
void pedirDatosV(int *ptr_value);
void agregar_pila(Nodo *&pila, int n);
bool salirC(char opc);
void eliminarNodos(Nodo *&pila);
bool pila_existente(Nodo *&pila);

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
    char opc;
    bool salir = false;
    do
    {
        print_menu(ptr_n);
        switch (*ptr_n)
        {
            case 1:
                do
                {
                    std::cout << "Ingresa un numero para la pila: " << std::endl;
                    pedirDatosV(ptr_n);
                    agregar_pila(pila_original,n);
                    std::cout << "Deseas salir s/n" << std::endl;
                    std::cin >> opc;
                } while (!salirC(opc));
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                if(!pila_existente(pila_original))
                {
                    std::cout << "Y la pila socio?" << std::endl;
                    break;
                }
                else
                {
                    eliminarNodos(pila_original);
                }
                break;
            case 5:
                salir = true;
                break;
            default:
                salir = true;
                break;
        }
    } while (!salir);
    return 0;
}

void pedirDatosV(int *ptr_value)
{
    std::cin >> *ptr_value;
}

void agregar_pila(Nodo *&pila, int n)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    std::cout << "Elemento " << n << " agregado a la pila.\n";
}

bool salirC(char opc)
{
    if(opc=='s'||opc=='S') return true;
    else return false;
}

void print_menu(int *ptr_value)
{
    std::cout << "Hola tonotos!" << std::endl;
    std::cout << "1. Agregar Nodos" << std::endl;
    std::cout << "2. Eliminar un solo nodo" << std::endl;
    std::cout << "3. Ver pilas" << std::endl;
    std::cout << "4. Eliminar todas las pilas" << std::endl;
    std::cout << "5. Salir" << std::endl;
    std::cout << "Ingresa una opcion" << std::endl;
    pedirDatosV(ptr_value);
}

void eliminarNodos(Nodo *&pila)
{
    int i = 0;
    Nodo *aux;
    do
    {
        aux = pila;
        std::cout<< i << " .[" << aux->dato << "] eliminado.\n" << std::endl;
        pila = pila->siguiente;
        i++;
        delete aux;
    }while(pila!=NULL);
}

bool pila_existente(Nodo *&pila)
{
    return (pila == NULL)? false : true;
}