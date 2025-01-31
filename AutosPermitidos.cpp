/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#include "AutosPermitidos.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Constructor: carga los datos desde el archivo
AutosPermitidos::AutosPermitidos() {
    cargarDesdeArchivo();
}

// Cargar autos permitidos desde el archivo
void AutosPermitidos::cargarDesdeArchivo() {
    std::ifstream archivoEntrada("autos_permitidos.txt");
    if (!archivoEntrada.is_open()) {
        std::cerr << "No se pudo abrir el archivo autos_permitidos.txt. Creando uno nuevo." << std::endl;
        return;
    }

    std::string linea;
    while (getline(archivoEntrada, linea)) {
        std::stringstream ss(linea);
        std::string placa, marca, color, nombre, cedula, correo;

        getline(ss, placa, ',');
        getline(ss, marca, ',');
        getline(ss, color, ',');
        getline(ss, nombre, ',');
        getline(ss, cedula, ',');
        getline(ss, correo, ',');

        Auto autoPermitido(placa, marca, color);
        Propietario propietario(nombre, cedula, correo);
        registros.emplace_back(autoPermitido, propietario);
        trie.insert(placa); // Insertar en el Trie
    }
    archivoEntrada.close();
}

// Guardar autos permitidos en el archivo
void AutosPermitidos::guardarEnArchivo() {
    std::ofstream archivoSalida("autos_permitidos.txt", std::ios::trunc);
    if (!archivoSalida.is_open()) {
        std::cerr << "Error al abrir el archivo autos_permitidos.txt para guardar." << std::endl;
        return;
    }

    for (const auto& registro : registros) {
        archivoSalida << registro.autoPermitido.placa << ","
                      << registro.autoPermitido.marca << ","
                      << registro.autoPermitido.color << ","
                      << registro.propietario.nombre << ","
                      << registro.propietario.cedula << ","
                      << registro.propietario.correo << "\n";
    }
    archivoSalida.close();
}

void AutosPermitidos::guardarPropietarios() {
    std::ofstream archivoPropietarios("Propietarios.txt", std::ios::trunc);
    if (!archivoPropietarios.is_open()) {
        std::cerr << "Error al abrir el archivo Propietarios.txt para guardar." << std::endl;
        return;
    }

    for (const auto& registro : registros) {
        if (!registro.propietario.nombre.empty() &&
            !registro.propietario.cedula.empty() &&
            !registro.propietario.correo.empty()) {
            archivoPropietarios << registro.propietario.nombre << ","
                                << registro.propietario.cedula << ","
                                << registro.propietario.correo << "\n";
        }
    }
    archivoPropietarios.close();
}

// Agregar un nuevo auto permitido
void AutosPermitidos::agregarAuto(const Auto& autoPermitido, const Propietario& propietario) {
    for (const auto& registro : registros) {
        if (registro.autoPermitido.placa == autoPermitido.placa) {
            std::cout << "El auto con placa " << autoPermitido.placa << " ya está registrado." << std::endl;
            return;
        }
    }

    registros.emplace_back(autoPermitido, propietario);
    trie.insert(autoPermitido.placa); // Insertar en el Trie
    guardarEnArchivo();
    guardarPropietarios();
    std::cout << "Auto y propietario agregados correctamente." << std::endl;
}

// Buscar un auto por placa
bool AutosPermitidos::buscarAuto(const std::string& placa) const {
    return trie.search(placa);
}

// Eliminar un auto permitido por placa
void AutosPermitidos::eliminarAuto(const std::string& placa) {
    for (auto it = registros.begin(); it != registros.end(); ++it) {
        if (it->autoPermitido.placa == placa) {
            registros.erase(it);
            trie.remove(placa); // Eliminar del Trie
            guardarEnArchivo();
            std::cout << "Auto eliminado correctamente." << std::endl;
            return;
        }
    }
    std::cout << "No se encontró un auto con la placa " << placa << "." << std::endl;
}

// Mostrar todos los autos permitidos
void AutosPermitidos::mostrarAutos() const {
    if (registros.empty()) {
        std::cout << "No hay autos permitidos registrados." << std::endl;
        return;
    }

    std::cout << "Autos Permitidos:\n";
    for (const auto& registro : registros) {
        std::cout << "Placa: " << registro.autoPermitido.placa
                  << ", Marca: " << registro.autoPermitido.marca
                  << ", Color: " << registro.autoPermitido.color << std::endl;
    }
}

void AutosPermitidos::mostrarAutoPorPlaca(const std::string& placa) const {
    bool encontrado = false;

    for (const auto& registro : registros) {
        if (registro.autoPermitido.placa == placa) {
            std::cout << "Auto encontrado:\n"
                      << "Placa: " << registro.autoPermitido.placa
                      << ", Marca: " << registro.autoPermitido.marca
                      << ", Color: " << registro.autoPermitido.color << std::endl;
            encontrado = true;
            break;  // Asume que solo hay un auto por placa
        }
    }

    if (!encontrado) {
        std::cout << "No se encontró un auto con la placa " << placa << "." << std::endl;
    }
}

void AutosPermitidos::mostrarPropietarios() {
    std::ifstream archivoPropietarios("Propietarios.txt");
    if (!archivoPropietarios.is_open()) {
        std::cerr << "No se pudo abrir el archivo Propietarios.txt para leer." << std::endl;
        return;
    }

    std::cout << "Propietarios Registrados:\n"; // Muestra el título solo una vez
    std::string linea;
    while (getline(archivoPropietarios, linea)) {
        std::stringstream ss(linea);
        std::string nombre, cedula, correo;

        getline(ss, nombre, ',');
        getline(ss, cedula, ',');
        getline(ss, correo, ',');

        // Verifica si los datos están completos antes de mostrarlos
        if (!nombre.empty() && !cedula.empty() && !correo.empty()) {
            std::cout << "Nombre: " << nombre
                      << ", Cedula: " << cedula
                      << ", Correo: " << correo << std::endl;
        } else {
            std::cerr << "Se encontró un registro inválido en Propietarios.txt: " << linea << std::endl;
        }
    }

    archivoPropietarios.close();
}

// Nuevos métodos para obtener placas y registros
std::vector<std::string> AutosPermitidos::getPlacas() const {
    std::vector<std::string> placas;
    for (const auto& registro : registros) {
        placas.push_back(registro.autoPermitido.placa);
    }
    return placas;
}

std::vector<Registro> AutosPermitidos::getRegistros() const {
    return registros;
}
