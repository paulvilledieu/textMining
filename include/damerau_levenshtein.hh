#include "tries.hh"

using namespace std;

vector<tuple<string, unsigned, unsigned>> distance_dl(Trie*& t, const string& word, unsigned max_dist);
vector<tuple<string, unsigned, unsigned>> distance_rec(Trie* t, char c, const string& word,
		unsigned max_dist, vector<unsigned> previous_row, string current_word);
