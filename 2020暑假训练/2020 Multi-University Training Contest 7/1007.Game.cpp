#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
typedef long long LL;
struct Node{
	int x,y;
}a[N];
struct Node1{
	LL x;int id;
	bool operator <(const Node1 &b)const{return x>b.x;}
}b[N];
bool vis[N];
LL dis(Node a,Node b){
	return 1ll*(a.x-b.x)*(a.x-b.x)+1ll*(a.y-b.y)*(a.y-b.y);
}
void work(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	while(!vis[1]&&n>1){
		memset(vis,0,sizeof(bool)*(n+1));
		for(int i=2;i<=n;i++){
			LL w=0;
			for(int j=1;j<=n;j++)w=max(w,dis(a[i],a[j]));
			for(int j=1;j<=n;j++)if(w==dis(a[i],a[j]))vis[j]=1;
		}
		int si=1;
		for(int i=2;i<=n;i++)if(!vis[i])a[++si]=a[i];
		n=si;
	}
	if(n==1&&!vis[1])puts("NO");
	else puts("YES");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
