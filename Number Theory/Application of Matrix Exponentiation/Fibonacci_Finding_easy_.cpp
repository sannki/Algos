// https : //www.hackerrank.com/challenges/fibonacci-finding-easy/problem
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

int ar[3];
int T[3][3], I[3][3];

void mul(int A[3][3], int B[3][3])
{
    int res[3][3];
    rep(i, 1, 2)
    {
        rep(j, 1, 2)
        {
            res[i][j] = 0;
            rep(k, 1, 2)
            {
                res[i][j] = (res[i][j] % mod + (A[i][k] * B[k][j]) % mod) % mod;
            }
        }
    }
    rep(i, 1, 2) rep(j, 1, 2) A[i][j] = res[i][j];
}
int getfib(int n)
{
    if (n <= 2)
    {
        return ar[n];
    }
    T[1][1] = 0;
    T[1][2] = T[2][1] = T[2][2] = 1;

    I[1][1] = I[2][2] = 1;
    I[1][2] = I[2][1] = 0;

    n--;
    while (n > 0)
    {
        if (n & 1)
        {
            mul(I, T);
        }
        mul(T, T);
        n >>= 1;
    }

    int ans = (ar[1] * I[1][1] + ar[2] * I[2][1]) % mod;
    return ans;
}
void solve()
{
    int n;
    cin >> ar[1] >> ar[2] >> n;
    n++;

    cout << getfib(n) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    rep(i, 1, t)
    {
        solve();
    }
}
