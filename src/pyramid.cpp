#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

void pyramid(int height, bool direction) {
    vector<string> ref;

    // cool trick where bitshift is 2^i
    string largest = std::to_string(1 << (height - 1)) + ' ';

    int width = largest.length();

    ref.push_back(largest);
    for (int i = height - 2; i >= 0; i--) {
        string s = std::to_string(1 << i);
        s.resize(width, ' ');
        ref.push_back(s);
    }
    string blanks(width, ' ');
    for (int i = 0; i < height - 1; i++) ref.push_back(blanks);

    /*
    ref contains an ordered list of strings to print
    like with height = 4, ref = {"8 ", "4 ", "2 ", "1 ", "  ", "  ", "  "}
    this way, the pyramid can just be printed with sliding windows on ref
    */

    int size = static_cast<int>(ref.size());  // avoid goofy unsigned arithmetic
    if (direction) {
        for (int i = 0; i < height; i++) {
            for (int j = size - i - 1; j > size - i - 1 - height; j--)
                std::cout << ref[j];
            for (int j = height - i; j < height; j++) std::cout << ref[j];
            std::cout << '\n';
        }
    } else {
        for (int i = 0; i < height; i++) {
            for (int j = height - 1 + i; j > i - 1; j--) std::cout << ref[j];
            for (int j = i + 1; j < height + i; j++) std::cout << ref[j];
            std::cout << '\n';
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc == 2 || (argc == 3 && std::string(argv[2]) == "up")) {
        pyramid(std::stoi(argv[1]), true);
    } else if (argc == 3 && std::string(argv[2]) == "down") {
        pyramid(std::stoi(argv[1]), false);
    } else {
        std::cerr << "Usage: " << argv[0] << " <height> [up/down]\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
