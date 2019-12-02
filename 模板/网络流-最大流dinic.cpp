#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int v[105][105],dis[105];//v���ڽӾ���dis��bfsʱ�ֵĲ� 
int q[2000],l,r;//BFS���� ,��,β 
int n;
bool bfs(){
	memset(dis,-1,sizeof(dis));
	dis[1]=0;
	l=0;r=1;
	q[0]=1;
	while(l<r){//���в�Ϊ�� 
		int j=q[l++];
		for(int i=1;i<=n;i++){
			if(v[j][i]>0&&dis[i]==-1)dis[i]=dis[j]+1,q[r++]=i;
		}
	}
	if(dis[n]>0)return 1;//�ж��Ƿ��ܵ�n 
	return 0;
}
bool dfs(int x,int low){//lowΪ����ǰ�ڵ������ 
	int ans=0;
	if(x==n)return low;
	for(int i=1;i<=n;i++){
		if(v[x][i]&&dis[i]==dis[x]+1&&(ans=dfs(i,min(low,v[x][i])))){
			v[x][i]-=ans;v[i][x]+=ans;//�ߵ������������ 
			return ans;
		}
	}
	return ans;
}
int main(){
	int ans=0,tans;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)scanf("%d",v[i]+j);//�ڽӾ������ 
	}
	while(bfs()){//�ж��Ƿ��ܵ�n 
		while(tans=dfs(1,0x7fffffff))ans+=tans;//������·���� 
	}
	printf("%d",ans);
	return 0;
} 
