#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n == 1)
        return false; //Usually 1 is not considered as prime

    else if (n == 2) //2 is considered as prime
        return true;

    else if (n % 2 == 0) //if number is even then its not prime
        return false;

    //we can skip to check divisible by even numbers as the numbers which came to this else will only be odds
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;

    // if (n == 1)
    // {
    //     return false;
    // }

    // for (int i = 2; i * i <= n; i++)
    //     if (n % i == 0)
    //         return false;
    // return true;
}

int main()
{
    int n;
    cin >> n;
    bool ans = isPrime(n);
    if (ans)
    {
        cout << n << " is prime!" << endl;
    }
    else
    {
        cout << n << " is not a prime!" << endl;
    }
}