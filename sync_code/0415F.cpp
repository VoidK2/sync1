#include <bits/stdc++.h>
using namespace std;
long long  a[100],tot[100];

int main(){
    memset(a, 0, sizeof(a));
    memset(tot, 0, sizeof(tot));
    a[1]=1;a[2]=1;a[3]=2;tot[1]=1;tot[2]=2;tot[3]=4;
    for(int i=3;i<=99;i++){
        a[i]=a[i-1]+a[i-2];
        tot[i]=tot[i-1]+a[i];
    }
   // printf("a[99]%lld\n",a[60]);
    freopen("inputlx.txt","r",stdin);
    long long t,n,ans,temp,t1,j;
    bitset<64> b;
    scanf("%lld", &t);
    while(t--){
        b.reset();
        scanf("%lld",&n);
        for (int i = 1; i <= 99; i++)
        {
            if (tot[i]>=n&&tot[i-1]<n){
                b.flip(i-1);
                temp=i-1;
                goto loop;
                int x = max(1,2);
            }
        }
        loop:
        unsigned long long ans=b.to_ullong();
        ans=ans+(n-temp-1);
        printf("%lld\n",ans);
    }
}