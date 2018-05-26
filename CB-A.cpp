#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int ans, l, r, t, ii;
    freopen("input.txt","r",stdin);
    scanf("%d", &t);
    char a[100];
    while (t--){
        ans = 0;
        scanf("%d%d", &l, &r);
        for (int i = l; i <= r; i++){
            memset(a, '\0', sizeof(a));
            sprintf(a, "%d", i);
            int len = strlen(a);
            for (int j = 0; l <= len; j++){
                if (a[j] == '7')
                    ans++;
            }
            ii=i;
            while (ii >= 7){
                if (i % 7 == 0)
                    ans++;
                ii=i/7;
            }
        }
        printf("%d\n", ans);
    }
}