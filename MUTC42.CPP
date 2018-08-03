#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // freopen("input.txt", "r", stdin);
    int T;
    char str[501];
    scanf("%d", &T);
    while(T --)
    {
        scanf("%s", str);
        bool flag = true;
        int len = strlen(str);
        if(str[0] == '?')
            str[0] = '1';
        if(len >= 2){
            if(str[1] == '?' && str[0] == '0')
                str[1] = '+';
            else if(str[1] == '?')
                str[1] = '1';
            for(int i = 2; i < len; i ++){
                if(str[i] == '?'){
                    if(str[i-1] == '0' && (str[i-2] == '+' || str[i-2] == '*'))
                        str[i] = '+';
                    else
                        str[i] = '1';
                }
            }
        }
        if(str[0]=='+' || str[0]=='*' || str[len-1]=='+' || str[len-1]=='*')
        flag = false;
        if(len > 1){
            if(str[0]=='0'&&str[1]!='*'&&str[1]!='+')
                flag = false;
            for(int i = 0; i < len; i ++){
                if(str[i]!='+'&&str[i]!='*'){
                    int j=0;
                    for(j = i; j < len; j ++)
                        if(str[j]=='+'||str[j]=='*')
                            break;
                    if(str[i]=='0'&&j-i>1){
                        flag = false;
                        break;
                    }
                    i = j;
                }
            }
            for(int i = 1; i < len; i ++){
                if((str[i-1]=='+'||str[i-1]=='*')&&(str[i]=='+'||str[i]=='*')){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag)
            printf("IMPOSSIBLE\n");
        else
            printf("%s\n", str);
    }
    return 0;
}
