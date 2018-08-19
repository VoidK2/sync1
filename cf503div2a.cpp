#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n,h,a,b,k,ta,fa,tb,fb,ans;
int main(){
    // freopen("input.txt","r",stdin);
	scanf("%d %d %d %d %d",&n,&h,&a,&b,&k);
	while(k--){
		scanf("%d %d %d %d",&ta,&fa,&tb,&fb);
		ans=0;
		if(ta!=tb){
			if(fa>b){
				ans =ans+abs(fa-b);
				ans =ans+abs(tb-ta);
				ans =ans+abs(fb-b);
			}
			else if(fa<a){
				ans =ans+abs(a-fa);
				ans =ans+abs(tb-ta);
				ans =ans+abs(fb-a);
			}
			else if(fa<=b&&fa>=a)
			ans=ans+abs(tb-ta)+abs(fb-fa);
		}
		else
		ans = abs(fb-fa);
		printf("%d\n",ans);
	}
}
