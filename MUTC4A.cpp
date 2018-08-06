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