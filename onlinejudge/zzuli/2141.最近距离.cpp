#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Node{
	int x,y,r;
}a[N];
inline int dis(int u,int v){
	return max(0,abs(a[u].x-a[v].x)-a[u].r-a[v].r)+max(0,abs(a[u].y-a[v].y)-a[u].r-a[v].r);
}
void work(){
	int n,m,op,x,y,r,u,v;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].r);
	for(int i=0;i<m;i++){
		scanf("%d",&op);
		if(op==1)
			scanf("%d%d%d%d",&u,&x,&y,&r),a[u]={x,y,r};
		else{
			scanf("%d%d",&u,&v);
			if(v-u+1>16){puts("0");continue;}
			int ans=1e9;
			for(int j=u;j<v;j++)
				for(int k=j+1;k<=v;k++)ans=min(ans,dis(j,k));
			printf("%d\n",ans);
		}
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
