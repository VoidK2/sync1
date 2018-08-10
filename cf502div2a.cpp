#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("input.txt","r",stdin);
    int t,ts,ans;
    scanf("%d",&t);
    int aa[1005];
    memset(aa,0,sizeof(aa));
    for(int i=0;i<t;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        aa[i]=a+b+c+d;
        if(i==0){
            ts=aa[i];
        }
    }
    sort(aa,aa+t,cmp);
    for(int i=0;i<t;i++){
        // printf("%d ",aa[i]);
        if(ts==aa[i]){
            ans=i+1;
            break;
        }
    }
    printf("%d",ans);

}