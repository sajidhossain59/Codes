#include <iostream>
using namespace std;

int checkPrime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
    return true;
}


signed main(){
    int n;
    cin>>n;
    (checkPrime(n)==true)? cout<<"Prime":cout<<"Not Prime";
}