#include "tries.hh"

using namespace std;

// Distance dl (damerau levenshtein), compute the distance for a given Trie
// It takes a max distance and a word and call the recursive function distance_rec
vector<tuple<string, unsigned short, unsigned>> distance_dl(Trie*& t, const string& word, unsigned short max_dist);

// The recursive function used to browse all the nodes of the Trie and construct the distance matrix
// It takes the current Trie node, the letter, the base word, the maximum distance, the previous row
// of the matrix and the current word since the root of the Trie
vector<tuple<string, unsigned short, unsigned>> distance_rec(Trie* t, char c, const string& word,
		unsigned short max_dist, vector<unsigned short> previous_row, string current_word, vector<unsigned short> pre_previous_row);
