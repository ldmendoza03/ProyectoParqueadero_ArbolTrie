/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#ifndef TRIENODE_H
#define TRIENODE_H

#include <unordered_map>

class TrieNode {
public:
    bool isEndOfWord; // Indica si es el final de una palabra
    std::unordered_map<char, TrieNode*> children; // Hijos del nodo

    TrieNode() : isEndOfWord(false) {}
};

#endif // TRIENODE_H
