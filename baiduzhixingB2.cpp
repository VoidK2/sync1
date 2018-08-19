// #include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct st{
    int bin,len;
}log1[10001];
bool cmp(st a,st b){
    return a.len>b.len;
}

int main(){
    // freopen("input.txt","r",stdin);
    int n,c;
    while(scanf("%d%d",&n,&c)!=EOF){
        char a[10001];
        memset(log1,0,sizeof(log1));
        getchar();
        scanf("%s",a);
        // printf("%s",a);
        int l=0;
        for(int i=0;i<n;i++){
            if(a[i]=='1'){
                for(int j=i;j<n;j++){
                    if(a[j]=='0'){
                        log1[l].bin=i;
                        log1[l++].len=j-i;
                        i=j;
                        goto loop1;
                    }
                }
            }
            loop1:
            i=i;
        }
        sort(log1,log1+l,cmp);
        // printf("%d%d",log1[0].bin,log1[0].len); 
        int ans=0;
        if(c==0){
            if(a[0]=='0')
            printf("0\n");
            if(a[0]=='1'){
                for(int i=0;i<l;i++){
                    if(log1[i].bin==0){
                        ans==log1[i].len;
                        break;
                    }
                }
                printf("%d\n",ans);
            }
            
        }      
        ans=log1[0].len;
        if(c==1){
            printf("%d\n",ans);
        }
        if(c>=2){
            int cshu=(c-1)/2;
            for(int i=1;i<=cshu;i++){
                ans+=log1[i].len;
            }
            printf("%d\n",ans);
        }
    }

}