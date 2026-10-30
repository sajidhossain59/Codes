#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> coins(n);
    int total_sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
        total_sum += coins[i];
    }

    sort(coins.begin(), coins.end());

    int sum = 0;
    int count = 0;cp
    for (int coin : coins) {
        sum += coin;
        count++;
        if (sum > total_sum - sum) {
            break;
        }
    }

    cout << count << "\n";

    return 0;
}