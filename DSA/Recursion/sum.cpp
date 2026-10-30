#include <bits/stdc++.h>
using namespace std;


int sum(int n){
    if(n==0){
        return n;
    }
    else{
        return n+sum(n-1);
    }

}


signed main(){
    int n;
    cin >> n;
    int sum_n = sum(n);
    cout << sum_n;
}