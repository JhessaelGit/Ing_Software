#pragma once
#include <iostream>
#include "Nodo.h"
#include <random>
using namespace std;

template <typename T>
class Lista8
{
public:
    Nodo<T>* primer = NULL;
    Nodo<T>* ultimo = NULL;
    int contador = 0;
public:
    ~Lista8();
    bool insertarPrincipio(T elem);
    bool insertarFinal(T elem);
    bool eliminarPrincipio();
    bool eliminarFinal();
    void mostrar();
    bool buscar(T elemBuscado);
    bool eliminarElemDado(T elemBuscado);
    Nodo<T>* bucarEnesimoElem(int posicionBuscada);
    bool eliminarTodo();
//    T randomL8();
    int getContador();
    void disminuircont();

    Nodo<T>* getPrimer();
    Nodo<T>* getUltimo();

    void setPrimer(Nodo<T> primer);
};


template<typename T>
inline Lista8<T>::~Lista8()
{
    eliminarTodo();
}


template<typename T>
inline bool Lista8<T>::insertarPrincipio(T elem)
{
    bool resp = false;
    if (primer == NULL)
    {
        primer = new Nodo<T>();
        primer->setElem(elem);
        ultimo = primer;
        resp = true;
        contador++;
    }
    else
    {
        Nodo<T>* aux = new Nodo<T>();
        aux->setElem(elem);
        aux->setSiguiente(primer);
        primer->setAnterior(aux);
        primer = aux;
        resp = true;
        contador++;
    }
    return resp;
}

template<typename T>
inline bool Lista8<T>::insertarFinal(T elem)
{
    bool resp = false;
    if (ultimo == NULL)
    {
        ultimo = new Nodo<T>();
        ultimo->setElem(elem);
        primer = ultimo;
        resp = true;
        contador++;
    }
    else
    {
        Nodo<T>* aux = new Nodo<T>();
        aux->setElem(elem);
        aux->setAnterior(ultimo);
        ultimo->setSiguiente(aux);
        ultimo = aux;
        resp = true;
        contador++;
    }

    return resp;
}

template<typename T>
inline bool Lista8<T>::eliminarPrincipio()
{
    bool resp;
    if (primer == NULL) {
        resp = false;
    }
    else {
        resp = true;
        if (primer != ultimo) {
            primer = primer->getSiguiente();
            delete primer->getAnterior();
            primer->setAnterior(NULL);
        }
        else {
            delete primer;
            primer = NULL;
            ultimo = NULL;
        }
    }
    return resp;
}

template<typename T>
inline bool Lista8<T>::eliminarFinal()
{
    bool resp;
    if (ultimo == NULL) {
        resp = false;
    }
    else {
        resp = true;
        if (primer != ultimo) {
            ultimo = ultimo->getAnterior();
            delete ultimo->getSiguiente();
            ultimo->setSiguiente(NULL);
        }
        else {
            delete ultimo;
            primer = NULL;
            ultimo = NULL;
        }
    }
    return resp;
}

template<typename T>
inline void Lista8<T>::mostrar()
{
    Nodo<T>* i = primer;
    while (i != NULL) {
        cout << i->getElem() << " - ";
        i = i->getSiguiente();
    }
    cout << endl;
}

template<typename T>
inline bool Lista8<T>::buscar(T elemBuscado)
{
    bool resp = false;
    Nodo<T>* i = primer;
    if (primer == NULL) {
        resp = false;
    }
    else {
        do {
            if (i->getElem() == elemBuscado) {
                resp = true;
            }
            else {
                i = i->getSiguiente();
            }
        } while (i != NULL && resp == false);
    }
    return resp;
}

template<typename T>
inline bool Lista8<T>::eliminarElemDado(T elemBuscado)
{
    bool resp = false;
    Nodo<T>* i = primer;

    if (primer == NULL) {
        // La lista está vacía
        return false;
    }

    while (i != NULL && !resp) {
        if (i->getElem() == elemBuscado) {
            if (i == primer) {
                // Eliminar el primer nodo
                if (primer == ultimo) {
                    // Solo hay un elemento en la lista
                    delete primer;
                    primer = ultimo = NULL;
                }
                else {
                    // Más de un elemento
                    primer = primer->getSiguiente();
                    delete primer->getAnterior();
                    primer->setAnterior(NULL);
                }
            }
            else if (i == ultimo) {
                // Eliminar el último nodo
                ultimo = ultimo->getAnterior();
                delete ultimo->getSiguiente();
                ultimo->setSiguiente(NULL);
            }
            else {
                // Eliminar un nodo en el medio
                Nodo<T>* Ant = i->getAnterior();
                Nodo<T>* Sig = i->getSiguiente();
                Ant->setSiguiente(Sig);
                Sig->setAnterior(Ant);
                delete i;
            }
            resp = true;
        }
        else {
            i = i->getSiguiente();
        }
    }

    return resp;
}


template<typename T>
inline Nodo<T>* Lista8<T>::bucarEnesimoElem(int posicionBuscada)
{
    Nodo<T>* NodoBuscado = primer;
    int i = 0;
    if (primer != NULL && posicionBuscada >= 0) {
        while (NodoBuscado != NULL && i < posicionBuscada) {
            NodoBuscado = NodoBuscado->getSiguiente();
            i++;
        }
    }
    else {
        NodoBuscado = NULL;
    }
    return NodoBuscado;
}

template<typename T>
inline bool Lista8<T>::eliminarTodo()
{
    bool resp = false;
    Nodo<T>* i = primer;
    Nodo<T>* sigNodo;
    if (primer != NULL) {
        do {
            sigNodo = i->getSiguiente();
            delete i;
            i = sigNodo;
        } while (i != NULL);
        primer = NULL;
        ultimo = NULL;
        resp = true;
    }
    return resp;
}


/*template<typename T>
inline T Lista8<T>::randomL8()
{
    T aux;
    random_device rd;
    mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, contador - 1);
    int num1 = dis(gen);
    return aux;
}*/

template<typename T>
inline int Lista8<T>::getContador()
{
    return contador;
}

template<typename T>
inline void Lista8<T>::disminuircont()
{
    contador--;
}

template<typename T>
inline Nodo<T>* Lista8<T>::getPrimer()
{
    return primer;
}

template<typename T>
inline Nodo<T>* Lista8<T>::getUltimo()
{
    return ultimo;
}

