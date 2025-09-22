#include <vector>
#include <iostream>

using std::vector;

vector<int> targetVector(vector<int> nums, vector<int> index) {
    vector<int> target;

    for (int i = 0; i < index.size(); i++) {
        target.insert(target.begin() + index[i], nums[i]);
    }

    return target;
}

int main() {
    vector<int> v = targetVector({1}, {0});

    for (int el : v) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}