#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

struct{
    int A,B,C;
}ps[1001];

int main(){
    freopen("input.txt","r",stdin);
    int a,b,c;
    int t;
    cin>>t;
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        int ans=0;
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                for(int z=1;z<=c;z++){
                    for(int x=0;x<=ans;x++){
                        if((i!=ps[x].A||j!=ps[x].A||z!=ps[x].A)||(i!=ps[x].B||j!=ps[x].B||z!=ps[x].B)||(i!=ps[x].C||j!=ps[x].C||z!=ps[x].C)){
                            ans++;
                            ps[ans].A=i;ps[ans].B=j;ps[ans].C=z;
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}