#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M_PI 3.14159265358979323846
using namespace std;
int main(){
    // freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,R;
        scanf("%d%d",&n,&R);
        double ans=2*M_PI*R;
        R=(double)R;
        for(int i=1;i<=n;i++){
            int xi,yi,ri;
            scanf("%d%d%d",&xi,&yi,&ri);
            // printf("%d%d\n",xi,yi);
            ri=(double)ri;
            double rr=sqrt(pow(xi,2)+pow(yi,2));
            double p=(ri+R+rr)/2;
            double d=4*sqrt((p*(p-ri)*(p-R)*(p-rr)))/rr;
            double rr1=sqrt(pow(R,2)-pow((d/2),2));
            // printf("%f  %f\n",rr,ans);
            if(rr+ri==R&&rr<R){
                ans+=2*M_PI*ri;
            }else if(rr+ri>R&&rr<=rr1){
                ans+=2*M_PI*ri;
                // printf("%f\n",(2*asin(d/2/R)));
                // printf("%f\n",(2*asin(d/2/ri)));
                ans-=R*(2*asin((d/2)/R));
                ans-=ri*(2*asin((d/2)/ri));
            }else if(rr>rr1&&rr-ri<R){
                // ans+=2*M_PI*ri;
                
                // printf("%f\n",(2*asin(d/2/R)));
                ans-=R*(2*asin((d/2)/R));
                ans+=ri*(2*asin((d/2)/ri));
            }
        }
        printf("%.20lf",ans);
    }
    return 0;
}