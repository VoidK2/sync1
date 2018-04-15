#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p[100005];

int r(ll n, ll k)
{
    int sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += p[i];
        sum = sum % k;
    }
    if (sum % k == 0)
    {
        return n;
    }
    for (ll i = n - 1; i > 0; i--)
    {
        sum = 0;
        for (ll ii = 0; ii < i; ii++)
        {
            sum += p[ii];
            sum = sum % k;
        }
        if (sum % k == 0)
            return i;
        for (ll j = 0; j < n - i; j++)
        {
            sum = sum - p[j] + p[j + i];
            sum = sum % k;
            if (sum % k == 0)
                return i;
        }
    }
    return 0;
}

int main()
{
    ll n, k;
    //freopen("inputlx.txt","r",stdin);
    while (cin >> n)
    {
        cin >> k;
        memset(p, 0, sizeof(p));
        for (ll i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        cout << r(n, k) << endl;
    }
    return 0;
}
