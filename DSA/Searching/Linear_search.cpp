#include <bits/stdc++.h>
using namespace std;

int l_s(int a[10], int f, int size){
    
    for(int i=0;i<size;i++){
        if(a[i]==f){
            return i;
        }
    }
    return -1;
}


int main(){
    int array[10]={10,15,12,23,45,23,43,55,34,2};
    int size = sizeof(array)/sizeof(array[0]);
    int input;
    cout << "search a number:";
    cin >> input;
    if(l_s(array,input,size)!=-1){
        cout << "Found at index:" << l_s(array,input,size);
    }
    else{
        cout << "Not found";
    }
}