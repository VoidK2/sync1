## 2018 Multi-University Training Contest 3 SUMMARY
## A Ascending Rating
```c++
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
// #define mod 100000007
#define ll long long 
using namespace std;
int read () {
    int x = 0; char ch = getchar();
    for ( ; ch < '0' || ch > '9'; ch = getchar());
    for ( ; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - 48;
    return x;
}
int main(){
    freopen("input.txt","r",stdin);
    int t;
    int n,m,k,p,q,r,mo,a[10000005];
    int h,t,Q[10000005];
    ll A,B;
    scanf("%d",&t);
    while(t--){
        cin >> n >> m >> k >> p >> q >> r >> mo;
        for (int i = 1; i <= k; ++i) a[i] = read();
        for (int i = k + 1; i <= n; ++i) a[i] = (1ll * p * a[i - 1] + 1ll * q * i + r) % mo;
        h = 0, t = 1, A = B = 0;
        for (int i = n; i >= n - m + 1; --i) {
            if (a[i] < a[Q[h]]) Q[++h] = i;
            else {
                for ( ; t <= h && a[i] >= a[Q[h]]; ) --h;
                Q[++h] = i;
            }
        }
        A += a[Q[t]] ^ (n - m + 1);
        B += (h - t + 1) ^ (n - m + 1);
        for (int i = n - m; i; --i) {
            if (Q[t] == i + m) ++t;
            if (a[i] < a[Q[h]]) Q[++h] = i;
            else {
                for ( ; t <= h && a[i] >= a[Q[h]]; ) --h;
                Q[++h] = i;
            }
            A += a[Q[t]] ^ i;
            B += (h - t + 1) ^ i;
        }
        cout << A << " " << B << endl;
    }
    return 0;
}
```
<!-- ## C Dynamic Graph Matching
```c++

``` -->
## D Euler Function
```c++
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mod 100000007
using namespace std;

int main()
{
    // freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int k;
        scanf("%d", &k);
        if(k == 1)
            puts("5");
        else
            printf("%d\n", k+5);
    }
    return 0;
}
```
## F Grab The Tree
- 这是模拟方法
```c++
#include <bits/stdc++.h>
#define mod 100000007
using namespace std;

const int MAXN = 1e5+9;
int w[MAXN];
bool visa[MAXN], visb[MAXN];
int cnta[32], cntb[32];

int main()
{
    // freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(w, 0, sizeof(w));
        memset(visa, 0, sizeof(visa));
        memset(visb, 0, sizeof(visb));
        memset(cnta, 0, sizeof(cnta));
        memset(cntb, 0, sizeof(cntb));
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &w[i]);
        while(--n)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if(visa[b] || visb[a])
                swap(a, b);
            if(!visa[a])
            {
                bitset<32> tmp = w[a];
                for(int i = 31; i >= 0; i--)
                    if(tmp.test(i))
                        cnta[i]++;
                visa[a] = 1;
            }
            if(!visb[b])
            {
                bitset<32> tmp = w[b];
                for(int i = 31; i >= 0; i--)
                    if(tmp.test(i))
                        cntb[i]++;
                visb[b] = 1;
            }
        }
        bool f = 1;
        for(int i = 0; i < 32; i++)
            if((cnta[i]+cntb[i])%2 == 1)
            {
                puts("Q");
                f = 0;
                break;
            }
        if(f)
            puts("D");
    }
    return 0;
}
```
- 这是找的规律
```c++
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
```
## G Intertellar Travel
```c++
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 200005;

int n, top;

struct point {
    int x, y, i;
    point () {}
    point (int _x,int _y,int _i = 0) :
        x(_x), y(_y), i(_i) {}
} a[N], s[N];
point operator - (point u, point v) {
    return point(u.x - v.x, u.y - v.y, u.i);
}
bool cmp (point u, point v) {
    ll t = 1ll * u.x * v.y - 1ll * u.y * v.x;
    return t == 0 ? (u.x == v.x ? u.i < v.i: u.x < v.x) : t < 0;
}

bool cmp2 (point u, point v) {
    ll t = 1ll * u.x * v.y - 1ll * u.y * v.x;
    return t == 0 ? u.i < v.i : t < 0;
}
void solve () {
    s[top = 1] = a[1];
    for (int i = 2; i <= n; ++i) {
        if (a[i].x == a[i - 1].x && a[i].y == a[i - 1].y) continue;
        while (top >= 2 && cmp2(a[i] - s[top - 1], s[top] - s[top - 1])) --top;
        s[++top] = a[i];
    }
}

int main () {
    int T; cin >> T;
    for ( ; T; --T) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &a[i].x, &a[i].y);
            a[i].i = i;
        }
        sort(a + 2, a + n, cmp);
        solve();
        for (int i = 1; i <= top; ++i) {
            printf("%d%c", s[i].i, i < top ? ' ' : '\n');
        }
    }
    return 0;
}
```
## L Visual Cube
```c++
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mod 100000007
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        char m[100][100];
        memset(m,'\0',sizeof(m));
        int yl=(c+b)*2+2;
        int xl=(a+b)*2+2;
        // for(int i=0;i<2*b;i++){
        //     for(int j=2*b;j>0;j--){
        //         m[i][j]='.';
        //     }
        // }
        for(int i=1;i<=2*b;i++){
            int pos=2*b-i+1;
                int len=2*a+1;
                if(i%2==1){
                    for(int z=1;z<=len;z++){
                        if(z%2==1){m[i][pos+z]='+';}
                        if(z%2==0){m[i][pos+z]='-';}
                    }
                }
                if(i%2==0){
                    for(int z=1;z<=len;z++){
                        if(z%2==1){m[i][pos+z]='/';}
                        if(z%2==0){m[i][pos+z]='\0';}
                    }
                }
            
        }
        int pos=2*b;
        for(int i=1;i<2*c+2;i++){
            if(i%2==1){
                for(int y=1;y<=2*a+1;y++){
                    if(y%2==1){m[pos+i][y]='+';}
                    if(y%2==0){m[pos+i][y]='-';}
                }
            }
            if(i%2==0){
                for(int y=1;y<=2*a+1;y++){
                    if(y%2==1){m[pos+i][y]='|';}
                    if(y%2==0){m[pos+i][y]='\0';}
                }
            }
        }
        pos=2*a+2*b+2;
        int len=2*c+1;
        for(int i=1;i<=2*b;i++){
            int pos2=i-1;
            if(i%2==1){
                for(int y=1;y<=len;y++){
                    if(y%2==1){m[pos2+y][pos-i]='+';}
                    if(y%2==0){m[pos2+y][pos-i]='|';}
                }
            }
            if(i%2==0){
                for(int y=1;y<=len;y++){
                    if((y+1)%2==1){m[pos2+y][pos-i]='\0';}
                    if((y+1)%2==0){m[pos2+y][pos-i]='/';}
                }
            }
            
        }
        for(int i=1;i<=yl-1;i++){
            for(int y=1;y<xl;y++){
                if(m[i][y]=='\0'){
                    printf(".");
                }else{
                    printf("%c",m[i][y]);
                }
            }
            printf("\n");
        }
        

    }
    return 0;
}
```