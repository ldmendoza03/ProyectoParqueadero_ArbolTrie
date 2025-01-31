/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#ifndef __Validaciones_Validaciones_h
#define __Validaciones_Validaciones_h

#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <regex>
#include <set>
#include <limits>

using namespace std;

template <typename T>
class Validaciones
{
public:
    Validaciones();
    T ingresar(const char *msj, const char *tipo);
    std::string ingresarFecha(const char *msj);
    std::string ingresarPlaca(const char *msj);
    std::string ingresarCedula(const char *msj);
    std::string ingresarCorreo(const char *msj);
    std::string ingresarEspacioId(const char *msj);
    static string ingresarHora(const string& mensaje);

private:
    T numero;
};

#endif
