#include <cstdio>
using namespace std;
int main()
{
  freopen("input.txt", "r", stdin);
  int a = 0;
  scanf("%d", &a);
  a++;
  a++;
  a++;
  a = a++;
  printf("%d", a);
  return 0;
}