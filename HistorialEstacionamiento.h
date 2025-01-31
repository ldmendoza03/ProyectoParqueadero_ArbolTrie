/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#ifndef HISTORIALESTACIONAMIENTO_H
#define HISTORIALESTACIONAMIENTO_H

#include <string>
#include <vector>

class HistorialEstacionamiento {
private:
    struct Registro {
        std::string placa;
        std::string espacioId;
        std::string fechaEntrada;
        std::string fechaSalida;
    };

    std::vector<Registro> registros;

public:
    void registrarEntrada(const std::string& placa, const std::string& espacioId);
    void registrarSalida(const std::string& placa);
    void mostrarHistorialPorFecha(const std::string& fecha) const;
    void mostrarHistorialPorFechaYPlaca(const std::string& fecha, const std::string& placa) const;
    void mostrarHistorialPorRangoHoras(const std::string& horaInicio, const std::string& horaFin) const;
};

#endif // HISTORIALESTACIONAMIENTO_H
