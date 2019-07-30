#ifndef TRIES_H 
#define TRIES_H

#include <iostream>
#include<cstdio> 
#include <vector>
#include <fstream>
#include <sstream>
#include <tuple>
#include <algorithm>
#define CHAR_SIZE 128

using namespace std;

class Trie {

public:
    bool isWord;
    std::vector<tuple<Trie*, char>> character;
    unsigned freq;

    Trie(const string& dictionary_file);
    Trie();

    void insert(const string& word, const unsigned& freq);
    bool search(const string&);
    void print_trie();
    void write_trie(ofstream& file, char c);
    void serialize(Trie *&curr, FILE *fp, char key);
    int deserialize(Trie *&curr, FILE *fp);
};


#endif
