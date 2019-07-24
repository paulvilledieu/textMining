#include "tries.hh"

using namespace std;

vector<tuple<string, int>> distance_dl(Trie* t, string word, int max_dist);
void distance_rec(Trie* t, char c, string word, int max_dist, vector<int> previous_row, vector<tuple<string, int>> result);
