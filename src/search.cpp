#include <vector>
#include <algorithm> // for std::min and std::max
#include <iostream>
#include <cmath> // for log2

using std::vector;

bool searchMat(vector<vector<int>> matrix, int target) {
    int matrixSize = matrix.size() * matrix[0].size();
    if (matrixSize == 0) return false;

    int mid = matrixSize / 2;
    int step = mid / 2;

    for (int i = 0; i <= std::log2(matrixSize) + 1; i++) {
        int v = mid / matrix[0].size(); // row index
        int h = mid % matrix[0].size(); // column index

        if (matrix[v][h] == target) {
            return true;
        } else if (target < matrix[v][h]) {
            mid -= step;
            if (mid < 0) break;
        } else {
            mid += step;
            if (mid >= matrixSize) break;
        }

        step = (step / 2 == 0) ? 1 : step / 2;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 13;

    std::cout << (searchMat(matrix, target) ? "true" : "false") << std::endl;
}