#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
typedef long long LL;
struct Node{
	int a,b,c;
}a[N],b[N];
int tmp[N*3],tmp1[N*3],si=1,si1=1;
bool vis[N*3][N*3],vis1[N*3][N*3],V[N*3][N*3];
int que[N*N*9][2],s,t;
void calc(int *a,int x,int y){*a=x,*(a+1)=y;}
LL bfs(){
	LL ans=0;
	while(s<t){
		int x=que[s][0],y=que[s++][1];
		ans+=1ll*(tmp[x]-tmp[x-1])*(tmp1[y]-tmp1[y-1]);
		if(!x||!y||x>=si||y>=si1)return -1;
		if(!V[x-1][y]&&!vis1[x][y])calc(que[t++],x-1,y),V[x-1][y]=1;
		if(!V[x][y-1]&&!vis[x][y])calc(que[t++],x,y-1),V[x][y-1]=1;
		if(!V[x+1][y]&&!vis1[x+1][y])calc(que[t++],x+1,y),V[x+1][y]=1;
		if(!V[x][y+1]&&!vis[x][y+1])calc(que[t++],x,y+1),V[x][y+1]=1;
	}
	return ans;
}
void check(int &x,int &y){if(x>y)swap(x,y);}
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c),check(a[i].a,a[i].b),tmp[si++]=a[i].a,tmp[si++]=a[i].b,tmp1[si1++]=a[i].c;
	for(int i=0;i<m;i++)scanf("%d%d%d",&b[i].c,&b[i].a,&b[i].b),check(b[i].a,b[i].b),tmp1[si1++]=b[i].a,tmp1[si1++]=b[i].b,tmp[si++]=b[i].c;
	sort(tmp,tmp+si),sort(tmp1,tmp1+si1);
	si=unique(tmp,tmp+si)-tmp,si1=unique(tmp1,tmp1+si1)-tmp1;
	for(int i=0;i<n;i++){
		int x=lower_bound(tmp,tmp+si,a[i].a)-tmp,y=lower_bound(tmp,tmp+si,a[i].b)-tmp,
		z=lower_bound(tmp1,tmp1+si1,a[i].c)-tmp1;
		for(int i=x+1;i<=y;i++)vis[i][z+1]=1;
	}
	for(int i=0;i<m;i++){
		int x=lower_bound(tmp1,tmp1+si1,b[i].a)-tmp1,y=lower_bound(tmp1,tmp1+si1,b[i].b)-tmp1,
		z=lower_bound(tmp,tmp+si,b[i].c)-tmp;
		for(int i=x+1;i<=y;i++)vis1[z+1][i]=1;
	}
	int u=lower_bound(tmp,tmp+si,0)-tmp,v=lower_bound(tmp1,tmp1+si1,0)-tmp1;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)calc(que[t++],u+i,v+j),V[u+i][v+j]=1;
	LL ans=bfs();
	if(ans==-1)puts("INF");
	else printf("%lld\n",ans);
	return 0;
} 
