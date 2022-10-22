#include <bits/stdc++.h>
#include <chrono>

using namespace std;

long long C(int n, int k) {
    if (k == 0 || k == n)  {
        return 1;
    }
    else {
        return C(n - 1, k - 1) + C(n - 1, k);
    }
}

long long C2(int n, int k) {
    if (k == 1) {
        return n;
    }
    else {
        return (double)n/k * C2(n - 1, k - 1);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    auto start_time = std::chrono::steady_clock::now();
    cout << C(n, k) << endl;
    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    cout << elapsed_ms.count() << " mcs\n";
    auto start_time_2 = std::chrono::steady_clock::now();
    cout << C2(n, k) << endl;
    auto end_time_2 = std::chrono::steady_clock::now();
    auto elapsed_ms2 = std::chrono::duration_cast<std::chrono::microseconds>(end_time_2 - start_time_2);
    cout << elapsed_ms2.count() << " mcs\n";

    return 0;
}
