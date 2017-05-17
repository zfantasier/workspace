#include <iostream>
const int  maxlen = 10000;
using namespace std;
class HP
{
        public:
                int len,s[maxlen];
                HP()    {   (*this)=0;  };
                HP(int  inte)    {  (*this)=inte;   };
                HP(const char* str) {   (*this)=str;   };
                friend std::ostream& operator<<( std::ostream &cout,const HP&x );
                HP operator =(  int inte    );
                HP operator =(  const char* str );
                HP operator +(  const HP& b );
                HP operator *(  const HP& b );
};

ostream& operator<<( ostream &cout,const HP&x )
{
        for(int i=x.len;i>=1;i--) cout<<x.s[i];
        return cout;
}

HP HP::operator =(  int inte    )
{
		if(inte==0){len =1;s[1]=0;return (*this);}
		for(len=0;inte>0;){s[++len]=inte%10;inte/=10;};
		return (*this);
};
HP HP::operator =(  const char* str )
{
		len =  strlen(str);
		for(int i=1;i<= len;i++) s[i] = str[i-1]-'0';
		return *this;
};

HP HP::operator *(  const HP& b )
{
		int i,j;HP c;c.len=len+b.len;
		for(i=1;i<=c.len;i++) c.s[i]=0;
		for(i=1;i<=len;i++) for(j=1;j<=b.len;j++) c.s[i+j-1]+=s[i]*b.s[j];
		for(i=1;i<c.len;i++){c.s[i+1]+=c.s[i]/10;c.s[i]%=10;};
		while(c.s[i]){c.s[i+1]=c.s[i]/10;c.s[i]%=10;i++;}
		while(i>1&&!c.s[i]) i--;c.len=i;
		return c;

};
HP HP::operator +(  const HP& b )
{	
		int i; HP c; c.s[1]=0;
		for(i=1;i<=b.len||i<=len||c.s[i];i++)
		{
				if(i<=len) c.s[i] += s[i];
				if(i<=b.len) c.s[i]+=b.s[i];
				c.s[i+1]=c.s[i]/10;c.s[i]%=10;
		}
		c.len=i-1; if(c.len==0) c.len=1;
		return c;
};
HP N,M;


int main()
{
cin>>N>>M;
HP n = N-M;
HP k = 1;
HP base =0;
while(1){
base = k*k+3*k;
if(base>=n) break;
k = k + 1;
}


cout<<M+k<<endl;
return 0;
}