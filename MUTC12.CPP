#include <cstdio>
#include <cmath>
#include <bitset>
#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    freopen("inputlx.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
       int n;
       long long one,two,three;
       scanf("%d",&n);
       bitset<20> b1(n);
       int len=b1.size();
       if(len>=3){
           for(int i=20;i<=0;i--){
               if(b1[i]==1){
                   int one=pow(2,i);
                   b1.flip(i);
                   break;
               }
            cout<<b1[i];
           }
           for(int i=20;i<=0;i--){
               if(b1[i]=='1'){
                   int two=pow(2,i);
                   b1.flip(i);
                   break;
               }
           }
           three=b1.to_ullong();
           printf("%lld %lld %lld %lld ",one,two,three,one*two*three);
       }

    }
    return 0;
}