#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mod 100000007
using namespace std;
int a[100001];
int temp[100001];
int upper_bound(int arr[], int s, int e, int key)
{
    int mid;
    if (arr[e] <= key)
        return e + 1;
    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] <= key)
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}

int LIS(int d[], int n)
{
    int i = 0, len = 1, *end = (int *)alloca(sizeof(int) * (n + 1));
    end[1] = d[0]; 
    for (i = 1; i < n; i++)
    {
        int pos = upper_bound(end, 1, len, d[i]);
        end[pos] = d[i];
        if (len < pos)
            len = pos;
    }
    return len;
}
struct{
    int l,r,len;
}ans[1];
void invert(int l,int r,int len){
    for(int i=0;i<len;i++){
        temp[i]=a[i];
    }
    for(int i=0;i<=r-l;i++){
        temp[l+i]=a[r-i];
    }
}
int main(){
    // freopen("input.txt","r",stdin);
    // int a[10]={1,2,5,4,4,0};
    // int len=LIS(a,6);
    // printf("%d",len);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        getchar();
        memset(ans,0,sizeof(ans));
        char tmp[100005];
        scanf("%s",tmp);
        // puts(tmp);
        int len=strlen(tmp);
        for(int i=0;i<len;i++){
            a[i]=tmp[i]-'0';
        }
        // for(int i=0;i<len;i++){
        //     printf("%d",a[i]);
        // }
        for(int i=0;i<len;i++){
            if(a[i]>a[i+1]){
            for(int j=i+1;j<len;j++){
                if(a[j]<a[j-1]){
                invert(i,j,len);
                int t1=LIS(temp,len);
                if(t1>ans[0].len){
                    ans[0].len=t1;ans[0].l=i;ans[0].r=j;
                    for(int i=0;i<len;i++){
            printf("%d",temp[i]);
        }
                }}
            }}else{
                continue;
            }
        }
        printf(" %d %d %d\n",ans[0].len,ans[0].l+1,ans[0].r+1);
    }
    return 0;
}