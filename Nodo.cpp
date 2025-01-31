/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#include "Nodo.h"
#include <iostream>

Nodo::Nodo(const string& id)
    : id(id), ocupado(false), placa(""), horaIngreso(0), siguiente(nullptr), anterior(nullptr) {}

void Nodo::mostrarEstado() const {
    cout << "Espacio " << id << ": "
         << (ocupado ? "Ocupado" : "Libre")
         << ", Placa: " << (placa.empty() ? "N/A" : placa)
         << ", Hora Ingreso: " << (horaIngreso == 0 ? "N/A" : ctime(&horaIngreso)) << endl;
}
