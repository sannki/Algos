// https : //www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/
/*
    3--> ((())) (()()) (())() ()(()) ()()() ((())) (()()) (())() ()(()) ()()()
*/
#include <bits/stdc++.h>

#define int long long
#define io                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;

vector<string> res;

void fn(int o, int c, string out = "")
{
    if (o == 0 and c == 0)
    {
        res.push_back(out);
        return;
    }
    if (o == c)
    {
        out.push_back('(');
        fn(o - 1, c, out);
    }
    else if (o != 0)
    {
        string out1, out2;
        out1 = out;
        out2 = out;
        out1.push_back('(');
        out2.push_back(')');
        fn(o - 1, c, out1);
        fn(o, c - 1, out2);
    }
    else
    {
        out.push_back(')');
        fn(o, c - 1, out);
    }
}

void solve(int n)
{
    int open, close;
    open = close = n;
    fn(open, close);
    for (auto i : res)
        cout << i << " ";
}

int32_t main()
{
    int n;
    cin >> n;
    solve(n);
    for (auto i : res)
        cout << i << " ";
}