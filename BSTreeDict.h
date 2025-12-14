#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

using namespace std;

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
    // miembros publicos
	BSTree<TableEntry<V>>* tree ;
    public:
    // miembros privados     
   	 void insert(string key, V value) override{
        TableEntry<V> aux = TableEntry<V>(key, value);
        tree->insert(aux); 
    }
    	V search(string key)override{
        TableEntry<V> aux = TableEntry<V>(key);
        return tree->search(aux).value;
    }
   	V remove(string key)override{
        TableEntry<V> aux = TableEntry<V>(key);
        V pos = search(key);
        tree->remove(aux);
        return pos;
    }
    	int entries() override{
        return tree->size();
    }
	BSTreeDict(){
        this->tree = new BSTree<TableEntry<V>>();
    }
	~BSTreeDict(){
        delete tree;
    }
	friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
        out << *bs.tree << endl;
        return out;
    }  
	V operator[](std::string key){
        return search(key);
    }
};

#endif
