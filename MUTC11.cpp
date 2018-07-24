#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mod 100000007
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    int t;
    char s[30]="0";
    scanf("%d",&t);
    getchar();
    while(t--){
        memset(s,'\0',sizeof(s));
        gets(s);
        // printf("\n%s\n",s);
        int h,m,zf,tz=0,ftz=0,pos1,pos2=0,posb1,posb2,flag=0;
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='.'){pos2=i;flag=1;break;}
        }
        if(flag==0){
            pos2=strlen(s);
            // printf("%d    ",pos2);
        }
        for(int i=0;i<=strlen(s);i++){
            if(s[i]=='+'){
                zf=1;pos1=i;break;}
            if(s[i]=='-'){
                zf=0;pos1=i;break;}
        }
        // printf("%d     ",pos1);
        for(int i=0;i<=strlen(s);i++){
            if(s[i]==' '){posb1=i;s[i]='-';break;}
        }
        for(int i=0;i<=strlen(s);i++){
            if(s[i]==' '){posb2=i;s[i]='-';break;}
        } 
        if(flag){
        ftz=s[pos2+1]-'0';}
        if(pos2-pos1==3){
            tz=(s[pos1+1]-'0')*10+(s[pos1+2]-'0');
        }
        if(pos2-pos1==2){
            tz=s[pos1+1]-'0';
        }
        if(posb1==2){
            h=(s[0]-'0')*10+(s[1]-'0');
        }
        if(posb1==1){
            h=s[0]-'0';
        }
        if(posb2-posb1==3){
            m=(s[posb1+1]-'0')*10+(s[posb1+2]-'0');
        }
        if(posb2-posb1==2){
            m=(s[posb1+1]-'0');
        }
        
        // printf("%d %d %d %d %d",h,m,zf,tz,ftz);
        if(zf==1){
            m+=ftz*6;
            if(m>=60){
                m=0;
                h++;
            }
            h+=tz-8;
            if(h<0){ h+=24;}
            if(h>=24){h-=24;}
            
        }
        if(zf==0){
            m-=ftz*6;
            if(m<0){
                m+=60;
                h--;
            }
            h-=tz+8;
            if(h<0){h+=24;}
            if(h>=24){h-=24;}
            
        }
        printf("%02d:%02d\n",h,m);
    }
    return 0;
}