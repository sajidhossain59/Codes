#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    vector<char> numbers;
    for (char c : s) {
        if (c != '+') {
            numbers.push_back(c);
        }
    }

    sort(numbers.begin(), numbers.end());

    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers[i];
        if (i + 1 < numbers.size()) {
            cout << "+";
        }
    }
    cout << "\n";

    return 0;
}