#include <bits/stdc++.h>

#define int long long
#define ll long long
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

vector<bool> prime;
void SieveOfEratosthenes(ll n) //O(nloglogn)
{
    prime.assign(n + 1, 1);

    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    // prime[1] = false;
}
bool isPrime(ll n) //O(sqrt(n))
{
    if (n < 2)
        return false;
    //For 2,3 does not the enter the for loop.
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
std::vector<ll> generatePrimeFactors(ll n)
{
    std::vector<ll> prime;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            prime.pb(i);
            while (n % i == 0)
                n = n / i;
        }
    }
    if (n != 1)
        prime.pb(n);
    return prime;
}
map<ll, ll> generatePrimeFactorization(ll n)
{
    map<ll, ll> cnt;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n && n % i == 0)
        {
            n /= i;
            cnt[i]++;
        }
    }
    if (n != 1)
        cnt[n]++;
    return cnt;
}
std::vector<ll> generateFactors(ll n)
{
    std::vector<ll> factors;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.pb(i);
            if (n / i != i)
                factors.pb(n / i);
            //24 - 1,2,3,4,6,8,12
        }
    }
    //    factors.pb(1);
    //    if (n != 1)
    //        factors.pb(n);
    sort(factors.begin(), factors.end());
    return factors;
}

ll extendedGCD(ll a, ll b, ll &x, ll &y)
{
    //produces correct results for negative integers as well
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1, d;
    d = extendedGCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
ll gcd(ll a, ll b) //O(log min(a,b))
{
    /*
    recursive implementation below
    if(!b) return a;
    return gcd(b,a%b);
    */

    //non-recursive implementation below
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll multiply(ll a, ll b, ll m);
ll singlemod(ll a, ll m);
ll modpow(ll x, ll n, ll m) //O(logn)// used for calculating (x^n)%m
{
    if (n == 0)
        return 1;
    ll res = 1;
    while (n)
    {
        if (n % 2)
            res = multiply(res, x, m);
        x = multiply(x, x, m);
        n = n >> 1;
    }
    return singlemod(res, m);
}
ll fastpow(ll x, ll n)
{
    if (n == 0)
        return 1;
    ll res = 1;
    while (n)
    {
        if (n % 2)
            res = res * x;
        x = x * x;
        n = n >> 1;
    }
    return res;
}
ll modinverse(ll x, ll m) //O(logn)
{
    return modpow(x, m - 2, m);
}
ll add(ll a, ll b, ll m)
{
    return (((a % m) + (b % m)) % m);
}
ll substract(ll a, ll b, ll m)
{
    //    if (a < b)
    //        swap(a, b);
    return (((a % m) - (b % m) + m) % m);
}
ll multiply(ll a, ll b, ll m)
{
    // if (a > b) swap(a, b);
    // ll ans = 0;
    // while (a)
    // {
    //     if (a % 2)
    //         ans = add(ans, b, m);
    //     b = add(b, b, m);
    //     a = a >> 1;
    // }
    // return (ans % m);
    return (((a % m) * (b % m)) % m);
}
ll divide(ll a, ll b, ll m)
{
    ll temp = modinverse(b, m);
    return multiply(a, temp, m);
}
ll singlemod(ll a, ll m)
{
    return (((a % m) + m) % m);
}
ll eulerstotientfunction(ll n) //O(sqrt(n))
{
    ll ans = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n = n / i;
            ans -= ans / i;
        }
    }
    if (n > 1)
        ans -= ans / n;
    return ans;
}

ll ncr(ll n, ll k, ll m)
{
    if (k > n)
        return 0;
    if (m == 0)
    {
        ll res = 1;
        k = min(k, n - k);
        for (ll i = 1; i <= k; i++)
        {
            res *= (n - i + 1);
            res /= i;
        }
        return res;
    }
    else
    {
        ll res = 1;
        k = min(k, n - k);
        for (ll i = 1; i <= k; i++)
        {
            res = multiply(res, n - i + 1, m);
            res = divide(res, i, m);
        }
        return singlemod(res, m);
    }
}
ll kadaneAlgo(const std::vector<ll> &arr)
{
    ll size = arr.size();
    ll currmax = arr[0], maxsofar = arr[0];
    for (ll i = 1; i < size; i++)
    {
        //debug2(currmax,maxsofar);
        currmax = max(arr[i], currmax + arr[i]);
        maxsofar = max(maxsofar, currmax);
    }
    return maxsofar;
}
ll getDigitSum(ll n)
{
    ll co = 0;
    while (n > 0)
    {
        co += n % 10;
        n = n / 10;
    }
    return co;
}

ll ceil(ll a, ll b)
{
    return (a + b - 1) / b;
}

ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}
//const int p1 = 13331,m1 = 1e9+9,p2 = 7919, m2 = 1e9+9;
//const int p1 = 97266353,m1 = 972663749,p2 = 97336357, m2 = 1000000007;
//const int p1 = 31 ,m1 = 1e9+7;

//grid cells
//D U R L
//ll dx[] = {1, -1, 0, 0};
//ll dy[] = {0, 0, 1, -1};
//ll dx[] = {-2,-2,-1,1,2,-2,1,-1};
//ll dy[] = {-1,1,2,2,1,-1,-2,-2};
//bool isSafe(ll x, ll y, ll n, ll m)
//{
//    return (x >= 0 && x < n && y >= 0 && y < m);
//}

//---------------TEMPLATE ABOVE--------------//

void solve()
{
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
