#ifndef TRIES_H 
#define TRIES_H

#include <iostream>
#include <vector>
#include <fstream> 

#define CHAR_SIZE 128


class Trie {

public:
    bool isLeaf;
    std::vector<Trie *> character;
    Trie() {
        this->isLeaf = false;
    	this->character.resize(CHAR_SIZE);
        for (int i = 0; i < CHAR_SIZE; i++)
	    this->character.push_back(nullptr);
    }

    void insert(std::string);
    bool deletion(Trie*&, std::string);
    bool search(std::string);
    void print_trie();
    void write_trie(std::ofstream& file, char c);
    bool haveChildren(Trie const*);
};


#endif
