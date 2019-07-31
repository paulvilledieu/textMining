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
    /* Is the last char of a word ? */
    bool isWord;
    /* Children of this Trie in tuple format <Trie, key> */
    std::vector<tuple<Trie*, char>> character;
    /* Frequency of the word n if isWord 0 otherwise */
    unsigned freq;

    // Constructor for the serialization part, read from the dictionary file
    Trie(const string& dictionary_file);
    // Constructor for the deserialization
    Trie(bool isWord, unsigned freq);

    // Iterative function to insert a key in the Trie
    void insert(const string& word, const unsigned& freq);
    // Iterative function to search a key in Trie
    // It returns true if the word is found in the Trie, otherwise false
    bool search(const string&);
    // Method to display the Trie in a file, can be read with WebGraphViz
    void print_trie();
    // Simple function to write line per line the Trie in a file
    void write_trie(ofstream& file, char c);
    /* Dump the Trie into a file */
    void serialize(FILE *fp, char key);
    /* Load data from file into the Trie */
    int deserialize(FILE *fp);
};


#endif
