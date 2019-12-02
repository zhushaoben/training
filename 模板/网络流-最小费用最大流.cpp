/******************************************************************
1��ÿ�β����Ƿ����Դ�㵽���Ŀ�����·����
����pre[i]��¼·���ϵ����i�ıߵı�š�
�����·��ָ����Դ�㵽��ǰ������· �Ҽ�¼·�������б߶���ʣ����������С��Min��
2��������������·�����ӻ������pre������ǰ�ң�����ÿ����
�������������Min������߼���Min
�ܷ����ۼ�Min * edge[i].cost���������ۼ�Min��
******************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<deque>
using namespace std;
#define maxn 5005
#define maxe 150000
struct Edge{
	int next,from,to,w,fl;
}edge[maxe];
int n,m,s,t,fi[maxn],se=1,dis[maxn],pre[maxn],flow[maxn],ans1,ans2;
bool vis[maxn];
inline void add_edge(int u,int v,int w,int fl){
	edge[++se].next=fi[u],edge[se].fl=fl,edge[se].to=v,edge[se].w=w,edge[se].from=u,fi[u]=se,
	edge[++se].next=fi[v],edge[se].fl=0,edge[se].to=u,edge[se].w=-w,edge[se].from=v,fi[v]=se;
}
bool SPFA(){
	deque<int> q;int sum=0,tot=1;
	memset(dis,0x3f,sizeof(dis)),memset(vis,0,sizeof(vis));
	q.push_back(s),vis[s]=1,dis[s]=0,flow[s]=0x3f3f3f3f,flow[t]=0;
	while(!q.empty()){
		int u=q.front();q.pop_front();
		if(dis[u]*tot>sum){//LLL�Ż� 
			q.push_back(u);continue;
		}
		vis[u]=0,sum-=dis[u],tot--;
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(edge[i].fl&&dis[v]>dis[u]+edge[i].w){
				dis[v]=dis[u]+edge[i].w,flow[v]=min(flow[u],edge[i].fl),pre[v]=i;//pre[i]��¼·���ϵ����i�ıߵı��
				if(vis[v])continue;
				vis[v]=1,sum+=dis[v],tot++;
				if(q.empty()||dis[v]>dis[q.front()])q.push_back(v);//SLF�Ż� 
				else q.push_front(v);
			}
		}
	}
	if(flow[t]){//����·���ϵıߵ�ʣ������ 
		for(int i=pre[t];i;i=pre[edge[i].from]){
			edge[i].fl-=flow[t],edge[i^1].fl+=flow[t];
		}
	}
	return flow[t];
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	int u,v,w,f;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&u,&v,&f,&w),add_edge(u,v,w,f);
	}
	while(SPFA())ans1+=flow[t],ans2+=flow[t]*dis[t];//���������·���� 
	printf("%d %d",ans1,ans2);
	return 0;
}
