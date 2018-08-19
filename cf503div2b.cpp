#include <iostream>
#include <cstring>
#include <cstdio> 
using namespace std;
int buld[1005][1005],n,x,lev,tes;
bool flg[1005];
void dfs(int y){
	flg[y] = 1;
	if(!tes){
	for(int i = 1;i <= n;i ++){
		if(buld[y][i] == 1){
			if(flg[i] == 1){
				lev = i;
				tes = true;
				return ;
			}
			else
			dfs(i);
		}
	}}
}
int main(){
    freopen("input.txt","r",stdio);
	scanf("%d",&n);
	memset(buld,0,sizeof(buld));
	for(int i = 1;i <= n;i ++){
		scanf("%d",&x);
		buld[i][x] = 1;
	}
	tes = false;
	memset(flg,0,sizeof(flg));
	dfs(1);
	printf("%d",lev);
	for(int i = 2;i <= n;i ++){
		tes = false;
		memset(flg,0,sizeof(flg));
		dfs(i);
		printf(" %d",lev);
	}
	printf("\n");
}
