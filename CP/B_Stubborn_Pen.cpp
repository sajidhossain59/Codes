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
    int n,count=0;string s;cin>>n>>s;
    char c='R';
    for(int i=0;i<n;i++){
        if(s[i]!=c){
            count++;
            c=s[i];
        }
        c=='R'?c='B':c='R';
    }
    cout<<count<<nl;
}


int32_t main() {

   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   
   int t; cin >> t; while (t--)
   solve();

   test();
   return 0;
}