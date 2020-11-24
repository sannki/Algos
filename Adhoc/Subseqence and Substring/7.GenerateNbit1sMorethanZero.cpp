// https : //practice.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1
/*
    Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s than 0’s for any prefix of the number.

Example 1:

Input:  N = 2
Output: 11 10
Explanation: 11 and 10 have more than 
or equal 1's than 0's
Example 2:

Input:  N = 3
Output: 111 110 101
Explanation: 111, 110 and 101 have more 
than or equal 1's than 0's
*/
#include <bits/stdc++.h>

#define int long long
#define io                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;
#define pb push_back
vector<string> res;
void solve(int n, int one, int zero, string out = "")
{
    if (out.size() == n)
    {
        res.pb(out);
        return;
    }
    if (one == zero)
    {
        out.pb('1');
        solve(n, one + 1, zero, out);
    }
    else
    {
        string out1 = out, out2 = out;
        out1.pb('1');
        out2.pb('0');
        solve(n, one + 1, zero, out1);
        solve(n, one, zero + 1, out2);
    }
}
vector<string> fn(int N)
{
    // Your code goes here
    int one, zero;
    one = 0, zero = 0;
    solve(N, one, zero);
    return res;
}

int32_t main()
{
    int n;
    cin >> n;
    fn(n);
    for (auto i : res)
        cout << i << " ";
}