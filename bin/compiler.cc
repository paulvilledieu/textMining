#include "damerau_levenshtein.hh"
#include "tries.hh"

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 3)
        return -1;
    const string& dict_name_out = argv[2];
    const string& dict_name_in = argv[1];
    cout << "dict_name_in: " << dict_name_in << endl;
    cout << "dict_name_out: " << dict_name_out << endl;
    const string& path = "/home/pierre-hugo/Documents/text-mining/src/test_words.txt";
    cout << "Trie instantiation\n";
    Trie* t = new Trie(path);

    const string s1 = "sunndd";
    cout << "Trie insertion: " << s1 << "\n";
    t->insert(s1);

    const string s2 = "satunday";
    cout << "Trie insertion: " << s2 << "\n";
    t->insert(s2);

    cout << "Trie search for " << s2 << "\n";
    cout << t->search(s2) << "\n";

    const string s3 = "sunday";
    cout << "Trie distance for the word: " << s3 << "\n";
    vector<tuple<string, unsigned>> distances = distance_dl(t, s3, 2);
    cout << "results size: " << distances.size() << endl;
    for (unsigned i = 0; i < distances.size(); ++i)
        cout << get<0>(distances[i]) << "\n";

    cout << "Trie deletion: " << s2 << "\n";
    t->deletion(t, s2);

    cout << "Trie search for " << s2 << "\n";
    cout << t->search(s2) << "\n";

    cout << "Trie displayed\n";
    t->print_trie();

    return 0;
}
