#include <bits/stdc++.h>
using namespace std;


int b_s(int a[], int size, int key){
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(a[j]>a[j+1]){
                int c = a[j];
                a[j] = a[j+1];
                a[j+1] = c;
            }
        }
    }

    int start=0,end=size-1,mid;
    
    
    while(start<=end){
        mid = (start+end)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;

    
}


int main(){
    int a[] = {2,3,1,5,4};
    int size = sizeof(a)/sizeof(a[0]);
    int input;
    
    cout << "Search for number:";
    cin >> input;

    int result = b_s(a, size, input);
    
    if(result != -1){
        cout << "Found at index: " << result << endl;
    }
    else{
        cout << "Not found" << endl;
    }
}