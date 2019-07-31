#include "tries.hh"

using namespace std;

vector<tuple<string, unsigned short, unsigned>> distance_dl(Trie*& t, const string& word, unsigned short max_dist);
vector<tuple<string, unsigned short, unsigned>> distance_rec(Trie* t, char c, const string& word,
		unsigned short max_dist, vector<unsigned short> previous_row, string current_word);
