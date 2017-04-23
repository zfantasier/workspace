#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
int k,m,n;
int main()
{
	int N=0,M=0,K=0;
	int mark=1,a,b,c,result=0,temp=0;
	cin>>N>>M>>K;
	int* A = (int*)malloc(sizeof(int)*(K+1));
	int* B = (int*)malloc(sizeof(int)*(K+1));
	int* H = (int*)malloc(sizeof(int)*(M+1));
	for(int i=1;i<=M;i++)
	{
	cin>>H[i];
	}
	
	
	
	for(int j=1;j<=K;j++)
	{
	cin>>a>>b;
	if(a==mark)
	{
	A[j]=a;
	B[j]=b;
	mark = b;
	}
	else if(b==mark)
	{
	A[j]=b;
	B[j]=a;
	mark = a;
	}
	else{
	A[j]=0;
	B[j]=0;
	}
	
	}
	temp = H[0];
	
	for(int i=1;i!=K+1;i++)
	{
	for(int j=1;j!=M+1;j++)
	{
		if(A[i]==H[j])
		{ 
			result=H[j]; 
			temp=H[j];
			break;
		}
	}
	if(A[i]==temp) break;
	result = mark;
	}
	cout<<result<<endl;
	return 0;
}
