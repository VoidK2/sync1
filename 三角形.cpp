#include<bits/stdc++.h>
using namespace std;
// typedef long long ll;
int judgetriangle(int a,int b,int c){
    if(a+b>c&&b+c>a&&a+c>b){
        if(a==b||b==c||c==a){
            if(b!=c||a!=c||a!=b){
                return 2;
            }
            return 1;
        }
        return 3;
    }
    else
        return 0;
}
int main(){
    int a,b,c;
     freopen("input.txt","r",stdin);
    printf("input three intgers：\n");
    scanf("%d%d%d",&a,&b,&c);
    int ts=judgetriangle(a,b,c);
    if((a<=0||b<=0||c<=0)||ts==0){
        printf("Can not form a valid triangle!\n");
    }
    else if(ts==1){
        printf("This is a Equilateral Triangle\n");
        //等边三角形
    }
    else if(ts==2){
        printf("This is a Isosceles Triangle\n");
        //等腰三角形
    }
    else if(ts==3){
        printf("Just a Normal Triangle\n");
        //普通三角形
    }
}