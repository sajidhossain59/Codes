#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define out(val) cout<<#val<<'='<<val

void solve() {
    long long n;
    cin >> n;

    for (long long a = sqrt(n); a >= 1; --a) {
        if (n % a == 0) {
            long long b = n / a;
            cout << 2 * (a + b) << "\n";
            break;
        }
    }
}


signed main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   //int t; cin >> t; while (t--)
      solve();
   return 0;
}


// Help of ai to breakdown logic