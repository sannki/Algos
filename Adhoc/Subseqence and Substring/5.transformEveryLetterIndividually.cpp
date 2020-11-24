// https : //leetcode.com/problems/letter-case-permutation/

/* Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.Return a list of all possible strings we could create.You can return the output in any order.
Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Input: S = "3z4"
Output: ["3z4","3Z4"]
*/

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

class Solution
{
public:
    vector<string> res;
    void solve(string inp, string out = "")
    {
        if (inp.length() == 0)
        {
            res.push_back(out);
            return;
        }
        if (isdigit(inp[0]))
        {
            out.push_back(inp[0]);
            inp.erase(inp.begin());
            solve(inp, out);
        }
        else
        {
            string out1 = out;
            if (isupper(inp[0]))
                out1.push_back(tolower(inp[0]));
            else
                out1.push_back(toupper(inp[0]));
            string out2 = out + inp[0];
            inp.erase(inp.begin());
            solve(inp, out1);
            solve(inp, out2);
        }
    }
    vector<string> letterCasePermutation(string S)
    {
        solve(S);
        return res;
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution obj;

    string inp;
    cin >> inp;
    vector<string> res = obj.letterCasePermutation(inp);
    for (auto i : res)
    {
        cout << '[';
        cout << i;
        cout << "] ";
    }
}
