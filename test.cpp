#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mod 100000007
using namespace std;

int main()
{
    //  freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
      int n;
      scanf("%d",&n);
      int sum=0,tmp1,tmp2;
      for(int i=1;i<=n;i++){
        scanf("%d",&tmp1);
        sum=sum^tmp1;
      }
      for(int i=1;i<n;i++){
        scanf("%d%d",&tmp1,&tmp2);
      }
      if(sum==0){
        printf("D\n");
      }else{
        printf("Q\n");
      }
    }
    return 0;
}
