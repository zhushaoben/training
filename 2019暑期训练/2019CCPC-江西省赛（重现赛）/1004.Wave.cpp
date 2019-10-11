#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100005
int n,m,nex[maxn],fi[maxn];
inline void add(int i,int x){
	nex[i]=fi[x],fi[x]=i;
}
int check(int a,int b){
	if(fi[a]<fi[b])swap(a,b);
	int ans=2;
	for(int i=fi[a],i1,j1,j=fi[b];i&&j;i=i1,j=j1){
		i1=nex[i],j1=nex[j];
		while(i1>j)i1=nex[i1];
		if(!i1)break;ans++;
		while(j1>i1)j1=nex[j1];
		if(!j1)break;ans++;
	}
	return ans;
}
void work(){
	memset(fi,0,sizeof(fi));
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x),add(i,x);
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if(fi[i]&&fi[j]){
				ans=max(ans,check(i,j));
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d%d",&n,&m))work();
	return 0;
} 
