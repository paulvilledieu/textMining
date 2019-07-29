#include "tries.hh"

using namespace std;

vector<tuple<string, int>> distance_dl(Trie* t, string word, int max_dist);
vector<tuple<string, int>> distance_rec(Trie* t, char c, string word, int max_dist, vector<int> previous_row, string current_word);
