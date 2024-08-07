#pragma once
#include <string>

template <typename T>
class NodoL1
{
private:
  T elem;
public:
  NodoL1();
  NodoL1(T& elem);
  ~NodoL1();

  T getElem();

  void setElem(T& elem);

};

template<typename T>
inline NodoL1<T>::NodoL1()
{
}

template<typename T>
inline NodoL1<T>::NodoL1(T& elem)
{
  this->elem = elem;
}

template<typename T>
inline NodoL1<T>::~NodoL1()
{
}

template<typename T>
T NodoL1<T>::getElem()
{
  return elem;
}

template<typename T>
inline void NodoL1<T>::setElem(T& elem)
{
  this->elem = elem;
}
