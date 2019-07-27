#include "damerau_levenshtein.hh"
#include "tries.hh"

using namespace std;

int main(int argc, char **argv)
{
    cout << "Trie instantiation\n";
    Trie *t = new Trie();

    string s1 = "sunndd";
    cout << "Trie insertion: " << s1 << "\n";
    t->insert(s1);

    string s2 = "satunday";
    cout << "Trie insertion: " << s2 << "\n";
    t->insert(s2);

    cout << "Trie search for " << s2 << "\n";
    cout << t->search(s2) << "\n";

    string s3 = "sunday";
    cout << "Trie distance for the word: " << s3 << "\n";
    vector<tuple<string, int>> distances = distance_dl(t, s3, 2);
    cout << "results size: " << distances.size() << endl;
    for (int i = 0; i < distances.size(); ++i)
        cout << get<0>(distances[i]) << "\n";

    cout << "Trie deletion: " << s2 << "\n";
    t->deletion(t, s2);

    cout << "Trie search for " << s2 << "\n";
    cout << t->search(s2) << "\n";

    cout << "Trie displayed\n";
    t->print_trie();

    return 0;
}
