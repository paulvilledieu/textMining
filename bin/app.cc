#include <iostream>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "tries.hh"
#include "damerau_levenshtein.hh"

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2) {
        cerr << "TextMiningApp: Argument Error: Please provide the path of your dict.bin\n";
        return -1;
    }

    struct stat sb;
    int fd = open(argv[1], O_RDONLY);
    if (fstat(fd, &sb) == -1) {
        cerr << "TextMiningApp: File Error: The file '" << argv[1] << "' could not be loaded\n";
        return -1;
    }

    void* addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

    // -----------------------------
    FILE *fp = fopen(argv[1], "r"); 
    if (fp == NULL) 
    { 
        puts("Could not open file"); 
        return 0; 
    } 
    auto trie = new Trie();
    trie->deserialize(trie, fp);
    fclose(fp); 
    // -----------------------------

    string approx, word;
    unsigned dist;
    cin >> approx >> dist >> word;
    vector<string> final_res;
    vector<tuple<string, unsigned, unsigned>> res = distance_dl(trie, word, dist);
    for (auto r : res)
    {
        string s = "";
        if (final_res.size() != 0) {
            s += ",";
        }
        s += "{\"word\":\"" + get<0>(r) + "\",\"freq\":" + to_string(get<2>(r)) + ",\"distance\":" +  to_string(get<1>(r)) + "}";
        final_res.push_back(s);
    }
    while (!cin.eof())
    {
      cin >> approx >> dist >> word;
      res = distance_dl(trie, word, dist);
        for (auto r : res)
        {
            string s = "";
            if (final_res.size() != 0) {
                s += ",";
            }
            s += "{\"word\":\"" + get<0>(r) + "\",\"freq\":" + to_string(get<2>(r)) + ",\"distance\":" +  to_string(get<1>(r)) + "}";
            final_res.push_back(s);
        }
    }
    
    cout << '[';
    for (auto r : final_res) {
        cout << r;
    }
    cout << ']' << endl;
    
    munmap(addr, sb.st_size);
    close(fd);
    return 0;
}