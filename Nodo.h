/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#ifndef NODO_H
#define NODO_H

#include <string>
#include <ctime>
using namespace std;

class Nodo {
public:
    string id;          // Identificador del espacio (01-12)
    bool ocupado;       // Estado del espacio (true = ocupado, false = libre)
    string placa;       // Placa del auto estacionado (vacío si está libre)
    time_t horaIngreso; // Tiempo de ingreso (0 si está libre)
    Nodo* siguiente;
    Nodo* anterior;

    // Constructor
    Nodo(const string& id);

    // Método para mostrar el estado del nodo
    void mostrarEstado() const;
};

#endif // NODO_H
