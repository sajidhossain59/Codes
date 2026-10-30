#include <bits/stdc++.h>
using namespace std;

int bf(int a[], int b[], int LS, int LP){
    for(int i=1; i<=LS-LP+1; i++){
        int flag = true;
        for(int j=0;j<LP && flag==true; j++){
            if(b[j] != a[j+i]){
                flag = false;
            }
        }
        if(flag == true){
            return i;
        }
    }
    return 0;
}

int main(){
    int array1[] = {1,2,3,4,5,6,7,8,9,10};
    int matching[] = {8,9,10};
    int LS = sizeof(array1)/sizeof(array1[0]);
    int LP = sizeof(matching)/sizeof(matching[0]);

    int output1 = bf(array1,matching,LS,LP);

    cout << "Found at index:" << output1;
    
}