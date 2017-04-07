#include<bits/stdc++.h>
using namespace std;
int m,n,mm=1000000000,mp,nm=1000000000,np;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){int l,r;cin>>r>>l;nm=min(nm,l);np=max(np,r);}
	cin>>m;
	for(int i=0;i<m;i++){int l,r;cin>>r>>l;mm=min(mm,l);mp=max(mp,r);}
	cout<<max(0,max(mp-nm,np-mm));
}
