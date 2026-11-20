#include <bits/stdc++.h>
using namespace std;


int fibonacci(int n){
    int a=0,b=1,c;
    if(n==1){
        return a;
    }
    else if(n==2){
        return b;
    }
    else{
        for(int i=3;i<=n;i++){
            c=a+b;
            a=b;b=c;
        }
        return c;
    }
}


signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<fibonacci(i)<<" ";
    }
}