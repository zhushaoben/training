#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dsu[N],si[N];
void init(int n){for(int i=1;i<=n;i++)dsu[i]=i;}
int Find(int x){return dsu[x]==x?x:dsu[x]=Find(dsu[x]);}
void merge(int a,int b){dsu[a]=b,si[a]+=si[b];}
int main(){
	return 0;
}
