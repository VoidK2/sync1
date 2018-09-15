#include <cstdio>
#include <cmath>
using namespace std;
#define mod 998244353
#define ll long long

ll pow3(ll a, ll b)
{
    a %= mod;
    ll ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans = ans * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return ans;
}

int main()
{
    freopen("input.txt","r",stdin);
    ll a, b, c, d;
    ll n;
    scanf("%lld", &n);
    while (n--)
    {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        ll ans = 0;
        ans = (pow3(2, a) % mod) * (pow3(2, b) % mod - (b + 1)% mod + ((pow3(2, c) % mod) * (d + b + 1)% mod) % mod) % mod;
        printf("%lld\n", ans);
    }
    return 0 ;
}