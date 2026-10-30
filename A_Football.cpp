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
#define fr(arr)           \
    cout << #arr << '\n';  \
    for (auto ai : arr)    \
        cout << ai << ' '; \
    cout << '\n';





void test(){

}

// solution

void solve(){
    int cnt=0;
    string str1;
    cin >> str1;
    char tag;
    tag=str1[0];
    for(int i=0;i<str1.length();i++){
        if(tag==str1[i]){
            cnt++;
            if(cnt==7){
                break;
            }
            //out(cnt);
        }
        else{tag=str1[i];cnt=1;}
    }
    cnt>=7? yes:no;

}


int32_t main() {

   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   //int t; cin >> t; while (t--)
   solve();

   test();
   return 0;
}
