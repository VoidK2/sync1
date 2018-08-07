#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f;

int main()
{
    freopen("input.txt", "r", stdin);
    string str, str2;
    while (cin >> str)
    {
        int temp = 0;
        int t1 = 0, t2 = 0;
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '4' || str[i] == '7')
            {
                if (str[i] == '4')
                    t1++;
                if (str[i] == '7')
                    t2++;
                str2[temp++] = str[i];
            }
        }
        if (t1 > 0 || t2 > 0)
        {
            if (t1 >= t2)
                cout << '4' << endl;
            else
                cout << '7' << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}
