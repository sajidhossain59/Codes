#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Function to compute Greatest Common Divisor
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to compute Least Common Multiple
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    // Step 1: Define the denominators x_i
    vector<long long> x(n);
    for (int i = 0; i < n - 1; ++i) {
        long long val = (long long)(i + 1) * (i + 2);
        x[i] = val;
    }
    x[n - 1] = n;

    // Step 2: Find LCM of all x_i
    long long M = 1;
    for (int i = 0; i < n; ++i) {
        M = lcm(M, x[i]);
    }

    // Step 3: Compute a_i = M / x_i
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = M / x[i];
    }

    // Output the result
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}