// https: //www.geeksforgeeks.org/permute-string-changing-case/
// abc-- > abc Abc aBc ABc abC AbC aBC ABC
// https : //www.youtube.com/watch?v=J2Er5XceU_I&ab_channel=AdityaVerma
/*
1 abc
ABC ABc AbC Abc aBC aBc abC abc
*/

#include <bits/stdc++.h>

#define int long long
#define io                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;

void fn(string inp, string out = "")
{
    if (inp.length() == 0)
    {
        cout << out << " ";
        return;
    }
    string out1 = out;
    out1.push_back(toupper(inp[0]));
    string out2 = out + inp[0];
    inp.erase(inp.begin());
    fn(inp, out1);
    fn(inp, out2);
}

void solve()
{
    string s;
    cin >> s;
    fn(s);

    //Uncomment for bit masking method..

    // vector<string> res;
    // int n = (1 << s.length()) - 1;
    // for (int i = 0; i <= n; i++)
    // {
    //     string temp = s;
    //     for (int j = 0; j < s.size(); j++)
    //     {
    //         if ((i >> j) & 1)
    //             temp[j] = toupper(s[j]);
    //     }
    //     res.push_back(temp);
    // }
    // for (auto i : res)
    //     cout << i << " ";
}

int32_t main()
{
    io;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}