#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m;
char a[N][N],b[N][N],c[N][N],d[N][N];
void work(){
	for(int i=1;i<=n;i++)scanf("%s",a[i]);
	for(int i=1;i<=n;i++)scanf("%s",b[i]);
	int ans=0,h,f;
	for(int i=1;i<=n;i++)for(int j=0;j<m;j++)c[i][j]=d[i][j]=0;
	for(int i=1;i<=n;i++){
		h=0,f=(i&1)?1:-1;
		for(int j=0;j<m;j++,f*=-1){
			if(!c[i][j])
				if(a[i][j]=='|')c[i][j]=1,c[i+1][j]=2;
				else c[i][j]=3,c[i][j+1]=4;
			if(!d[i][j])
				if(b[i][j]=='|')d[i][j]=1,d[i+1][j]=2;
				else d[i][j]=3,d[i][j+1]=4;
			if(c[i][j]==d[i][j]);
			else if(c[i][j]==1)h+=f;
			else if(d[i][j]==1)h-=f;
			ans+=abs(h);
		}
	}
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d%d",&n,&m))work();
	return 0;
}
