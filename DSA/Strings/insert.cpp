#include <iostream>
#include <string>
using namespace std;


int main(){

    string Dataset = "ABDEFGH";
    string Add = "C";
    int input_index = 2;
    string output;
    // output = Dataset.insert(2,"C");
    // cout << output ;

    // insertion manually

    output = Dataset.substr(0,input_index) + Add + Dataset.substr(input_index,Dataset.length()-input_index+1);
    cout << output;
}