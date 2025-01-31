/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#ifndef PROPIETARIO_H
#define PROPIETARIO_H

#include <string>

class Propietario {
public:
    std::string nombre;
    std::string cedula;
    std::string correo;

    Propietario(const std::string& nombre, const std::string& cedula, const std::string& correo);
};

#endif // PROPIETARIO_H
