#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    freopen("input.txt","r+",stdin);
    int n;
    char a1[10000],a2[10000];
    scanf("%d",&n);
    cin>>a1;
    cin>>a2;
    for(int i=0;i<n;i++){
        if(a2[i]!=a1[i]){
            for(int j=i+1;j<n;j++){
                if(a1[j]==a2[i]){
                    
                }
            }
        }
    }
    return 0;
}