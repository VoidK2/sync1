#include <bits/stdc++.h>
using namespace std;
char temp[7][5000];
void jisuan(){

}
int cnt(){
    int flag=1,ans;
    for(int i=1;i<=5000;i++){
        if(flag&&temp[1][i]=='0'){
            ans++;
        }
        else{
            flag=0;
            break;
        }
    }
    return ans;
}
int main(){
    int n,ans;
    scanf("%d",&n);
    memset(temp,'0',sizeof(temp));
    temp[1][0]='1';
    for(int i=1;i<=n;i++){
        scanf("%s",temp[2]);
        jisuan();
    }
    ans=cnt();
    printf("%d",ans);
}