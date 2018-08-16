#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    // freopen("input.txt","r",stdin);
    int ans;
    int a[51];
    char b;
    int n,k,f=1;
    scanf("%d%d",&n,&k);
    // printf("%d %d ",n,k);
    getchar();
    for(int i=0;i<n;i++){
        scanf("%c",&b);
        // printf("%c ",b);
            a[i]=b-96;
        // printf("%d \n",a[i
    }
    sort(a,a+n);
    ans=a[0];
 
    // printf("%d \n",ans);
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]>=2){
            ans+=a[i];
            f++;
            // printf("%d %d s%d\n",ans,f,i);
        }else{
            continue;
        }
        if(f==k){break;}
    }
    if(f==k){
        printf("%d\n",ans);
    }else{
        printf("-1");
    }
}