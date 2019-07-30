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
    
    const string& path = "/home/pierre-hugo/Documents/text-mining/src/test_words.txt";
    cerr << "Trie instantiation\n";
    Trie* t = new Trie(path);

    const string s1 = "sunndd";
    t->insert(s1, 2);

    const string s2 = "satunday";
    t->insert(s2, 3);

    const string s3 = "sunday";
    cerr << "Trie distance for the word: " << s3 << "\n";
    
    vector<tuple<string, unsigned, unsigned>> distances = distance_dl(t, s3, 2);
    cerr << "results size: " << distances.size() << endl;
    
    for (unsigned i = 0; i < distances.size(); ++i)
        cerr << get<0>(distances[i]) << "! \n";

    cerr << "Trie search for " << "me\n";
    cerr << t->search("me") << "\n";

    cerr << "Trie displayed\n";
    t->print_trie();

    return 0;
}
