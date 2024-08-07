#include <iostream>
#include <cstdlib>
#include "Vertice.h"
#include "Nodo.h"
#include "Lista8.h"
#include "Grafo.h"
#include <map>
using namespace std;

void menu() 
{
    cout << "Mincut" << endl;
    cout << "1. Leer de Archivo de grafos" << endl; //lito
    cout << "2. Mostrar Grafo" << endl; //lito
    cout << "3. Buscar aristas al azar" << endl; //lito
    cout << "4. MinCut" << endl; //lito
    cout << "5. EncontrarMinimo" << endl; //aaa
    cout << "0. Salir" << endl;
    //Primera prueba del git pa ver si se guarda
    //Comentario agregado en el primer git
}
int main()
{
    Grafo<string> Inicio;
    Grafo<string> Inicio2;
    string arista1;
    string arista2;
    int menor;
    int option;
    do
    {
        menu();
        cin >> option;
        switch (option)
        {
        case 1: {
            Inicio.LeerArchivo();
            break;
        }
        case 2: {
            Inicio.MostrarGrafo();
            break;
        }
        case 3: {
            Inicio.Aleatorio(arista1,arista2);
            break;
        }
        case 4: {
            Inicio.Contraer(arista1, arista2);
            break;
        }
        case 5: {
            int menosPior=0;//menos pior
            for (int i = 0; i < 90000; i++)//
             {
              Grafo<string> Inicio2=Inicio.copiaLista(); // Crea una copia profunda de Inicio
                //Grafo<string> Inicio2;
                //Inicio2=Inicio;
                //Inicio2.LeerArchivo();
                while (Inicio2.getTamano() > 2)
                {
                    //Inicio2.MostrarGrafo();
                    Inicio2.Aleatorio(arista1, arista2);
                    Inicio2.Contraer(arista1, arista2);
                }
                 menor = Inicio2.contarAristas();
                Inicio2.limpiar();
                if(i!=0)
                {
                    //cout <<i<<" Menor: " << menor << endl;
                    if(menosPior>menor)
                    {
                        menosPior=menor;
                    }
                }
                 else{
                     menosPior=menor;
                 }
                //Inicio2.MostrarGrafo();

            }
            cout<<"Menor de los Piores: "<< menosPior<<endl;
          //Inicio.FindMinEdges();
            break;
        }
        default:
            break;
        }
     
    } while (option != 0);
}
