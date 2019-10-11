#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
struct Node{
	int a,b;
	bool operator < (const Node &c)const{
		return a<c.a;
	}
}a[maxn+5];
priority_queue<int> p;
int main(){
	int n,m,ans=0;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d%d",&a[i].a,&a[i].b);
	sort(a,a+n);
	for(int i=1,j=0;i<=m;i++){
		while(j<n&&a[j].a==i)p.push(a[j++].b);
		if(!p.empty()){ans+=p.top();p.pop();}
	}
	printf("%d",ans);
	return 0;
} 
