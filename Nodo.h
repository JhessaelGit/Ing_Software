#pragma once
#include <iostream>
template <typename T>
class Nodo
{
private:
    T elem;
    Nodo<T>* siguiente = NULL;
    Nodo<T>* anterior = NULL;
public:
    Nodo();
    Nodo(T& elem);
    ~Nodo();

    T getElem();
    Nodo<T>* getSiguiente();
    Nodo<T>* getAnterior();

    void setElem(T elem);
    void setSiguiente(Nodo<T>* siguiente);
    void setAnterior(Nodo<T>* anterior);
};

template<typename T>
inline Nodo<T>::Nodo()
{
}

template<typename T>
inline Nodo<T>::Nodo(T& elem)
{
    this->elem = elem;
}

template<typename T>
inline Nodo<T>::~Nodo()
{
}

template<typename T>
T Nodo<T>::getElem()
{
    return elem;
}

template<typename T>
inline Nodo<T>* Nodo<T>::getSiguiente()
{
    return siguiente;
}

template<typename T>
inline Nodo<T>* Nodo<T>::getAnterior()
{
    return anterior;
}

template<typename T>
inline void Nodo<T>::setElem(T elem)
{
    this->elem = elem;
}

template<typename T>
inline void Nodo<T>::setSiguiente(Nodo<T>* siguiente)
{
    this->siguiente = siguiente;
}

template<typename T>
inline void Nodo<T>::setAnterior(Nodo<T>* anterior)
{
    this->anterior = anterior;
}
