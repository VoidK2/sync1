// #include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
bool can(int a,int b, int c){
    if((a+b>c&&abs(a-b)<c)||(b+c>a&&abs(b-c)<a)||(a+c>b&&abs(a-c)<b))
    return true;
    return false;
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("input.txt","r",stdin);
    int t;
    while(scanf("%d",&t)!=EOF){
        int a[1001];
        for(int i=0;i<t;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+t,cmp);
        // for(int i=0;i<t;i++){
        //     printf("%d ",a[i]);
        // }
        int ans=-1;
        for(int i=0;i<t-2;i++){
            for(int j=i+1;j<t-1;j++){
                for(int z=j+1;z<t;z++){
                    if(can(a[i],a[j],a[z])){
                        ans=a[i]+a[j]+a[z];
                        goto loop1;
                    }
                }
            }
        }
        loop1:
        printf("%d\n",ans);
    }

}