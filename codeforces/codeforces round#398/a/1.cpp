#include <iostream>
#include <stack>
#include <fstream>
#define MAX 100000
using namespace std;

int N=0;
int data[MAX];
int main()
{
		int purely();
		ifstream fin("input.txt");
		fin>>N;
		//cin>>N;
		for (int i=0;i<N;i++)
		{
				fin>>data[i];
	 			//cin>>data[i];
		}
		purely();
		return 0;
}

int purely()
{
		ofstream fout;
		fout.open("output.txt");
		int* left;
		int* right;
		left = &data[0];
		right = &data[1];
		stack<int>mys;
		int* end = &data[N];
		while(right != end&&N!=0)
		{
				while(*right <= *left)
				{
						fout<<*left<<"  ##  huiche"<<endl;
						//cout<<*left<<endl;
						while(!mys.empty())
						{
								fout<<mys.top()<<" ";
								//cout<<mys.top()<<" ";
								mys.pop();
						}
						//cout<<'\b'<<endl;
						left = right;
						right +=  1;
				}
				while(*left < *right)
				{
						cout<<"@@ huiche"<<endl;
						mys.push(*left);
						left = right;
						right += 1;
				}
				if(right == end)
				{
						while(!mys.empty()){ fout<<mys.top()<<" ";
											//cout<<mys.top<<" ";
											 mys.pop();
										};
						//cout<<'\b';
				}
		}
		fout.close();
		return 0;
}
