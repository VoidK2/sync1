#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    // freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int mx,my,n,x,y;
        long long ans=0;
        scanf("%d%d%d",&mx,&my,&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&x,&y);
            ans+=min(min(x,mx-x),min(y,my-y));
            // printf("%d ",ans);
        }
        printf("%lld\n",ans);
    }
}