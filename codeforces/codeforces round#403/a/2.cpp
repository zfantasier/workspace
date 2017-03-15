#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int dfs(int);
int color[2*100001];
int *max_data=new int[2*100001]();
vector <int> adj[2*100001];
int main()
{
        while(in){
        int N;
        in>>N;


        for(int i=1,x,y;i<N;i++)
        {
                in>>x>>y;
                adj[x].pb(y);max_data[x]++;
                adj[y].pb(x);max_data[y]++;
        }
        int temp_max_data=0;
        int result_row =0;
        for(int i=1;i<=N;i++)
        {
                if(max_data[i]>temp_max_data)  {temp_max_data = max_data[i];result_row=i;}
        }
        out<<temp_max_data+1<<endl;

        color[1]=1;
        dfs(1);
        for(int i=1;i<=N;i++)
        {
                for(int j:adj[i])
                    {
                            out<<j<<' ';
                    }
                out<<endl;
        }
        for(int i=1;i<=N;i++) out<<color[i];
        }
        in.close();
        out.close();
        return 0;
}

  int dfs(int i)
  {
        int p=1;
        for(int j:adj[i])
        {
                if(j==0) break;
                if(color[j]==0) color[j]=(++p);
                else continue;
                dfs(j);
        }
        return 0;
  }
