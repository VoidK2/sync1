#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    char num[100010],ans[100010];
    scanf("%d",&t);
    while(t--){
        memset(num, '\0', sizeof(num));
        memset(ans, '\0', sizeof(ans));
        scanf("%s",num);
        int len=strlen(num);
        if(len>=2){
            
                if((num[len-1]-'0')%2!=0){
                    if((num[len-2]-'0')>=5)
                    num[len-1]=num[len-1]+'1';
                    for(int i=len-2;i<=0;i++){
                        num[]
                    }
                }
        }
        if(len==1){

        }
    }
}