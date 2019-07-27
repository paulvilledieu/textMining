#include "tries.hh"

Trie::Trie()
{
    // int character_frequency[41] = ["e", "s", "a", "i", "r", "n", "t", "o", "u", "l", "c", "m", "p", "d", "v", "g", "h", "f", "0", "b", "2", "1", "q", "j", "x", "y", "3", "5", "7", "4", "6", "9", "w", "z", "k", "8", "_", ".", "+", "&", "#"];

    this->isLeaf = false;
    this->character.resize(CHAR_SIZE);
    for (int i = 0; i < CHAR_SIZE; i++)
        this->character.push_back(nullptr);
}

Trie::Trie(string dictionary_file)
{
    fstream f(dictionary_file);
    string s;
    unsigned freq;
    f >> s >> freq;

    while (!f.eof())
    {
        this->insert(s);
	f >> s >> freq;
    }
}


// Iterative function to insert a key in the Trie
void Trie::insert(string key)
{
    // start from root node
    Trie* curr = this;
    for (int i = 0; i < key.length(); i++)
    {
        // create a new node if path doesn't exists
        if (curr->character[key[i]] == nullptr)
	{
            curr->character[key[i]] = new Trie();
        }
        // go to next node
        curr = curr->character[key[i]];
    }

    // mark current node as leaf
    curr->isLeaf = true;
}

// Iterative function to search a key in Trie. It returns true
// if the key is found in the Trie, else it returns false
bool Trie::search(string key)
{
    // return false if Trie is empty
    if (this == nullptr)
        return false;

    Trie* curr = this;
    for (int i = 0; i < key.length(); i++)
    {
        // go to next node
        curr = curr->character[key[i]];

        // if string is invalid (reached end of path in Trie)
        if (curr == nullptr)
            return false;
    }

    // if current node is a leaf and we have reached the
    // end of the string, return true
    return curr->isLeaf;
}

// returns true if given node has any children
bool Trie::haveChildren(Trie const* curr)
{
    for (int i = 0; i < CHAR_SIZE; i++)
        if (curr->character[i])
            return true;
            // child found

    return false;
}

// Recursive function to delete a key in the Trie
bool Trie::deletion(Trie*& curr, string key)
{
    // return if Trie is empty
    if (curr == nullptr)
        return false;

    // if we have not reached the end of the key
    if (key.length())
    {
        // recur for the node corresponding to next character in the key
        // and if it returns true, delete current node (if it is non-leaf)

        if (curr != nullptr &&
            curr->character[key[0]] != nullptr &&
            deletion(curr->character[key[0]], key.substr(1)) &&
            curr->isLeaf == false)
        {
            if (!haveChildren(curr))
            {
                delete curr;
                curr = nullptr;
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    // if we have reached the end of the key
    if (key.length() == 0 && curr->isLeaf) {
        // if current node is a leaf node and don't have any children
        if (!haveChildren(curr)) {
            // delete current node
            delete curr;
            curr = nullptr;

            // delete non-leaf parent nodes
            return true;
        }

        // if current node is a leaf node and have children
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
    for (int i = 0; i < CHAR_SIZE; ++i)
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
