#include<bits/stdc++.h>
using namespace std;
#define maxn 500000
int d[maxn+5];
struct Node{
	int a[4],si;
	void insert(int x){
		for(int i=0;i<si;i++)if(a[i]==x)return;
		a[si++]=x;
	}
	int del(){
		for(int i=0;i<si;i++)d[a[i]]--;
		for(int i=0;i<si;i++)if(d[a[i]]==1)return a[i];
		return 0;
	}
}b[maxn+5];
int main(){
	int n,fi=0,la=0,x,y,z;scanf("%d",&n);
	for(int i=2;i<n;i++)scanf("%d%d%d",&x,&y,&z),d[x]++,d[y]++,d[z]++,b[x].insert(y),b[x].insert(z),b[y].insert(x),b[y].insert(z),b[z].insert(y),b[z].insert(x);
	for(int i=1;i<=n;i++)if(d[i]==1)if(!fi)fi=i;else la=i;
	for(int i=0;i<b[la].si;i++)if(d[b[la].a[i]]==2)d[b[la].a[i]]++;d[la]=3;
	while(fi){
		printf("%d ",fi);
		fi=b[fi].del();
	}
	return 0;
}
