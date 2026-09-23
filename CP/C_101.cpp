#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N=2e5+5;
const ll INF=1e18;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int first=-1,last=-1,len=1,ma=0,recf=-1,recl=-1;
    bool j1=false;
    for(int i=0;i<n;i++){
        if(a[i]==0&&!j1) continue;
        if(a[i]==1){
            if(!j1) j1=true;
            if(first==-1){
                first=i;
                continue;
            }else{
                if(i-first>ma){
                    ma=i-first;
                    recf=first;
                    recl=i;
                }
                first=i;
            }
        }else if(a[i]==-1){
            if(!j1) j1=true;
            if(first==-1){
                first=i;
                continue;
            }else{
                if(i-first>ma){
                    ma=i-first;
                    recf=first;
                    recl=i;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(i==recf||i==recl||i==first) cout<<"1 ";
        else if(a[i]==-1) cout<<"0 ";
        else cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

// Not my code