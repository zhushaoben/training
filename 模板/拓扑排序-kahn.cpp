#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
priority_queue<int>a;
vector<int>v[505];
int size[505],list[505],top=0;//sizeΪÿ�������,listΪ������� 
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
		for(int i=1;i<=n;i++){//���������Ϊ0�Ķ���������
			if(!size[i])a.push(-i);
		}
		while(!a.empty()){
			int u=-a.top();
			a.pop();
			list[top++]=u;
			for(int i=0;i<v[u].size();i++){//u��ÿ���ڽӵ�v
				size[v[u][i]]--;//ɾ����(u, v)��
				if(!size[v[u][i]])a.push(-v[u][i]);//���ɾ���ߺ�v���Ϊ0����v�������
			}
			v[u].clear();
		}
		bool d=0;
		for(int i=1;i<=n;i++){//���ͼ�л��бߴ�������ڻ�
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
