#include<bits/stdc++.h>
using namespace std;
const int inf = 0x1f1f1f1f;
struct Node{
	int x,y,z;string name;
}a[30];
string name[30];
int f[1<<20][21],dis[30][30],vis[30];
int main(){
	int n,s,ans=inf;scanf("%d",&n);
	memset(f,0x1f,sizeof(f));
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y>>a[i].name;
		name[i]=a[i].name;
	}
	sort(name,name+n);
	s=unique(name,name+n)-name;
	for(int i=0;i<=n;i++){
		if(i!=n)for(int j=0;j<s;j++)if(a[i].name==name[j])a[i].z=j;
		for(int j=0;j<i;j++)dis[i][j]=dis[j][i]=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
	}
	f[0][n]=0;for(int j=0;j<n;j++)f[1<<j][j]=dis[n][j];
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(!(i&(1<<j)))continue;
			for(int k=0;k<n;k++){
				if(i&(1<<k))continue;
				f[i|(1<<k)][k]=min(f[i|(1<<k)][k],f[i][j]+dis[j][k]);
			}
			f[i][n]=min(f[i][n],f[i][j]+dis[j][n]);
		}
		int w=0;
		for(int j=0;j<n;j++)if(i&(1<<j))vis[a[j].z]=1;
		for(int j=0;j<s;j++)w+=vis[j],vis[j]=0;
		if(w==s)ans=min(ans,f[i][n]);
	}
	printf("%d",ans);
	return 0;
} 
