#include  <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
const int INF = 0x3f3f3f3f;
struct edge{
    int to;
    int w;
    int next;
    int ci;
}e[MAXN];

int head[MAXN],dist[MAXN];
bool vis[MAXN];

int n,m,cnt;

void add(int i,int j,int ci)
{
    e[cnt].to = j;
    e[cnt].ci = ci;
    e[cnt].next = head[i];
    head[i] = cnt++; 
}

void spfa(int s)
{
    queue<int> q;
    memset(dist,0x3f,sizeof(dist));
    memset(vis,0,sizeof(vis));
    vis[s] = 1;
    q.push(s);
    dist[s] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int  i = head[u];i != -1;i = e[i].next)
        {
            int v = e[i].to;
            int temp= 0x3f;
            for(int j = head[u];j!= -1;j = e[i].next)
            {
                if(e[u].ci == e[v].ci)
                    e[j].w == 0;
                else
                    e[j].w == 1;
                if(e[j].w <=temp)
                    temp = e[j].w;
            }
            
            
                dist[v] = dist[u] + temp;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    int a,b,c;
    while(scanf("%d%d",&n,&m) == 2)
    {
        cnt = 0;
        memset(head,-1,sizeof(head));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        spfa(1);
        printf("%d\n",dist[n] == INF ? -1 : dist[n]);
    }
    return 0;
}