
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
 
int main()
{
  string ch;
  cin>>ch;
  int a = ch.length();
	if(ch[a-1] != 'a' && ch[a-1] != 'e' && ch[a-1] != 'i' && ch[a-1] != 'o' && ch[a-1] != 'u' && ch[a-1] != 'n'){
		printf("NO\n");
		return 0;
	}
  for(int i=0;i<a-1;i++){
    if(ch[i] != 'a' && ch[i] != 'e' && ch[i] != 'i' && ch[i] != 'o' && ch[i] != 'u' && ch[i] != 'n'){
      if(ch[i+1] != 'a' && ch[i+1] != 'e' && ch[i+1] != 'i' && ch[i+1] != 'o' && ch[i+1] != 'u'){
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("YES\n");
  return 0;
}