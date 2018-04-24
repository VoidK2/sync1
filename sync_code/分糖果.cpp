#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
void print1(int a[], int len)
{
    for (int i = 1; i <= len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
bool check1(int a[], int len)
{
    int flag = a[1];
    for (int i = 2; i <= len; i++)
    {
        if (a[i] != flag)
            return true;
    }
    return false;
}
int main()
{
       freopen("inputlx.txt","r",stdin);
    int que[110], num = 0, temp = 0, ans = 0;
    memset(que, 0, sizeof(que));
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        scanf("%d", &que[i]);
    }
    while (check1(que, num))
    {

        que[num] += que[1] / 2;
        que[1] = que[1] - que[1] / 2;
        // que[1]+=que[2]/2;
        // que[2]=que[2]-que[2]/2;
        //        print1(que, num);
        for (int i = 1; i < num; i++)
        {
            que[i] += que[i + 1] / 2;
            que[i + 1] = que[i + 1] - que[i + 1] / 2;
        }

        for (int i = 1; i <= num; i++)
        {
            if (que[i] % 2 == 1)
            {
                que[i] += 1;
                ans++;
            }
        }
        //        print1(que, num);
    }
    printf("%d", ans);
}