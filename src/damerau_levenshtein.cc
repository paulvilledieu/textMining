#include "damerau_levenshtein.hh"

vector<tuple<string, int>> distance_dl(Trie* t, string word, int max_dist)
{
    vector<int> current_row;
    vector<tuple<string, int>> result;
    
    if (t == nullptr)
        return result;

    current_row.resize(word.length() + 1);
    for (int i = 0; i < word.length(); ++i)
        current_row.push_back(i);

    for (int i = 0; i < CHAR_SIZE; ++i)
        if (t->character[i] != nullptr)
	    distance_rec(t->character[i], (char)i, word, max_dist, current_row, result);

    return result;
}


void distance_rec(Trie* t, char c, string word, int max_dist, vector<int> previous_row, vector<tuple<string, int>> result)
{
    return;
}
