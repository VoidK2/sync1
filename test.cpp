
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

struct Point  
{  
    int x,y;  
};   
bool cmp1(Point a,Point b){
  return max(a.x,b.x);
}
bool cmp2(Point a,Point b){
  return max(a.y,b.y);
}
const int maxN=10000;  
Point PointSet[maxN];  
Point ch[maxN];  
int len;  
int main(){
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        int ans=0;
        scanf("%d",&n);
        if(n<=3){ans=1;}
        for(int i=0;i<n;i++){
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            PointSet[i].x=t1;
            PointSet[i].y=t2;
        }
        sort(PointSet,PointSet+n,cmp1);
        for(int i=0;i<len-2;i++){
            int xx=i,yy=i+1,zz=i+2;
            if((ch[yy].x==ch[xx].x&&ch[yy].y==ch[zz].y)||(ch[yy].x==ch[zz].x&&ch[yy].y==ch[xx].y)){
                ans=1;
                break;
            }else if(abs(ch[xx].x-ch[yy].x)==abs(ch[xx].y-ch[yy].y)&&abs(ch[zz].x-ch[yy].x)==abs(ch[zz].y-ch[yy].y)&&(((ch[xx].x*ch[yy].y-ch[xx].y*ch[yy].x)+(ch[yy].x*ch[zz].y-ch[yy].y*ch[zz].x)+(ch[zz].x*ch[xx].y-ch[zz].y*ch[xx].x))!=0)){
                ans=1;
                break; 
            }
        }
        int xx=len-2,yy=len-1,zz=0;
            if((ch[yy].x==ch[zz].x&&ch[yy].y==ch[zz].y)||(ch[yy].x==ch[xx].x&&ch[yy].y==ch[xx].y)){
                ans=1;
                break;
            }else if(abs(ch[xx].x-ch[yy].x)==abs(ch[xx].y-ch[yy].y)&&abs(ch[zz].x-ch[yy].x)==abs(ch[zz].y-ch[yy].y)&&(((ch[xx].x*ch[yy].y-ch[xx].y*ch[yy].x)+(ch[yy].x*ch[zz].y-ch[yy].y*ch[zz].x)+(ch[zz].x*ch[xx].y-ch[zz].y*ch[xx].x))!=0)){
                ans=1;
                break; 
            }
            xx=len-1,yy=0,zz=1;
            if((ch[yy].x==ch[zz].x&&ch[yy].y==ch[zz].y)||(ch[yy].x==ch[xx].x&&ch[yy].y==ch[xx].y)){
                ans=1;
                break;
            }else if(abs(ch[xx].x-ch[yy].x)==abs(ch[xx].y-ch[yy].y)&&abs(ch[zz].x-ch[yy].x)==abs(ch[zz].y-ch[yy].y)&&(((ch[xx].x*ch[yy].y-ch[xx].y*ch[yy].x)+(ch[yy].x*ch[zz].y-ch[yy].y*ch[zz].x)+(ch[zz].x*ch[xx].y-ch[zz].y*ch[xx].x))!=0)){
                ans=1;
                break; 
            }
        if(ans){
            printf("Yes\n");
        }else{
            printf("No\n");
        }

    }
    return 0;
}