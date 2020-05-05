#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char s[N];int f[N],g[2*N];
int main(){
	int n,k,c;scanf("%d%d%d%s",&n,&k,&c,s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='o')f[i]=f[max(0,i-c-1)]+1;
		f[i]=max(f[i-1],f[i]);
	}
	for(int i=n;i>=1;i--){
		if(s[i]=='o')g[i]=g[i+c+1]+1;
		g[i]=max(g[i],g[i+1]);
	}
	if(f[n]>k)return 0;
	for(int i=1;i<=n;i++){
		if(s[i]=='o'&&f[i-1]<f[i]&&g[i+1]<g[i])printf("%d\n",i);
	}
	return 0;
}
