#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    int alen,blen,p;
    scanf("%d%d%d",&alen,&blen,&p);
    string a,b;
    cin>>a>>b;
//    cout<<a<<b<<endl;
    int ans,l,r;
    for(int i=1;i<=p;i++){
        ans=0;
        scanf("%d%d",&l,&r);
//        printf("%d %d\n",l,r);
        int pos=l,f;
//        printf("%d",pos);
        while(1){
        	pos=a.find(b,pos);
            if(pos!=-1&&pos+blen<=(r)){
            	// printf("%d %d\n",pos,pos+blen);
            	pos+=blen;
                ans++;
            }else{
            	break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}