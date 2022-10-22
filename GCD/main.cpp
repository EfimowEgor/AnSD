#include <bits/stdc++.h>

using namespace std;

int NOD(int a, int b);
int NOK(int a, int b);

int GCD(int a, int b) {
    return b?GCD(b,a%b):a;
}

int main() {
    int a, b, a2, b2, _1, _2;
    cin >> a >> b;
    a2 = a;
    b2 = b;
    _1 = a;
    _2 = b;
    cout << "Recursion" << endl;
    cout << "GCD" << ": " << GCD(max(a, b), min(a, b)) << " LCM:" << a * b / (GCD(a, b)) << endl;
    // Time complexity: O(log n) cuz we divide every iteration out range
    while (min(a2, b2)) {
        int modulo = max(a2, b2) % min(a2, b2);
        a2 = b2;
        b2 = modulo;
    }
    cout << "Iter GCD: " << a2 << " " << "Iter LCM: " << (a * b) / a2 << endl;
    cout << NOD(_1, _2) << " " << NOK(_1, _2) << endl;
    return 0;

}
int NOD (int a, int b){
    if (a < b){
        swap (a,b);}
    while(a % b != 0){
        a = a % b;
        swap (a, b);
    }
    return b;
}
int NOK (int a, int b){
    int k = a*b/NOD(a,b);
    return k;
}

