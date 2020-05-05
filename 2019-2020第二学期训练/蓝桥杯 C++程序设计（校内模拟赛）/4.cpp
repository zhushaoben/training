#include<bits/stdc++.h>
using namespace std;
const int mo=10000;
int f[1005];
void work(){
	int n,m,pre,x;scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)f[i]=1;
	for(int i=2;i<=n;i++){
		x=pre=0;
		if(i&1)for(int i=1;i<=m;i++)x=f[i],f[i]=(f[i-1]+pre)%mo,pre=x;
		else for(int i=m;i>=1;i--)x=f[i],f[i]=(f[i+1]+pre)%mo,pre=x;
	}
	int ans=0;
	for(int i=1;i<=m;i++)(ans+=f[i])%=mo;
	printf("%d",ans);
}
int main(){
	int T=1;
//	scanf("%d",&T);
	while(T--)work();
	return 0;
} 
