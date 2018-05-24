#include <bits/stdc++.h>
using namespace std;
bool checksame(int a[],int len) {
    int res;
    for(int i=0; i<len; i++) {
        if(a[i]!=a[0]) {
            return false;
            exit();
        }
    }
    return true;
}
int main() {
    freopen("input.txt","r",stdin);
    int n,a[110],supple=0,temp=0,exchage=0;
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    while(checksame(a)) {
        
    }

}