#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define nl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pb(x) push_back(x)
#define ok cout << "OK\n"
#define out(x) cout << #x << '=' << x << ' '
#define FOR(x) for(auto i:x)cout << i << ' '





void test(){

}

// solution

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    (abs(a-b)==1 && abs(b-c)==1)? cout<<"YES"<<nl:cout<<"NO"<<nl;
}


int32_t main() {

   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   int t; cin >> t; while (t--)
   solve();

   test();
   return 0;
}