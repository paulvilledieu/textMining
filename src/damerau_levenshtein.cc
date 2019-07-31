#include "damerau_levenshtein.hh"


// Auxiliary function to compute the min in a vector of integers
unsigned short min(vector<unsigned short> v)
{
    if (v.size() == 0)
        return -1;

    unsigned short min_ = v[0];

    for (unsigned short i = 1; i < v.size(); ++i)
        if (min_ > v[i])
	    min_ = v[i];

    return min_;
}


// Auxiliary function to merge two vectors to get the results recursively
// Used in the functions below
void merge_vectors(vector<tuple<string, unsigned short, unsigned>>& v1, vector<tuple<string, unsigned short, unsigned>> v2)
{
    for (unsigned short i = 0; i < v2.size(); ++i)
        v1.push_back(v2[i]);
}


// Distance dl (damerau levenshtein), compute the distance for a given Trie
// It takes a max distance and a word and call the recursive function distance_rec
vector<tuple<string, unsigned short, unsigned>> distance_dl(Trie*& t, const string& word, unsigned short max_dist)
{
    vector<unsigned short> current_row;
    vector<tuple<string, unsigned short, unsigned>> results;
   
    // Check if the Trie given is not null
    if (t == nullptr)
        return results;

    // Compute the first row of the distance matrix
    for (unsigned short i = 0; i <= word.length(); ++i)
        current_row.push_back(i);

    // Iterate over the first children of the Trie
    for (unsigned short i = 0; i < t->character.size(); ++i)
    {
	string current_word = "";
        current_word += get<1>(t->character[i]);
	merge_vectors(results, distance_rec(get<0>(t->character[i]), get<1>(t->character[i]), word, max_dist, current_row, current_word, current_row));
    }

    // Lambda used to sort the results
    auto sortRuleLambda = [] (tuple<string, unsigned short, unsigned> const& s1, tuple<string, unsigned short, unsigned> const& s2) -> bool
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

    // Sort the results with the lambda defined previously
    sort(results.begin(), results.end(), sortRuleLambda);
    return results;
}


// The recursive function used to browse all the nodes of the Trie and construct the distance matrix
// It takes the current Trie node, the letter, the base word, the maximum distance, the previous row
// of the matrix and the current word since the root of the Trie
vector<tuple<string, unsigned short, unsigned>> distance_rec(Trie* t, char c, const string& word, unsigned short max_dist, vector<unsigned short> previous_row, string current_word, vector<unsigned short> pre_previous_row)
{
    //cerr << "letter :" << c << " and current word: " << current_word << " && isWord = " << t->isWord<< " && freq: " << t->freq << endl;
    unsigned short column = word.length() + 1;
    // Current row used to compute the new distance in the matrix
    vector<unsigned short> current_row;
    // Vector containing the results (word, distance, frequency)
    vector<tuple<string, unsigned short, unsigned>> results;
    // Need to insert the previous row
    current_row.push_back(previous_row[0] + 1);
    
    // Iterate over the letter in the word + 1
    for (unsigned short i = 1; i < column; ++i)
    {
	// Compute the different distances between the letters of the words
	unsigned short insert_dist = current_row[i - 1] + 1;
	unsigned short delete_dist = previous_row[i] + 1;
	unsigned short replace_dist = 0;
        if (word[i - 1] != c)
	    replace_dist = previous_row[i - 1] + 1;
	else
	    replace_dist = previous_row[i - 1];

	// Take the minimum of these distances
	vector<unsigned short> dist;
	dist.push_back(insert_dist);
	dist.push_back(delete_dist);
	dist.push_back(replace_dist);

	if (current_word.length() > 1 && i - 1 > 0 && c == word[i - 2] && current_word[current_word.length() - 2] == word[i - 1] && word[i - 1] != c)
            dist.push_back(pre_previous_row[i - 2] + 1);

        // Insert it in the current row of the matrix
	current_row.push_back(min(dist));
    }

    // Check if the current word is a word and if his distance is smaller than max_dist
    if (current_row[current_row.size() - 1] <= max_dist && t->isWord)
        results.push_back(make_tuple(current_word, current_row[current_row.size() - 1], t->freq));
    
    // If the distance of the current word is still smaller, call the function recursively
    // on the children
    if (min(current_row) <= max_dist)
        for (unsigned short i = 0; i < t->character.size(); ++i)
	{
	    merge_vectors(results, distance_rec(get<0>(t->character[i]), get<1>(t->character[i]), word, max_dist, current_row, current_word + get<1>(t->character[i]), previous_row));
        }
    // Return the results
    return results;
}
