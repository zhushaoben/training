#include<bits/stdc++.h>
using namespace std;
struct Q{
	int a,b,c,d;
}q[55];
int n,m,Q,ans,a[15];
void update(){
	int w=0;
	for(int i=0;i<Q;i++)
		if(a[q[i].b]-a[q[i].a]==q[i].c)w+=q[i].d;
	ans=max(ans,w);
}
void work(int l,int d){
	if(d==n+1){update();return;}
	for(int i=l;i<=m;i++)a[d]=i,work(i,d+1);
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=0;i<Q;i++)scanf("%d%d%d%d",&q[i].a,&q[i].b,&q[i].c,&q[i].d);
	work(1,1);
	printf("%d",ans);
	return 0;
}
