#include  <bits/stdc++.h>
using namespace std;
struct{
    char a[11];
    int b;
}pai[257];
int main(){
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int pai1
        int m,n;
        scanf("%d%d",&m,&n);
        for(int i=0;i<n;i++){
            char a2[11];
            int a1;
            scanf("%d %s\n",&pai[i].b,pai[i].a);
        }
        char org[2001];
        string orgb;
        scanf("%s",org);
        char x[17][5] = {
        "0000", "0001", "0010", "0011",
        "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011",
        "1100", "1101", "1110", "1111", "xxxx"
        };
        int nn = 16;
        

        int len=strlen(org);
        for(int j=0;j<len;j++){
            char c = org[j];
            if (c >= 'a' && c <= 'f') nn = c - 'a' + 10;
            if (c >= 'A' && c <= 'F') nn = c - 'A' + 10;
            if (c >= '0' && c <= '9') nn = c - '0';
            orgb.append(x[nn]);
        }
        int ji;
        string orgb2;
        char orgb1[20000];
        char ans[20000];
        memset(orgb1,'\0',sizeof(orgb1));
        memset(ans,'\0',sizeof(ans));
        strcpy(orgb1,orgb.c_str());
        printf("%s\n",orgb1);
        len = strlen(orgb1);
        int posa=0;
        for(int i=0;i<len;i++){
            if(orgb1[i]=='1'&&i%9<8){ji++;ji=ji%2;}
            if(i%9==8){
                if(orgb[i]-'0'!=ji){
                    // 校验正确
                    // printf("%d %d\n",orgb[i]-'0',ji);
                    int posb=i;
                    for(int j=posb-8;j<posb;j++){
                        ans[posa++]=orgb1[j];
                        // printf("%c",orgb1[j]);
                    }
                }
                ji=0;
            }
        }
        for(){
            for(){
                str.find(pai[j].a)
            }
        }
    }  
}