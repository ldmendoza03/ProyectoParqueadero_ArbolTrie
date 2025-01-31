/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#ifndef ORDENAMIENTOS_H
#define ORDENAMIENTOS_H

#include <vector>

class Ordenamientos {
public:
    static void quickSort(std::vector<int>& arr, int low, int high);
    static void bubbleSort(std::vector<int>& arr);
    static void shellSort(std::vector<int>& arr);
    static void heapSort(std::vector<int>& arr);
    static void radixSort(std::vector<int>& arr);
    static void bucketSort(std::vector<int>& arr);
};

#endif // ORDENAMIENTOS_H