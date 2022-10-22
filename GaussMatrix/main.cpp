#include <bits/stdc++.h>

using namespace std;

int sign = 1;

double det(double * m, int size, int currLine, int diagElem) {
    if (currLine + 1 == size) {
        double r = 1;
        for(int i = 0; i < size; ++i) {
            r *= m[i*size + i];
        }
        return r;
    }
    for(int i = 0; i < size; ++i) {
        double dif = -(m[(i + currLine + 1)*size + diagElem]/(double)m[currLine*size + diagElem]);
        for(int j = currLine; j < size; ++j) {
            m[(i + currLine + 1)*size + j] = m[(i + currLine + 1)*size + j] + m[currLine*size + j] * dif;
        }
    }
    det(m, size, currLine + 1, diagElem + 1);
}

int main() {
    int n;
    cin >> n;
    double matrix[n][n];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    double res = det(*matrix, n, 0, 0);
    cout << res;
    return 0;
}
