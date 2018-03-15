#include <bits/stdc++.h>
using namespace std;
char dir[4]= {'U','R','D','L'};
int diri=0;
int main() {
    freopen("input.txt","r",stdin);
    bool a[110][110];
    memset(a,true,sizeof(a));
    int n,m,x,y,k;
    char s;


    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        for(int j; j<=m; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d%d%c%d",&x,&y,&s,&k);
    for(int i=0; i<=3; i++) {
        if(dir[i]==s) {
            diri=i;
            break;
        }
    }
    int steps=0;
    while(steps==k) {
        if(a[x][y]==white) {
            a[x][y]=black;
            diri--;
            if(dir[diri%4]=='R') {
                y++;
            }
            if(dir[diri%4]=='L') {
                y--;
            }
            if (dir[diri % 4] == 'U')
            {
                x++;
            }
            if (dir[diri % 4] = 'D')
            {
                x--;
            }
        }
        if(a[x][y]==black) {
            a[x][y]=white;
            diri++;
            if (dir[diri] == 'R')
            {
                y++;
            }
            if (dir[diri] == 'L')
            {
                y--;
            }
            if (dir[diri] == 'U')
            {
                x++;
            }
            if (dir[diri] = 'D')
            {
                x--;
            }
        }
    }
    printf("%d %d",x,y);

}