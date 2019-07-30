#include "tries.hh"

Trie::Trie()
{
    // int character_frequency[41] = ["e", "s", "a", "i", "r", "n", "t", "o", "u", "l", "c", "m", "p", "d", "v", "g", "h", "f", "0", "b", "2", "1", "q", "j", "x", "y", "3", "5", "7", "4", "6", "9", "w", "z", "k", "8", "_", ".", "+", "&", "#"];

    this->isLeaf = false;
    this->character.resize(CHAR_SIZE);
    for (int i = 0; i < CHAR_SIZE; i++)
        this->character.push_back(nullptr);
}

Trie::Trie(const string& dictionary_file)
{
    this->isLeaf = false;
    this->character.resize(CHAR_SIZE);
    for (unsigned i = 0; i < CHAR_SIZE; i++)
        this->character.push_back(nullptr);

    ifstream infile(dictionary_file);
    string line;

    while (getline(infile, line))
    {
        istringstream iss(line);
        string s;
        unsigned freq;

        if (!(iss >> s >> freq))
	    break;

        this->insert(s);
	cout << "added " << s << endl;
    }
}


// Iterative function to insert a key in the Trie
void Trie::insert(const string& word)
{
    // start from root node
    Trie* curr = this;
    for (unsigned i = 0; i < word.length(); i++)
    {
        // create a new node if the path doesn't exist
        if (curr->character[word[i]] == nullptr)
            curr->character[word[i]] = new Trie();
        
	// go to the next node
        curr = curr->character[word[i]];
    }

    // mark the current node as leaf
    curr->isLeaf = true;
}

// Iterative function to search a key in Trie
// It returns true if the word is found in the Trie, otherwise false
bool Trie::search(const string& word)
{
    // return false if the Trie is empty
    if (this == nullptr)
        return false;

    // start from the root
    Trie* curr = this;
    for (unsigned i = 0; i < word.length(); i++)
    {
        // go to the next node
        curr = curr->character[word[i]];

        // if the string is invalid (reached end of path in Trie)
        if (curr == nullptr)
            return false;
    }

    // if the current node is a leaf and we have reached the
    // end of the string, return true otherwise false
    return curr->isLeaf;
}

// returns true if the given node has any children
bool Trie::haveChildren(const Trie* curr)
{
    for (unsigned i = 0; i < CHAR_SIZE; i++)
        if (curr->character[i])
            return true;
            // child found

    return false;
}

// Recursive function to delete a key in the Trie
bool Trie::deletion(Trie*& curr, const string& word)
{
    // return if the Trie is empty
    if (curr == nullptr)
        return false;

    // if we have not reached the end of the key
    if (word.length())
    {
        // call deletion for the node corresponding to next character in the key
        // and if it returns true, delete the current node (if it is non-leaf)

        if (curr != nullptr &&
            curr->character[word[0]] != nullptr &&
            deletion(curr->character[word[0]], word.substr(1)) &&
            curr->isLeaf == false)
        {
            if (!haveChildren(curr))
            {
                delete curr;
                curr = nullptr;
                return true;
            }
            else
                return false;
        }
    }

    // if we have reached the end of the word
    if (word.length() == 0 && curr->isLeaf) {
        // if the current node is a leaf node and doesn't have any children
        if (!haveChildren(curr)) {
            // delete current node
            delete curr;
            curr = nullptr;

            // delete non-leaf parent nodes
            return true;
        }

        // if the current node is a leaf node and have children
        else {
            // mark current node as non-leaf node (DON'T DELETE IT)
            curr->isLeaf = false;

            // don't delete its parent nodes
            return false;
        }
    }

    return false;
}

void Trie::write_trie(ofstream& file, char c)
{
    for (unsigned i = 0; i < CHAR_SIZE; ++i)
    {
	if (this->character[i] != nullptr)
        {
	    char new_c = i;
            file << "\"" << c << "\"" << " -> " << "\"" << new_c << "\"" << endl;
            this->character[i]->write_trie(file, new_c);
	}
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

void Trie::serialize(Trie *&curr, FILE *fp, char key)
{
    // Base case 
    if (curr == nullptr) return; 
  
    // Else, store current node and recur for its children 
    fprintf(fp, "%c ", key); 
    for (auto& child : curr->character)
         get<0>(child)->serialize(child, fp, get<1>(child)); 
  
    // Store marker at the end of children 
    fprintf(fp, "%c ", ')'); 
}

int deserialize(Trie *&curr, FILE *fp) 
{ 
    // Read next item from file. If theere are no more items or next 
    // item is marker, then return 1 to indicate same 
    char key; 
    if ( !fscanf(fp, "%c ", &key) || key == ')' ) 
       return 1; 
  
    // Else create node with this item and recur for children 
    auto child = make_tuple(new Trie(), key); 
    for (auto& child : curr->character)
      if (get<0>(child)->deserialize(get<0>(child), fp)) 
         break; 
  
    // Finally return 0 for successful finish 
    return 0; 
} 
