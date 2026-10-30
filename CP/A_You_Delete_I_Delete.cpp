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
    int k;
    string s;
    cin >> s;
    int len = s.length();
    for(int i=0;i<len;i++){
        if(s[i]=='0'){
            k=i;break;
        }
        
    }
    s.erase(k,1);
    cout << nl;
    for(int i=0;i<len;i++){
        if(s[i]=='1'){
            k=i;break;
        }
    }
    s.erase(k,1);
    cout << s;
}



int32_t main() {

   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   int t; cin >> t; while (t--)
   solve();

   test();
   return 0;
}