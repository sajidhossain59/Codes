#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define out(val) cout<<#val<<'='<<val

void solve() {
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
   }
   int cnt1 = 0, cnt2 = 0;
   for (int i = 0; i < n; i++) {
      if (arr[i] == 1) {
         cnt1++;
      }
   }
   if (cnt1 >= n - cnt1)cout << "Bessie\n";
   else cout << "Elsie\n";
}


signed main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   int t; cin >> t; while (t--)
      solve();
   return 0;
}