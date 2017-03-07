#include <iostream>
#define MAX 100001
using namespace std;
int purely();
int N=0;
int data[MAX];
int t=0;
int f=0;
int main()
{
            cin>>N;
            f = N;
            while(N--){
            cin>>t;
            data[t]=1;
                                        while(data[f]==1)
                                        {
                                                    cout<<f--<<" ";
                                        }
                                        cout<<endl;
            }
return 0;
}

