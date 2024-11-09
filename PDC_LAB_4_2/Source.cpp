#include <iostream>
#include <vector>

using namespace std;

void generateCombinations(int n, int r) {
    vector<int> combination(r);
    for (int i = 0; i < r; ++i) {
        combination[i] = i + 1;
    }

    while (true) {
        cout << "{ ";
        for (int i = 0; i < r; ++i) {
            cout << combination[i] << (i < r - 1 ? ", " : " ");
        }
        cout << "}" << endl;
        int i = r - 1;
        while (i >= 0 && combination[i] == n - r + i + 1) {
            --i;
        }
        if (i < 0) {
            break;
        }

        ++combination[i];

        for (int j = i + 1; j < r; ++j) {
            combination[j] = combination[j - 1] + 1;
        }
    }
}

int main() {
    int n, r;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter r: ";
    cin >> r;

    
    if (n <= 0 || r < 0 || n < r) {
        cout << "Invalid input. Please ensure that n > 0, r >= 0, and n >= r." << endl;
        return 1;
    }

    generateCombinations(n, r);
    return 0;
}
