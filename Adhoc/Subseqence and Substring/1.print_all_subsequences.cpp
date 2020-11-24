// abc -->  c b bc a ac ab abc
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

void print_subs(string input, string output = "")
{
    if (input.length() == 0)
    {
        cout << output << " ";
        return;
    }
    print_subs(input.substr(1), output);
    print_subs(input.substr(1), output + input[0]);
}
void solve()
{
    string s;
    cin >> s;
    print_subs(s);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    rep(i, 1, t)
    {
        solve();
    }
}
