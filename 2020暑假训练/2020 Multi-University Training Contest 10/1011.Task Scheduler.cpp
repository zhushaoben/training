#include<bits/stdc++.h>
using namespace std;
const int N=105;
struct Node{
	int id,t;
	bool operator <(const Node &b)const{
		if(t!=b.t)return t>b.t;
		return id<b.id;
	}
}a[N];
void work(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){scanf("%d",&a[i].t),a[i].id=i;}
	if(k!=0)sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)printf("%d%c",a[i].id,(i==n?'\n':' '));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
