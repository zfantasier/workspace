#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
int k,m,n;
int main()
{
	int N=0,M=0,K=0;
	int result_1=0x7FFFFFFF,result_2=0x7FFFFFF,result=0;  //0x7FFFFFFF 为int最大值
	cin>>N>>M>>K;
	int* data = (int*)malloc(sizeof(int)*(N+1)); //开辟动态数组
	for(int i=1;i<=N;i++) cin>>data[i];
	
	for(int i=M-1;i>=1;i--)            //比较M前的部分，并返回最小距离
	{
		if(data[i]>K||data[i]==0)
		{
		continue;
		}
		else
		{ 
		result_1=(M-i)*10; break;
		}
	};
	
	
	for(int i=M+1;i<=N;i++)			//比较M后的部分，并返回最小距离
	{
		if(data[i]>K||data[i]==0) {continue;}
		else{ result_2=(i-M)*10; break;}
	};
	result=((result_1>result_2)?result_2:result_1);//返回两者中的最小值
	cout<<result<<endl;
	
	return 0;
}
