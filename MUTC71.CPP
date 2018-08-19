#include <cstdio>
#include <cstring>
using namespace std;
int a[3][3];
void rotate(int lo,int ro){
    int tmp,r,l;
    if(lo==1){r=1;l=1;}
    if(lo==2){r=2;l=1;}
    if(lo==3){r=1;l=2;}
    if(lo==4){r=2;l=2;}
    if(ro==1){
        tmp=a[l][r];
        a[l][r]=a[l+1][r];
        a[l+1][r]=a[l+1][r+1];
        a[l+1][r+1]=a[l][r+1];
        a[l][r+1]=tmp;
    }
    else if(ro==0){
        tmp=a[l][r];
        a[l][r]=a[l][r+1];
        a[l][r+1]=a[l+1][r+1];
        a[l+1][r+1]=a[l+1][r];
        a[l+1][r]=tmp;
    }
}
int main(){
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int quer=0;
        scanf("%d",&quer);
        // printf("%d\n",quer);
        memset(a,0,sizeof(a));
        getchar();
        for(int i=1;i<=3;i++){
            char b[3];
            scanf("%s",b);
            for(int j=1;j<=3;j++){
                a[i][j]=b[j-1]-'0';
            }
        }
        for(int i=1;i<=quer;i++){
            char b[2];
            scanf("%s",b);
            int lo=0,ro=0;
            lo=b[0]-'0';
            if(b[1]=='C'){ro=1;}
            if(b[1]=='R'){ro=0;}
            // printf("%d%d\n",lo,ro);
            rotate(lo,ro);
        }
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                printf("%d",a[i][j]);
            }
            printf("\n");
        }
    }
}