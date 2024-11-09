#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> generatePermutations(int n) {
    vector<vector<int>> allPermutations;
    vector<int> currentPermutation(n);

    for (int i = 0; i < n; ++i) {
        currentPermutation[i] = i + 1;
    }

    allPermutations.push_back(currentPermutation);

    while (next_permutation(currentPermutation.begin(), currentPermutation.end())) {
        allPermutations.push_back(currentPermutation);
    }

    return allPermutations;
}

void printPermutations(const vector<vector<int>>& permutations) {
    for (const auto& perm : permutations) {
        cout << "permutation = {";
        for (size_t i = 0; i < perm.size(); ++i) {
            cout << perm[i] << (i < perm.size() - 1 ? ", " : "");
        }
        cout << "}" << endl;
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n > 0) {
        vector<vector<int>> permutations = generatePermutations(n);
        printPermutations(permutations);
    }
    else {
        cout << "n must be a positive integer." << endl;
    }

    return 0;
}
