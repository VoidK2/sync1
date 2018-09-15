#include <cstdio>
int main(){
    int a[100000];
    a[1]=0;
    a[2]=0;
    a[3]=1;
    for(int i=4;i<=20;i++){
        a[i]=(i-3)*a[i-1]+(2*i-4)*a[i-2]+(i-2)*a[i-3];
        a[i]=a[i]%998244353;
        printf("%d ",a[i]);
    }
}