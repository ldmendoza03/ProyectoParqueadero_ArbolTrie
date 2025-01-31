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
#include "Validaciones.h"
#include <iostream>
#include "HistorialEstacionamiento.h"
using namespace std;

// Constructor: Inicializa el menú con las opciones disponibles
Menu::Menu(Parqueadero* p, HistorialEstacionamiento* h, AutosPermitidos* a)
    : parqueadero(p), historial(h), autosPermitidos(a), seleccionActual(0) {
    opciones = {
        "Mostrar estado del parqueadero",
        "Estacionar un auto",
        "Retirar un auto",
        "Registrar auto permitido",
        "Eliminar auto permitido",
        "Mostrar autos permitidos",
        "Mostrar propietarios",
        "Mostrar historial de estacionamientos",
        "Buscar autos (Búsqueda Binaria)", // Nueva opción
        "Ordenamientos", // Nueva opción para ordenamientos
        "Salir"
    };
}

// Mostrar el menú principal
void Menu::mostrarMenu() {
    system("cls");
    cout << "Sistema de Gestion de Parqueadero\n";
    cout << "--------------------------------\n";

    for (int i = 0; i < opciones.size(); i++) {
        if (i == seleccionActual) {
            cout << " > " << opciones[i] << " <\n"; // Opción seleccionada
        } else {
            cout << "   " << opciones[i] << "\n"; // Opción no seleccionada
        }
    }
}

// Ejecutar la opción seleccionada
void Menu::ejecutarOpcion() {          
    system("cls");
    switch (seleccionActual) {
        case 0:
            parqueadero->mostrarEstado();
            break;
        case 1: {
            string placa, espacioId;
            Validaciones<string> validador;
            placa = validador.ingresar("Ingresa la placa del auto a estacionar(sin guiones): ", "string");
            cout << endl;
            if (!autosPermitidos->buscarAuto(placa)) {
                cout << "El auto no está permitido. Registrelo primero.\n";
                break;
            }
            parqueadero->mostrarEstado();
            espacioId = validador.ingresarEspacioId("Ingrese el id del espacio a estacionarse: ");
            cout << endl;
            if (parqueadero->estacionarAuto(placa, espacioId)) {
                historial->registrarEntrada(placa, espacioId);
            }
            break;
        }
        case 2: {
            string placa;
            Validaciones<string> validador;
            placa = validador.ingresar("Ingrese la placa del auto a retirar(sin guiones): ", "string");
            if (parqueadero->retirarAuto(placa)) {
                historial->registrarSalida(placa);
            }
            break;
        }
        case 3: {
            string placa, marca, color, nombre, cedula, correo;
            Validaciones<string> validador;
            placa = validador.ingresar("Ingrese la placa del auto(sin guiones): ", "string");
            cout << endl;
            marca = validador.ingresar("Ingrese la marca del auto: ", "string");
            cout << endl;
            color = validador.ingresar("Ingrese el color: ", "string");
            cout << endl;
            nombre = validador.ingresar("Ingrese el nombre del propietario: ", "string");
            cout << endl;
            cedula = validador.ingresarCedula("Ingrese la cedula del propietario: ");
            cout << endl;
            correo = validador.ingresarCorreo("Ingrese el correo del propietario: ");
            cout << endl;
            Auto autoObj(placa, marca, color);
            Propietario propietario(nombre, cedula, correo);
            autosPermitidos->agregarAuto(autoObj, propietario);
            break;
        }
        case 4: {
            string placa;
            Validaciones<string> validador;
            placa = validador.ingresar("Ingrese la placa del auto a eliminar(sin guiones): ", "string");
            cout << endl;
            autosPermitidos->eliminarAuto(placa);
            if (parqueadero->retirarAuto(placa)){
                historial->registrarSalida(placa);
            }
            break;
        }
        case 5:
            mostrarSubmenuAutosPermitidos();
            break;
        case 6:
            autosPermitidos->mostrarPropietarios();
            break;
        case 7:
            mostrarSubmenuHistorial();
            break;
        case 8: // Nueva opción para búsqueda binaria
            mostrarSubmenuBusquedaBinaria();
            break;
        case 9: // Nueva opción para ordenamientos
            mostrarSubmenuOrdenamientos();
            break;
        case 10:
            cout << "Saliendo del programa...\n";
            exit(0);
        default:
            cout << "Opcion no valida.\n";
            break;
    }
    system("pause");
}

// Mostrar submenú de búsqueda binaria
void Menu::mostrarSubmenuBusquedaBinaria() {
    vector<string> opcionesBusqueda = {
        "Buscar placas en un rango",
        "Buscar placas por color",
        "Regresar al menú principal"
    };
    int seleccionSubmenu = 0;

    while (true) {
        system("cls");
        cout << "Opciones de Búsqueda Binaria\n";
        cout << "-----------------------------\n";

        for (int i = 0; i < opcionesBusqueda.size(); i++) {
            if (i == seleccionSubmenu) {
                cout << " > " << opcionesBusqueda[i] << " <\n";
            } else {
                cout << "   " << opcionesBusqueda[i] << "\n";
            }
        }

        char tecla = _getch();
        if (tecla == 72) { // Flecha arriba
            seleccionSubmenu = (seleccionSubmenu - 1 + opcionesBusqueda.size()) % opcionesBusqueda.size();
        } else if (tecla == 80) { // Flecha abajo
            seleccionSubmenu = (seleccionSubmenu + 1) % opcionesBusqueda.size();
        } else if (tecla == '\r') { // Enter
            system("cls");
            switch (seleccionSubmenu) {
                case 0: {
                    string placaInicio, placaFin;
                    cout << "Ingrese la placa de inicio: ";
                    cin >> placaInicio;
                    cout << "Ingrese la placa de fin: ";
                    cin >> placaFin;
                    vector<string> resultados = buscarPlacasEnRango(autosPermitidos->getPlacas(), placaInicio, placaFin);
                    cout << "Placas encontradas en el rango '" << placaInicio << "' a '" << placaFin << "':" << endl;
                    for (const auto& placa : resultados) {
                        cout << placa << endl;
                    }
                    break;
                }
                case 1: {
                    string colorBuscado;
                    cout << "Ingrese el color a buscar: ";
                    cin >> colorBuscado;
                    vector<string> resultados = buscarPlacasPorColor(autosPermitidos->getRegistros(), colorBuscado);
                    cout << "Placas encontradas con el color '" << colorBuscado << "':" << endl;
                    for (const auto& resultado : resultados) {
                        cout << resultado << endl;
                    }
                    break;
                }
                case 2:
                    return; // Regresar al menú principal
                default:
                    cout << "Opción no válida." << endl;
                    break;
            }
        }
    }
}

// Función para buscar placas en un rango
vector<string> Menu::buscarPlacasEnRango(const vector<string>& placas, const string& inicio, const string& fin) {
    vector<string> resultados;
    // Implementar búsqueda binaria para encontrar el rango
    for (const auto& placa : placas) {
        if (placa >= inicio && placa <= fin) {
            resultados.push_back(placa);
        }
    }
    return resultados;
}

// Función para buscar placas que contienen un color específico
vector<string> Menu::buscarPlacasPorColor(const vector<Registro>& registros, const string& color) {
    vector<string> resultados;
    for (const auto& registro : registros) {
        if (registro.autoPermitido.color == color) {
            resultados.push_back("Placa: " + registro.autoPermitido.placa + ", Propietario: " + registro.propietario.nombre);
        }
    }
    return resultados;
}

// Mostrar submenú de autos permitidos
void Menu::mostrarSubmenuAutosPermitidos() {
    vector<string> opcionesAutos = {
        "Mostrar todos los autos permitidos",
        "Buscar auto por placa",
        "Regresar al menu principal"
    };
    int seleccionSubmenu = 0;

    while (true) {
        system("cls");
        cout << "Opciones de Autos Permitidos\n";
        cout << "-----------------------------\n";

        for (int i = 0; i < opcionesAutos.size(); i++) {
            if (i == seleccionSubmenu) {
                cout << " > " << opcionesAutos[i] << " <\n";
            } else {
                cout << "   " << opcionesAutos[i] << "\n";
            }
        }

        char tecla = _getch();
        if (tecla == 72) { // Flecha arriba
            seleccionSubmenu = (seleccionSubmenu - 1 + opcionesAutos.size()) % opcionesAutos.size();
        } else if (tecla == 80) { // Flecha abajo
            seleccionSubmenu = (seleccionSubmenu + 1) % opcionesAutos.size();
        } else if (tecla == '\r') { // Enter
            system("cls");
            if (seleccionSubmenu == 0) { 
                // Opción: Mostrar todos los autos permitidos
                autosPermitidos->mostrarAutos();
            } else if (seleccionSubmenu == 1) { 
                // Opción: Buscar auto por placa
                string placa;
                Validaciones<string> validador;
                placa = validador.ingresar("Ingrese la placa del auto(sin guiones): ", "string");
                cout << endl;

                if (autosPermitidos->buscarAuto(placa)) {
                    autosPermitidos->mostrarAutoPorPlaca(placa); // Mostrar detalles del auto
                } else {
                    cout << "El auto con placa " << placa << " no esta permitido.\n";
                }
            } else if (seleccionSubmenu == 2) { 
                // Opción: Regresar al menú principal
                break;
            }
            system("pause");
        }
    }
}

// Mostrar submenú del historial
void Menu::mostrarSubmenuHistorial() {
    vector<string> opcionesHistorial = {
        "Mostrar historial por fecha",
        "Mostrar historial por fecha y placa",
        "Mostrar historial por rango de hora",
        "Regresar al menu principal"
    };
    int seleccionSubmenu = 0;

    while (true) {
        system("cls");
        cout << "Opciones de Historial\n";
        cout << "-----------------------\n";

        for (int i = 0; i < opcionesHistorial.size(); i++) {
            if (i == seleccionSubmenu) {
                cout << " > " << opcionesHistorial[i] << " <\n";
            } else {
                cout << "   " << opcionesHistorial[i] << "\n";
            }
        }

        char tecla = _getch();
        if (tecla == 72) { // Flecha arriba
            seleccionSubmenu = (seleccionSubmenu - 1 + opcionesHistorial.size()) % opcionesHistorial.size();
        } else if (tecla == 80) { // Flecha abajo
            seleccionSubmenu = (seleccionSubmenu + 1) % opcionesHistorial.size();
        } else if (tecla == '\r') { // Enter
            system("cls");
            if (seleccionSubmenu == 0) {
                string fecha;
                Validaciones<string> validador;
                fecha = validador.ingresarFecha("Ingrese la fecha (YYYY-MM-DD): ");
                cout << endl;
                historial->mostrarHistorialPorFecha(fecha);
                cout << endl;
            } else if (seleccionSubmenu == 1) {
                string fecha, placa;
                Validaciones<string> validador;
                fecha = validador.ingresarFecha("Ingrese la fecha (YYYY-MM-DD): ");
                cout << endl;
                placa = validador.ingresarPlaca("Ingrese la placa (sin guiones): ");
                cout << endl;
                historial->mostrarHistorialPorFechaYPlaca(fecha, placa);
            } else if (seleccionSubmenu == 2) {
                string horaInicio, horaFin;
                Validaciones<string> validador;
                horaInicio = validador.ingresarHora("Ingrese la hora de inicio (HH:MM:SS): ");
                cout << endl;
                horaFin = validador.ingresarHora("Ingrese la hora de fin (HH:MM:SS): ");
                cout << endl;
                historial->mostrarHistorialPorRangoHoras(horaInicio, horaFin);
                cout << endl;
            } else if (seleccionSubmenu == 3) {
                break; // Regresar al menú principal
            }
            system("pause");
        }
    }
}

// Iniciar el menú interactivo
void Menu::iniciar() {
    while (true) {
        mostrarMenu();
        char tecla = _getch();
        if (tecla == 72) { // Flecha arriba
            seleccionActual = (seleccionActual - 1 + opciones.size()) % opciones.size();
        } else if (tecla == 80) { // Flecha abajo
            seleccionActual = (seleccionActual + 1) % opciones.size();
        } else if (tecla == '\r') { // Enter
            ejecutarOpcion();
        } else if (tecla == 59) { // F1 (en ASCII extendido)
            mostrarGuiaRapida();
        }
    }
}

void Menu::mostrarGuiaRapida() {
    system("cls");
    std::cout << "Guia Rapida para el Usuario del Sistema de Parqueadero\n";
    std::cout << "------------------------------------------------------\n";
    std::cout << "- Consultar el Estado del Parqueadero\n";
    std::cout << "  Utiliza la opcion 'Mostrar estado del parqueadero' en el menu principal para ver los espacios disponibles y ocupados.\n\n";
    std::cout << "- Estacionar un Auto\n";
    std::cout << "  Asegurate de que el auto este registrado como permitido.\n";
    std::cout << "  Selecciona un espacio disponible.\n\n";
    std::cout << "- Retirar un Auto\n";
    std::cout << "  Ingresa la placa del auto para liberar el espacio ocupado.\n\n";
    std::cout << "- Registrar Autos Permitidos\n";
    std::cout << "  Agrega nuevos autos permitidos ingresando su placa, marca, color y datos del propietario.\n\n";
    std::cout << "- Eliminar Autos Permitidos\n";
    std::cout << "  Elimina autos registrados si no necesitan acceso al parqueadero.\n\n";
    std::cout << "- Visualizar Historial\n";
    std::cout << "  Consulta las entradas y salidas del parqueadero por placa o fecha.\n\n";
    std::cout << "- Navegacion del Menu\n";
    std::cout << "  Usa las flechas del teclado para moverte entre las opciones.\n";
    std::cout << "  El sistema actualizara automaticamente la informacion despues de cada operacion.\n\n";
    std::cout << "Presiona cualquier tecla para regresar al menu principal...\n";
    _getch(); // Esperar a que el usuario presione una tecla
}

// Mostrar submenú de ordenamientos
void Menu::mostrarSubmenuOrdenamientos() {
    std::vector<std::string> opcionesOrdenamientos = {
        "Quick Sort",
        "Bucket Sort",
        "Bubble Sort",
        "Shell Sort",
        "Radix Sort",
        "Heap Sort",
        "Volver al Menu Principal"
    };
    int seleccionSubmenu = 0;

    while (true) {
        system("cls");
        std::cout << "Opciones de Ordenamientos\n";
        std::cout << "--------------------------\n";

        for (int i = 0; i < opcionesOrdenamientos.size(); i++) {
            if (i == seleccionSubmenu) {
                std::cout << " > " << opcionesOrdenamientos[i] << " <\n";
            } else {
                std::cout << "   " << opcionesOrdenamientos[i] << "\n";
            }
        }

        char tecla = _getch();
        if (tecla == 72) { // Flecha arriba
            seleccionSubmenu = (seleccionSubmenu - 1 + opcionesOrdenamientos.size()) % opcionesOrdenamientos.size();
        } else if (tecla == 80) { // Flecha abajo
            seleccionSubmenu = (seleccionSubmenu + 1) % opcionesOrdenamientos.size();
        } else if (tecla == '\r') { // Enter
            system("cls");
            if (seleccionSubmenu == 6) { // Volver al menú principal
                break;
            } else {
                // Obtener las placas de autos permitidos
                std::vector<std::string> placas = autosPermitidos->getPlacas(); // Obtener las placas
                std::vector<int> arr; // Suponiendo que deseas ordenar enteros, ajusta según sea necesario

                // Convertir las placas a enteros si es necesario, o simplemente usar std::string
                // Aquí solo se muestra un ejemplo de cómo podrías hacerlo
                for (const auto& placa : placas) {
                    // Convertir placa a un valor que desees ordenar, por ejemplo, usando el hash de la placa
                    arr.push_back(std::hash<std::string>{}(placa)); // Ejemplo de conversión
                }

                // Luego, puedes llamar a los métodos de ordenamiento
                switch (seleccionSubmenu) {
                    case 0:
                        Ordenamientos::quickSort(arr, 0, arr.size() - 1);
                        break;
                    case 1:
                        Ordenamientos::bucketSort(arr);
                        break;
                    case 2:
                        Ordenamientos::bubbleSort(arr);
                        break;
                    case 3:
                        Ordenamientos::shellSort(arr);
                        break;
                    case 4:
                        Ordenamientos::radixSort(arr);
                        break;
                    case 5:
                        Ordenamientos::heapSort(arr);
                        break;
                }
                // Mostrar el arreglo ordenado
                std::cout << "Arreglo ordenado:\n";
                for (int num : arr) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;
                system("pause");
            }
        }
    }
}