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
    int n;cin>>n;
    vector <ll> arr1;
    ll o=0,e=0;
    for (int i=0;i<n;i++){
        int x;cin >> x;arr1.pb(x);
    }
     for(auto i:arr1){
        if(i%2==0)e++;
        else o++;
     }

     e>o? cout << "READY FOR BATTLE\n":cout<<"NOT READY\n";
}


int32_t main() {

   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   //int t; cin >> t; while (t--)
   solve();

   test();
   return 0;
}