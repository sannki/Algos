// abc -->  a b ab c ac bc abc
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define rep(i, l, r) for (int i = (int)(l); i <= (int)(r); i++)
#define repi(i, l, r) for (int i = (int)(l); i >= (int)(r); i--)
const int inf = 1e18;

using namespace std;

void subs(string s)
{
    vector<string> res;
    int n = (1 << s.size()) - 1; //range i.e (2^n)-1

    for (int i = 0; i <= n; i++)
    {
        int temp = i;
        int cnt = 0;
        string s1;
        while (temp > 0)
        {
            if (temp & 1)
            {
                s1 += s[cnt];
            }
            cnt++;
            temp >>= 1;
        }
        res.push_back(s1);
    }
    for (auto i : res)
        cout << i << " ";
}
int32_t main()
{
    string s;
    cin >> s;
    subs(s);
    return 0;
}
