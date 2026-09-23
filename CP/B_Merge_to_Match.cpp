#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    vector<int> b(m);
    
    for (auto& x : a) {
        cin >> x;
    }
    for (auto& x : b) {
        cin >> x;
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    bool ok = (n >= 2 * m);
    
    if (ok) {
        for (int i = 0; i < m; i++) {
            if (a[i] > b[i] || a[n - m + i] < b[i]) {
                ok = false;
                break;
            }
        }
    }
    
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}



// Not my solution