#include<bits/stdc++.h>
using namespace std;
#define maxn 12
#define maxm 1000
struct Node{
	int a,b,x;
}a[maxm];
int f[1<<maxn];
int main(){
	int n,m,x,s;scanf("%d%d",&n,&m),s=1<<n;
	for(int i=0;i<m;i++){
		scanf("%d%d",&a[i].a,&a[i].b);
		for(int j=0;j<a[i].b;j++)scanf("%d",&x),a[i].x|=(1<<x);
		a[i].x>>=1;
	}
	for(int i=1;i<s;i++)f[i]=1e9;
	for(int i=0;i<s;i++){
		if(f[i]==1e9)continue;
		for(int j=0;j<m;j++){
			f[i|a[j].x]=min(f[i|a[j].x],f[i]+a[j].a);
		}
	}
	printf("%d",f[s-1]!=1e9?f[s-1]:-1);
	return 0;
}
