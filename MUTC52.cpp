#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t,k,k1,k2;
int cmp(int x,int y)
{
    return x > y;
}
char n[15],m[15],l[15],c;
int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d\n",&t);
    // printf("%d\n",t);
    while(t --)
    {
        scanf("%s %d",n,&k);
        k1 = k,k2 = k;
        for(int i = 0;i < strlen(n);i ++)
        {
            m[i] = n[i];
            l[i] = n[i];
        }
        for(int i = 0;i < strlen(n);i ++)
        {
            m[i] = n[i];
            l[i] = n[i];
            for(int j = i+1;j < strlen(n);j ++)
            {
                if(m[i] > m[j] && k1)
                {
                    c = m[i];
                    m[i] = m[j];
                    m[j] = c;
                    k1 --;
                }
                if(l[i] < l[i] && k2)
                {
                    c = l[i];
                    l[i] = l[j];
                    l[j] = c;
                    k2 --;
                }
            }
        }
        printf("%s %s\n",m,l);
    }
}