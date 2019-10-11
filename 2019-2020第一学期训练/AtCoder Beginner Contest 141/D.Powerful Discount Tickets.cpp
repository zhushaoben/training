#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
#define LL long long
priority_queue<int>q;
int main(){
	int n,m,x;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&x),q.push(x);
	for(int i=0;i<m;i++){
		int w=q.top();q.pop();
		if(!w)break;
		w>>=1;q.push(w);
	}
	LL ans=0;
	for(int i=0;i<n;i++){ans+=q.top();q.pop();}
	printf("%lld",ans);
	return 0;
}
