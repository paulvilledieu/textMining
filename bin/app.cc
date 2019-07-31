#include <iostream>
#include "tries.hh"
#include "damerau_levenshtein.hh"

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2) {
        cerr << "TextMiningApp: Argument Error: Please provide the path of your dict.bin\n";
        return -1;
    }

    FILE *fp = fopen(argv[1], "r"); 
    if (fp == NULL) 
    { 
        puts("Could not open file"); 
        return 0; 
    }

    /* Create an empty Trie */
    auto trie = new Trie(false, 0);
    /* Load the Trie with values in dict.bin */
    trie->deserialize(fp);
    fclose(fp); 

    /* Read 'approx dist testWord' from stdin */
    string approx, word, dist;
    cin >> approx >> dist >> word;
    /* The final JSON */
    vector<string> final_res;
    /* The results for each query */
    vector<tuple<string, unsigned short, unsigned>> res;
    /* Loop for each query */
    while (!cin.eof())
    {
        /* Get the Damereau Levenshtein distance sorted results */
        res = distance_dl(trie, word, atoi(dist.c_str()));
        for (auto r : res)
        {
            string s = "";
            if (final_res.size() != 0) {
                s += ",";
            }
            s += "{\"word\":\"" + get<0>(r) + "\",\"freq\":" + to_string(get<2>(r)) + ",\"distance\":" +  to_string(get<1>(r)) + "}";
            final_res.push_back(s);
        }
        /* Print the final JSON on stdout */
        cout << '[';
        for (auto r : final_res) {
            cout << r;
        }
        cout << ']' << endl;
        final_res.clear();
        cin >> approx >> dist >> word;
    }
    
    return 0;
}
