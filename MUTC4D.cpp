#include <cstdio>
#include <algorithm>
using namespace std;
struct a1{
    int i,j;
    double r;
}a[101];
bool cmp(a1  aa,a1 bb){
    return aa.r>bb.r;
}
int main(){
    // freopen("input.txt", "r", stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].i,&a[i].j);
            a[i].r=(double)a[i].i/((double)a[i].j+(double)a[i].i);
            // printf("%lf\n",a[i].r);
        }
        sort(a,a+n,cmp);
        // for(int i=0;i<n;i++)
        //     printf("%d %d \n",a[i].i,a[i].j);
        int c1=m,ans=0;
        for(int i=0;i<n;i++){
            if(c1>=a[i].i+a[i].j){
                c1=c1*a[i].r;
                // printf("%d %d\n",c1,i);
                ans++;
            }else{
                break;
            }
        }
        printf("%d\n",ans);
    }
}