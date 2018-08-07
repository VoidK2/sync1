# 2018 Multi-University Training Contest 4 SUMMARY
## Problem B. Harvest of Apples
> 裸的莫队算法，离线算法
```c++
#include <cstdio>
#include <algorithm>
using namespace std;

#define N 311111
#define A 1111111
#define BLOCK 555 // ~sqrt(N)

int cnt[A], a[N], ans[N], answer = 0;

struct node {
	int L, R, i;
}q[N];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}

void add(int position) {
	cnt[a[position]]++;
	if(cnt[a[position]] == 1) {
		answer++;
	}
}

void remove(int position) {
	cnt[a[position]]--;
	if(cnt[a[position]] == 0) {
		answer--;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

	int m;
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		scanf("%d%d", &q[i].L, &q[i].R);
		q[i].L--; q[i].R--;
		q[i].i = i;
	}

	sort(q, q + m, cmp);

	int currentL = 0, currentR = 0;
	for(int i=0; i<m; i++) {
		int L = q[i].L, R = q[i].R;
		while(currentL < L) {
			remove(currentL);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}
		while(currentR <= R) {
			add(currentR);
			currentR++;
		}
		while(currentR > R+1) {
			remove(currentR-1);
			currentR--;
		}
		ans[q[i].i] = answer;
	}

	for(int i=0; i<m; i++)
		printf("%d\n", ans[i]);
}
```
## Problem D. Nothing is Impossible
```c++
#include <cstdio>
#include <algorithm>
using namespace std;
struct a1{
    int i,j;
    double r;
}a[101];
bool cmp(a1  aa,a1 bb){
    return aa.r>bb.r;
}
int main(){
    // freopen("input.txt", "r", stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].i,&a[i].j);
            a[i].r=(double)a[i].i/((double)a[i].j+(double)a[i].i);
            // printf("%lf\n",a[i].r);
        }
        sort(a,a+n,cmp);
        // for(int i=0;i<n;i++)
        //     printf("%d %d \n",a[i].i,a[i].j);
        int c1=m,ans=0;
        for(int i=0;i<n;i++){
            if(c1>=a[i].i+a[i].j){
                c1=c1*a[i].r;
                // printf("%d %d\n",c1,i);
                ans++;
            }else{
                break;
            }
        }
        printf("%d\n",ans);
    }
}
```
## Problem J. Let Sudoku Rotate
```c++
#include <bits/stdc++.h>
using namespace std;

int ord(char c) {
    if (isdigit(c)) return c - '0';
    return c - 'A' + 10;
}

char str(int c) {
    if (c < 10) return c + '0';
    return c + 'A' - 10;
}

int r[16][16], c[16][16];
int a[16][16];
int b[4][4];
char s[16];
int ret;

void add(int ip, int jp, int v) {
    for (int i = ip * 4; i < (ip + 1) * 4; ++i) {
        for (int j = jp * 4; j < (jp + 1) * 4; ++j) {
            r[i][a[i][j]] += v; c[j][a[i][j]] += v;
        }
    }
}

bool rot(int ip, int jp) {
    for (int i = ip * 4; i < (ip + 1) * 4; ++i) {
        for (int j = jp * 4; j < (jp + 1) * 4; ++j) {
            --r[i][a[i][j]]; --c[j][a[i][j]];
            b[j - jp * 4][(ip + 1) * 4 - i - 1] = a[i][j];
        }
    }
    bool succ = true;
    for (int i = ip * 4; i < (ip + 1) * 4; ++i) {
        for (int j = jp * 4; j < (jp + 1) * 4; ++j) {
            a[i][j] = b[i - ip * 4][j - jp * 4];
            if ((++r[i][a[i][j]] > 1) || (++c[j][a[i][j]] > 1)) succ = false;
        }
    }
    return succ;
}

void dfs(int ip, int jp, int now) {
    if (ip == 4 && jp == 0) {
        ret = min(ret, now);
        return;
    }
    add(ip, jp, 1); if (now >= ret) return;
    for (int i = 1; i <= 4; ++i) {
        if (rot(ip, jp)) dfs(jp == 3 ? ip + 1 : ip, jp == 3 ? 0 : jp + 1, now + (i & 3));
    }
    add(ip, jp, -1);
}

void solve () {
    for (int i = 0; i < 16; ++i) {
        scanf("%s", s);
        for (int j = 0; j < 16; ++j) a[i][j] = ord(s[j]);
    }
    memset(r, 0, sizeof(r)); memset(c, 0, sizeof(c));
    ret = 16 * 4; dfs(0, 0, 0);
    printf("%d\n", ret);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}
```

## Problem K. Expression in Memories
>几次错误提交都是因为一个特殊情况没考虑到
```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // freopen("input.txt", "r", stdin);
    int T;
    char str[501];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", str);
        bool flag = true;
        int len = strlen(str);
        if(str[0] == '?')
            str[0] = '1';
        if(len >= 2){
            if(str[1] == '?' && str[0] == '0')
                str[1] = '+';
            else if(str[1] == '?')
                str[1] = '1';
            for(int i = 2; i < len; i ++){
                if(str[i] == '?'){
                    if(str[i-1] == '0' && (str[i-2] == '+' || str[i-2] == '*'))
                        str[i] = '+';
                    else
                        str[i] = '1';
                }
            }
        }
        if(str[0]=='+' || str[0]=='*' || str[len-1]=='+' || str[len-1]=='*')
        flag = false;
        if(len > 1){
            if(str[0]=='0'&&str[1]!='*'&&str[1]!='+')
                flag = false;
            for(int i = 0; i < len; i ++){
                if(str[i]!='+'&&str[i]!='*'){
                    int j=0;
                    for(j = i; j < len; j ++)
                        if(str[j]=='+'||str[j]=='*')
                            break;
                    if(str[i]=='0'&&j-i>1){
                        flag = false;
                        break;
                    }
                    i = j;
                }
            }
            for(int i = 1; i < len; i ++){
                if((str[i-1]=='+'||str[i-1]=='*')&&(str[i]=='+'||str[i]=='*')){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag)
            printf("IMPOSSIBLE\n");
        else
            printf("%s\n", str);
    }
    return 0;
}
```
## Problem L. Graph Theory Homework
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
    int a[100001];
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int ans=sqrt(abs(a[0]-a[n-1]));
        printf("%d\n",ans);
    }
    return 0;
}
```