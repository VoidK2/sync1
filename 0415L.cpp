#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100005];
int main()
{
    freopen("inputlx.txt","r",stdin);
    scanf("%d %d", &n, &k);
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i] += a[i-1];
    }
    for (int i = 1; i <= n; i ++)
    {
        a[i] %= k;
    }
    int cnt = 0;
    for (int i = 0; i <= n; i ++)
    for (int j = i+1; j <= n; j ++)
    if(a[i] == a[j])
    {
            cnt = max(cnt,j-i);
    }
    printf("%d\n",cnt);
}