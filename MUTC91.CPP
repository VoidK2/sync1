#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    // freopen("input.txt","r",stdin);
    int a[1000001];
    a[0]=0;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]=a[i]+a[i-1];
    }
    int op,l,r;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&op,&l,&r);
        if(op==1){
            for(int j=l;j<r;j++){
                if(a[j]-a[j-1]>a[j+1]-a[j]){
                    a[j]=a[j-1]+a[j+1]-a[j];
                }
            }
        }
        if(op==2){
            printf("%d\n",a[r]-a[l-1]);
        }
    }
}