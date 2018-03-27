#include <bits/stdc++.h>
using namespace std;
double cudis(int x1,int y1,int x2,int y2){
    return sqrt(pow((x1-x2),2.0)+pow((y1-y2),2.0));
}
struct house
{
    int x = 0;
    int y = 0;
} house[51];

struct dist{
    double distans[51];
}dist[25];
struct posto{
    int x=0;
    int y=0;
    bool status1=false;
}posto[26];
int main(){
    freopen("inputlx.txt","r",stdin);
    int n,m,k;
    double sumdis=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i =1;i<=n;i++){
        scanf("%d%d",&house[i].x,&house[i].y);
        house[i].status1=true;
    }
    for(int i =1;i<=m;i++){
        scanf("%d%d",&posto[i].x,&posto[i].y);
        for(int j=1;j<=n;j++){
            dist[i].distans[j]=cudis(posto[i].x,house[j].x,posto[i].y,house[j].y);
        }
    }
    for(int i=1;i<=m;i++){
        
    }

    

}