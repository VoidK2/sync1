#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    // freopen("input.txt","r+",stdin);
    int n,m;
    cin>>n>>m;
    // printf("%d  %d",n,m);
    int t1,t2;
    bool a[110];
    int ans=0;
    memset(a,false,sizeof(a));
    for(int i=1;i<=n;i++){
        scanf("%d %d",&t1,&t2);
        for(int j=t1;j<=t2;j++){
            a[j]=true;
        }
    }
    for(int i=1;i<=m;i++){
        if(a[i]!=true){ans++;}
    }
    printf("%d\n",ans);
    if(ans!=0){
     for(int i=1;i<=m;i++){
        if(a[i]!=true){printf("%d ",i);}
    }}
    return 0;
}