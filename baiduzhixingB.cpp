// #include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        int n,m;
        int al[1005][26];
        memset(al,0,sizeof(al));
        scanf("%d %d",&n,&m);
        printf("%d%d\n",n,m);
        getchar();
        char tem;
        printf("Case #%d:\n",tt);
        for(int i=1;i<=n;i++){
            scanf("%c",&tem);
			// printf("%d\n",tem-64); 
            al[i][tem-64]++;
        //    printf("%d\n",al[i][tem-64]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=26;j++){
                al[i][j]+=al[i-1][j];
            }
        }
        int l,r,z=0;
//        while(1){
        for(int i=1;i<=m;i++){
            scanf("%d%d",&l,&r);
            for(int j=1;j<=26;j++){
                if(al[r][j]-al[l-1][j]!=0){
                    printf("%d\n",al[r][j]-al[l-1][j]);
                    z=1;
                    break;
                }else{
                	continue;
                }
            }
            if(z==0){
                printf("0\n");
            }
        }
    }
}