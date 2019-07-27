#include "damerau_levenshtein.hh"

int min(vector<int> v)
{
    if (v.size() == 0)
        return -1;
    int min_ = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        if (min_ > v[i])
	    min_ = v[i];
    }

    return min_;
}

vector<tuple<string, int>> merge_vectors(vector<tuple<string, int>> v1, vector<tuple<string, int>> v2)
{
    for (int i = 0; i < v2.size(); ++i)
        v1.push_back(v2[i]);
    return v1;
}

vector<tuple<string, int>> distance_dl(Trie* t, string word, int max_dist)
{
    vector<int> current_row;
    vector<tuple<string, int>> results;
    
    if (t == nullptr)
        return results;

    current_row.resize(word.length() + 1);
    for (int i = 0; i <= word.length(); ++i)
        current_row.push_back(i);

    for (int i = 0; i < CHAR_SIZE; ++i)
        if (t->character[i] != nullptr)
	{
	    string current_word = "";
	    results = merge_vectors(results, distance_rec(t->character[i], (char)i, word, max_dist, current_row, current_word + (char)i));
        }
    return results;
}


vector<tuple<string, int>> distance_rec(Trie* t, char c, string word, int max_dist, vector<int> previous_row, string current_word)
{
    cout << "letter :" << c << " and current word: " << current_word<< endl;
    int column = word.length() + 1;
    vector<int> current_row;
    vector<tuple<string, int>> results;
    current_row.push_back(previous_row[0] + 1);

    for (int i = 1; i < column; ++i)
    {
	int insert_dist = current_row[i - 1] + 1;
	int delete_dist = previous_row[i] + 1;
	int replace_dist = 0;
        if (word[i - 1] != c)
	    replace_dist = previous_row[i - 1] + 1;
	else
	    replace_dist = previous_row[i - 1];

	vector<int> dist;
	dist.push_back(insert_dist);
	dist.push_back(delete_dist);
	dist.push_back(replace_dist);

	current_row.push_back(min(dist));
    }

    if (current_row[current_row.size() - 1] <= max_dist && t->isLeaf)
    {
        results.push_back(make_tuple(current_word, current_row[current_row.size() - 1]));
    }
    if (min(current_row) <= max_dist)
        for (int i = 0; i < CHAR_SIZE; ++i)
	    if (t->character[i] != nullptr)
	        results = merge_vectors(results, distance_rec(t->character[i], (char)i, word, max_dist, current_row, current_word + (char)i));

    return results;
}
