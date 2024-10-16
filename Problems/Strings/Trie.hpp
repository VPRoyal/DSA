#ifndef TRIE_HPP
#define TRIE_HPP

#include <unordered_map>
#include <string>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode();
};

class Trie {
private:
    TrieNode* root;

public:
    Trie();
    void insert(const std::string& word);
    bool search(const std::string& word);
};

#endif // TRIE_HPP
