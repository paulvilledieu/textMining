#include "damerau_levenshtein.hh"
#include "tries.hh"

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 3)
        return -1;
    
    const string& dict_name_out = argv[2];
    const string& dict_name_in = argv[1];
    
    cerr << "dict_name_in: " << dict_name_in << endl;
    cerr << "dict_name_out: " << dict_name_out << endl;
    
    cerr << "Trie instantiation\n";
    
    Trie* t = new Trie(dict_name_in);
    FILE *fp = fopen(argv[2], "w"); 
    t->serialize(fp, '\0');
    fclose(fp); 
    cerr << "Trie serialized\n";
    return 0;
}
