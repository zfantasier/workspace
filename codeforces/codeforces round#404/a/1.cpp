#include <iostream>
#include <string>
using  std::string;
using  std::wstring;
int main()
{
int N;
int result = 0;
string str;
std::cin>>N;
while(N--)
{
std::cin>>str;
if(str=="Tetrahedron"){result+=4;}
else if(str=="Cube"){result+=6;}
else if(str=="Octahedron" ){result+=8;}
else if(str=="Dodecahedron"){result+=12;}
else if(str=="Icosahedron"){result+=20;}
};

std::cout<<result<<std::endl;
return 0;
};