/******************************************************************
�����
******************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 10005
struct Edge{
	int next,to,w;
}edge[maxn*2];
int fi[maxn],se,n,k,size[maxn],root,ma[maxn],sum,ans,depth[maxn];
int b[maxn],si;
bool vis[maxn];
inline void add_edge(int u,int v,int w){
	edge[++se].next=fi[u],edge[se].to=v,edge[se].w=w,fi[u]=se,
	edge[++se].next=fi[v],edge[se].to=u,edge[se].w=w,fi[v]=se;
}
int cal(int x){
	
}
void getroot(int x,int f){//�ҵ���ǰ�������� 
	size[x]=1,ma[x]=0;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==f||vis[v])continue;//vis[v]=1��ʾ�����ڱ����� 
		getroot(v,x);
		size[x]+=size[v];ma[x]=max(ma[x],size[v]);//ma[x]Ϊ��x�ֿ�����������Ľڵ��� 
	}
	ma[x]=max(ma[x],sum-size[x]);//sum-size[x]Ϊ���ڵ����ӵ������Ĵ�С 
	if(ma[x]<ma[root])root=x;//�������� 
}
void solve(int x){
	ans+=cal(x);vis[x]=1;//��ͳ�ƹ����ĵĴ� 
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(vis[v])continue;
		sum=size[v];root=0;
		getroot(v,0);//�ݹ�������������
		solve(root);//ͳ�������Ĵ� 
	}
}
int main(){
	sum = ma[0] = n;//��ʼ�� 
    root = 0;
    getroot(1,0);//������ 
    solve(root);//����� 
	return 0;
}
