#include <bits/stdc++.h>
using namespace std;



int main(){
    int a[5]={4,24,5,21,6};
    int t=1;

    for(int p=0;p<2;p++){
        int m=a[0];
        for(int i=1;i<5;i++){
            if(t*m<t*a[i]){
                m=a[i];
            }
            
        }
        cout << m << endl;
        t=-t;
    }
}