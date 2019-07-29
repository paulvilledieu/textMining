#include <iostream>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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

    string approx, dist, word;
    cin >> approx >> dist >> word;
    cerr << word << "\n";

    while (!cin.eof())
    {
      cin >> approx >> dist >> word;
      cerr << word << "\n";
    }

    munmap(addr, sb.st_size);
    close(fd);
    return 0;
}