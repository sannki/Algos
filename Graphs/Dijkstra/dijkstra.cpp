#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define rep(i, l, r) for (int i = (int)(l); i <= (int)(r); i++)
#define repi(i, l, r) for (int i = (int)(l); i >= (int)(r); i--)
const int inf = 1e18;

using namespace std;

vector<vector<pii>> adj;

vi dijkstra(int src, int n)
{
    vi dist(n + 1, inf);
    set<pii> s;
    dist[src] = 0;

    s.insert({dist[src], src});

    while (!s.empty())
    {
        int i = s.begin()->second;
        s.erase(s.begin());

        for (auto p : adj[i])
        {
            int nb = p.first;
            int wt = p.second;
            if (dist[i] + wt < dist[nb])
            {
                s.erase({dist[nb], nb});
                dist[nb] = dist[i] + wt;
                s.insert({dist[nb], nb});
            }
        }
    }
    return dist;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    rep(i, 1, m)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
    }
    int src;
    cin >> src;
    vi res = dijkstra(src, n);
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
