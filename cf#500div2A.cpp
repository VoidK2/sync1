#include <iostream>
using namespace std;
int n,m,a[200005],x,sum;
int main()
{
	cin >> n >> m;
	sum = 0;
	int  cnt = 0;
	while(n --)
	{
		cin >> x;
		sum += x;
		a[cnt ++] = sum/m;
		sum %= m;
	}
	cout << a[0];
	for(int i = 1;i < cnt;i ++)
	cout << ' ' << a[i];
	cout << endl;
}
