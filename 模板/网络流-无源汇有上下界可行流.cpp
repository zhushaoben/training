/******************************************************************
��Դ�������½������
���Ƚ������½��������ͼת������ͨ��������ͼ

�Ƚ�������Դ��s(��Ϊ0)�͸��ӻ��t(��Ϊn+1) 
����ԭͼ�еı�x->y��������Ϊ[b,c]����ô����x->y������Ϊc-b
����ԭͼ�е�ĳһ����i����flow(i)Ϊ�������������бߵ��½�ͼ�ȥ�������������бߵ��½��
��flow(i)<0����ô����s->i������Ϊ-flow(i)
��flow(i)>0����ô����i->t������Ϊflow(i)

��ⷽ��

����ͼ����s��t������� 
����ͼ��������ôһ������һ�ֿ����� 
��ʱ��ԭͼ��ÿһ���ߵ�����ӦΪ��ͼ�ж�Ӧ�ıߵ�����+�����ߵ������½�
******************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 205
#define maxm 50000
struct Edge{
	int next,to,w,fl;
}edge[maxm];
int n,m,t,fi[maxn],flow[maxn],ans[maxm],depth[maxn],que[maxn],first,last;
bool vis[maxn];
inline void add_edge(int u,int v,int w,int x){
	edge[x].next=fi[u],fi[u]=x,edge[x].to=v,edge[x].w=w,edge[x].fl=0,
	edge[x^1].next=fi[v],fi[v]=x^1,edge[x^1].to=u,edge[x^1].w=edge[x^1].fl=0;
} 
inline void init(){
	memset(fi,0,sizeof(fi)),memset(flow,0,sizeof(flow));
}
inline bool bfs(){//�����Ƿ��������· 
	memset(vis,0,sizeof(vis));
	depth[0]=1,first=last=0,que[last++]=0,vis[0]=1;
	while(first<last){
		int x=que[first++],v;
		for(int i=fi[x];i;i=edge[i].next){
			v=edge[i].to;
			if(!vis[v]&&edge[i].w)que[last++]=v,vis[v]=1,depth[v]=depth[x]+1;//ע������Ϊ0�ı߲����� 
		}
	}
	return vis[t];
}
int dfs(int u,int f){
	if(u==t||!f)return f;
	int v,x,sum=0;
	for(int i=fi[u];i;i=edge[i].next){
		v=edge[i].to;
		if(depth[v]==depth[u]+1){//����·����������һ�� 
			x=dfs(v,min(edge[i].w,f-sum));
			sum+=x,edge[i].w-=x,edge[i^1].w+=x,edge[i].fl+=x,edge[i^1].fl-=x;
		}
	}
	return sum;
}
inline int dinic(){//dinic������� 
	int sum=0,x;
	while(bfs()){//��ͼ�ֲ� 
		if(x=dfs(0,0x3f3f3f3f))sum+=x;//�ڷֹ����ͼ�Ͻ���dfs������· 
	}
	return sum;
}
int main(){
	init(),scanf("%d%d",&n,&m),t=n+1;
	int u,v,w,se=(m<<1)+1,sum=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&u,&v,ans+i,&w),
		add_edge(u,v,w-ans[i],i<<1),flow[u]+=ans[i],flow[v]-=ans[i];
	}
	for(int i=1;i<=n;i++){
		if(flow[i]>0)add_edge(i,t,flow[i],++++se),sum+=flow[i];//��flow(i)>0����ô����i->t������Ϊflow(i)
		if(flow[i]<0)add_edge(0,i,-flow[i],++++se);//��flow(i)<0����ô����s->i������Ϊ-flow(i)
	}
	if(dinic()==sum){//����ͼ��������ôһ������һ�ֿ�����  
		printf("YES\n");
		for(int i=1;i<=m;i++){
			printf("%d\n",ans[i]+edge[i<<1].fl);//ÿһ���ߵ�����ӦΪ��ͼ�ж�Ӧ�ıߵ�����+�����ߵ������½�
		}
	}
	else printf("NO\n");//���򣬲����ڿ����� 
	return 0; 
}
