#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define int ll
#define INF 100000000000000010
#define M (ll)(1e9 + 7)
using namespace std;
#define sort(arr) sort(arr.begin(), arr.end())
#define be(arr) arr.begin(), arr.end()
#define F first
#define S second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb(v) push_back(v)
#define pf(v) push_front(v)
#define FOR(arr)           \
    for (auto ai : arr)    \
        cout << ai << ' '; \
    cout << '\n';
#define OK cout << "OK" << endl
#define out(x) cout << #x << '=' << x << ' '

/*submited by atromitos*/

/*
****think harder
*/

/*problem statements
 */

/*Obs
 */

/*steps
 */
void test_case()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> cnt(101, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= arr[i]; j++)
        {
            cnt[j]++;
        }
    }
    for(auto &ai:arr)ai=0;
    for(int i=n-1;i>=0;i--){
        int j=1;
        while(j<=100&&cnt[j]>0){
            arr[i]++;
            cnt[j++]--;
        }
    }
    FOR(arr);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;
    while (tt--)
        test_case();
    return 0;
}