/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#include "Validaciones.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <regex>
#include <limits>

using namespace std;

template <typename T>
Validaciones<T>::Validaciones()
{
}

template <typename T>
T Validaciones<T>::ingresar(const char *msj, const char *tipo)
{
    char cad[100];
    char c;
    int i = 0;
    T valor;
    printf("%s", msj);
    while ((c = getch()) != 13)
    {
        if (tipo == "entero")
        {
            if (c >= '0' && c <= '9')
            {
                printf("%c", c);
                cad[i++] = c; // Cambiar a i++
            }
            else if (c == 8)
            {
                if (i > 0)
                {
                    printf("\b \b");
                    i--;
                }
            }
        }
        else if (tipo == "flotante" || tipo == "double")
        {
            if (c >= '0' && c <= '9')
            {
                printf("%c", c);
                cad[i++] = c; // Cambiar a i++
            }
            else if (c == 8)
            {
                if (i > 0)
                {
                    printf("\b \b");
                    i--;
                }
            }
            else if (c == 46)
            {
                bool aux = false;
                for (int j = 0; cad[j] != '\0'; j++)
                {
                    if (cad[j] == 46)
                    {
                        aux = true;
                        break;
                    }
                }
                if (aux == false)
                {
                    printf("%c", c);
                    cad[i++] = c; // Cambiar a i++
                }
            }
        }
        else if (tipo == "string")
        {
            if (isalpha(c) || c == ' ')
            {
                printf("%c", c);
                cad[i++] = c; // Cambiar a i++
            }
            else if (c == 8)
            {
                if (i > 0)
                {
                    printf("\b \b");
                    i--;
                }
            }
        }
        else if (tipo == "char")
        {
            if (isalpha(c))
            {
                printf("%c", c);
                valor = c;
                break;
            }
            else if (c == 8)
            {
                if (c >= 'a' && c <= 'z')
                {
                    printf("\b \b");
                }
            }
        }
    }
    cad[i] = '\0';
    if (tipo == "entero")
    {
        int entero;
        entero = atoi(cad);
        return valor = entero;
    }
    else if (tipo == "flotante")
    {
        float flotante;
        for (int j = 0; cad[j] != '\0'; j++)
        {
            flotante = atof(cad);
        }
        return valor = flotante;
    }
    else if (tipo == "double")
    {
        double doble;
        for (int j = 0; cad[j] != '\0'; j++)
        {
            doble = atof(cad);
        }
        return valor = doble;
    }
    else if (tipo == "char")
    {
        return valor;
    }
    else if (tipo == "string")
    {
        for (int j = 0; cad[j] != '\0'; j++)
        {
            valor = valor + cad[j];
        }
        return valor;
    }
    return valor; 
}

template <typename T>
std::string Validaciones<T>::ingresarFecha(const char *msj) {
    char cad[11]; // Fecha en formato YYYY-MM-DD (10 caracteres + '\0')
    char c;
    int i = 0;
    char ultimoCaract = 0; // Para guardar el último carácter ingresado
    printf("%s", msj);

    while ((c = getch()) != 13) // Enter para finalizar
    {
        if ((c >= '0' && c <= '9') || c == '-') // Permitir números y guiones
        {
            if (c == '-' && ultimoCaract == '-') // Evitar guiones consecutivos
            {
                continue; // Ignorar el guion y no agregarlo
            }

            if (i < 10) // Limitar a 10 caracteres
            {
                printf("%c", c);
                cad[i++] = c;
                ultimoCaract = c; // Actualizar el último carácter ingresado
            }
        }
        else if (c == 8) // Backspace para borrar
        {
            if (i > 0)
            {
                printf("\b \b");
                i--;
                ultimoCaract = (i > 0) ? cad[i - 1] : 0; // Actualizar el último carácter al borrar
            }
        }
    }
    cad[i] = '\0'; // Terminar la cadena

    // Validar el formato
    if (i != 10 || cad[4] != '-' || cad[7] != '-') // Verificar longitud y posiciones de los guiones
    {
        printf("\nFormato invalido. Intente de nuevo.\n");
        return ingresarFecha(msj); // Llamar recursivamente en caso de error
    }
    return std::string(cad); // Devolver la fecha válida
}

template <typename T>
std::string Validaciones<T>::ingresarPlaca(const char *msj) {
    char cad[20]; // Tamaño máximo para la placa
    char c;
    int i = 0;
    printf("%s", msj);

    while ((c = getch()) != 13) // Enter para finalizar
    {
        if (isalnum(c)) // Permitir solo letras y números
        {
            if (i < 19) // Limitar el tamaño
            {
                c = toupper(c); // Convertir a mayúscula
                printf("%c", c);
                cad[i++] = c;
            }
        }
        else if (c == 8) // Backspace para borrar
        {
            if (i > 0)
            {
                printf("\b \b");
                i--;
            }
        }
    }
    cad[i] = '\0'; // Terminar la cadena

    // Convertir a std::string para validar
    std::string placa(cad);

    // Validar formato de placa ecuatoriana
    std::regex formatoEcuador(R"([A-Z]{3}\d{3,4}[A-Z]?)"); // AAA1234 o AAA123A
    if (!std::regex_match(placa, formatoEcuador))
    {
        printf("\nFormato de placa invalido. Intente de nuevo.\n");
        return ingresarPlaca(msj); // Llamar recursivamente en caso de error
    }

    // Validar los primeros tres caracteres (región o provincia)
    std::set<std::string> provinciasValidas = {
        "A", "B", "U", "G", "X", "W", "P", "Y", "T", "O", "M", "N", "S", "R", "H", "Z", "J", "K", "Q", "I", "E", "L", "V", "C"};
    std::string provincia = placa.substr(0, 1);
    if (provinciasValidas.find(provincia) == provinciasValidas.end())
    {
        printf("\nCodigo de provincia invalido. Intente de nuevo.\n");
        return ingresarPlaca(msj); // Llamar recursivamente en caso de error
    }

    return placa; // Devolver la placa válida
}

template <typename T>
std::string Validaciones<T>::ingresarCedula(const char *msj) {
    char cad[20]; // Tamaño máximo para la cédula
    char c;
    int i = 0;
    printf("%s", msj);

    while ((c = getch()) != 13) // Enter para finalizar
    {
        if (isdigit(c)) // Permitir solo números
        {
            if (i < 10) // Limitar el tamaño a 10 dígitos
            {
                printf("%c", c);
                cad[i++] = c; // Cambiar a i++
            }
        }
        else if (c == 8) // Backspace para borrar
        {
            if (i > 0)
            {
                printf("\b \b");
                --i;
            }
        }
    }
    cad[i] = '\0'; // Terminar la cadena

    // Validar longitud de cédula
    if (i != 10)
    {
        printf("\nFormato de cédula inválido. Intente de nuevo.\n");
        return ingresarCedula(msj); // Llamar recursivamente en caso de error
    }

    return std::string(cad); // Devolver la cédula válida
}

template <typename T>
std::string Validaciones<T>::ingresarCorreo(const char *msj) {
    char cad[50]; // Tamaño máximo para el correo
    char c;
    int i = 0;
    printf("%s", msj);

    while ((c = getch()) != 13) // Enter para finalizar
    {
        if (isalnum(c) || c == '@' || c == '.' || c == '_') // Permitir caracteres válidos
        {
            if (i < 49) // Limitar el tamaño
            {
                printf("%c", c);
                cad[i++] = c;
            }
        }
        else if (c == 8) // Backspace para borrar
        {
            if (i > 0)
            {
                printf("\b \b");
                --i;
            }
        }
    }
    cad[i] = '\0'; // Terminar la cadena

    // Validar formato de correo
    std::regex formatoCorreo(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (!std::regex_match(cad, formatoCorreo))
    {
        printf("\nFormato de correo inválido. Intente de nuevo.\n");
        return ingresarCorreo(msj); // Llamar recursivamente en caso de error
    }

    return std::string(cad); // Devolver el correo válido
}

template <typename T>
std::string Validaciones<T>::ingresarEspacioId(const char *msj) {
    char cad[20]; // Tamaño máximo para el ID del espacio
    char c;
    int i = 0;
    printf("%s", msj);

    while ((c = getch()) != 13) // Enter para finalizar
    {
        if (isalnum(c)) // Permitir solo letras y números
        {
            if (i < 19) // Limitar el tamaño
            {
                printf("%c", c);
                cad[i++] = c;
            }
        }
        else if (c == 8) // Backspace para borrar
        {
            if (i > 0)
            {
                printf("\b \b");
                --i;
            }
        }
    }
    cad[i] = '\0'; // Terminar la cadena

    return std::string(cad); // Devolver el ID del espacio
}

template <typename T>
string Validaciones<T>::ingresarHora(const string& mensaje) {
    char cad[9]; // Hora en formato HH:MM:SS (8 caracteres + '\0')
    char c;
    int i = 0;
    printf("%s", mensaje.c_str());

    while ((c = getch()) != 13) // Enter para finalizar
    {
        if (isdigit(c) || c == ':') // Permitir números y dos puntos
        {
            if (i < 8) // Limitar a 8 caracteres
            {
                printf("%c", c);
                cad[i++] = c;
            }
        }
        else if (c == 8) // Backspace para borrar
        {
            if (i > 0)
            {
                printf("\b \b");
                --i;
            }
        }
    }
    cad[i] = '\0'; // Terminar la cadena

    // Validar el formato
    if (i != 8 || cad[2] != ':' || cad[5] != ':') // Verificar longitud y posiciones de los dos puntos
    {
        printf("\nFormato inválido. Intente de nuevo.\n");
        return ingresarHora(mensaje); // Llamar recursivamente en caso de error
    }
    return std::string(cad); // Devolver la hora válida
}

// Implementaciones de las funciones de plantilla
template class Validaciones<int>;
template class Validaciones<float>;
template class Validaciones<double>;
template class Validaciones<std::string>;
