#include <iostream>
#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

int main()
{

int N=10;
                int **data = new int*[N+1]();
                int *max_data = new int[N]();
                for(int i=0;i<=N;i++)
                {
                        data[i] = new int[N]();
                }
                for(int i=0;i<=N;i++){
                    for(int j=0;j<N;j++)
                        {out<<data[i][j]<<' ';}
                        out<<endl;
                        }

for(int i = 0; i <=N; i++) delete data[i];
delete data;
out.close();

 return 0;


}
