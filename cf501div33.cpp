#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char mp[110][110];
char mp2[110][110];
int aaa[10000],ll=0;
bool findma(int x,int y,int len){
        for(int z=1;z<=len;z++){
            if(mp[x+z][y]!='*'||mp[x][y-z]!='*'||mp[x-z][y]!='*'||mp[x][y+z]!='*'){
               return false;
               break;
            }
        }
        for(int z=1;z<=len;z++){
            mp2[x][y]=mp[x][y];
            mp2[x-z][y]=mp[x-z][y];
            mp2[x+z][y]=mp[x+z][y];
            mp2[x][y+z]=mp[x][y+z];
            mp2[x][y-z]=mp[x][y-z];
        }
    return true;
}

int findx(int n,int m){
    int ans1=0;
    for(int i=2;i<=n-1;i++){
        for(int j=2;j<=m-1;j++){
            for(int z=1;z<=(min(n,m)/2);z++){
                if(mp[i][j]=='*'){
                    if(findma(i,j,z)){ans1++;
                    aaa[++ll]=i;aaa[++ll]=j;aaa[++ll]=z;
                    }
                }
            }
            // printf("%d %c\n",ans1,mp[i][j]);
        }
    }
    return ans1;
}
int main(){
    int n,m,ans;
    freopen("input.txt","r",stdin);
    memset(mp,'.',sizeof(mp));
    memset(mp2,'.',sizeof(mp2));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m+1;j++){
            scanf("%c",&mp[i][j]);
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //     printf("%c",mp[i][j]);
    //     }
    // }
    ans=findx(n,m);
    int f=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]!=mp2[i][j]){
                f=1;break;
            }
        }
    }
    // if(f==0){
        printf("%d\n",ans);
        for(int i=1;i<=ll;i+=3){
            printf("%d %d %d\n",aaa[i],aaa[i+1]-1,aaa[i+2]);
        }
    // }
    if(f==1){
        printf("-1");
    }
    return 0;
    }