#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mod 100000007
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int k;
        scanf("%d", &k);
        if(k == 1)
            puts("5\n");
        else
            printf("%d\n", k+5);
    }
    return 0;
}
