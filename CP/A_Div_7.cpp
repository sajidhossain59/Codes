#include <bits/stdc++.h>
using namespace std;
#define ll long long

int check(string s1, string s2)
{
    int ans = 0;
    if (s1.size() < s2.size())
    {
        while (s1.size() < s2.size())
            s1 = "0" + s1;
    }
    else if (s2.size() < s1.size())
    {
        return 10000;
    }
    int n = s2.size();
    for (int i = 0; i < n; i++)
        if (s1[i] != s2[i])
            ans++;
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    if (n % 7 == 0)
    {
        cout << n << "\n";
    }
    else
    {
        int ans = 100000;
        string s1 = to_string(n), s2 = to_string(n);
        int val;
        for (int i = 1; i <= 4444; i++)
        {
            if (i * 7 > 999)
                break;
            s2 = to_string(i * 7);
            //  cout<<s1<<endl;
            //  cout<<s2<<endl;
            //  cout<<"val:"<<check(s2,s1)<<endl;
            if (check(s1, s2) < ans)
            {
                ans = check(s1, s2);
                val = i * 7;
            }
        }
        cout << val << '\n';
    }
    // cout<<check("7","23");
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}