#include <bits/stdc++.h>
using namespace std;

void conc(string &str1, string &str2){
    char newstr[100];
    int i=0;
    for(auto s:str1){
        newstr[i]=s;
        i++;
    }
    newstr[i++]=' ';
    for(auto s:str2){
        newstr[i]=s;
        i++;
    }
    newstr[i]='\0';
    for(auto i:newstr){
        cout<<i;
        if(i=='\0')break;
    }
}
void del();
void repl();
void ins();





int main(){
    string s1,s2;
    cin >> s1>>s2;
    string input_string = "Engineering";
    conc(s1, s2);


}