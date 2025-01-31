/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>

class Trie {
private:
    TrieNode* root;

public:
    Trie();
    void insert(const std::string& key);
    bool search(const std::string& key) const;
    bool remove(const std::string& key);
    bool removeHelper(TrieNode* node, const std::string& key, int depth);
};

#endif // TRIE_H
