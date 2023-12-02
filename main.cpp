#include <iostream>
#include <string>

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
void eliminarNodo(Nodo *&pila);
bool pila_existente(Nodo *&pila);
void recorrerPila(Nodo *&pila);
bool b_existencias(Nodo *&pila, int n);
bool pila_no_repetido(Nodo *&pilaS, Nodo *&pilaO);
bool pila_par(Nodo *&pilaS, Nodo *&pilaO);
bool pila_impar(Nodo *&pilaS, Nodo *&pilaO);
bool pila_positivo(Nodo *&pilaS, Nodo *&pilaO);
bool pila_negativo(Nodo *&pilaS, Nodo *&pilaO);
void eliminadorDePilas(Nodo *&pilaOriginal,Nodo *&pilaNoRepetidos, Nodo *&pilaPares, Nodo *&pilaImpares,Nodo *&pilaPositivos,Nodo *&pilaNegativos);
void actualizador_pilas(Nodo *&pilaNoRepetidos, Nodo *&pilaPares, Nodo *&pilaImpares,Nodo *&pilaPositivos,Nodo *&pilaNegativos);
void pilas_existentes(Nodo *&pilaOriginal,Nodo *&pilaNoRepetidos, Nodo *&pilaPares, Nodo *&pilaImpares,Nodo *&pilaPositivos,Nodo *&pilaNegativos);
bool noRepetido(Nodo*pila_no_repetidos,int auxdato);

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
    // Cuerpo del programa
    do
    {
        pilas_existentes(pila_original,pila_no_repetidos,pila_pares,pila_impares,pila_positivos,pila_negativos);
        print_menu(ptr_n);
        switch (*ptr_n)
        {
            case 1:
                do
                {
                    std::cout << "\tIngresa un numero para la pila -> " << std::endl;
                    pedirDatosV(ptr_n);
                    agregar_pila(pila_original,n);
                    std::cout << "Deseas salir (s/n): " << std::endl;
                    std::cin >> opc;
                } while (!salirC(opc));
                actualizador_pilas(pila_no_repetidos,pila_pares,pila_impares,pila_positivos,pila_negativos);
                break;
            case 2:
                eliminarNodo(pila_original);
                actualizador_pilas(pila_no_repetidos,pila_pares,pila_impares,pila_positivos,pila_negativos);
                break;
            case 3:
                if(pila_existente(pila_original))
                {
                    bool salir_v = false;
                    do
                    {
                        print_menu_pilas(ptr_n);
                        switch (*ptr_n)
                        {
                            case 1:
                                recorrerPila(pila_original);
                                break;
                            case 2:{

							    Nodo* aux = pila_original;
							    while (aux!=NULL) 
								{
							        if (noRepetido(pila_no_repetidos, aux->dato)) 
									{
							            Nodo* nuevo_nodo=new Nodo();
							            nuevo_nodo->dato=aux->dato;
							            nuevo_nodo->siguiente=pila_no_repetidos;
							            pila_no_repetidos=nuevo_nodo;
							    	}
							    	
							        aux=aux->siguiente;
							    }
									
									Nodo*auxiliar=pila_no_repetidos;
								    while(auxiliar!=NULL) 
									{
								        std::cout<<".["<<auxiliar->dato<<"]."<<"\n";
								        auxiliar=auxiliar->siguiente;
								    }
								    std::cout << "\n";
									
									
                                break;
                            }
                            case 3:
                                if(pila_par(pila_original,pila_pares))
                                {
                                    recorrerPila(pila_pares);
                                }
                                else
                                {
                                    std::cout << "*NO se logro crear la pila pares*" << std::endl;
                                }
                                break;
                            case 4:
                                if(pila_impar(pila_original,pila_impares))
                                {
                                    recorrerPila(pila_impares);
                                }
                                else
                                {
                                    std::cout << "*NO se logro crear la pila impares*" << std::endl;
                                }
                                break;
                            case 5:
                                if(pila_positivo(pila_original,pila_positivos))
                                {
                                    recorrerPila(pila_positivos);
                                }
                                else
                                {
                                    std::cout << "*NO se logro crear la pila positivos*" << std::endl;
                                }
                                break;
                            case 6:
                                if(pila_negativo(pila_original,pila_negativos))
                                {
                                    recorrerPila(pila_negativos);
                                }
                                else
                                {
                                    std::cout << "*NO se logro crear la pila negativos*" << std::endl;
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
                    std::cout << "*NO HAY UNA PILA QUE VISUALIZAR*" << std::endl;
                    break;
                }
            case 4:
                eliminadorDePilas(pila_original,pila_no_repetidos,pila_pares,pila_impares,pila_positivos,pila_negativos);
                break;
            default:
                if(pila_existente(pila_original))
                {
                    std::cout << "*PARA SALIR DEBES DE ELIMINAR LAS PILAS*" << std::endl;
                    break;
                }
                else
                {
                    salir = true;
                    break;
                }
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
    std::cout << "\t\t\t.:PILAS:." << std::endl;
    std::cout << "\t1. Agregar Nodos" << std::endl;
    std::cout << "\t2. Eliminar un solo nodo" << std::endl;
    std::cout << "\t3. Ver pilas" << std::endl;
    std::cout << "\t4. Eliminar todas las pilas" << std::endl;
    std::cout << "\t5. Salir" << std::endl;
    std::cout << "Ingresa una opcion: " << std::endl;
    pedirDatosV(ptr_value);
}

void eliminarNodos(Nodo *&pila)
{
    int i = 0;
    Nodo *aux;
    do
    {
        aux = pila;
        std::cout<< i << " .[" << aux->dato << "] eliminado." << std::endl;
        pila = pila->siguiente;
        i++;
        delete aux;
    }while(pila!=NULL);
}

void eliminarNodo(Nodo *&pila)
{
    Nodo *aux;
    if(pila_existente(pila))
    {
        aux = pila;
        std::cout << " .[" << aux->dato << "] eliminado." << std::endl;
        pila = pila->siguiente;
        delete aux;
    }
    else
    {
        std::cout << "*NO HAY PILA QUE ELIMINAR*" << std::endl;
    }
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
        std::cout<< i << " .[" << aux->dato << "]." << std::endl;
        aux = aux->siguiente;
        i++;
    }while(aux!=NULL);
}

void print_menu_pilas(int *ptr_value)
{
    std::cout << "\t\t\t.:Menu pilas:." << std::endl;
    std::cout << "\t1. Pila original" << std::endl;
    std::cout << "\t2. Pila sin numeros repetidos" << std::endl;
    std::cout << "\t3. Pila numeros pares" << std::endl;
    std::cout << "\t4. Pila numeros impares" << std::endl;
    std::cout << "\t5. Pila numeros positivos" << std::endl;
    std::cout << "\t6. Pila numeros negativos" << std::endl;
    std::cout << "\t7. Regresar al menu principal" << std::endl;
    std::cout << "Ingresa una opcion: " << std::endl;
    pedirDatosV(ptr_value);
}

bool b_existencias(Nodo *&pila, int n)
{
    Nodo *aux = pila;
    int i = 0;
    bool b_existencia = false;
    while(aux!=NULL)
    {
        if(aux->dato == n)
        {
            i++;
        }
        aux = aux->siguiente;
    }
    if(i > 1)
    {
        std::cout << "Numero " << n << " repetido." << std::endl;
        b_existencia = true;
    }
    return b_existencia;
}

bool pila_no_repetido(Nodo *&pilaS, Nodo *&pilaO)
{
    Nodo *aux = pilaS;
    if(pila_existente(pilaO)) return true;
    do
    {
        if(!b_existencias(aux,aux->dato))
        {
            Nodo *nuevo_nodo = new Nodo();
            nuevo_nodo->dato = aux->dato;
            nuevo_nodo->siguiente = pilaO;
            pilaO = nuevo_nodo;
        }
        aux = aux->siguiente;
    } while (aux!=NULL);
    return pila_existente(pilaO);
}

bool pila_par(Nodo *&pilaS, Nodo *&pilaO)
{
    Nodo *aux = pilaS;
    if(pila_existente(pilaO)) return true;
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
    return pila_existente(pilaO);
}

bool pila_impar(Nodo *&pilaS, Nodo *&pilaO)
{
    Nodo *aux = pilaS;
    if(pila_existente(pilaO)) return true;
    do
    {
        if(aux->dato % 2 != 0)
        {
            Nodo *nuevo_nodo = new Nodo();
            nuevo_nodo->dato = aux->dato;
            nuevo_nodo->siguiente = pilaO;
            pilaO = nuevo_nodo;
        }
        aux = aux->siguiente;
    }while(aux!=NULL);
    return pila_existente(pilaO);
}

bool pila_positivo(Nodo *&pilaS, Nodo *&pilaO)
{
    Nodo *aux = pilaS;
    if(pila_existente(pilaO)) return true;
    do
    {
        if(aux->dato > 0)
        {
            Nodo *nuevo_nodo = new Nodo();
            nuevo_nodo->dato = aux->dato;
            nuevo_nodo->siguiente = pilaO;
            pilaO = nuevo_nodo;
        }
        aux = aux->siguiente;
    }while(aux!=NULL);
    return pila_existente(pilaO);
}

bool pila_negativo(Nodo *&pilaS, Nodo *&pilaO)
{
    Nodo *aux = pilaS;
    if(pila_existente(pilaO)) return true;
    do
    {
        if(aux->dato < 0)
        {
            Nodo *nuevo_nodo = new Nodo();
            nuevo_nodo->dato = aux->dato;
            nuevo_nodo->siguiente = pilaO;
            pilaO = nuevo_nodo;
        }
        aux = aux->siguiente;
    }while(aux!=NULL);
    return pila_existente(pilaO);
}

void eliminadorDePilas(Nodo *&pilaOriginal,Nodo *&pilaNoRepetidos, Nodo *&pilaPares, Nodo *&pilaImpares,Nodo *&pilaPositivos,Nodo *&pilaNegativos)
{
    if(pila_existente(pilaOriginal))
    {
       std::cout << "*Pila Original eliminada*" << std::endl;
        eliminarNodos(pilaOriginal);
    }
    else
    {
        std::cout << "NO HAY PILA QUE ELIMINAR" << std::endl;
        return;
    }
    if(pila_existente(pilaNoRepetidos))
    {
        std::cout << "*Pila No Repetidos eliminada*" << std::endl;
        eliminarNodos(pilaNoRepetidos);
    }
    if(pila_existente(pilaPares))
    {
        std::cout << "*Pila Pares eliminada*" << std::endl;
        eliminarNodos(pilaPares);
    }
    if(pila_existente(pilaImpares))
    {
        std::cout << "*Pila Impares eliminada*" << std::endl;
        eliminarNodos(pilaImpares);
    }
    if(pila_existente(pilaPositivos))
    {
        std::cout << "*Pila Positivos eliminada*" << std::endl;
        eliminarNodos(pilaPositivos);
    }
    if(pila_existente(pilaNegativos))
    {
        std::cout << "*Pila Negativos eliminada*" << std::endl;
        eliminarNodos(pilaNegativos);
    }
}

void actualizador_pilas(Nodo *&pilaNoRepetidos, Nodo *&pilaPares, Nodo *&pilaImpares,Nodo *&pilaPositivos,Nodo *&pilaNegativos)
{
    if(pila_existente(pilaNoRepetidos))
    {
        std::cout << "*Pila No Repetidos actualizada*" << std::endl;
        eliminarNodos(pilaNoRepetidos);
    }
    if(pila_existente(pilaPares))
    {
        std::cout << "*Pila Pares actualizada*" << std::endl;
        eliminarNodos(pilaPares);
    }
    if(pila_existente(pilaImpares))
    {
        std::cout << "*Pila Impares actualizada*" << std::endl;
        eliminarNodos(pilaImpares);
    }
    if(pila_existente(pilaPositivos))
    {
        std::cout << "*Pila Positivos actualizada*" << std::endl;
        eliminarNodos(pilaPositivos);
    }
    if(pila_existente(pilaNegativos))
    {
        std::cout << "*Pila Negativos actualizada*" << std::endl;
        eliminarNodos(pilaNegativos);
    }
}

void pilas_existentes(Nodo *&pilaOriginal,Nodo *&pilaNoRepetidos, Nodo *&pilaPares, Nodo *&pilaImpares,Nodo *&pilaPositivos,Nodo *&pilaNegativos)
{
    std::string resultado;
    if(pila_existente(pilaOriginal)) resultado.append("|O|");
    if(pila_existente(pilaNoRepetidos)) resultado.append("NR|");
    if(pila_existente(pilaPares)) resultado.append("P|");
    if(pila_existente(pilaImpares)) resultado.append("I|");
    if(pila_existente(pilaPositivos)) resultado.append("PO|");
    if(pila_existente(pilaNegativos)) resultado.append("NE|");
    std::cout << "Pilas existentes -> " << resultado << std::endl;
}

bool noRepetido(Nodo* pila_no_repetidos, int auxdato) {
    while (pila_no_repetidos!=NULL) {
        if (pila_no_repetidos->dato==auxdato) {
            return false;
        }
        pila_no_repetidos=pila_no_repetidos->siguiente;
    }
    return true;
}