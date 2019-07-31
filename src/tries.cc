#include "tries.hh"

Trie::Trie(bool isWord, unsigned freq)
{
    // int character_frequency[41] = ["e", "s", "a", "i", "r", "n", "t", "o", "u", "l", "c", "m", "p", "d", "v", "g", "h", "f", "0", "b", "2", "1", "q", "j", "x", "y", "3", "5", "7", "4", "6", "9", "w", "z", "k", "8", "_", ".", "+", "&", "#"];

    this->isWord = isWord;
    this->freq = freq;
}

Trie::Trie(const string& dictionary_file)
{
    this->isWord = false;
    this->freq = 0;

    ifstream infile(dictionary_file);
    string line;

    while (getline(infile, line))
    {
        istringstream iss(line);
        string s;
        unsigned freq;

        if (!(iss >> s >> freq))
	    break;

        this->insert(s, freq);
    }
}


// Iterative function to insert a key in the Trie
void Trie::insert(const string& word, const unsigned& freq)
{
    // start from root node
    Trie* curr = this;
    for (unsigned i = 0; i < word.length(); i++)
    {
        // create a new node if the path doesn't exist
	char tmp = word[i];
	vector<tuple<Trie*, char>>::iterator it = find_if(curr->character.begin(), curr->character.end(), [&tmp](const tuple<Trie*, char>& val){
	    if (get<1>(val) == tmp)
	        return true;
	    return false; 
	});
        if (curr->character.end() == it)
	{
            curr->character.push_back(make_tuple(new Trie(false, 0), tmp));
	    curr = get<0>(curr->character[curr->character.size() - 1]);
	}
	else
            // go to the next node
            curr = get<0>(*it);
    }

    // mark the current node as a word
    curr->isWord = true;
    curr->freq = freq;
}

// Iterative function to search a key in Trie
// It returns true if the word is found in the Trie, otherwise false
bool Trie::search(const string& word)
{
    // start from the root
    Trie* curr = this;
    for (unsigned i = 0; i < word.length(); i++)
    {
	char tmp = word[i];
        vector<tuple<Trie*, char>>::iterator it = find_if(curr->character.begin(), curr->character.end(), [&tmp](const tuple<Trie*, char>& val){
	    if (get<1>(val) == tmp)
	        return true;
	    return false; 
	});
        if (curr->character.end() == it)
	    return false;

        // go to the next node
        curr = get<0>(*it);

        // if the string is invalid (reached end of path in Trie)
    }

    // if the current node is a word and we have reached the
    // end of the string, return true otherwise false
    return curr->isWord;
}

void Trie::write_trie(ofstream& file, char c)
{
    for (unsigned i = 0; i < this->character.size(); ++i)
    {
	char new_c = get<1>(this->character[i]);
        file << "\"" << c << "\"" << " -> " << "\"" << new_c << "\"" << endl;
        get<0>(this->character[i])->write_trie(file, new_c);
    }
}

void Trie::print_trie()
{
    ofstream file;
    
    file.open("graph.txt");
    if (file.bad())
        return;

    file << "digraph G {" << endl;
    
    this->write_trie(file, '\0');
    
    file << "}" << endl;

    file.close();
}

/* Dump the Trie into a file */
void Trie::serialize(FILE *fp, char key)
{
    // If root node: skip writing
    if (key != '\0')
        fprintf(fp, "%c-%u ", key, this->freq); 
    // Writing key + frequency for each child
    for (auto& child : this->character)
         get<0>(child)->serialize(fp, get<1>(child)); 
  
    // Store marker at the end of children 
    fprintf(fp, "%c-%u ", ')', 0); 
}

/* Load data from file into the Trie */
int Trie::deserialize(FILE *fp) 
{ 
    // Read next item from file. If theere are no more items or next 
    // item is marker, then return 1 to indicate same 
    char key;
    unsigned freq;
    while (fscanf(fp, "%c-%u ", &key, &freq) != EOF && key != ')' && key != '\n') {
        // Else create node with this item and recur for children 
        this->character.push_back(make_tuple(new Trie(freq != 0, freq), key)); 
        get<0>(this->character[this->character.size() - 1])->deserialize(fp);
    }
  
    // Finally return 0 for successful finish 
    return 0; 
} 
