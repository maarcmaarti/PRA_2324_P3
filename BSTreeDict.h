#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
    BSTree<TableEntry<V>>* tree;
    public:
    BSTreeDict(){
        tree = new BSTree<TableEntry<V>>();
    }
    ~BSTreeDict(){
        delete tree;
    }
     void insert(std::string key, V value) override {
        TableEntry<V> te(key, value);
        tree->insert(te);
    
    }
    V search(std::string key) override {
        TableEntry<V> te(key);
        TableEntry<V>* result = tree->search(te);

        if (result == nullptr)
            throw std::runtime_error("Clave no encontrada en BSTreeDict");

        return result->value;
    }
    void remove(std::string key) override {
        TableEntry<V> te(key);
        tree->remove(te);
    }
    std::string entries() override {
        return tree->inorder();
    }
    V operador[](std::string key) {
        return search(key);
    }
    friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V>& bs){
        out << bs.tree->inorder();
        return out;
    }
};

#endif