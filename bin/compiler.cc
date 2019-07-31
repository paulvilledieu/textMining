#include "damerau_levenshtein.hh"
#include "tries.hh"

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 3)
        return -1;
    
    const string& dict_name_out = argv[2];
    const string& dict_name_in = argv[1];
    

    Trie* t = new Trie(dict_name_in);
    FILE *fp = fopen(argv[2], "w"); 
    t->serialize(fp, '\0');
    fclose(fp); 
    return 0;
}
