/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#ifndef AUTO_H
#define AUTO_H

#include <string>

class Auto {
public:
    std::string placa;
    std::string marca;
    std::string color;

    Auto(const std::string& placa, const std::string& marca, const std::string& color);
};

#endif // AUTO_H
