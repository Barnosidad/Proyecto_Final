#include <iostream>

struct Nodo
{
    // type
    int dato;
    // pointer to next nodo, if is the first node points to null
    Nodo *siguiente;
};

void print_menu(int *ptr_value);
void print_menu_pilas(int *ptr_value);
void pedirDatosV(int *ptr_value);
void agregar_pila(Nodo *&pila, int n);
bool salirC(char opc);
void eliminarNodos(Nodo *&pila);
bool pila_existente(Nodo *&pila);
void recorrerPila(Nodo *&pila);
void pila_par(Nodo *&pilaS, Nodo *&pilaO);
void eliminadorDePilas(Nodo *&pilaOriginal,Nodo *&pilaNoRepetidos, Nodo *&pilaPares, Nodo *&pilaImpares,Nodo *&pilaPositivos,Nodo *&pilaNegativos);

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
    bool salir = false, salir_v = false;;
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
                if(pila_existente(pila_original))
                {
                    do
                    {
                        print_menu_pilas(ptr_n);
                        switch (*ptr_n)
                        {
                            case 1:
                                recorrerPila(pila_original);
                                break;
                            case 3:
                                pila_par(pila_original,pila_pares);
                                if(pila_existente(pila_pares))
                                {
                                    recorrerPila(pila_pares);
                                }
                                else
                                {
                                    std::cout << "No se logro crear la pila pares" << std::endl;
                                }
                                break;
                            default:
                                salir_v = true;
                                break;
                        }
                    } while (!salir_v);
                    break;
                }
                else
                {
                    std::cout << "Y la pila papito?" << std::endl;
                    break;
                }
            case 4:
                eliminadorDePilas(pila_original,pila_no_repetidos,pila_pares,pila_impares,pila_positivos,pila_negativos);
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

void recorrerPila(Nodo *&pila)
{
    Nodo *aux = pila;
    int i = 0;
    do
    {
        std::cout<< i << " .[" << aux->dato << "].\n" << std::endl;
        aux = aux->siguiente;
        i++;
    }while(aux!=NULL);
}

void print_menu_pilas(int *ptr_value)
{
    std::cout << "Menu pilas" << std::endl;
    std::cout << "1. Pila original" << std::endl;
    std::cout << "2. Pila sin numeros repetidos" << std::endl;
    std::cout << "3. Pila numeros pares" << std::endl;
    std::cout << "4. Pila numeros impares" << std::endl;
    std::cout << "5. Pila numeros positivos" << std::endl;
    std::cout << "6. Pila numeros negativos" << std::endl;
    std::cout << "7. Regresar al menu principal" << std::endl;
    std::cout << "Ingresa una opcion" << std::endl;
    pedirDatosV(ptr_value);
}

void pila_par(Nodo *&pilaS, Nodo *&pilaO)
{
    Nodo *aux = pilaS;
    do
    {
        if(aux->dato % 2 == 0)
        {
            Nodo *nuevo_nodo = new Nodo();
            nuevo_nodo->dato = aux->dato;
            nuevo_nodo->siguiente = pilaO;
            pilaO = nuevo_nodo;
        }
        aux = aux->siguiente;
    }while(aux!=NULL);
}

void eliminadorDePilas(Nodo *&pilaOriginal,Nodo *&pilaNoRepetidos, Nodo *&pilaPares, Nodo *&pilaImpares,Nodo *&pilaPositivos,Nodo *&pilaNegativos)
{
    if(pila_existente(pilaOriginal))
    {
       std::cout << "Pila Original eliminada" << std::endl;
        eliminarNodos(pilaOriginal);
    }
    else
    {
        std::cout << "Y la pila original papito?" << std::endl;
        return;
    }
    if(pila_existente(pilaNoRepetidos))
    {
        std::cout << "Pila Original eliminada" << std::endl;
        eliminarNodos(pilaNoRepetidos);
    }
    if(pila_existente(pilaPares))
    {
        std::cout << "Pila Original eliminada" << std::endl;
        eliminarNodos(pilaPares);
    }
    if(pila_existente(pilaImpares))
    {
        std::cout << "Pila Original eliminada" << std::endl;
        eliminarNodos(pilaImpares);
    }
    if(pila_existente(pilaPositivos))
    {
        std::cout << "Pila Original eliminada" << std::endl;
        eliminarNodos(pilaPositivos);
    }
    if(pila_existente(pilaNegativos))
    {
        std::cout << "Pila Original eliminada" << std::endl;
        eliminarNodos(pilaNegativos);
    }
}