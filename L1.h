#pragma once
#include <iostream>
#include "NodoL1.h"
#define TAM 220
using namespace std;

template <typename T>
class L1
{
private:
  NodoL1<T> arr[TAM];
  int fin = - 1;
public:
  void InsertarFinal(T element);
  void Eliminar(int nodo);
  T getNodo(int Nodo);
  void MostrarL1();
};

template<typename T>
inline void L1<T>::InsertarFinal(T element)
{
  fin++;
  arr[fin].setElem(element);
}

template<typename T>
inline void L1<T>::Eliminar(int nodo)
{
  if (fin != -1)
  {
    T aux = arr[fin].getElem();
    arr[nodo].setElem(aux);
    fin--;
  }
  else
  {
    cout << "No hay datos" << endl;
  }
}

template<typename T>
inline T L1<T>::getNodo(int Nodo)
{
  return arr[Nodo].getElem();
}


template<typename T>
inline void L1<T>::MostrarL1()
{
  for (int i = 0; i <= fin; i++)
  {
    cout << arr[i].getElem() << " | ";
  }
  cout << endl;
}
