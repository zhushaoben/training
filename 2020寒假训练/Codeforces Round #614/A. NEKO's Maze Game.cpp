#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
bool vis[2][maxn];
int main(){
	int n,q,num=0,x,y;scanf("%d%d",&n,&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&x,&y),x--;
		if(vis[x][y]=!vis[x][y])num+=vis[1-x][y-1]+vis[1-x][y]+vis[1-x][y+1];
		else num-=vis[1-x][y-1]+vis[1-x][y]+vis[1-x][y+1];
		if(num)puts("No");
		else puts("Yes");
	}
	return 0;
}
