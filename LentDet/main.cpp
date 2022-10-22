#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, det = 0;
    cin >> n;
    int matrix[n][n];
    // fill matrix w/ values
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    if (n <= 0) {
        cout << "Incorrect input" << endl;
    }
    if (n == 1) {
        cout << matrix[0][0];
    }
    if (n == 2) {
        cout << matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1];
    }
    else {
        int t = matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1]; // n - 1
        int f = matrix[0][0]; // n - 2
        for (int i = 0; i < n - 2; ++i) {
            det = matrix[0][0]*t - matrix[1][0]*matrix[0][1]*f;
            f = t;
            t = det;
        }
        cout << det << endl;
        // Using formula
        cout << (n + 1) * pow(3, n) << endl;
    }

    return 0;
}
