#include <bits/stdc++.h>
using namespace std;

int main(){
    int value = 10;
    int *add = &value;
    int **add2 = &add;

    cout << **add2;
}