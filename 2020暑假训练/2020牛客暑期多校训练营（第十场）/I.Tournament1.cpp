#include<bits/stdc++.h>
using namespace std;
//int st[10000],ed[10000];
void work(){
	int n,n1;scanf("%d",&n),n1=(n*2)/3;
	for(int i=1;i<=n1;i++)for(int j=1;j<i;j++)printf("%d %d\n",j,i);
	for(int i=1;i<=n1;i++)for(int j=n1+1;j<=n;j++)printf("%d %d\n",i,j);
	for(int i=n1+1;i<=n;i++)for(int j=i+1;j<=n;j++)printf("%d %d\n",i,j);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
