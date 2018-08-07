#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mod 100000007
using namespace std;

int main()
{
    // freopen("input.txt","r",stdin);
    int t;
    int a[100001];
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int ans=sqrt(abs(a[0]-a[n-1]));
        printf("%d\n",ans);
    }
    return 0;
}
