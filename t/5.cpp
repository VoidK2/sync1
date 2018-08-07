#include <bits/stdc++.h>
using namespace std;
long long a[1501];
int loc=1;
void init() {
    long long  n = 0 ;
    for (long long i = 0; i <1100; i++)
    {
        string ret;
        n = i;
        long long length;
        for (long long j = 2;; j++)
            if (n <= pow(2, j) - 2)
            {
                length = j - 1;
                break;
            }
        while (length > 0)
        {
            length--;
            if (n > pow(2, length + 1) - 2 + pow(2, length))
            {
                ret.append(1, '7');
                n = n - (long long)pow(2, length + 1);
            }
            else
            {
                ret.append(1, '4');
                n = n - (long long)pow(2, length);
            }
        }
        //  cout<<ret<<endl;
        a[i] = atoi(ret.c_str());
    }
}



int main() {
    // freopen("input.txt","r",stdin);
    long long l=0,r=0,res=0;
    scanf("%lld%lld",&l,&r);
    init();
    int lloc,rloc;
    for(int i=loc;i<=1100;i++){
        if(a[i]<=l&&a[i+1]>l)
        lloc=i;
        if(a[i]<=r&&a[i+1]>r)
        rloc=i;
    }
    for(long long i=l; i<=r; i++) {
        for(int j=loc ; j<=1100; j++,loc++) {
            if(a[j]>=i) {
                res+=a[j];
                break;
            }
        }
    }
    printf("%lld",res);
}