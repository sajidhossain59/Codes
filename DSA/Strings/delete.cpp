#include <iostream>
#include <string>
using namespace std;


int main(){
    string Dataset = "ABCDEFGH";
    string output;
    output = Dataset.erase(1,2);
    cout << output ;
}