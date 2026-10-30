#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define nl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pb(x) push_back(x)
#define ok cout << "OK\n"
#define out(x) cout << #x << '=' << x << ' ';
#define for(arr)           \
    cout << #arr << '\n';  \
    for (auto ai : arr)    \
        cout << ai << ' '; \
    cout << '\n';





void test(){

}

// solution

void solve(){
    ll n,k;
    cin >> n >> k;
    ll odd = (n+1)/2;
    if(k<=odd){
        cout << (2*k)-1;
    }
    else{
        k-=odd;
        cout << (k)*2;
    }
    
}


int32_t main() {

   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   //int t; cin >> t; while (t--)
   solve();

   test();
   return 0;
}