#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
vector<int>g[505];
int vis[505],list[505],top=0;//vis��ʾ�ڵ����״̬,listΪ������� 
bool dfs(int u)  
{  
    vis[u] = -1;//-1������ʾ����u���ڷ���  
    for(int i = 0 ; i < g[u].size() ; i ++)  {  
        if(vis[g[u][i]] == -1)//��ʾ�������������Σ��϶������˻�  
            return false;  
        else if(vis[g[u][i]] == 0)  {  
            if(!dfs(g[u][i]))return false;  
        }  
    }  
    vis[u] = 1;
    list[top++] = u;//�ŵ��������������ʱ��ǵõ�������������ݵ�ԭ��  
    return true;  
}  
int main(){
	int n,m,x,y;
	while(scanf("%d%d",&n,&m)!=EOF&&(n||m)){
		bool d=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)g[i].clear();
		top=0;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
		}
		for(int i=n;i>0;i--){
			if(!vis[i])if(!dfs(i))d=1;
		}
		if(d)printf("wrong\n");
		else {
			for(int i=top-1;i>0;i--)printf("%d ",list[i]);
			printf("%d\n",list[0]);
		}
	} 
	return 0;
} 
