#include<bits/stdc++.h>
using namespace std;
#define LL long long
int v[30][30],a[30],b[30],n;
LL ans=0;
bool work(int x,int y){
	LL w=0;
	for(int i=0;i<n;i++)w-=v[a[i]][b[y]]+v[b[i]][a[x]]-v[a[i]][a[x]]-v[b[i]][b[y]];
	if(w>0){swap(a[x],b[y]),ans+=w;return 1;}
	return 0;
}
int main(){
	int n1;scanf("%d",&n),n1=n<<1;
	for(int i=0;i<n;i++)a[i]=i,b[i]=i+n;
	for(int i=0,j;i<n1;i++){
		if(i<n){
			for(j=0;j<n;j++)scanf("%d",v[i]+j);
			for(;j<n1;j++)scanf("%d",v[i]+j),ans+=v[i][j];
		}
		else for(j=0;j<n1;j++)scanf("%d",v[i]+j);
	}
	while(1){
		bool fl=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				fl|=work(i,j);
			}
		}
		if(!fl)break;
	}
	printf("%lld",ans);
	return 0;
} 
