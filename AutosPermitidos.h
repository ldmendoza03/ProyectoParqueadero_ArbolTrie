/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#ifndef AUTOSPERMITIDOS_H
#define AUTOSPERMITIDOS_H

#include "Auto.h"
#include "Propietario.h"
#include "Registro.h"
#include "Trie.h"  
#include <vector>
#include <string>

class AutosPermitidos {
private:
    Trie trie; // Usar Trie en lugar de vector
    std::vector<Registro> registros; // Para almacenar propietarios

    void cargarDesdeArchivo();
    void guardarEnArchivo();
    void guardarPropietarios();

public:
    AutosPermitidos();
    void agregarAuto(const Auto& autoPermitido, const Propietario& propietario);
    bool buscarAuto(const std::string& placa) const;
    void eliminarAuto(const std::string& placa);
    void mostrarAutos() const;
    void mostrarAutoPorPlaca(const std::string& placa) const;
    void mostrarPropietarios();
    
    // Nuevos métodos para obtener placas y registros
    std::vector<std::string> getPlacas() const; // Método para obtener placas
    std::vector<Registro> getRegistros() const; // Método para obtener registros
};

#endif // AUTOSPERMITIDOS_H
