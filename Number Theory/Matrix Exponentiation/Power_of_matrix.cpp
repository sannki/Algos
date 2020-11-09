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

#define N 101
int ar[N][N], I[N][N]; //matrix ar and identity mat I

void mul(int A[][N], int B[][N], int dim)
{
    int res[dim + 1][dim + 1];

    //mul A with B
    rep(i, 0, dim - 1)
    {
        rep(j, 0, dim - 1)
        {
            res[i][j] = 0;
            rep(k, 0, dim - 1)
            {
                res[i][j] = (res[i][j] % mod + (A[i][k] * B[k][j]) % mod) % mod;
            }
        }
    }
    //storing res in A(Identity here)
    rep(i, 0, dim - 1) rep(j, 0, dim - 1) A[i][j] = res[i][j];
}

void power(int A[][N], int dim, int n)
{
    //making identity mat first
    rep(i, 0, dim - 1) rep(j, 0, dim - 1) i == j ? I[i][j] = 1 : 0;

    //Naive Approach..
    // rep(i, 1, n) mult I with A, n times..

    // {
    //     mul(I, A, dim);
    // }

    // int res = 1;
    // here our res is I

    while (n > 0)
    {
        if (n & 1)
        {
            mul(I, A, dim);
        }
        mul(A, A, dim);
        n /= 2;
    }

    //storing result of I in ar..
    rep(i, 0, dim - 1) rep(j, 0, dim - 1) ar[i][j] = I[i][j];
}

void printMat(int A[][N], int dim)
{
    rep(i, 0, dim - 1)
    {
        rep(j, 0, dim - 1)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

void solve()
{
    memset(ar, 0, sizeof ar);
    memset(I, 0, sizeof I);
    int dim, n;
    cin >> dim >> n;
    //we need to cal matrix A^n;

    rep(i, 0, dim - 1) rep(j, 0, dim - 1) cin >> ar[i][j];

    power(ar, dim, n); //cal ar of dimension dim ^ n

    printMat(ar, dim);
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
