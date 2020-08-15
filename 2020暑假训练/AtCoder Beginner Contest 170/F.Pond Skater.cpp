#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e6+5;
int h,w,k,x1,Y1,x2,y2,dr[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
LL dist[N*4];
char s[N];
inline int calc(int x,int y,int z){return (x*w+y)*4+z;}
priority_queue<pair<LL,int> >q;
inline LL ceil(LL x){
	return (x-1)/k*k+k;
}
void dijk(){
	memset(dist,0x3f,sizeof(dist));
	pair<LL,int>u;
	int v=calc(x1,Y1,0);LL w1;
	dist[v]=dist[v+1]=dist[v+2]=dist[v+3]=0;
	q.push({dist[v],v});q.push({dist[v],v+1});q.push({dist[v],v+2});q.push({dist[v],v+3});
	while(!q.empty()){
		u=q.top();q.pop();
		if(-u.first!=dist[u.second])continue;
		int x=u.second/4/w,y=(u.second/4)%w,d=u.second%4,x3,y3;
		for(int i=0;i<4;i++){
			x3=x+dr[i][0],y3=y+dr[i][1];
			if(x3<0||y3<0||x3>=h||y3>=w||s[calc(x3,y3,0)>>2]!='.')continue;
			if(d==i){
				if(dist[v=calc(x3,y3,i)]>dist[u.second]+1){
					dist[v]=dist[u.second]+1;
					q.push({-dist[v],v});
				}
			}
			else{
				if(dist[v=calc(x3,y3,i)]>ceil(dist[u.second])+1){
					dist[v]=ceil(dist[u.second])+1;
					q.push({-dist[v],v});
				}
			}
			
		}	
	}
}
int main(){
	scanf("%d%d%d",&h,&w,&k);
	scanf("%d%d%d%d",&x1,&Y1,&x2,&y2),x1--,Y1--,x2--,y2--;
	for(int i=0;i<h;i++)scanf("%s",s+i*w);
	dijk();
	LL ans=1e17;
	for(int i=0;i<4;i++)ans=min(ans,dist[calc(x2,y2,i)]);
	if(ans>1e15)printf("-1");
	else printf("%d",ceil(ans)/k);
	return 0;
} 
