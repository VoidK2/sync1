#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;
ll gcd(ll a, ll b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int main()
{
    freopen("input.txt", "r", stdin);
    ll t;
    scanf("%lld", &t);
    while (t--)
    {
        ll a1, b1, c1, a2, b2, c2;
        scanf("%lld%lld%lld%lld%lld%lld", &a1, &b1, &c1, &a2, &b2, &c2);
        ll sum = a1 + b1 + c1;
        ll kf = (a1 * (c2 - b2) + b1 * (a2 - c2) + c1 * (b2 - a2)) * -1;
        ll as = abs(gcd(kf, sum));
        // printf("%lld %lld %lld\n", kf, sum, as);
        if (sum != as)
        {
            printf("%lld/%lld\n", kf / as, sum / as);
        }
        else{
            printf("%lld\n", kf / as);
        }
    }
}