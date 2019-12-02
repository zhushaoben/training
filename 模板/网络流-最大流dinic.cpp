#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int v[105][105],dis[105];//v是邻接矩阵，dis是bfs时分的层 
int q[2000],l,r;//BFS队列 ,首,尾 
int n;
bool bfs(){
	memset(dis,-1,sizeof(dis));
	dis[1]=0;
	l=0;r=1;
	q[0]=1;
	while(l<r){//队列不为空 
		int j=q[l++];
		for(int i=1;i<=n;i++){
			if(v[j][i]>0&&dis[i]==-1)dis[i]=dis[j]+1,q[r++]=i;
		}
	}
	if(dis[n]>0)return 1;//判断是否能到n 
	return 0;
}
bool dfs(int x,int low){//low为到当前节点最大流 
	int ans=0;
	if(x==n)return low;
	for(int i=1;i<=n;i++){
		if(v[x][i]&&dis[i]==dis[x]+1&&(ans=dfs(i,min(low,v[x][i])))){
			v[x][i]-=ans;v[i][x]+=ans;//边的最大流量更新 
			return ans;
		}
	}
	return ans;
}
int main(){
	int ans=0,tans;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)scanf("%d",v[i]+j);//邻接矩阵读边 
	}
	while(bfs()){//判断是否能到n 
		while(tans=dfs(1,0x7fffffff))ans+=tans;//用增广路更新 
	}
	printf("%d",ans);
	return 0;
} 
