## 4.Game
```c++
#include <cstdio>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("Yes\n");
    }
}
```
## 5 Hack It
```c++
#include <cstdio>
using namespace std;
int main(){
    int P=47,f[233333],an=0,gg[2333][2333];
    for(int i=0;i<P;i++)
    {
        for(int r=0;r<P;++r)
        {
            ++an;
            for(int j=i,k=0;k<P;k++,j=(j+r)%P)
                f[j*P+k]=an;
            for(int j=0;j<P*P;++j)
                if(f[j]==an) gg[i*P+r][j]=1;
        }
    }
    printf("%d\n",1999);
    for(int i=0;i<1999;++i,puts(""))
        for(int j=0;j<1999;++j)
            putchar(gg[i+2][j+2]+48);****
}
```
## 5 Matrix
```c++
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#define L long long
using namespace std;
const int q=998244353;
int n,m,t,c[3010][3010],f[3010][3010],x[9000010],a[3010],b[3010],p;
int main()
{
    int i,j,k,l;
    for(i=0;i<=3000;i++)
      {
       c[i][0]=1;
       for(j=1;j<=i;j++)
         c[i][j]=(c[i-1][j]+c[i-1][j-1])%q;
      }
    x[0]=1;
    for(i=1;i<=9000000;i++)
      x[i]=(x[i-1]<<1)%q;
    while(scanf("%d%d",&n,&m)!=EOF)
      {
       scanf("%d%d",&i,&j);
       a[i]=1;
       for(k=i+1;k<=n;k++)
         {
          a[k]=1;
          for(l=i;l<k;l++)
            a[k]=(a[k]-(L)a[l]*c[k][l])%q;
         }
       b[j]=1;
       for(k=j+1;k<=m;k++)
         {
          b[k]=1;
          for(l=j;l<k;l++)
            b[k]=(b[k]-(L)b[l]*c[k][l])%q;
         }
       for(k=i;k<=n;k++)
         for(l=j;l<=m;l++)
           f[k][l]=(L)c[n][k]*c[m][l]%q*x[(n-k)*(m-l)]%q;
       p=0;
       for(k=i;k<=n;k++)
         for(l=j;l<=m;l++)
           p=(p+(L)f[k][l]*a[k]%q*b[l])%q;
       p=(p+q)%q;
       printf("%d\n",p);
      }
    return 0;
}
```
## 7 Naive Operations
```c++
#include <bits/stdc++.h>
#define eps 1e-8
#define INF 0x3f3f3f3f
#define MOD 1e9+7
#define PI acos(-1)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e5 + 5;

int n, q;
int MIN[maxn << 2];
int lazy[maxn << 2];
int ans[maxn << 2];
int b[maxn << 2];


void pushup(int rt) {
    MIN[rt] = min(MIN[rt << 1], MIN[rt << 1 | 1]);
    ans[rt] = ans[rt << 1] + ans[rt << 1 | 1];
}

void pushdown(int rt) {
    if(lazy[rt]) {
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        MIN[rt << 1] -= lazy[rt];
        MIN[rt << 1 | 1] -= lazy[rt];
        lazy[rt] = 0;
    }
}
//建树
void build(int l, int r, int rt) {
    lazy[rt] = 0;
    ans[rt] = 0;
    if(l == r) {
        scanf("%d", &b[rt]);
        MIN[rt] = b[rt];
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void updata(int L, int R, int l, int r, int rt) {
    if(L <= l && R >= r) {
        MIN[rt]--;
        if(MIN[rt]) {
            lazy[rt]++;
            return;
        } else {
            if(l == r) {
                ans[rt]++;
                MIN[rt] = b[rt];
                return;
            }

        }
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if(L <= m) updata(L, R, lson);
    if(R > m) updata(L, R, rson);
    pushup(rt);
}
//查询
int query(int L, int R, int l, int r, int rt) {
    if(L <= l && R >= r) {
        return ans[rt];
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    int sum = 0;
    if(m >= L) sum += query(L, R, lson);
    if(m < R) sum += query(L, R, rson);
    return sum;
}
int main() {
    while(~scanf("%d%d", &n, &q)) {
        build(1, n, 1);
        for(int i = 1; i <= q; i++) {
            char op[10];
            int a, b;
            scanf("%s%d%d", op, &a, &b);
            if(op[0] == 'q') {
                printf("%d\n", query(a, b, 1, n, 1));
            } else {
                updata(a, b, 1, n, 1);
            }
        }
    }
    return 0;
}
```
## 10 Swaps and Inversions
```c++
#include <cstdio>
#include <cstring>
using namespace std;
long long cnt,ans;
int main(){
    int n,x,y;
    long long a[100001],b[100001];
    void merge_sort(int *a,int x,int y,int *b){
        if(y-x>1){
            int m=x+(y-x)/2;
            int p=x,q=m,i=x;
            merge_sort(a,x,m,b);
            merge_sort(a,m,y,t);
            while(p<m||q<y){
                if(q>=y||(p<m&&a[p]<=a[q])){
                    b[i++]=a[p++];
                }else{
                    b[i++]=a[1++];
                    cnt+=m-p;
                }
                for(i=x;i<y;i++){
                    a[i]=b[i];
                }
            }
        }
    }
    int main(){
        int n,x,y;
        while(scanf("%d%d%d",&n,&x,&y)!=EOF){
            cnt=0;ans=0;
            for(int i=0;i<n;i++){
                scanf("%d",&a[i]);
            }
            memset(b,0,sizeof(b));
            merge_sort(a,0,n,b);
            printf("%d",min(x,y)*cnt);
        }
        return 0;
    }
}
```
