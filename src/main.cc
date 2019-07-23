
#include "tries.hh"

int main(int argc, char **argv)
{
    std::cout << "Trie instantiation\n";
    Trie *t = new Trie();

    std::cout << "Trie insertion\n";
    t->insert("calotte");

    std::cout << "Trie displayed\n";
    t->print_trie();

    std::cout << "Trie insertion\n";
    t->insert("catin");

    return 0;
}
