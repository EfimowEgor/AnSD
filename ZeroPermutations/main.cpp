#include <bits/stdc++.h>

using namespace std;

set<string> uniqueValues;

void P2(int n, string str);

void P1(int n, string str) {
    if (n == 0) {
        // log(n)
        uniqueValues.insert(str);
    } else {
        str += "0";
        P2(n - 1, str);
    }
}

void P2(int n, string str) {
    if (n == 0) {
        // log(n)
        uniqueValues.insert(str);
    } else {
        str += "1";
        P1(n - 1, str);
        P2(n - 1, str);
    }
}

int main() {
    int n;
    cin >> n;
    P1(n, "");
    P2(n, "");
    for (auto &x:uniqueValues) {
        cout << x << endl;
    }
    return 0;
}
