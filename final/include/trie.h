#pragma once

#include <string>
#include <vector>


class Trie
{
public:
    // insert @word into the trie
    void insert(const std::string& word)
    {
        // TODO
    }

    // return a list of words that have @prefix as their prefix
    std::vector<std::string> words_with_prefix(const std::string& prefix) const
    {
        // TODO
        return {};
    }

    // return true if @word exists in the trie
    bool contains(const std::string& word) const
    {
        // TODO
        return false;
    }

    // return the number of words contained in the trie
    // CONDITION: must be O(1) 
    size_t num_words() const
    {
        // TODO
        return 0;
    }

    // return the shortest word in the trie
    std::string shortest_word() const
    {
        // TODO
        return "";
    }

    // return the longest word in the trie
    std::string longest_word() const
    {
        // TODO
        return "";
    }

    // return the alphabetically first word in the trie
    std::string alphabetically_first() const
    {
        // TODO
        return "";
    }

    // return the alphaetically last word in the trie
    std::string alphabetically_last() const
    {
        // TODO
        return "";
    }
};