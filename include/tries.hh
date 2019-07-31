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
    Trie(bool isWord, unsigned freq);

    void insert(const string& word, const unsigned& freq);
    bool search(const string&);
    void print_trie();
    void write_trie(ofstream& file, char c);
    /* Dump the Trie into a file */
    void serialize(FILE *fp, char key);
    /* Load data from file into the Trie */
    int deserialize(FILE *fp);
};


#endif
