#include <iostream>
using namespace std;




signed main(){
    int p,r;
    cin>>p>>r;
    int x;x=p;
    for(int i=p-1;i>=(p-r)+1;i--){
        x=x*i;
    }
    cout << x;
}