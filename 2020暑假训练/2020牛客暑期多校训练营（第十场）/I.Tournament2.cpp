#include<bits/stdc++.h>
using namespace std;
//int st[10000],ed[10000];
int n,a[305][305],tot;
void add(int x,int y)
{
	a[x][y]=a[y][x]=++tot;
}
int calc()
{
	int ret=0;
	for(int i=1; i<=n; i++) {
		int mn=1e9,mx=0;
		for(int j=1; j<=n; j++) if(i!=j) mx=max(mx, a[i][j]),mn=min(mn, a[i][j]);
		ret+=mx-mn;
//		printf("%d %d %d\n",i,mn,mx);
	}
//	puts("");
	return ret;
}
void work(){
	int n1;scanf("%d",&n),n1=(n*2)/3;
	for(int i=1;i<n;i++)
		for(int j=min(i-1,n-i);j;j--)printf("%d %d\n",j,i);//,add(i,j);
	for(int i=1;i<n;i++)
		for(int j=max(i+1,n-i+1);j<=n;j++)printf("%d %d\n",i,j);//,add(i,j);
//	printf("%d",calc());
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
