#ifndef TRIES_H 
#define TRIES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <tuple>
#define CHAR_SIZE 128

using namespace std;

class Trie {

public:
    bool isLeaf;
    std::vector<Trie*> character;

    Trie(string dictionary_file);
    Trie();

    void insert(std::string);
    bool deletion(Trie*&, std::string);
    bool haveChildren(Trie const*);
    bool search(std::string);
    void print_trie();
    void write_trie(std::ofstream& file, char c);
};


#endif
