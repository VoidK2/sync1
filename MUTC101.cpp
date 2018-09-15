#include <bits/stdc++.h>
typedef long long ll;
const double esp=0.999999;
using namespace std;
const int MOD = 998244353;

ll ksm(ll a, ll b, ll n)
{
    a %= n;
    ll ans = 1;
    while (b)
    {
    if (b % 2 == 1)
        ans = ans * a % n;
    b /= 2;
    a = a * a % n;
    }   
    return ans;
}

int main()
{
   freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        ll ans;
        scanf("%d",&n);
        if(n < 4)
            printf("0\n");
        else
        {
            ans = (ksm(2,n-4,MOD)*ksm(3,n-4,MOD))%MOD;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
