#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        char a[201][201];
        memset(a,'\0',sizeof(a));
        int n,m;
        scanf("%d%d",&n,&m);
        int maxn=max(n,m);
        int minn=min(n,m);
        // printf("%d%d\n",maxn,minn);
        if(n%2==0&&m%2==0){
            for(int i=1;i<=maxn/2;i++){
                a[i][1]='(';a[i][minn]=')';
            }
            if(maxn>=4){
                for(int j=1;j<=maxn/2;j++){
                    for(int i=2;i<=minn-1;i=i+2){
                     a[j][i]='(';a[j][i+1]=')';
                    }
            }}
            for(int i=(maxn/2)+1;i<=maxn;i++){
                for(int j=1;j<=minn;j=j+2){
                    a[i][j]='(';a[i][j+1]=')';
                }
            }
        }
        else if(n%2==0&&m%2!=0){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(i<=m/2){
                        a[i][j]='(';
                    }else{
                        a[i][j]=')';
                    }
                }
            }
        }
        else if(n%2!=0&&m%2==0){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j=j+2){
                    a[i][j]='(';a[i][j+1]=')';
                }
            }
        }
        else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    a[i][j]='(';
                }
            }
        }
        // 输出
        if(n%2!=0||m%2!=0){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    printf("%c",a[i][j]);
                }
                printf("\n");
            }
        }else{
            if(maxn==m){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        printf("%c",a[j][i]);
                    }
                    printf("\n");
                }
            }
            else{
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        printf("%c",a[i][j]);
                    }
                    printf("\n");
                }
            }
        }
        
    }
}