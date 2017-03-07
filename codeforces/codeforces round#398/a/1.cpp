#include <iostream>
#include <stack>
#define MAX 100000
using namespace std;
int purely();
int N=0;
int data[MAX];
int main()
{
		while(cin>>N){
		for (int i=0;i<N;i++)
		{
	 			cin>>data[i];
		}
		purely();

}return 0;
}

int purely(){
		int* left;
		int* right;
		left = &data[0];
		right = &data[1];
		stack<int>mys;
		int* end = &data[N];
		while(N!=0)
		{       if(N==1) {cout<<*left;break;}
				while(*right <= *left&&right!=end)
				{
                        cout<<*left;
						while(!mys.empty())
						{
                                cout<<" "<<mys.top();
								mys.pop();
						}
						cout<<endl;
						left = right;
						right +=  1;
				}
				while(*left < *right)
				{
                        cout<<endl;
						mys.push(*left);
						left = right;
						right += 1;
				}
				if(right == end)
				{      cout << *left;
						while(!mys.empty()){ cout<<" "<<mys.top();
											 mys.pop();
										};
						break;
				}
		}
		return 0;
}
