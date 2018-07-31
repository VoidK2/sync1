#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mod 100000007
using namespace std;
int main(){
    // freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        char m[100][100];
        memset(m,'\0',sizeof(m));
        int yl=(c+b)*2+2;
        int xl=(a+b)*2+2;
        // for(int i=0;i<2*b;i++){
        //     for(int j=2*b;j>0;j--){
        //         m[i][j]='.';
        //     }
        // }
        for(int i=1;i<=2*b;i++){
            int pos=2*b-i+1;
                int len=2*a+1;
                if(i%2==1){
                    for(int z=1;z<=len;z++){
                        if(z%2==1){m[i][pos+z]='+';}
                        if(z%2==0){m[i][pos+z]='-';}
                    }
                }
                if(i%2==0){
                    for(int z=1;z<=len;z++){
                        if(z%2==1){m[i][pos+z]='/';}
                        if(z%2==0){m[i][pos+z]='\0';}
                    }
                }
            
        }
        int pos=2*b;
        for(int i=1;i<2*c+2;i++){
            if(i%2==1){
                for(int y=1;y<=2*a+1;y++){
                    if(y%2==1){m[pos+i][y]='+';}
                    if(y%2==0){m[pos+i][y]='-';}
                }
            }
            if(i%2==0){
                for(int y=1;y<=2*a+1;y++){
                    if(y%2==1){m[pos+i][y]='|';}
                    if(y%2==0){m[pos+i][y]='\0';}
                }
            }
        }
        pos=2*a+2*b+2;
        int len=2*c+1;
        for(int i=1;i<=2*b;i++){
            int pos2=i-1;
            if(i%2==1){
                for(int y=1;y<=len;y++){
                    if(y%2==1){m[pos2+y][pos-i]='+';}
                    if(y%2==0){m[pos2+y][pos-i]='|';}
                }
            }
            if(i%2==0){
                for(int y=1;y<=len;y++){
                    if((y+1)%2==1){m[pos2+y][pos-i]='\0';}
                    if((y+1)%2==0){m[pos2+y][pos-i]='/';}
                }
            }
            
        }
        for(int i=1;i<=yl-1;i++){
            for(int y=1;y<xl;y++){
                if(m[i][y]=='\0'){
                    printf(".");
                }else{
                    printf("%c",m[i][y]);
                }
            }
            printf("\n");
        }
        

    }
    return 0;
}