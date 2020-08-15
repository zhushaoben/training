#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int fa[N];
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<n;i++)fa[i]=i;
	for(int i=1;i<n;i++){
		int u=Find(i),v=Find(i*2%n);
		if(u!=v){
			if(u>v)swap(u,v);
			fa[v]=u;
		}
		v=Find(i*3%n);
		if(u!=v){
			if(u>v)swap(u,v);
			fa[v]=u;
		}
	}
	for(int i=1;i<n;i++){
		if(Find(i)!=1)return puts("wa"),0;
	}
	}
	
	return 0;
}
