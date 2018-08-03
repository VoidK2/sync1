#include <bits/stdc++.h>
#define mod 100000007
using namespace std;

const int MAXN = 1e5+9;
int w[MAXN];
bool visa[MAXN], visb[MAXN];
int cnta[32], cntb[32];

int main()
{
    // freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(w, 0, sizeof(w));
        memset(visa, 0, sizeof(visa));
        memset(visb, 0, sizeof(visb));
        memset(cnta, 0, sizeof(cnta));
        memset(cntb, 0, sizeof(cntb));
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &w[i]);
        while(--n)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if(visa[b] || visb[a])
            	swap(a, b);
            if(!visa[a])
            {
                bitset<32> tmp = w[a];
                for(int i = 31; i >= 0; i--)
                    if(tmp.test(i))
                        cnta[i]++;
                visa[a] = 1;
            }
            if(!visb[b])
            {
                bitset<32> tmp = w[b];
                for(int i = 31; i >= 0; i--)
                    if(tmp.test(i))
                        cntb[i]++;
                visb[b] = 1;
            }
        }
        bool f = 1;
        for(int i = 0; i < 32; i++)
            if((cnta[i]+cntb[i])%2 == 1)
            {
                puts("Q");
                f = 0;
                break;
            }
        if(f)
            puts("D");
    }
    return 0;
}
