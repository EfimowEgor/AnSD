#include <bits/stdc++.h>

using namespace std;

vector<string> strings;
vector<string> strings2;

int fac(int n) {
    return n?n*fac(n-1):1;
}

void PWOR(string toPermute, int i, int n) {
    int j;
    if (i == n)
        strings.push_back(toPermute);
    else {
        for (j = i; j < n; ++j) {
            swap(toPermute[i], toPermute[j]);
            PWOR(toPermute, i + 1, n);
        }
    }
}

void PWR(string str, string prefix, int i, int n) {
    if (n == 1) {
        for (int j = 0; j < i; ++j) {
            strings2.push_back(prefix + str[j]);
        }
    }
    else {
        for (int k = 0; k < i; ++k) {
            PWR(str, prefix + str[k], i, n - 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<char> s;
    s.resize(n);
    iota(s.begin(), s.end(), '0');
    string str(s.begin(), s.end());
//    PWOR(str, 0, n);
//    sort(strings.begin(), strings.end());
//    cout << "Number of permutations: " << " " << fac(n) << endl;
//    for(auto &x : strings) {
//        cout << x << endl;
//    }

    PWR(str, "", n, n);
    for (auto &y : strings2) {
        cout << y << endl;
    }
    cout << strings2.size() << endl;
    return 0;
}
