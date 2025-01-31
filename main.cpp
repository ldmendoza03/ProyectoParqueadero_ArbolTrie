/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#include "Menu.h"

int main() {
    int capacidad = 10; // Define la capacidad del parqueadero
    Parqueadero parqueadero(capacidad); // Pasa la capacidad al constructor
    HistorialEstacionamiento historial;
    AutosPermitidos autosPermitidos;

    Menu menu(&parqueadero, &historial, &autosPermitidos);
    menu.iniciar();

    return 0;
}
