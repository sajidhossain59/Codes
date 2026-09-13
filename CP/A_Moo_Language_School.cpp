#include<bits/stdc++.h>
using namespace std;
#define ll long long


void solve() {
   ll n,k,result=0;
   string s;
   cin >> n >> k;
   cin >> s;

   int i=0,zero=0;
   while(i<n){
      for(int j=0;j<k && i<n;j++){
         if(s[i]=='0'){
            zero++;
         }
         i++;
      }
      if(zero==0){
         result++;
      }
      zero=0;
   }
   cout<< result << "\n";

}


signed main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   int t; cin >> t; while(t--)
   solve();
   return 0;
}