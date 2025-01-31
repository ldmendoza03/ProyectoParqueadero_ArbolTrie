/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#ifndef PARQUEADERO_H
#define PARQUEADERO_H

#include <string>
#include <vector>

class Parqueadero {
private:
    std::vector<std::string> espacios; // Espacios de estacionamiento
    int capacidad; // Capacidad total del parqueadero

public:
    Parqueadero(int capacidad); // Constructor que toma un argumento
    void mostrarEstado() const;
    bool estacionarAuto(const std::string& placa, const std::string& espacioId);
    bool retirarAuto(const std::string& placa);
};

#endif // PARQUEADERO_H
