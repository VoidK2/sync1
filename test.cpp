#include <cstdio>
using namespace std;
int main(){
    int i=70,ans;
    while (i >= 7){
                if (i % 7 == 0)
                    ans++;
                i=i/7;
            }
            printf("%d",ans);
    return 0;
}