
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

struct Point  
{  
    float x,y;  
};  
  

float multiply(Point p1,Point p2,Point p0)  
{  
    return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));  
}  
  
float dis(Point p1,Point p2)  
{  
    return(sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));  
}  
  
  
void Graham_scan(Point PointSet[],Point ch[],int n,int &len)  
{  
    int i,j,k=0,top=2;  
    Point tmp;  
  
    //找到最下且偏左的那个点  
    for(i=1;i<n;i++)  
        if ((PointSet[i].y<PointSet[k].y)||((PointSet[i].y==PointSet[k].y)&&(PointSet[i].x<PointSet[k].x)))  
            k=i;  
    //将这个点指定为PointSet[0]  
    tmp=PointSet[0];  
    PointSet[0]=PointSet[k];  
    PointSet[k]=tmp;  
  
    //按极角从小到大,距离偏短进行排序  
    for (i=1;i<n-1;i++)  
    {  
        k=i;  
        for (j=i+1;j<n;j++)  
            if( (multiply(PointSet[j],PointSet[k],PointSet[0])>0)  
                ||((multiply(PointSet[j],PointSet[k],PointSet[0])==0)  
                    &&(dis(PointSet[0],PointSet[j])<dis(PointSet[0],PointSet[k]))) )  
                k=j;//k保存极角最小的那个点,或者相同距离原点最近  
        tmp=PointSet[i];  
        PointSet[i]=PointSet[k];  
        PointSet[k]=tmp;  
    }  
    //第三个点先入栈  
    ch[0]=PointSet[0];  
    ch[1]=PointSet[1];  
    ch[2]=PointSet[2];  
    //判断与其余所有点的关系  
    for (i=3;i<n;i++)  
    {  
        //不满足向左转的关系,栈顶元素出栈  
        while(multiply(PointSet[i],ch[top],ch[top-1])>=0) top--;  
        //当前点与栈内所有点满足向左关系,因此入栈.  
        ch[++top]=PointSet[i];  
    }  
    len=top+1;  
}  
  
const int maxN=10000;  
Point PointSet[maxN];  
Point ch[maxN];  
int len;  
int main(){
    freopen("input.txt","r+",stdin);
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
            PointSet[i].x=(float)t1;
            PointSet[i].y=(float)t2;
        }
        Graham_scan(PointSet,ch,n,len);
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