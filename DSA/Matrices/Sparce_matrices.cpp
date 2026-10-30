#include <bits/stdc++.h>
using namespace std;

int main(){
    int sparse_matrix [5][6] = {{0,0,0,6,0,0},
                                {0,0,1,0,0,5},
                                {0,0,0,0,4,5},
                                {0,4,0,0,3,0},
                                {0,0,5,0,5,0}
                                };


    int size = 0;
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            if(sparse_matrix[i][j]!=0){
                size++;
            }
        }
    }

    int result_matrix [size][3];

    int k=0;

    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            if(sparse_matrix[i][j]!=0){
                result_matrix[k][0] = i;
                result_matrix[k][1] = j;
                result_matrix[k][2] = sparse_matrix[i][j];
                k++;

            }
        }
    }

    for(int i = 0;i<size;i++){
        for(int j=0;j<3;j++){
            cout<< result_matrix[i][j] << " ";
        }
        cout<<endl;
    }
}


//done code