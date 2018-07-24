#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define mod 1000000007
int main()
{
  freopen("input.txt", "r", stdin);
  int n, m, ans = 0;
  float d = 0,oneN = 0;
  bool map[2001][2001];
  memset(map, false, sizeof(map));
  char a[2001];
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++){
    scanf("%s", a);
    for (int j = 0; j < m; j++){
      map[i][j + 1] = a[j] - '0';
      if (map[i][j + 1] == 1){
        oneN++;
      }
    }
  }
  float devide=1/oneN;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      for (int t = 1; t <= n; t++){
        for (int z = 1; z <= m; z++){
          if (map[t][z] == 1){
            d += devide * (abs(i - t) + abs(j - z));
            // printf("d=%f\n", d);
          }
        }
      }
      ans = ans ^ ((int)d%mod);
      // printf("ans=%d\n", ans);
      d = 0;
    }
  }
  printf("%d", ans);
  return 0;
}