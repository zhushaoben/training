#include<bits/stdc++.h>
using namespace std;
#define maxm 170005
#define maxn 505
struct Node{
	int next,to;long double w;
}edge[maxm*4];
struct N{
	int x1,y1,x2,y2;
}a[maxn];
int fi[maxm],se,X[maxn],Y[maxn],sx,sy,A[maxn][maxn],B[maxn][maxn],vis[maxm],T;
long double dis[maxm];
inline void add_edge(int u,int v,double w){
	edge[++se].next=fi[u],fi[u]=se,edge[se].to=v,edge[se].w=w,
	edge[++se].next=fi[v],fi[v]=se,edge[se].to=u,edge[se].w=w;
}
priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > > q;
long double dij(int s,int t){
	for(int i=0;i<maxm;i++)dis[i]=1e10;
	q.push(make_pair(dis[s]=0,s));
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u]==T)continue;vis[u]=T;
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].w){
				dis[v]=dis[u]+edge[i].w;
				q.push(make_pair(dis[v],v));
			}
		}
	} 
	return dis[t];
} 
void work(){
	memset(A,0,sizeof(A)),memset(B,0,sizeof(B));
	memset(fi,0,sizeof(fi)),se=sx=sy=0;T++;
	int xs,ys,xt,yt,n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		X[sx++]=a[i].x1,X[sx++]=a[i].x2,Y[sy++]=a[i].y1,Y[sy++]=a[i].y2;
	}
	scanf("%d%d%d%d",&xs,&ys,&xt,&yt);
	X[sx++]=xs,X[sx++]=xt,Y[sy++]=ys,Y[sy++]=yt;X[sx++]=-1e7,Y[sy++]=-1e7;
	sort(X,X+sx),sort(Y,Y+sy);
	sx=unique(X,X+sx)-X,sy=unique(Y,Y+sy)-Y;
	xs=lower_bound(X,X+sx,xs)-X,xt=lower_bound(X,X+sx,xt)-X,
	ys=lower_bound(Y,Y+sy,ys)-Y,yt=lower_bound(Y,Y+sy,yt)-Y;
	for(int i=0;i<n;i++){
		a[i].x1=lower_bound(X,X+sx,a[i].x1)-X,a[i].x2=lower_bound(X,X+sx,a[i].x2)-X,
		a[i].y1=lower_bound(Y,Y+sy,a[i].y1)-Y,a[i].y2=lower_bound(Y,Y+sy,a[i].y2)-Y;
		A[a[i].x1+1][a[i].y1]++,A[a[i].x2+1][a[i].y1]--;
		A[a[i].x1+1][a[i].y2+1]--,A[a[i].x2+1][a[i].y2+1]++;
		B[a[i].x1][a[i].y1+1]++,B[a[i].x2+1][a[i].y1+1]--;
		B[a[i].x1][a[i].y2+1]--,B[a[i].x2+1][a[i].y2+1]++;
	}
	for(int i=1;i<sx;i++){
		for(int j=1;j<sy;j++)A[i][j]+=A[i-1][j],B[i][j]+=B[i-1][j];
	}
	for(int i=1;i<sx;i++){
		for(int j=1;j<sy;j++){
			A[i][j]+=A[i][j-1],B[i][j]+=B[i][j-1];
			add_edge(i*410+j,(i-1)*410+j,(long double)(X[i]-X[i-1])/(A[i][j]+1));
			add_edge(i*410+j,i*410+j-1,(long double)(Y[j]-Y[j-1])/(B[i][j]+1));
		}
	}
	int s=xs*410+ys,t=xt*410+yt;
	printf("%.5Lf\n",dij(s,t));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
