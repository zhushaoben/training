#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	int n,m,x,y;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)a[i]=-1;
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		if(a[x]!=-1&&a[x]!=y)return puts("-1"),0;
		a[x]=y;
	}
	if(n==1)return putchar('0'+max(0,a[1])),0;
	if(a[1]==0)return puts("-1"),0;
	for(int i=1;i<=n;i++)putchar('0'+max(i==1?1:0,a[i]));
	return 0;
}
