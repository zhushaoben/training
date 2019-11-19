#include<bits/stdc++.h>
using namespace std;
int f[2003][2003],m;
int dfs(int x,int y)
{
	if (x==0)return 0;
	if (x<=y+m)return 1;
	if(f[x][y]!=-1)return f[x][y];
	for (int i=1;i<=y+m;++i)
	{
		if (i>x)break;
		if (dfs(x-i,i)==0)return f[x][y]=1;
	}
	return f[x][y]=0;
}
int t,n;
int main(){	
	while(~scanf("%d%d",&n,&m)){
		memset(f,-1,sizeof(f));
		if (dfs(n,1-m))puts("hyy");
		else puts("wqy");
	}
//	puts("");puts("");puts("");}
	return 0;
}
