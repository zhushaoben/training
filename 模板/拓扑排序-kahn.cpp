#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
priority_queue<int>a;
vector<int>v[505];
int size[505],list[505],top=0;//size为每个点入度,list为结果数组 
int main(){
	int n,m,x,y;
	while(scanf("%d%d",&n,&m)!=EOF){
		top=0;
		memset(size,0,sizeof(size));
		while(!a.empty())a.pop();
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			size[y]++;
		}
		for(int i=1;i<=n;i++){//将所有入度为0的顶点加入队列
			if(!size[i])a.push(-i);
		}
		while(!a.empty()){
			int u=-a.top();
			a.pop();
			list[top++]=u;
			for(int i=0;i<v[u].size();i++){//u的每个邻接点v
				size[v[u][i]]--;//删除边(u, v)；
				if(!size[v[u][i]])a.push(-v[u][i]);//如果删除边后v入度为0，则将v加入队列
			}
			v[u].clear();
		}
		bool d=0;
		for(int i=1;i<=n;i++){//如果图中还有边存在则存在环
			if(!v[i].empty())v[i].clear(),d=1;
		}
		if(d)printf("wrong\n");
		else{
			for(int i=0;i<top-1;i++){
				printf("%d ",list[i]);
			}
			printf("%d",list[top-1]);
			printf("\n");
		}
	}
	return 0;
}
