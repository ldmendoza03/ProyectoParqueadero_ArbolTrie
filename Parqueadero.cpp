/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#include "Parqueadero.h"
#include <iostream>

Parqueadero::Parqueadero(int capacidad) : capacidad(capacidad) {
    espacios.resize(capacidad, "Libre"); // Inicializa todos los espacios como libres
}

void Parqueadero::mostrarEstado() const {
    std::cout << "Estado del Parqueadero:\n";
    for (int i = 0; i < espacios.size(); i++) {
        std::cout << "Espacio " << i + 1 << ": " << espacios[i] << "\n";
    }
}

bool Parqueadero::estacionarAuto(const std::string& placa, const std::string& espacioId) {
    int id = std::stoi(espacioId) - 1; // Convertir a índice
    if (id < 0 || id >= capacidad || espacios[id] != "Libre") {
        std::cout << "Espacio no disponible.\n";
        return false;
    }
    espacios[id] = placa; // Estacionar el auto
    std::cout << "Auto " << placa << " estacionado en el espacio " << espacioId << ".\n";
    return true;
}

bool Parqueadero::retirarAuto(const std::string& placa) {
    for (int i = 0; i < espacios.size(); i++) {
        if (espacios[i] == placa) {
            espacios[i] = "Libre"; // Liberar el espacio
            std::cout << "Auto " << placa << " retirado del espacio " << i + 1 << ".\n";
            return true;
        }
    }
    std::cout << "Auto no encontrado.\n";
    return false;
}
