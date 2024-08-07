#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "Vertice.h"
#include <random>
#include "L1.h"
using namespace std;

template <typename T>
class Grafo
{
private:
  map<T, Vertice<T> > G;
    L1<T> aristasG;
    int tamano = 0;
  map<string, Vertice<string>>::iterator it;
  pair<T, Vertice<T>> i;
public:
    Grafo<T>(const Grafo<T>& other);
    Grafo<T>();
    ~Grafo<T>();
    void limpiar();
    void InsertarVertice(T a, T b);
    void MostrarGrafo();
    void LeerArchivo();
    void Aleatorio(T& VO,T& VF);
    void Contraer(T V0, T VF);
    int getTamano();
    int contarAristas();
    void FindMinEdges();
    Grafo<T> copiaLista();

};

template <typename T>
Grafo<T> Grafo<T>::copiaLista() 
{
    Grafo<T> grafoSalida;//grafo h
    //map<T, Vertice<T>> Gaux; //grafo en si
    grafoSalida.aristasG = aristasG;
    grafoSalida.tamano = tamano;
    for (it = G.begin(); it != G.end(); it++)
    {
        Nodo<T>* aux = it->second.listas.getPrimer();
        while (aux != NULL) 
        {
            grafoSalida.G[it->first].listas.insertarFinal(aux->getElem());
            aux = aux->getSiguiente();
        }
    }
    //grafoSalida.G = Gaux;
    return grafoSalida;
}


template <typename T>
Grafo<T>::Grafo() {}

template <typename T>
Grafo<T>::~Grafo() 
{
    for (it = G.begin(); it != G.end(); ++it)
    {
        it->second.listas.eliminarTodo();      
    }
}


template <typename T>
void Grafo<T>::limpiar() 
{
    for (it = G.begin(); it != G.end(); ++it)
    {
        it->second.listas.eliminarTodo();      
    }
}



template <typename T>
Grafo<T>::Grafo(const Grafo<T>& other) {
  tamano = other.tamano;
  G = other.G;
  aristasG = other.aristasG;
  // Copia los elementos de la lista
  for (auto it = other.G.begin(); it != other.G.end(); ++it) {
    G[it->first] = Vertice<T>(it->second);
  }
}



template<typename T>
inline void Grafo<T>::InsertarVertice(T a, T b)
{
  G[a].listas.insertarFinal(b);
  G[b].listas.insertarFinal(a);
}

template<typename T>
inline void Grafo<T>::MostrarGrafo()
{
  for (it = G.begin(); it != G.end(); ++it)
  {
    cout << it->first << " : ";
        cout << it->second.listas.getContador() << " | ";
    it->second.listas.mostrar();
    cout << endl;
  }
}

template<typename T>
inline void Grafo<T>::LeerArchivo()
{
    T numero;
    T Vertic;
    int inicio = 0;
    ifstream archivo("prueba.txt");
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo");
    }
    while (archivo >> numero)
    {
        if (numero != "-1")
        {
            if (inicio == 0)
            {
                Vertic = numero;
                tamano++;
                aristasG.InsertarFinal(numero);
            }
            else
            {
                G[Vertic].listas.insertarFinal(numero);
            }
            inicio++;
        }
        else
        {
            inicio = 0;
        }
    }
    archivo.close();
}

template<typename T>
inline void Grafo<T>::Aleatorio(T& VO, T& VF)
{
    random_device rd;
    mt19937 gen(rd());
    if (tamano > 2)
    {
        std::uniform_int_distribution<> dis(0, tamano - 1);
        int num1 = dis(gen);
        VF = aristasG.getNodo(num1);
        std::uniform_int_distribution<> dis2(0, G[VF].listas.getContador()-1);
        int num2 = dis2(gen);
        Nodo<T>* aux = G[VF].listas.bucarEnesimoElem(num2);
        VO = aux->getElem();
        aristasG.Eliminar(num1);
        //cout << VO << endl;
        //cout << VF << endl; 
    }
    else
    {
        cout << "Solo queda dos elemento" << endl;
    }
}

template<typename T>
inline void Grafo<T>::Contraer(T VO, T VF)
{
    Nodo<T>* i = G[VF].listas.getPrimer();
    while (i != NULL) {
        if (i->getElem() != VO)
        {
            G[VO].listas.insertarFinal(i->getElem());
            G[i->getElem()].listas.insertarFinal(VO);
        }
        G[i->getElem()].listas.eliminarElemDado(VF);
        G[i->getElem()].listas.disminuircont();
        i = i->getSiguiente();
    }
    G.erase(VF);
    tamano--;
}

template<typename T>
inline int Grafo<T>::getTamano()
{
    return tamano;
}

template<typename T>
inline int Grafo<T>::contarAristas()
{
    int resp;
    it = G.begin();
    resp=it->second.listas.getContador();
    return resp;
}

template<typename T>
inline void Grafo<T>::FindMinEdges()
{
    for (int i = 0; i < 5; i++)
    {
        T vertex1, vertex2;
        while (getTamano() > 2)
        {
            Aleatorio(vertex1, vertex2);
            Contraer(vertex1, vertex2);
        }
        int minEdges = contarAristas();
        cout << "minimo numero de vertices despues de la contraccion " << i+1 << ": " << minEdges << endl;
    }
}