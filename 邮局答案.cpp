//一定注意二维数组如果开小了的话，一般不会报错，这么简单的一道题我竟然弄了半天，愁。。。
#include <iostream>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <string.h>
#define N 10010
using namespace std;
int k, vis[55], tmpvis[55], mark[55];
int n, m;
double dis[55][55];
double sum = 9999999999.0;
struct T
{
    int x, y;
} post[55], vill[55];
void dfs(int node, int count, double tmpsum, double tmpdis[55])
{   //node是哪个记录邮局 ，count记录建立邮局个数  tmpsum记录当前的全部距离之和
    //tmpdis 记录每个用户和邮局的最小距离
    if (k - 1 - count > m - 1 - node)
        return; //剪枝   之后的节点如果不够||tmpsum>=sum
    double newdis[55];
    if (node + 1 < m)
        dfs(node + 1, count, tmpsum, tmpdis); //忽略本邮局，建立下一个邮局
    for (int i = 0; i < n; i++)               //记录下当前的数组情况
        newdis[i] = tmpdis[i];
    if (count == k - 1)
    { //出口，条件满足
        tmpvis[count] = node;
        for (int i = 0; i < n; i++)
        { //更新最小值
            if (newdis[i] > dis[node][i])
            {
                int temp = tmpsum;
                tmpsum = tmpsum - newdis[i] + dis[node][i];
                newdis[i] = dis[node][i];
            }
        }
        if (tmpsum < sum)
        { //更新输出最小值
            sum = tmpsum;
            for (int i = 0; i < k; i++)
            {
                vis[i] = tmpvis[i];
            }
        }
        return;
    }
    tmpvis[count] = node;     //加入新的邮局节点
    int mark1 = 1, mark2 = 1; //mark1==1说明为第一次，不可忽略，Mark2==1说明加入该点之后没有发挥作用   ，但是加入这两个标记位之后感觉好像有些情况是不对的，但是测试没有问题 ，并且没有改变90%超时的问题
    if (count == 0)
    { //如果是建立第一个邮局，初始化邮局到用户距离数组tmpdis和最小值
        for (int i = 0; i < n; i++)
        {
            tmpsum += dis[node][i];
            newdis[i] = dis[node][i];
        }
        mark1 = 0;
    }
    else
    { //判断是否有距离新加的节点更近的节点，如果有加入并且更新
        for (int i = 0; i < n; i++)
        {
            if (newdis[i] > dis[node][i])
            {
                int temp = tmpsum;
                tmpsum = tmpsum - newdis[i] + dis[node][i];
                newdis[i] = dis[node][i];
                mark2 = 0;
            }
        }
    }
    ////////if(tmpsum>sum) return ;//不可以这样剪枝，因为即便现在比sum大了，但是之后可能遇到更短的节点，一样可以更小
    if (!(mark1 && mark2))
        if (node + 1 < m)
            dfs(node + 1, count + 1, tmpsum, newdis);
    return;
}
int main()
{
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        sum = 9999999999.0;
        for (int i = 0; i < n; i++)
            scanf("%d%d", &vill[i].x, &vill[i].y);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &post[i].x, &post[i].y);
            for (int j = 0; j < n; j++)
            {
                dis[i][j] = sqrt(pow(vill[j].x - post[i].x, 2) + pow(vill[j].y - post[i].y, 2));
            }
        }
        double tmpdis[55];
        dfs(0, 0, 0, tmpdis);
        for (int i = 0; i < k; i++)
            printf("%d ", vis[i] + 1);
        cout << endl;
    }
    return 0;
}