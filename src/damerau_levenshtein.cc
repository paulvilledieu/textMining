#include "damerau_levenshtein.hh"

unsigned min(vector<unsigned> v)
{
    if (v.size() == 0)
        return -1;
    unsigned min_ = v[0];
    for (unsigned i = 1; i < v.size(); ++i)
    {
        if (min_ > v[i])
	    min_ = v[i];
    }

    return min_;
}

void merge_vectors(vector<tuple<string, unsigned, unsigned>>& v1, vector<tuple<string, unsigned, unsigned>> v2)
{
    for (unsigned i = 0; i < v2.size(); ++i)
        v1.push_back(v2[i]);
}

vector<tuple<string, unsigned, unsigned>> distance_dl(Trie*& t, const string& word, unsigned max_dist)
{
    vector<unsigned> current_row;
    vector<tuple<string, unsigned, unsigned>> results;
   
    if (t == nullptr)
        return results;

    current_row.resize(word.length() + 1);
    for (unsigned i = 0; i <= word.length(); ++i)
        current_row.push_back(i);

    for (unsigned i = 0; i < t->character.size(); ++i)
    {
	string current_word = "";
        current_word += get<1>(t->character[i]);
	merge_vectors(results, distance_rec(get<0>(t->character[i]), get<1>(t->character[i]), word, max_dist, current_row, current_word));
    }
    auto sortRuleLambda = [] (tuple<string, unsigned, unsigned> const& s1, tuple<string, unsigned, unsigned> const& s2) -> bool
    {
        if (get<1>(s1) < get<1>(s2))
            return true;
        else if (get<1>(s1) > get<1>(s2))
       	    return false;
        else
        {
            if (get<2>(s1) > get<2>(s2))
                return true;
            else if (get<2>(s1) < get<2>(s2))
       	        return false;
            else
            {
                if (get<0>(s1) < get<0>(s2))
                    return true;
		else
       	            return false;
            }
        }
    };
    sort(results.begin(), results.end(), sortRuleLambda);
    return results;
}


vector<tuple<string, unsigned, unsigned>> distance_rec(Trie* t, char c, const string& word, unsigned max_dist, vector<unsigned> previous_row, string current_word)
{
    cerr << "letter :" << c << " and current word: " << current_word << " && isWord = " << t->isWord<< " && freq: " << t->freq << endl;
    int column = word.length() + 1;
    vector<unsigned> current_row;
    vector<tuple<string, unsigned, unsigned>> results;
    current_row.push_back(previous_row[0] + 1);

    for (unsigned i = 1; i < column; ++i)
    {
	unsigned insert_dist = current_row[i - 1] + 1;
	unsigned delete_dist = previous_row[i] + 1;
	unsigned replace_dist = 0;
        if (word[i - 1] != c)
	    replace_dist = previous_row[i - 1] + 1;
	else
	    replace_dist = previous_row[i - 1];

	vector<unsigned> dist;
	dist.push_back(insert_dist);
	dist.push_back(delete_dist);
	dist.push_back(replace_dist);

	current_row.push_back(min(dist));
    }

    if (current_row[current_row.size() - 1] <= max_dist && t->isWord)
    {
	cerr << "add to results: " << current_word << " && isWord = " << t->isWord << endl;
        results.push_back(make_tuple(current_word, current_row[current_row.size() - 1], t->freq));
    }

    //cerr << "Trie addr: " << t << " && word: " << word << " && max_dist: " << max_dist << endl; 
    if (min(current_row) <= max_dist)
        for (unsigned i = 0; i < t->character.size(); ++i)
	    merge_vectors(results, distance_rec(get<0>(t->character[i]), get<1>(t->character[i]), word, max_dist, current_row, current_word + get<1>(t->character[i])));
    return results;
}
