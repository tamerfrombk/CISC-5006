#pragma once

#include <string>
#include <stdexcept>

class LinkedString
{
public:
    // default initialize the linked string to an empty string
    LinkedString()
        : head_(nullptr) {}

    // default initialize the linked string to an empty string
    LinkedString(const std::string& str)
    {
        throw std::logic_error("unimplemented");
    }

    // destructor to clean up all nodes
    ~LinkedString()
    {

    }

    // append @c to this LinkedString
    void append(char c)
    {
        throw std::logic_error("unimplemented");
    }

    // append all of the characters in @str to this LinkedString
    void append(const std::string& str)
    {
        throw std::logic_error("unimplemented");
    }

    // return the entire contents of the LinkedString as a std::string
    // HINT: essentially concatenate the linked list
    std::string str() const
    {
        throw std::logic_error("unimplemented");
    }

    // remove the first instance of @c from this LinkedString
    void remove(char c)
    {
        throw std::logic_error("unimplemented");
    }

    // return true if this LinkedString is empty
    bool empty() const
    {
        throw std::logic_error("unimplemented");
    }

    // removes all characters from this string effectively making size() == 0
    void clear()
    {
        throw std::logic_error("unimplemented");
    }

    // replaces __all__ instances of @old with @curr in this string and returns the number of
    // replacements that took place
    size_t replace_all(char old, char curr)
    {
        throw std::logic_error("unimplemented");
    }

    // return the character at @index using 0 indexing (e.g. index 0 is the first character)
    // return NULL character ('\0') if the string is empty or index is out of bounds
    char at(size_t index)
    {
        throw std::logic_error("unimplemented");
    }

    // return a substring starting from @index
    // out of range indexes return an empty string
    LinkedString substr(size_t index)
    {
        throw std::logic_error("unimplemented");
    }

private:
    struct Node {
        // the character value contained in this node
        char value;

        // pointer to the next element in the list or nullptr if at the end of the list
        Node *next;
        
        // Node constructor
        Node(char value, Node *next = nullptr)
            : value(value), next(next) {}
    };

    // the head pointer for the string
    Node *head_ = nullptr;
};