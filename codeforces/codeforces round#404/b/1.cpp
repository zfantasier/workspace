#include <iostream>
#include <stdlib.h>
#include <cstring>
int main()
{




int n,m,res=0,res1=0,res2=0,result1=0,result2=0;
std::cin>>n;
int* a = (int*)malloc(sizeof(int)*n);memset(a, 0, sizeof(int)*n);
int* b = (int*)malloc(sizeof(int)*n);memset(b, 0, sizeof(int)*n);
for(int i=0;i<n;i++)
{
std::cin>>a[i];
std::cin>>b[i];
}

std::cin>>m;
int* c = (int*)malloc(sizeof(int)*m);memset(c, 0, sizeof(int)*m);
int* d = (int*)malloc(sizeof(int)*m);memset(d, 0, sizeof(int)*m);
for(int i=0;i<m;i++)
{
std::cin>>c[i];
std::cin>>d[i];
}

for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
result1=c[j]-b[i];
result2=a[i]-d[j];
if(result1>result2) {}
else {result1=result2;};

if(result1>result2){result2 = result1;};
if(result2>res){res=result2;}
}
}
delete c;
delete b;

std::cout<<res<<std::endl;
delete a,d;
return 0;
}
