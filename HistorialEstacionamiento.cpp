/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#include "HistorialEstacionamiento.h"
#include <iostream>
#include <sstream>

void HistorialEstacionamiento::registrarEntrada(const std::string& placa, const std::string& espacioId) {
    Registro nuevoRegistro;
    nuevoRegistro.placa = placa;
    nuevoRegistro.espacioId = espacioId;
    nuevoRegistro.fechaEntrada = "Fecha y hora de entrada"; // Aquí deberías obtener la fecha y hora actual
    nuevoRegistro.fechaSalida = ""; // Inicialmente vacío
    registros.push_back(nuevoRegistro);
    std::cout << "Registro de entrada para el auto " << placa << " en el espacio " << espacioId << " registrado.\n";
}

void HistorialEstacionamiento::registrarSalida(const std::string& placa) {
    for (auto& registro : registros) {
        if (registro.placa == placa && registro.fechaSalida.empty()) {
            registro.fechaSalida = "Fecha y hora de salida"; // Aquí deberías obtener la fecha y hora actual
            std::cout << "Registro de salida para el auto " << placa << " registrado.\n";
            return;
        }
    }
    std::cout << "No se encontró un registro de entrada para el auto " << placa << ".\n";
}

void HistorialEstacionamiento::mostrarHistorialPorFecha(const std::string& fecha) const {
    std::cout << "Historial de estacionamientos para la fecha " << fecha << ":\n";
    for (const auto& registro : registros) {
        if (registro.fechaEntrada == fecha) {
            std::cout << "Placa: " << registro.placa
                      << ", Espacio: " << registro.espacioId
                      << ", Entrada: " << registro.fechaEntrada
                      << ", Salida: " << registro.fechaSalida << "\n";
        }
    }
}

void HistorialEstacionamiento::mostrarHistorialPorFechaYPlaca(const std::string& fecha, const std::string& placa) const {
    std::cout << "Historial de estacionamientos para la fecha " << fecha << " y placa " << placa << ":\n";
    for (const auto& registro : registros) {
        if (registro.fechaEntrada == fecha && registro.placa == placa) {
            std::cout << "Espacio: " << registro.espacioId
                      << ", Entrada: " << registro.fechaEntrada
                      << ", Salida: " << registro.fechaSalida << "\n";
        }
    }
}

void HistorialEstacionamiento::mostrarHistorialPorRangoHoras(const std::string& horaInicio, const std::string& horaFin) const {
    std::cout << "Historial de estacionamientos entre " << horaInicio << " y " << horaFin << ":\n";
    for (const auto& registro : registros) {
        // Aquí deberías comparar las horas de entrada y salida con el rango proporcionado
        // Esto es solo un ejemplo, necesitarías implementar la lógica de comparación
        std::cout << "Placa: " << registro.placa
                  << ", Espacio: " << registro.espacioId
                  << ", Entrada: " << registro.fechaEntrada
                  << ", Salida: " << registro.fechaSalida << "\n";
    }
}
