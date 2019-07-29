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

    Trie(const string& dictionary_file);
    Trie();

    void insert(const string& word);
    bool deletion(Trie*&, const string& word);
    bool haveChildren(const Trie*);
    bool search(const string&);
    void print_trie();
    void write_trie(ofstream& file, char c);
};


#endif
