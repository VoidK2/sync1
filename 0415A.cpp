#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("inputlx.txt","r",stdin);
    int t=0,n=0;
    long long ans=0;
    int a[100010],b[100010],c[100010];
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        ans=0;
        for(int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
        }
        for(int i=1; i<=n; i++) {
            scanf("%d",&b[i]);
        }
        for(int i=1; i<=n; i++) {
            c[i]=a[i]-b[i];
        }
        for(int i=1; i<=n-1; i++) {
            if(c[i] > 0 && c[i] != 0) {
                ans+=c[i];
                c[i+1]+=c[i];
                c[i] = 0;
            }
            if (c[i] < 0 && c[i] != 0) {
                ans-=c[i];
                c[i+1]+=c[i];
                c[i]=0;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}