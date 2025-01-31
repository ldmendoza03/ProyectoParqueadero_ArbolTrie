/*******************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                      *
 * Proposito:                      Parqueadero con Arbol Trie                              *
 * Autor:                          Leandro Mendoza, Steven Yadaycela                       *
 * Fecha de creacion:              04/12/2025                                              *
 * Fecha de modificacion:          30/01/2025                                              *
 * Materia:                        Estructura de datos                                     *
 * NRC :                           1978                                                    *
 ******************************************************************************************/

#include "Trie.h"

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const std::string& key) {
    TrieNode* node = root;
    for (char ch : key) {
        if (node->children.find(ch) == node->children.end()) {
            node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
    }
    node->isEndOfWord = true; // Marca el final de la palabra
}

bool Trie::search(const std::string& key) const {
    TrieNode* node = root;
    for (char ch : key) {
        if (node->children.find(ch) == node->children.end()) {
            return false; // No encontrado
        }
        node = node->children[ch];
    }
    return node->isEndOfWord; // Devuelve true si es una palabra completa
}

bool Trie::removeHelper(TrieNode* node, const std::string& key, int depth) {
    if (!node) return false;

    if (depth == key.size()) {
        if (!node->isEndOfWord) return false; // No es una palabra completa
        node->isEndOfWord = false; // Marca como no final
        return node->children.empty(); // Devuelve true si no tiene hijos
    }

    char ch = key[depth];
    if (removeHelper(node->children[ch], key, depth + 1)) {
        delete node->children[ch];
        node->children.erase(ch);
        return !node->isEndOfWord && node->children.empty();
    }
    return false;
}

bool Trie::remove(const std::string& key) {
    return removeHelper(root, key, 0);
}
