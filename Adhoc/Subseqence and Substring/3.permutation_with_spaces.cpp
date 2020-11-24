// https : //practice.geeksforgeeks.org/problems/permutation-with-spaces/0
// https : //www.youtube.com/watch?v=1cspuQ6qHW0&ab_channel=AdityaVerma
// abc --> (a b c)(a bc)(ab c)(abc)
#include <bits/stdc++.h>
#define int long long
#define io                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
    using namespace std;

void fn(string inp, string out)
{
    if (inp.length() == 0)
    {
        cout << "(" << out << ")";
        return;
    }
    string out1 = out + " " + inp[0];
    string out2 = out + inp[0];
    inp.erase(inp.begin());
    fn(inp, out1);
    fn(inp, out2);
}
void solve()
{
    string s;
    cin >> s;
    string out = "";
    out += s[0];
    s.erase(s.begin());
    fn(s, out);
}
int32_t main()
{
    io;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
}