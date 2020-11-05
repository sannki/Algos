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

int maxN = 1000000;
bool mask[1000001];

void sieve()
{
    for (int i = 3; i <= maxN; i += 2)
        mask[i] = true;

    for (int i = 3; i <= maxN; i += 2)
    {
        if (mask[i])
        {
            for (int j = i * i; j <= maxN; j += i)
                mask[j] = false;
        }
    }
    mask[0] = false;
    mask[1] = false;
    mask[2] = true;
}

void solve()
{
    sieve();

    rep(i, 2, 100) //Printing prime no between 1 and 100
    {
        if (mask[i])
            cout << i << " ";
    }
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
