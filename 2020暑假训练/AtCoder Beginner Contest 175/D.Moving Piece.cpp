#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e3+5;
int p[N],c[N],st[N],top;
bool vis[N];LL ans;
void solve(){
	
}
int main(){
	int n,k,x;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		top=0,x=i;
		do{
			st[++top]=x,vis[x]=1;
			x=p[x];
		}while(x!=i)
	}
	return 0;
}
