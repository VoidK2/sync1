#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a[30][30],ans;
    memset(a,0,sizeof(a));
    freopen("input.txt", "r", stdin);
    for(int i=1; i<=29; i++) {
        for(int j=1; j<=i; j++) {
            scanf("%lld",&a[i][j]);
        }
    }
    for(int i=2;i<=29;i++){
        for(int j=1;j<=29;j++){
            a[i][j]=a[i-1][j]/2+a[i-1][j-1]/2;
        }
    }
    for(int i=1;i<=29;i++){
        ans=max(ans,a[29][i]);
    }
    printf("max = %lld\n",ans);
    return 0;
}