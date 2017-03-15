#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

int main()
{
                while(in){
                int N=0;
                in>> N;
                int temp_N =N-1;
                if(in.fail()) break;
                int **data = new int*[N+1]();
                int *max_data = new int[N+1]();
                for(int i=0;i<=N;i++)
                {
                        data[i] = new int[N]();
                        data[i][0] = i;
                }

                while(temp_N--)
                {
                        int a,b;
                        in>>a>>b;
                        for(int k=1;k<N;k++)
                        {
                                if(data[a][k] == 0) {data[a][k]=b;max_data[a]++;break;}
                        }
                          for(int k=1;k<N;k++)
                        {
                                if(data[b][k] == 0) {data[b][k]=a;max_data[b]++;break;}
                        }

}
                //输出每次的迭代矩阵
                for(int i=0;i<=N;i++){
                    for(int j=0;j<N;j++)
                        {out<<data[i][j]<<' ';}
                        out<<endl;
                        }
                        out<<endl;
                //输出链表长度数组
                for(int i=1;i<N+1;i++) out<<max_data[i]<<' ';
                out<<endl;
                //输出链表的最大长度 并 返回值；
                int temp_max_data=0;
                int result_row =0;
                for(int i=1;i<=N;i++)
                {
                if(max_data[i]>temp_max_data)  {temp_max_data = max_data[i];result_row=i;}
                }
                temp_max_data+=1;
                out<<temp_max_data<<endl<<1;

                for(int i=0;i<temp_max_data-1;i++)  out<<' '<<data[result_row][i];
                out<<endl;
                for(int i = 0; i <=N; i++) delete data[i];
                delete data;
                delete max_data;
        }
        in.close();
        out.close();
        return 0;
  }

  int dfs(int i,int pat)
  {
        if()
        return 0;
  }
