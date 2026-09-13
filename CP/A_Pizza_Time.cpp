#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define out(val) cout<<#val<<'='<<val

void solve() {
   ll n;
   ll m1=0,m3;
   cin >> n;
   if (n<=2){
    cout << 0 << "\n";
   }
   else{
    while(n>0){
        m1+=n/3;
        m3=(n/3)+(n%3);
        if(m3<=2){
            break;
        }

    }
    cout << m1 <<"\n";
   }
}


signed main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   int t; cin >> t; while (t--)
      solve();
   return 0;
}