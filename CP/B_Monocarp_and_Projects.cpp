#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int64 x, y, k;
        cin >> x >> y >> k;

        int64 d = y - x;
        int64 ans = 0;

        // For x+i <= d, calculate d % (x+i) directly.
        int64 cnt = 0;

        if (x <= d) {
            cnt = min(k, d - x + 1);

            for (int64 i = 0; i < cnt; i++) {
                ans += d % (x + i);
            }
        }

        // For all remaining months, x+i > d,
        // so d % (x+i) = d.
        ans += (k - cnt) * d;

        cout << ans << '\n';
    }

    return 0;
}