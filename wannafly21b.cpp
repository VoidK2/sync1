#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char ma[55][55];
int main(){
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,x,y;
        cin>>n>>m;
        memset(ma,'-',sizeof(ma));
        // getchar();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char tmp;
                scanf("%c",&tmp);
                 printf("%c",tmp);
                ma[i][j]=tmp;
                if(tmp=='S'){x=i;y=j;printf("x=%d y=%d",x,y);}
            }
            getchar();
        }
        int ans=0,len=0,tem=0;
        for(int i=x;i>=0;i--){
            if(ma[i][y]=='#'){ans++;break;}
            tem++;
            if(ma[i][y]=='-'){len=max(len,tem);break;}
        }
        for(int i=x;i<=n;i++){
            if(ma[i][y]=='#'){ans++;break;}
            tem++;
            if(ma[i][y]=='-'){len=max(len,tem);break;}
        }
        for(int i=y;i>=0;i--){
            if(ma[x][i]=='#'){ans++;break;}
            tem++;
            if(ma[x][i]=='-'){len=max(len,tem);break;}
        }
        for(int i=y;i<=m;i++){
            if(ma[x][i]=='#'){ans++;break;}
            tem++;
            if(ma[x][i]=='-'){len=max(len,tem);break;}
        }
        if(ans==4){
            printf("-1\n");
        }
        else{
            printf("%d\n",len);
        }

        

    }

}