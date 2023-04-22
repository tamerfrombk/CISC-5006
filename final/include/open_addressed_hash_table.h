#pragma once

#include <cstddef>

template <class Value>
class OpenAddressedHashTable
{
public:
    // insert @key with an associated @value into the hash table IF @key is found
    void insert(int key, const Value& value)
    {
        // TODO
    }

    // update @key's value to @value IF @key exists
    // if @key does not exist, treat the operation as an insert
    void update(int key, const Value& value)
    {
        // TODO
    }

    // remove @key and its corresponding value
    void remove(int key)
    {
        // TODO
    }

    // return true if @key is in the hash table; otherwise return false
    // CONDITION: your implementation must be O(M) where M is the table size
    bool contains(int key) const
    {
        // TODO
        return false;
    }

    // returns the number of elements in the table
    // CONDITION: your implementation must be O(1)
    size_t num_elements() const
    {
        // TODO
        return 0;
    }

    // return the value mapped to @key if @key exists
    // otherwise, return @default_value
    Value get_value(int key, const Value& default_value)
    {
        // TODO
        return default_value;
    }
};