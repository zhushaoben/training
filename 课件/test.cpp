#include<bits/stdc++.h>
using namespace std;
const int maxn=1000,maxv=1000;
int n,V,f[maxn][maxv+5],g[maxn][maxv+5],val[maxn+5],v[maxn+5],w[maxn+5];
void read(){
	scanf("%d%d",&n,&V);
	for(int i=1;i<=n;i++)scanf("%d%d",v+i,val+i);
}
int main(){
	read();
	for(所有的组k){
		for(int j=V;j>=0;j--)f[k][j]=f[k-1][j];
		for(int j=V;j>=v[i];j--)
			for(所有属于k的物品i){
				f[j]=max(f[j],f[j-v[i]]+val[i]);
			}
	}
	return 0;
}
