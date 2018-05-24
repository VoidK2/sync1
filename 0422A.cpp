#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("inputlx.txt","r",stdin);
    double a,b,c;
    double ans[5];
    memset(ans,0,sizeof(ans));
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF){
        ans[0]=a-60;
        ans[1]=b-60;
        ans[2]=180-ans[0]-ans[1];
        sort(ans,ans+3);
        printf("%.4lf %.4lf %.4lf\n",ans[0],ans[1],ans[2]);
    }
}