#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define inf 0x3f3f3f3f
int a[300001];

int main(){
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        int len,maxn=0,minn=inf;
        scanf("%d",&len);
        for(int i=0;i<len;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+len);
        int nn=0;
        for(int i=len-1;i>0;i--){
            nn+=a[i]-a[i-1];
            // printf("%d ",nn);
        }
        int ans=0;
        if(nn<=3){
            for(int i=0;i<len;i++){
                ans+=a[i];
            }
            printf("%d\n",ans/len);
        }else{
            ans=nn;
            printf("%d\n",ans/3);
        }
        
    }
}