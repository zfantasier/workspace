#include <iostream>
#include <stdlib.h>
#include <math.h>
int64_t n,m,i;
int main(){
std::cin>>n>>m;
i=sqrt(n-m<<1);
std::cout<<(n<m?n:i*i+i>>1>=n-m?m+i:m+i+1);
}
