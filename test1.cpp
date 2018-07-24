#include <cstdio>
#include <bitset>
#include<iostream>
using namespace std;
int main() {
    printf("%d\n",36|100);
    bitset<10> b1(36);
    cout<<b1.to_string();
   return 0;
}