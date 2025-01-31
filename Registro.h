/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#ifndef REGISTRO_H
#define REGISTRO_H

#include "Auto.h"
#include "Propietario.h"

class Registro {
public:
    Auto autoPermitido;
    Propietario propietario;

    Registro(const Auto& autoPermitido, const Propietario& propietario); // Declaración del constructor
};

#endif // REGISTRO_H
