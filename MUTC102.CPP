#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
ll gcd(ll a,ll b){
    return b == 0 ? a : gcd(b,a%b);
}

ll phi[40000001];
bool flag[40000001];
int p[40000001];
const int MAXN = 40000001;
int cnt;
void Get_phi()
{
    cnt = 0;
    for(int i=0;i<MAXN;i++){
        flag[i]=true;
    }
    phi[1] = 1;
    for(int i=2; i<MAXN; i++)
    {
        if(flag[i])
        {
            p[cnt++] = i;
            phi[i] = i-1;
        }
        for(int j=0; j<cnt; j++)
        {
            if(i*p[j] > MAXN)
                break;
            flag[i*p[j]] = false;
            if(i%p[j] == 0)
            {
                phi[i*p[j]] = p[j] * phi[i];
                break;
            }
            else
                phi[i*p[j]] = (p[j]-1) * phi[i];
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    Get_phi();
    phi[1] = 0;
    for(int i=2;i<=20000000;i++){
        phi[i] = phi[i-1] + phi[2*i]/2;
    }
    int t,n,ans;
    scanf("%d",&t);
    while(t--){
        ans = 0;
        scanf("%d",&n);
        printf("%lld\n",phi[n]);
    }

    return 0;
}
