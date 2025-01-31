/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#pragma once
#include <iostream>
#include <vector>
#include "Parqueadero.h"
#include "AutosPermitidos.h"
#include "HistorialEstacionamiento.h"
#include "Registro.h" // Asegúrate de incluir el archivo de Registro
#include "Validaciones.h" // Asegúrate de incluir el archivo de Validaciones
#include "Ordenamientos.h" // Incluir el archivo de ordenamientos

using namespace std;

class Menu {
private:
    Parqueadero* parqueadero;
    HistorialEstacionamiento* historial;
    AutosPermitidos* autosPermitidos;

    vector<string> opciones; // Opciones del menú
    int seleccionActual; // Opción seleccionada

    void mostrarSubmenuAutosPermitidos();
    void mostrarSubmenuHistorial();
    void mostrarSubmenuBusquedaBinaria(); // Nuevo método para búsqueda binaria
    void mostrarSubmenuOrdenamientos(); // Declarar la función para mostrar el submenú de ordenamientos

    // Declaraciones de las funciones de búsqueda
    std::vector<std::string> buscarPlacasEnRango(const std::vector<std::string>& placas, const std::string& inicio, const std::string& fin);
    std::vector<std::string> buscarPlacasPorColor(const std::vector<Registro>& registros, const std::string& color);

public:
    Menu(Parqueadero* p, HistorialEstacionamiento* h, AutosPermitidos* a);
    void mostrarMenu();
    void ejecutarOpcion();
    void iniciar();
    void mostrarGuiaRapida();
};