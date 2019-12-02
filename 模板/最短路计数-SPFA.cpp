/******************************************************************
���·����-SPFA
�ڸ��¾���ʱ˳���������·��������
һ��Ҫʹ��add���飬Ҫ���ظ�����ʱ��ʹ��ƫ�� 
******************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>
using namespace std;
#define maxn 2005
int n,m,edge[maxn][maxn],dis[maxn],ans[maxn],add[maxn];
bool vis[maxn];
inline void add_edge(int u,int v,int w){
	edge[u][v]=min(edge[u][v],w);
}
void init(){
	memset(edge,0x3f,sizeof(edge)),memset(ans,0,sizeof(ans));
}
bool SPFA(int s){
	deque<int> q;
	memset(dis,0x3f,sizeof(dis)),memset(vis,0,sizeof(vis));
	q.push_back(s),vis[s]=1,dis[s]=0,add[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop_front();
		vis[u]=0;
		for(int v=1;v<=n;v++){
			if(dis[v]>=dis[u]+edge[u][v]){//ע��:����ҲҪ���¼������ 
				if(dis[v]==dis[u]+edge[u][v])add[v]+=add[u];
				else dis[v]=dis[u]+edge[u][v],ans[v]=0,add[v]=add[u];
				if(vis[v])continue;
				vis[v]=1;
				q.push_back(v);
				if(q.empty()||dis[v]>dis[q.front()])q.push_back(v);//SLF�Ż� 
				else q.push_front(v);
			}
		}
		ans[u]+=add[u],add[u]=0;
	}
	return dis[n]<200000;
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	int u,v,w;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w),add_edge(u,v,w);
	}
	if(!SPFA(1))printf("No answer");
	else for(int i=1;i<=n;i++)printf("%d %d",dis[n],ans[n]);
	return 0;
}
