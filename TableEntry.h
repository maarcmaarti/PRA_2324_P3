#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V>
class TableEntry {
public:
    std::string key;
    V value;

    // Constructor clave-valor
    TableEntry(const std::string& key, const V& value) {
        this->key = key;
        this->value = value;
    }

    // Constructor solo clave (para búsquedas y borrados)
    TableEntry(const std::string& key) {
        this->key = key;
        // value queda sin inicializar intencionalmente,
        // porque no se usa en las búsquedas
    }

    // Constructor por defecto
    TableEntry() : key(""), value() {}

    // Comparaciones por clave
    friend bool operator<(const TableEntry<V>& t1, const TableEntry<V>& t2) {
        return t1.key < t2.key;
    }

    friend bool operator>(const TableEntry<V>& t1, const TableEntry<V>& t2) {
        return t1.key > t2.key;
    }

    friend bool operator==(const TableEntry<V>& t1, const TableEntry<V>& t2) {
        return t1.key == t2.key;
    }

    friend bool operator!=(const TableEntry<V>& t1, const TableEntry<V>& t2) {
        return t1.key != t2.key;
    }

    // Impresión
    friend std::ostream& operator<<(std::ostream& out, const TableEntry<V>& te) {
        out << te.key << "->" << te.value;
        return out;
    }
};

#endif
