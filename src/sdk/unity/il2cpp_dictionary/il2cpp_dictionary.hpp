//
// Created by zxsrxt on 05.06.2025.
//

#ifndef IL2CPP_DICTIONARY_HPP
#define IL2CPP_DICTIONARY_HPP
#include "../il2cpp_array/il2cpp_array.hpp"
#include <map>

template<typename TKey, typename TValue>
class il2cpp_dictionary {
public:
    struct Entry {
        int hashCode, next;
        TKey key;
        TValue value;
    };
    void *klass;
    void *monitor;
    il2cpp_array<int> *buckets;
    il2cpp_array<Entry> *entries;
    int count;
    int version;
    int freeList;
    int freeCount;
    void *comparer;
    il2cpp_array<TKey> *keys;
    il2cpp_array<TValue> *values;
    void *syncRoot;
    std::vector<TKey> get_keys() {
        std::vector<TKey> ret;
        for (int i = 0; i < count; ++i) ret.emplace_back(entries->m_it[i].key);
        return std::move(ret);
    }
    std::vector<TValue> get_values() {
        std::vector<TValue> ret;
        for (int i = 0; i < count; ++i) ret.emplace_back(entries->m_it[i].value);
        return std::move(ret);
    }
};

#endif //IL2CPP_DICTIONARY_HPP
